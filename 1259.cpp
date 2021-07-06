#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500, MAXM = 5000, INF = 1000000100;

struct Edge
{
	Edge(){};
	Edge(int a, int b, int c, int d)
	{
		v = a;
		f = b;
		w = c;
		nxt = d;
	}
	int v, f, w, nxt;
};
Edge e[MAXM + 10];

queue<int> que;
bool inQue[MAXN + 10];
int g[MAXN + 10], a[101][101], dist[MAXN + 10], prev_[MAXN + 10], pree[MAXN + 10], nume, src, sink, maxflow, n, m;

void addedge(int u, int v, int c, int w)
{
	e[++nume] = Edge(v, c, w, g[u]);
	g[u] = nume;
	e[++nume] = Edge(u, 0, -w, g[v]);
	g[v] = nume;
}

void init()
{
	nume = 1;
	memset(g, 0, sizeof(g));
}

bool findPath()
{
	while (!que.empty())
	{
		que.pop();
	}
	que.push(src);
	for (int i = 0; i <= sink; i++)
	{
		dist[i] = INF;
	}
	dist[src] = 0;
	inQue[src] = 1;
	while (!que.empty())
	{
		int u = que.front();
		que.pop();
		for (int i = g[u]; i; i = e[i].nxt)
		{
			if (e[i].f > 0 && dist[u] + e[i].w < dist[e[i].v])
			{
				dist[e[i].v] = dist[u] + e[i].w;
				prev_[e[i].v] = u;
				pree[e[i].v] = i;
				if (!inQue[e[i].v])
				{
					inQue[e[i].v] = true;
					que.push(e[i].v);
				}
			}
		}
		inQue[u] = false;
	}
	return dist[sink] < INF;
}

int augment()
{
	int u = sink;
	int delta = INF;
	while (u != src)
	{
		if (e[pree[u]].f < delta)
		{
			delta = e[pree[u]].f;
		}
		u = prev_[u];
	}
	u = sink;
	while (u != src)
	{
		e[pree[u]].f -= delta;
		e[pree[u] ^ 1].f += delta;
		u = prev_[u];
	}
	maxflow += delta;
	return dist[sink] * delta;
}
int mincostflow()
{
	int cur = 0, ans = 0;
	while (findPath())
	{
		cur += augment();
	}
	return cur;
}

int main()
{
	int test;
	scanf("%d", &test);
	for (int ii = 1; ii <= test; ii++)
	{
		scanf("%d%d", &n, &m);
		src = n + 1;
		sink = n + 2;
		init();
		int ans = 0, tsum = 0, tans = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = INF;
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int u, v, p, s, x;
			scanf("%d%d%d%d%d", &u, &v, &p, &s, &x);
			a[u][v] = p - s;
			tans += s;
			if (x == 1)
			{
				ans += p;
				tsum++;
				addedge(src, v, 1, 0);
				addedge(u, sink, 1, 0);
				continue;
			}
			if (p >= s)
			{
				ans += s;
				addedge(u, v, 1, p - s);
				continue;
			}
			ans += p;
			tsum++;
			addedge(v, u, 1, s - p);
			addedge(src, v, 1, 0);
			addedge(u, sink, 1, 0);
		}
		maxflow = 0;
		ans += mincostflow();
		printf("Case %d: ", ii);
		if (maxflow != tsum)
		{
			printf("impossible\n");
			continue;
		}
		if (tans != ans)
		{
			printf("%d\n", ans);
			continue;
		}
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (a[i][j] > a[i][k] + a[k][j])
					{
						a[i][j] = a[i][k] + a[k][j];
					}
				}
			}
		}
		ans = INF;
		for (int i = 1; i <= n; i++)
		{
			ans = min(ans, a[i][i]);
		}
		if (ans == INF)
		{
			printf("impossible\n");
		}
		else
		{
			printf("%d\n", ans + tans);
		}
	}
	return 0;
}
