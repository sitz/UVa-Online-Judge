#include <bits/stdc++.h>

using namespace std;

#define maxn 2100
#define inf 1000000000

struct edge
{
	int from, to, cap, flow;
	int cost;
	edge(int from_, int to_, int cap_, int flow_, int cost_)
	{
		from = from_, to = to_, cap = cap_, flow = flow_, cost = cost_;
	}
};

struct MCMF
{
	int n, m;
	int flow;
	int cost;
	vector<edge> edges;
	vector<int> g[maxn];
	int inq[maxn];
	int d[maxn];
	int p[maxn];
	int a[maxn];
	queue<int> q;

	void init(int n_)
	{
		int i;
		n = n_;
		for (i = 0; i <= n; i++)
		{
			g[i].clear();
		}
		edges.clear();
	}

	void addedge(int from, int to, int cap, int cost)//有向图
	{
		edges.push_back(edge(from, to, cap, 0, cost));
		edges.push_back(edge(to, from, 0, 0, -cost));
		m = edges.size();
		g[from].push_back(m - 2);
		g[to].push_back(m - 1);
	}

	bool spfa(int s, int t)
	{
		int i, j;
		memset(inq, 0, sizeof(inq));
		for (i = 0; i <= n; i++)
		{
			d[i] = -(inf);
		}
		while (!q.empty())
		{
			q.pop();
		}
		d[s] = 0;
		inq[s] = true;
		q.push(s);
		a[s] = inf;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (i = 0; i < g[u].size(); i++)
			{
				edge &e = edges[g[u][i]];
				if (e.cap > e.flow && d[e.to] < d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = g[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if (d[t] == -(inf))
		{
			return false;
		}
		flow += a[t];
		cost += d[t] * a[t];
		int u = t;
		while (u != s)
		{
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
			u = edges[p[u]].from;
		}
		return true;
	}

	void solve(int s, int t)
	{
		flow = 0;//最大流
		cost = 0;//最小费用
		int i, j;
		for (i = 0; i < 2; i++)
		{
			spfa(s, t);
		}
		printf("%d\n", cost);
	};
};

int n;
MCMF solver;
struct node
{
	int x, y;
	int w;
	bool operator<(const node &r) const
	{
		if (x == r.x)
		{
			return y < r.y;
		}
		return x < r.x;
	}
} p[2100];

int main()
{
	int i, j;
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].w);
		}
		sort(p + 1, p + n + 1);
		int s, t;
		s = 0, t = 2 * n + 1;
		solver.init(2 * n + 1);
		for (i = 1; i <= n; i++)
		{
			solver.addedge(s, i, 1, 0);
			solver.addedge(i, i + n, 1, p[i].w);
			solver.addedge(i + n, t, 1, 0);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = i + 1; j <= n; j++)
			{
				if (p[j].x > p[i].y)
				{
					break;
				}
			}
			for (; j <= n; j++)
			{
				solver.addedge(i + n, j, 1, 0);
			}
		}
		solver.solve(s, t);
	}
	return 0;
}
