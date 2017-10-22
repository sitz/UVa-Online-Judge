#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

unsigned char mask[] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define tget(i) ((t[(i) / 8] & mask[(i) % 8]) ? 1 : 0)
#define tset(i, b) t[(i) / 8] = (b) ? (mask[(i) % 8] | t[(i) / 8]) : ((~mask[(i) % 8]) & t[(i) / 8])
#define chr(i) (cs == sizeof(int) ? ((int *)s)[i] : ((unsigned char *)s)[i])
#define isLMS(i) (i > 0 && tget(i) && !tget(i - 1))
// find the start or end of each bucket
void getBuckets(unsigned char *s, int *bkt, int n, int K, int cs, bool end)
{
	int i, sum = 0;
	for (i = 0; i <= K; i++)
	{
		bkt[i] = 0;// clear all buckets
	}
	for (i = 0; i < n; i++)
	{
		bkt[chr(i)]++;// compute the size of each bucket
	}
	for (i = 0; i <= K; i++)
	{
		sum += bkt[i];
		bkt[i] = end ? sum : sum - bkt[i];
	}
}
// compute SAl
void induceSAl(unsigned char *t, int *SA, unsigned char *s, int *bkt,
							 int n, int K, int cs, bool end)
{
	int i, j;
	getBuckets(s, bkt, n, K, cs, end);// find starts of buckets
	for (i = 0; i < n; i++)
	{
		j = SA[i] - 1;
		if (j >= 0 && !tget(j))
		{
			SA[bkt[chr(j)]++] = j;
		}
	}
}
// compute SAs
void induceSAs(unsigned char *t, int *SA, unsigned char *s, int *bkt,
							 int n, int K, int cs, bool end)
{
	int i, j;
	getBuckets(s, bkt, n, K, cs, end);// find ends of buckets
	for (i = n - 1; i >= 0; i--)
	{
		j = SA[i] - 1;
		if (j >= 0 && tget(j))
		{
			SA[--bkt[chr(j)]] = j;
		}
	}
}
// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
void SA_IS(unsigned char *s, int *SA, int n, int K, int cs)
{
	int i, j;
	unsigned char *t = (unsigned char *)malloc(n / 8 + 1);// LS-type array in bits
	// Classify the type of each character
	tset(n - 2, 0);
	tset(n - 1, 1);// the sentinel must be in s1, important!!!
	for (i = n - 3; i >= 0; i--)
	{
		tset(i, (chr(i) < chr(i + 1) || (chr(i) == chr(i + 1) && tget(i + 1) == 1)) ? 1 : 0);
	}
	// stage 1: reduce the problem by at least 1/2
	// sort all the S-substrings
	int *bkt = (int *)malloc(sizeof(int) * (K + 1));// bucket array
	getBuckets(s, bkt, n, K, cs, true);							// find ends of buckets
	for (i = 0; i < n; i++)
	{
		SA[i] = -1;
	}
	for (i = 1; i < n; i++)
		if (isLMS(i))
		{
			SA[--bkt[chr(i)]] = i;
		}
	induceSAl(t, SA, s, bkt, n, K, cs, false);
	induceSAs(t, SA, s, bkt, n, K, cs, true);
	free(bkt);
	// compact all the sorted substrings into the first n1 items of SA
	// 2*n1 must be not larger than n (proveable)
	int n1 = 0;
	for (i = 0; i < n; i++)
		if (isLMS(SA[i]))
		{
			SA[n1++] = SA[i];
		}
	// find the lexicographic names of all substrings
	for (i = n1; i < n; i++)
	{
		SA[i] = -1;// init the name array buffer
	}
	int name = 0, prev = -1;
	for (i = 0; i < n1; i++)
	{
		int pos = SA[i];
		bool diff = false;
		for (int d = 0; d < n; d++)
			if (prev == -1 || chr(pos + d) != chr(prev + d) || tget(pos + d) != tget(prev + d))
			{
				diff = true;
				break;
			}
			else if (d > 0 && (isLMS(pos + d) || isLMS(prev + d)))
			{
				break;
			}
		if (diff)
		{
			name++;
			prev = pos;
		}
		pos = (pos % 2 == 0) ? pos / 2 : (pos - 1) / 2;
		SA[n1 + pos] = name - 1;
	}
	for (i = n - 1, j = n - 1; i >= n1; i--)
		if (SA[i] >= 0)
		{
			SA[j--] = SA[i];
		}
	// stage 2: solve the reduced problem
	// recurse if names are not yet unique
	int *SA1 = SA, *s1 = SA + n - n1;
	if (name < n1)
	{
		SA_IS((unsigned char *)s1, SA1, n1, name - 1, sizeof(int));
	}
	else// generate the suffix array of s1 directly
		for (i = 0; i < n1; i++)
		{
			SA1[s1[i]] = i;
		}
	// stage 3: induce the result for the original problem
	bkt = (int *)malloc(sizeof(int) * (K + 1));// bucket array
	// put all left-most S characters into their buckets
	getBuckets(s, bkt, n, K, cs, true);// find ends of buckets
	for (i = 1, j = 0; i < n; i++)
		if (isLMS(i))
		{
			s1[j++] = i;// get p1
		}
	for (i = 0; i < n1; i++)
	{
		SA1[i] = s1[SA1[i]];// get index in s
	}
	for (i = n1; i < n; i++)
	{
		SA[i] = -1;// init SA[n1..n-1]
	}
	for (i = n1 - 1; i >= 0; i--)
	{
		j = SA[i];
		SA[i] = -1;
		SA[--bkt[chr(j)]] = j;
	}
	induceSAl(t, SA, s, bkt, n, K, cs, false);
	induceSAs(t, SA, s, bkt, n, K, cs, true);
	free(bkt);
	free(t);
}

