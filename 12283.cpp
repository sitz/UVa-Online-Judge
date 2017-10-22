#include <bits/stdc++.h>

using namespace std;

int dp[103][103], a[103];

void dfs(int i, int j)
{
	if (dp[i][j] != -1)
		return;
	if (i > j)
	{
		dp[i][j] = 0;
		return;
	}
	if (i == j)
	{
		dp[i][j] = 1;
		return;
	}
	if (j == i + 1)
	{
		dp[i][j] = (a[i] == a[j] ? 1 : 2);
		return;
	}
	int k;
	dfs(i, j - 1);
	dp[i][j] = dp[i][j - 1] + 1;
	for (k = i; k < j; k++)
	{
		if (a[k] == a[j])
		{
			dfs(i, k), dfs(k + 1, j - 1);
			if (dp[i][k] + dp[k + 1][j - 1] < dp[i][j])
				dp[i][j] = dp[i][k] + dp[k + 1][j - 1];
		}
	}
}

int main()
{
	int t, cs, n, m, num, i, j;
	scanf("%d", &t);
	for (cs = 1; cs <= t; cs++)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (num = 1, i = 2; i <= n; i++)
			if (a[i] != a[i - 1])
				a[++num] = a[i];
		n = num;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				dp[i][j] = -1;
		dfs(1, n);
		printf("Case %d: %d\n", cs, dp[1][n]);
	}
	return 0;
}
