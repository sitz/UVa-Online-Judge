#include <bits/stdc++.h>

using namespace std;

bool seen[1003];
int N, dp[1003][2];
vector<int> g[1003];

int solve(int node, int f)
{
	int &ret = dp[node][f];
	if (ret != -1)
	{
		return ret;
	}
	seen[node] = true;
	// 2 choices
	if (f == 1)
	{
		ret = 1;
		for (int i = 0; i < g[node].size(); i++)
		{
			if (seen[g[node][i]])
			{
				continue;
			}
			ret += min(solve(g[node][i], 0), solve(g[node][i], 1));
		}
	}
	else
	{
		ret = 0;
		for (int i = 0; i < g[node].size(); i++)
		{
			if (seen[g[node][i]])
			{
				continue;
			}
			ret += solve(g[node][i], 1);
		}
	}
	seen[node] = false;
	return ret;
}

int main()
{
	while (scanf("%d", &N) == 1, N)
	{
		for (int i = 1; i <= N; i++)
		{
			int n;
			scanf("%d", &n);
			g[i].resize(n);
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &g[i][j]);
			}
		}
		memset(dp, -1, sizeof dp);
		memset(seen, 0, sizeof seen);
		seen[1] = true;
		printf("%d\n", max(1, min(solve(1, 0), solve(1, 1))));
	}
	return 0;
}
