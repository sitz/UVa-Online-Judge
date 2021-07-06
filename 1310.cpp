#include <bits/stdc++.h>

using namespace std;

#define maxn 2010

int n, m;

int g[maxn][maxn];
int lowu[maxn];
int pre[maxn];
int dfs_clock;

void dfs(int u, int fa)
{
	int i, j;
	pre[u] = lowu[u] = ++dfs_clock;
	for (i = 1; i <= n; i++)
	{
		if ((g[u][i] || g[i][u]) && i != fa)
		{
			if (pre[i] == -1)
			{
				dfs(i, u);
				lowu[u] = min(lowu[u], lowu[i]);
				if (lowu[i] > pre[u])
				{
					printf("%d %d %d\n", u, i, 2);
					g[u][i] = g[i][u] = 0;
				}
			}
			else
			{
				lowu[u] = min(lowu[u], lowu[i]);
			}
		}
	}
}

void dfs2(int u, int fa)
{
	int i, j;
	pre[u] = lowu[u] = ++dfs_clock;
	for (i = 1; i <= n; i++)
	{
		if (g[u][i] && i != fa)
		{
			if (pre[i] == -1)
			{
				dfs2(i, u);
				lowu[u] = min(lowu[u], lowu[i]);
				if (g[u][i] && g[i][u])
				{
					if (lowu[i] > pre[u])
					{
						printf("%d %d %d\n", i, u, 1);
						g[u][i] = 0;
					}
					else
					{
						printf("%d %d %d\n", u, i, 1);
						g[i][u] = 0;
					}
				}
			}
			else
			{
				lowu[u] = min(lowu[u], pre[i]);
				if (g[u][i] && g[i][u])
				{
					printf("%d %d %d\n", u, i, 1);
					g[i][u] = 0;
				}
			}
		}
	}
}

int main()
{
	//   freopen("input.txt","r",stdin);
	int i, j;
	while (scanf("%d %d", &n, &m) == 2)
	{
		memset(g, 0, sizeof(g));
		for (i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			if (c == 1)
			{
				g[a][b] = 1;
			}
			else
			{
				g[a][b] = g[b][a] = 1;
			}
		}
		memset(pre, -1, sizeof(pre));
		dfs_clock = 0;
		dfs(1, -1);
		memset(pre, -1, sizeof(pre));
		dfs_clock = 0;
		for (i = 1; i <= n; i++)
		{
			if (pre[i] == -1)
			{
				dfs2(i, -1);
			}
		}
	}
	return 0;
}