const int MX = 6000100;

char in[MX];
int n, m, len[MX], deq[MX];
int which[MX], sa[MX], lcp[MX], b[MX];

void buildLCP(char *t, int n, int *a, int *lcp)
{
	int h = 0;
	rep(i, n + 1) b[a[i]] = i;
	rep(i, n + 1)
	{
		if (b[i])
		{
			for (int j = a[b[i] - 1]; j + h < n && i + h < n && t[j + h] == t[i + h]; ++h)
				;
			lcp[b[i]] = h;
		}
		else
		{
			lcp[b[i]] = -1;
		}
		if (h > 0)
		{
			--h;
		}
	}
}

int main()
{
	int cs;
	scanf("%d", &cs);
	while (cs--)
	{
		scanf("%d", &n);
		m = 0;
		rep(i, n)
		{
			scanf("%s", in + m);
			len[i] = strlen(in + m);
			m += len[i];
			in[m++] = '0' + i;
			len[i] = m;
		}
		len[m] = 0;
		SA_IS((unsigned char *)in, sa, m + 1, 256, sizeof(char));
		buildLCP(in, m, sa, lcp);
		int cur = 0;
		rep(i, m + 1)
		{
			if (i == len[cur] - 1)
			{
				which[b[i]] = n, cur++;
			}
			else
			{
				which[b[i]] = cur;
			}
		}
		int ans = 0, k = 0, use[6] = {}, h = 0, t = 0;
		for (int l = 0, r = 0; l < m; l++)
		{
			while (l > r)
			{
				r++;
			}
			while (r <= m && k < n)
			{
				int idx = which[r];
				if (idx < n && use[idx]++ == 0)
				{
					k++;
				}
				while (h < t && lcp[deq[t - 1]] >= lcp[r])
				{
					t--;
				}
				if (r)
				{
					deq[t++] = r;
				}
				r++;
			}
			if (k < n)
			{
				break;
			}
			ans = max(ans, lcp[deq[h]]);
			if (h < t && deq[h] <= l + 1)
			{
				h++;
			}
			int idx = which[l];
			if (idx < n && --use[idx] == 0)
			{
				k--;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
