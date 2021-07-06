#include <bits/stdc++.h>

using namespace std;

int ln, sn;
long long c[105][105], dp[105][2005], f[105], lst[2005], stk[2005];

int gcd(int p, int q)
{
	return p % q ? gcd(q, p % q) : q;
}

int find(int t)
{
	int p, q, c;
	for (p = 0, q = ln - 1; p <= q;)
	{
		c = ((p + q) >> 1);
		if (lst[c] == t)
		{
			return c;
		}
		else if (lst[c] > t)
		{
			q = c - 1;
		}
		else
		{
			p = c + 1;
		}
	}
	return -1;
}

int main()
{
	int count, n, m, i, j, k, l, p, q, r, sq;
	long long s, t;
	c[0][0] = 1;
	f[0] = 1;
	for (i = 1; i <= 100; i++)
	{
		c[i][0] = 1;
		f[i] = (f[i - 1] * i) % 2147483647;
		for (j = 1; j <= 100; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 2147483647;
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i = 2, r = m; i <= 100; i++)
		{
			if (r % i == 0)
			{
				while ((r /= i) % i == 0)
					;
			}
		}
		if (r != 1)
		{
			printf("0\n");
			continue;
		}
		for (i = 1, ln = 0, sn = 0, sq = (int)sqrt((double)m); i <= sq; i++)
		{
			if (m % i == 0)
			{
				lst[ln++] = i;
				if (m != i * i)
				{
					stk[sn++] = m / i;
				}
			}
		}
		for (i = sn - 1; i >= 0; i--)
		{
			lst[ln++] = stk[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (j = 0; j < n; j++)
		{
			for (i = 1; i + j <= n; i++)
			{
				for (k = ln - 1; k >= 0; k--)
				{
					if (m % (t = (lst[k] * i / gcd(lst[k], i))))
					{
						continue;
					}
					r = find((int)t);
					if (dp[j][k] == 0)
					{
						continue;
					}
					dp[j + i][r] += (dp[j][k] * c[n - j - 1][i - 1] % 2147483647) * f[i - 1] % 2147483647;
					dp[j + i][r] %= 2147483647;
				}
			}
		}
		printf("%lld\n", dp[n][ln - 1]);
	}
	return 0;
}
