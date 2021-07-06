#include <bits/stdc++.h>

using namespace std;

#define N 10000

bool vis[N + 3];
int comp[N + 3], in[N + 3];
vector<int> Edges[N + 3], rEdges[N + 3], sortedNodes;

void reset()
{
	for (int i = 0; i < N + 3; i++)
	{
		Edges[i].clear();
		rEdges[i].clear();
	}
	sortedNodes.clear();
	memset(vis, false, sizeof(vis));
	memset(in, 0, sizeof(in));
}

void dfs1(int x)
{
	vis[x] = true;
	for (size_t u = 0; u < Edges[x].size(); u++)
		if (!vis[Edges[x][u]])
		{
			dfs1(Edges[x][u]);
		}
	sortedNodes.push_back(x);
}

void dfs2(int x, int c)
{
	vis[x] = false;
	comp[x] = c;
	for (size_t u = 0; u < rEdges[x].size(); u++)
		if (vis[rEdges[x][u]])
		{
			dfs2(rEdges[x][u], c);
		}
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		reset();
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			Edges[a].push_back(b);
			rEdges[b].push_back(a);
		}
		for (int i = 1; i <= n; i++)
			if (!vis[i])
			{
				dfs1(i);
			}
		int c = 0;
		for (int i = sortedNodes.size() - 1; i >= 0; i--)
			if (vis[sortedNodes[i]])
			{
				dfs2(sortedNodes[i], ++c);
			}
		for (int i = 1; i <= n; i++)
		{
			for (size_t j = 0; j < Edges[i].size(); j++)
				if (comp[i] != comp[Edges[i][j]])
				{
					in[comp[Edges[i][j]]]++;
				}
		}
		int cnt = 0;
		for (int i = 1; i <= c; i++)
			if (in[i] == 0)
			{
				cnt++;
			}
		printf("Case %d: %d\n", ++cases, cnt);
	}
	return 0;
}
