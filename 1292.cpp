#include <bits/stdc++.h>

using namespace std;

const int maxn = 1501;

vector<int> e[maxn];
int n, dp[maxn][2];

void DFS(int u, int f)
{
	dp[u][0] = 0;
	dp[u][1] = 1;
	for (int i = 0; i < e[u].size(); i++)
	{
		int v = e[u][i];
		if (v == f)
		{
			continue;
		}
		DFS(v, u);
		dp[u][0] += dp[v][1];
		dp[u][1] += min(dp[v][1], dp[v][0]);
	}
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i <= n; i++)
		{
			e[i].clear();
		}
		for (int i = 0; i < n; i++)
		{
			int ita, itb, m;
			scanf("%d:(%d)", &ita, &m);
			for (int j = 0; j < m; j++)
			{
				scanf("%d", &itb);
				e[ita].push_back(itb);
				e[itb].push_back(ita);
			}
		}
		DFS(0, -1);
		printf("%d\n", min(dp[0][0], dp[0][1]));
	}
	return 0;
}
