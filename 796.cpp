#include <bits/stdc++.h>

using namespace std;

const int N = 201;
bool bridge[N][N];
int low[N], d[N];
int color[N], bcnt;
vector<int> g[N];

void dfs(int u, int parent, int deep)
{
	color[u] = 1;
	d[u] = low[u] = deep;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (color[v] == 1 && v != parent)
		{
			low[u] = low[u] < d[v] ? low[u] : d[v];
		}
		if (color[v] == 0)
		{
			dfs(v, u, deep + 1);
			low[u] = low[u] < low[v] ? low[u] : low[v];
			if (low[v] > d[u])
			{
				bcnt++;
				bridge[u][v] = bridge[v][u] = 1;
			}
		}
	}
	color[u] = 2;
}

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		memset(bridge, false, sizeof(bridge));
		bcnt = 0;
		for (int i = 0; i < N; i++)
		{
			g[i].clear();
			color[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			int a, b, c;
			scanf("%d (%d)", &a, &c);
			for (int j = 0; j < c; j++)
			{
				scanf("%d", &b);
				g[a].push_back(b);
				g[b].push_back(a);
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (!color[i])
			{
				dfs(i, 0, 0);
			}
		}
		printf("%d critical links\n", bcnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (bridge[i][j])
				{
					printf("%d - %d\n", i, j);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
