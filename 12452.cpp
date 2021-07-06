#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

int dp[10005][2], parent[10005];
vector<int> e[10005];

// dp[current_node][is_edge_covered]
void dfs(int v)
{
	int i, j, all, tmp, tmp2;
	for (i = 0; i < e[v].size(); i++)
	{
		if (e[v][i] != parent[v])
		{
			parent[e[v][i]] = v;
			dfs(e[v][i]);
		}
	}

	// compute dp[v][0] and/or dp[v][1]
	for (i = all = 0; i < e[v].size(); i++)
		if (e[v][i] != parent[v])
			all += dp[e[v][i]][1];

	dp[v][0] = min(dp[v][0], all);
	// know 100, cover parent -> compute dp[v][1]
	dp[v][1] = min(dp[v][1], all + 100);
	// know 100, don't cover parent -> compute dp[v][0]
	for (i = tmp = 0; i < e[v].size(); i++)
		if (e[v][i] != parent[v])
			tmp = max(tmp, dp[e[v][i]][1] - dp[e[v][i]][0]);
	dp[v][0] = min(dp[v][0], all - tmp + 100);

	// know 175, cover parent -> compute dp[v][1]
	dp[v][1] = min(dp[v][1], all - tmp + 175);
	// know 175, don't cover parent -> compute dp[v][0]
	for (i = tmp = tmp2 = 0; i < e[v].size(); i++)
	{
		if (e[v][i] != parent[v])
		{
			j = dp[e[v][i]][1] - dp[e[v][i]][0];
			if (j >= tmp)
			{
				tmp2 = tmp;
				tmp = j;
			}
			else if (j > tmp2)
			{
				tmp2 = j;
			}
		}
	}
	dp[v][0] = min(dp[v][0], all - tmp - tmp2 + 175);

	// know 500
	for (i = all = 0; i < e[v].size(); i++)
		if (e[v][i] != parent[v])
		{
			all += min(dp[e[v][i]][1], dp[e[v][i]][0]);
		}
	dp[v][1] = min(dp[v][1], all + 500);
}

int main()
{
	int T, t, N, n, a, b, i, j;
	scanf(" %d", &T);
	for (t = 0; t < T; t++)
	{
		scanf(" %d", &N);
		for (n = 0; n < N; n++)
			e[n].clear();
		for (n = 0; n < N; n++)
			dp[n][0] = dp[n][1] = MAX;
		memset(parent, 0, sizeof(parent));
		for (n = 0; n < N - 1; n++)
		{
			scanf(" %d %d", &a, &b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		parent[0] = 0;
		dfs(0);
		printf("$%d\n", min(dp[0][0], dp[0][1]));
	}
	return 0;
}
