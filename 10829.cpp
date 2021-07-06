#include <bits/stdc++.h>

using namespace std;

#define MX 200005
#define MAXN MX

#define REP(i, n) for (int i = 0; i < (n); i++)
#define OREP(i, n) for (int i = 1; i <= (n); i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;

int n, m, k, t;
int sa[MX], rank_[MX], height[MX], text[MX];
char input[MX];

class Suffix_DA
{
public:
	int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN];
	int cmp(int *r, int a, int b, int l)
	{
		return r[a] == r[b] && r[a + l] == r[b + l];
	}
	void da(int *r, int *sa, int n, int m)
	{
		int i, j, p, *x = wa, *y = wb, *t;
		for (i = 0; i < m; i++)
		{
			ws[i] = 0;
		}
		for (i = 0; i < n; i++)
		{
			ws[x[i] = r[i]]++;
		}
		for (i = 1; i < m; i++)
		{
			ws[i] += ws[i - 1];
		}
		for (i = n - 1; i >= 0; i--)
		{
			sa[--ws[x[i]]] = i;
		}
		for (j = 1, p = 1; p < n; j *= 2, m = p)
		{
			for (p = 0, i = n - j; i < n; i++)
			{
				y[p++] = i;
			}
			for (i = 0; i < n; i++)
				if (sa[i] >= j)
				{
					y[p++] = sa[i] - j;
				}
			for (i = 0; i < n; i++)
			{
				wv[i] = x[y[i]];
			}
			for (i = 0; i < m; i++)
			{
				ws[i] = 0;
			}
			for (i = 0; i < n; i++)
			{
				ws[wv[i]]++;
			}
			for (i = 1; i < m; i++)
			{
				ws[i] += ws[i - 1];
			}
			for (i = n - 1; i >= 0; i--)
			{
				sa[--ws[wv[i]]] = y[i];
			}
			for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
			{
				x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
			}
		}
	}
	void get_height(int *r, int *sa, int *rank_, int *height, int n)
	{
		int i, j, k = 0;
		for (i = 1; i <= n; i++)
		{
			rank_[sa[i]] = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (k)
			{
				k--;
			}
			j = sa[rank_[i] - 1];
			while (r[i + k] == r[j + k])
			{
				k++;
			}
			height[rank_[i]] = k;
		}
	}
	int dp[MAXN][32];
	void RMQ_init(int *height, int n)
	{
		for (int i = 0; i < n; i++)
		{
			dp[i][0] = height[i];
		}
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i + (1 << j) - 1 < n; i++)
			{
				dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
			}
	}
	int RMQ(int L, int R)
	{
		int k = 0;
		while ((1 << (k + 1)) <= R - L + 1)
		{
			k++;
		}
		return min(dp[L][k], dp[R - (1 << k) + 1][k]);
	}
};

Suffix_DA da;

int pre(int i, int j)
{
	if (rank_[i] > rank_[j])
	{
		swap(i, j);
	}
	return da.RMQ(rank_[i] + 1, rank_[j]);
}

int main()
{
	scanf("%d", &t);
	OREP(c, t)
	{
		scanf("%d %s", &n, input);
		int len = strlen(input);
		REP(i, len)
		{
			text[i] = input[i] - 'a' + 1;
			text[2 * len - i] = input[i] - 'a' + 1;
		}
		text[len] = 27;
		text[2 * len + 1] = 0;
		da.da(text, sa, 2 * len + 2, 28);
		memset(height, 0, sizeof height);
		da.get_height(text, sa, rank_, height, 2 * len + 1);
		da.RMQ_init(height, 2 * len + 1);
		int ret = 0;
		for (int L = (len - n) / 2; L >= 1; L--)
		{
			for (int i = 0; i < len; i += L)
			{
				int l, r;
				if (i + n + L < len)
				{
					r = min(n + L, pre(i, i + n + L));
				}
				else
				{
					r = 0;
				}
				if (i && i + n + L - 1 < len)
				{
					l = min(n + L - 1, pre(2 * len - (i - 1), 2 * len - (i + n + L - 1)));
				}
				else
				{
					l = 0;
				}
				if (!l)
				{
					if (r >= L)
					{
						ret++;
					}
				}
				else if (!r)
				{
				}
				else
				{
					if (l + r >= L)
					{
						ret += (min(L - 1, l) - max(0, L - r) + 1);
					}
				}
			}
		}
		printf("Case %d: %d\n", c, ret);
	}
	return 0;
}
