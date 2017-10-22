#include <bits/stdc++.h>

using namespace std;

int m, n;
int g[200];
char str[200];
int dp[1 << 12][1 << 12];

int solve(int state, int cmp)
{
	int i, j;
	if (dp[state][cmp] != -1)
	{
		return dp[state][cmp];
	}
	int num = 0;
	for (i = 0; i < n; i++)
	{
		if ((g[i] & state) == cmp)
		{
			num++;
		}
	}
	if (num == 1)
	{
		return dp[state][cmp] = 0;
	}
	int ans = 0x7fffffff;
	for (i = 0; i < m; i++)
	{
		if (state & (1 << i))
		{
			continue;
		}
		dp[state | (1 << i)][cmp] = solve(state | (1 << i), cmp);
		dp[state | (1 << i)][cmp | (1 << i)] = solve(state | (1 << i), cmp | (1 << i));
		ans = min(ans, max(dp[state | (1 << i)][cmp], dp[state | (1 << i)][cmp | (1 << i)]) + 1);
	}
	return dp[state][cmp] = ans;
}

int main()
{
	int i, j;
	while (scanf("%d %d", &m, &n) != EOF && m && n)
	{
		for (i = 0; i < n; i++)
		{
			g[i] = 0;
			scanf("%s", str);
			for (j = 0; j < m; j++)
			{
				g[i] = (g[i] << 1) + str[j] - '0';
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", solve(0, 0));
	}
	return 0;
}
