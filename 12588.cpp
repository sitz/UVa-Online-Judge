#include <bits/stdc++.h>

using namespace std;

int cases, cas, n, m, k, i, j, jz, l, x, r[31], quick[31];
double ans, p[11][110], dp[30000][2];

double work(int i, int j)
{
	int sum, minx, maxx, ii, u;
	double value;
	int b[11];
	if (dp[i][j] > -100000)
	{
		return dp[i][j];
	}
	sum = 0;
	minx = 100;
	maxx = 0;
	ii = i;
	for (u = 1; u <= n; u++)
	{
		b[u] = ii % jz;
		ii = ii / jz;
		sum = sum + b[u];
		if (b[u] < minx)
		{
			minx = b[u];
		}
		if (b[u] > maxx)
		{
			maxx = b[u];
		}
	}
	if (sum > m)
	{
		dp[i][j] = -50000;
		return dp[i][j];
	}
	if (sum == m)
	{
		if (maxx - minx > 1)
		{
			dp[i][j] = -50000;
		}
		else
		{
			dp[i][j] = 0;
		}
		return dp[i][j];
	}
	dp[i][j] = -50000;
	if (r[sum + 1] == 1 && j == 0)
	{
		for (u = 1; u <= n; u++)
			if (b[u] < jz - 1)
			{
				value = work(i + quick[u], 0);
				if (value > dp[i][j])
				{
					dp[i][j] = value;
				}
			}
	}
	else
	{
		for (u = 1; u <= n; u++)
			if (b[u] < jz - 1)
			{
				value = p[u][sum + 1] * (work(i + quick[u], 1) + 1) + (1 - p[u][sum + 1]) * work(i + quick[u], 0);
				if (value > dp[i][j])
				{
					dp[i][j] = value;
				}
			}
	}
	return dp[i][j];
}

int main()
{
	scanf("%d", &cases);
	for (cas = 1; cas <= cases; cas++)
	{
		scanf("%d%d", &n, &m);
		scanf("%d", &k);
		for (i = 1; i <= m; i++)
		{
			r[i] = 0;
		}
		for (i = 1; i <= k; i++)
		{
			scanf("%d", &x);
			r[x] = 1;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
			{
				scanf("%lf", &p[i][j]);
			}
		jz = (m - 1) / n + 2;
		quick[1] = 1;
		for (i = 2; i <= n; i++)
		{
			quick[i] = quick[i - 1] * jz;
		}
		l = 0;
		for (i = 1; i <= n; i++)
		{
			l = l * jz + jz - 1;
		}
		for (i = 0; i <= l; i++)
		{
			dp[i][0] = -200000;
			dp[i][1] = -200000;
		}
		ans = work(0, 1);
		printf("Case %d: %.4f\n", cas, ans);
	}
	return 0;
}
