#include <bits/stdc++.h>

using namespace std;

#define MAXN 2009

bool is_bad[150];
char bad[1005], good[1005];
int s[MAXN], sa[MAXN], t[MAXN], t2[MAXN], c[MAXN], rank_[MAXN], height[MAXN], n;

void build_sa(int m)
{
	int *x = t, *y = t2;
	for (int i = 0; i < m; i++)
	{
		c[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		c[x[i] = s[i]]++;
	}
	for (int i = 1; i < m; i++)
	{
		c[i] += c[i - 1];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		sa[--c[x[i]]] = i;
	}
	for (int k = 1; k <= n; k <<= 1)
	{
		int p = 0;
		for (int i = n - k; i < n; i++)
		{
			y[p++] = i;
		}
		for (int i = 0; i < n; i++)
		{
			if (sa[i] >= k)
			{
				y[p++] = sa[i] - k;
			}
		}
		for (int i = 0; i < m; i++)
		{
			c[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			c[x[y[i]]]++;
		}
		for (int i = 0; i < m; i++)
		{
			c[i] += c[i - 1];
		}
		for (int i = n - 1; i >= 0; i--)
		{
			sa[--c[x[y[i]]]] = y[i];
		}
		swap(x, y);
		p = 1;
		x[sa[0]] = 0;
		for (int i = 1; i < n; i++)
		{
			x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k] ? p - 1 : p++;
		}
		if (p >= n)
		{
			break;
		}
		m = p;
	}
}

void get_height()
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		rank_[sa[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (k)
		{
			k--;
		}
		int j = sa[rank_[i] - 1];
		while (s[i + k] == s[j + k])
		{
			k++;
		}
		height[rank_[i]] = k;
	}
}

bool check(int mid)
{
	int mi = 99999, ma = -1;
	for (int i = 1; i < n; i++)
	{
		if (height[i] >= mid)
		{
			mi = min(mi, sa[i]);
			ma = max(ma, sa[i]);
		}
		else
		{
			if (ma - mi >= mid)
			{
				return 1;
			}
			mi = ma = sa[i];
		}
	}
	return ma - mi >= mid;
}

int main()
{
	int T, t = 1, r;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		memset(is_bad, 0, sizeof is_bad);
		gets(good);
		gets(bad);
		int l = strlen(bad);
		for (int i = 0; bad[i] != '\0'; i++)
		{
			is_bad[bad[i]] = 1;
		}
		n = strlen(good);
		while (n > 0 && good[n - 1] == ' ')
		{
			good[n - 1] = '\0';
			--n;
		}
		int xx = 'z';
		for (int i = 0; good[i] != '\0'; i++)
		{
			if (is_bad[good[i]])
			{
				s[i] = xx++;
			}
			else
			{
				s[i] = good[i];
			}
		}
		s[n] = 0;

		printf("Case #%d: ", t++);
		if (n <= 1)
		{
			printf("0\n");
			continue;
		}
		n++;
		build_sa(xx + 3);
		get_height();
		l = 0, r = n >> 1;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			if (check(mid))
			{
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}
