#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100010;
const int INF = 1000000010;

struct Edge
{
	int u, v, c;
	Edge(int u = 0, int v = 0, int c = 0)
			: u(u), v(v), c(c)
	{
	}
};
vector<Edge> edges;

bool vis[MAXN];
int n, d[MAXN];
vector<int> G[MAXN], ans;

void add_edge(int u, int v, int c)
{
	edges.push_back(Edge(u, v, c));
	int idx = edges.size() - 1;
	G[u].push_back(idx);
}

void rev_bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(n - 1);
	vis[n - 1] = true;
	d[n - 1] = 0;

	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < G[u].size(); ++i)
		{
			int e = G[u][i];
			int v = edges[e].v;
			if (!vis[v])
			{
				vis[v] = true;
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

void bfs()
{
	memset(vis, 0, sizeof(vis));
	vis[0] = true;
	ans.clear();

	vector<int> nxt;
	nxt.push_back(0);
	for (int i = 0; i < d[0]; ++i)
	{
		int min_color = INF;
		for (int j = 0; j < nxt.size(); ++j)
		{
			int u = nxt[j];
			for (int k = 0; k < G[u].size(); ++k)
			{
				int e = G[u][k];
				int v = edges[e].v;
				if (d[u] == d[v] + 1)
				{
					min_color = min(min_color, edges[e].c);
				}
			}
		}
		ans.push_back(min_color);

		vector<int> nxt2;
		for (int j = 0; j < nxt.size(); ++j)
		{
			int u = nxt[j];
			for (int k = 0; k < G[u].size(); ++k)
			{
				int e = G[u][k];
				int v = edges[e].v;
				if (!vis[v] && d[u] == d[v] + 1 && edges[e].c == min_color)
				{
					vis[v] = true;
					nxt2.push_back(v);
				}
			}
		}
		nxt = nxt2;
	}

	printf("%d\n%d", d[0], ans[0]);
	for (int i = 1; i < ans.size(); ++i)
	{
		printf(" %d", ans[i]);
	}
	printf("\n");
}

int main()
{
	int m, u, v, c;
	while (scanf("%d%d", &n, &m) == 2)
	{
		edges.clear();
		for (int i = 0; i < n; ++i)
		{
			G[i].clear();
		}
		while (m--)
		{
			scanf("%d%d%d", &u, &v, &c);
			if (u == v)
			{
				continue;
			}
			add_edge(u - 1, v - 1, c);
			add_edge(v - 1, u - 1, c);
		}
		rev_bfs();
		bfs();
	}
	return 0;
}
