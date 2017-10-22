#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int to, w;
	Edge(int a = 0, int b = 0)
			: to(a), w(b)
	{
	}
};
vector<Edge> g[65];

int N, K, zero[65][65], one[65][65], two[65][65], sz[65];

int dfs(int nd, int p)
{
	int i, j, k, x, y, z;
	for (i = 0; i <= K; i++)
	{
		zero[nd][i] = one[nd][i] = two[nd][i] = -0xfffffff;
	}

	zero[nd][0] = 0;
	for (x = 0; x < g[nd].size(); x++)
	{
		if (g[nd][x].to == p)
		{
			continue;
		}
		sz[nd] += dfs(g[nd][x].to, nd);
	}

	// zero
	for (x = 0; x < g[nd].size(); x++)
	{
		int son = g[nd][x].to, sonw = g[nd][x].w;
		if (son == p)
		{
			continue;
		}
		for (j = K; j >= 0; j--)
		{
			for (i = 0; i <= K; i++)
			{
				int mm = max(zero[son][i], max(one[son][i], two[son][i]));
				if (j - i >= 0)
				{
					zero[nd][j] = max(zero[nd][j], zero[nd][j - i] + mm);
				}
			}
		}
	}

	// one, make path to son
	for (x = 0; x < g[nd].size(); x++)
	{
		int sonx = g[nd][x].to, sonxw = g[nd][x].w;
		if (sonx == p)
		{
			continue;
		}
		int dp[65] = {};
		for (i = 1; i <= K; i++)
		{
			dp[i] = -0xfffffff;
		}
		for (y = 0; y < g[nd].size(); y++)
		{
			int sony = g[nd][y].to, sonyw = g[nd][y].w;
			if (sony == p)
			{
				continue;
			}
			if (sony == sonx)
			{
				continue;// impt
			}
			for (j = K; j >= 0; j--)
			{
				for (i = 0; i <= K; i++)
				{
					int mm = max(zero[sony][i], max(one[sony][i], two[sony][i]));
					if (j - i >= 0)
					{
						dp[j] = max(dp[j], dp[j - i] + mm);
					}
				}
			}
		}
		for (i = 0; i <= K; i++)
		{
			for (j = 0; i + j <= K; j++)
			{
				one[nd][i + j] = max(one[nd][i + j], dp[i] + one[sonx][j] + sonxw);
				one[nd][i + j + 1] = max(one[nd][i + j + 1], dp[i] + zero[sonx][j] + sonxw);
			}
		}
	}

	// two, make a path through this node, between two son
	for (x = 0; x < g[nd].size(); x++)
	{
		int sonx = g[nd][x].to, sonxw = g[nd][x].w;
		if (sonx == p)
		{
			continue;
		}
		for (y = x + 1; y < g[nd].size(); y++)
		{
			int sony = g[nd][y].to, sonyw = g[nd][y].w;
			if (sony == p || sony == sonx)
			{
				continue;
			}
			int dp[65] = {};
			for (i = 1; i <= K; i++)
			{
				dp[i] = -0xfffffff;
			}
			for (z = 0; z < g[nd].size(); z++)
			{
				int sonz = g[nd][z].to, sonzw = g[nd][z].w;
				if (sonz == p || sonz == sonx || sonz == sony)
				{
					continue;
				}
				for (j = K; j >= 0; j--)
				{
					for (i = 0; i <= K; i++)
					{
						int mm = max(zero[sonz][i], max(one[sonz][i], two[sonz][i]));
						if (j - i >= 0)
						{
							dp[j] = max(dp[j], dp[j - i] + mm);
						}
					}
				}
			}

			for (i = 0; i <= K; i++)
			{
				for (j = 0; j <= K; j++)
				{
					for (k = 0; k <= K && i + j + k - 1 <= K; k++)
					{
						if (j && k)// j != 0, k != 0
							two[nd][i + j + k - 1] = max(two[nd][i + j + k - 1], dp[i] + one[sonx][j] + one[sony][k] + sonxw + sonyw);
						// j == 0 && k
						two[nd][i + j + k] = max(two[nd][i + j + k], dp[i] + zero[sonx][j] + one[sony][k] + sonxw + sonyw);
						// j && k == 0
						two[nd][i + j + k] = max(two[nd][i + j + k], dp[i] + one[sonx][j] + zero[sony][k] + sonxw + sonyw);
						// otherwise
						two[nd][i + j + k + 1] = max(two[nd][i + j + k + 1], dp[i] + zero[sonx][j] + zero[sony][k] + sonxw + sonyw);
					}
				}
			}
		}
	}
	return sz[nd];
}

int main()
{
	int T, i, j, k, x, y, v;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &N, &K);
		for (i = 1; i <= N; i++)
		{
			g[i].clear(); sz[i] = 1;
		}
		for (i = 1; i < N; i++)
		{
			scanf("%d%d%d", &x, &y, &v);
			g[x].push_back(Edge(y, v));
			g[y].push_back(Edge(x, v));
		}

		dfs(1, 0);

		int ret = 0;
		for (i = 1; i <= K; i++)
		{
			ret = max(ret, max(zero[1][i], max(one[1][i], two[1][i])));
		}
		printf("%d\n", ret);
	}
	return 0;
}
