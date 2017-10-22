#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010
#define INF 1000000000

struct edge
{
	int from, to, cap, flow, cost;
	edge(int from_, int to_, int cap_, int flow_, int cost_)
	{
		from = from_, to = to_, cap = cap_, flow = flow_, cost = cost_;
	}
};

struct MCMF
{
	int n, m, flow, cost, inq[MAXN], d[MAXN], p[MAXN], a[MAXN];
	queue<int> q;
	vector<edge> edges;
	vector<int> g[MAXN];

	void init(int n_)
	{
		int i;
		n = n_;
		for (i = 0; i <= n; i++)
			g[i].clear();
		edges.clear();
	}

	void addedge(int from, int to, int cap, int cost)
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
		for (i = 1; i <= n; i++)
		{
			d[i] = INF;
		}
		while (!q.empty())
		{
			q.pop();
		}
		d[s] = 0;
		inq[s] = true;
		q.push(s);
		a[s] = INF;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			inq[u] = false;
			for (i = 0; i < g[u].size(); i++)
			{
				edge &e = edges[g[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
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
		if (d[t] == (INF))
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

	int solve(int s, int t)
	{
		flow = 0;
		cost = 0;
		while (spfa(s, t))
		{
		}
		return cost;
	}
};

MCMF solver;
char map_[1010][1010];
int N, M, ans, r[1010], c[1010];

int main()
{
	int T;
	scanf("%d", &T);
	int i, j, test = 0;
	while (T--)
	{
		scanf("%d %d", &N, &M);
		memset(r, 0, sizeof(r));
		memset(c, 0, sizeof(c));
		int sum = 0;
		for (i = 1; i <= N; i++)
		{
			scanf("%s", map_[i] + 1);
			for (j = 1; j <= M; j++)
			{
				if (map_[i][j] == '1')
				{
					r[i]++, c[j]++, sum++;
				}
			}
		}
		int flag1, flag2;
		flag1 = flag2 = 0;
		ans = 0;
		if (sum % N == 0)
		{
			flag1 = 1;
			solver.init(N + 1);
			int need = sum / N;
			int s, t;
			s = 0, t = N + 1;
			for (i = 1; i <= N; i++)
			{
				solver.addedge(s, i, r[i], 0);
				solver.addedge(i, t, need, 0);
			}
			for (i = 1; i <= N; i++)
			{
				solver.addedge(i, i == N ? 1 : i + 1, INF, 1);
				solver.addedge(i, i == 1 ? N : i - 1, INF, 1);
			}
			ans += solver.solve(s, t);
		}
		if (sum % M == 0)
		{
			flag2 = 1;
			solver.init(M + 1);
			int need = sum / M;
			int s, t;
			s = 0, t = M + 1;
			for (i = 1; i <= M; i++)
			{
				solver.addedge(s, i, c[i], 0);
				solver.addedge(i, t, need, 0);
			}
			for (i = 1; i <= M; i++)
			{
				solver.addedge(i, i == M ? 1 : i + 1, INF, 1);
				solver.addedge(i, i == 1 ? M : i - 1, INF, 1);
			}
			ans += solver.solve(s, t);
		}
		printf("Case %d: ", ++test);
		if (flag1 && flag2)
		{
			printf("both %d\n", ans);
		}
		else if (flag1 && !flag2)
		{
			printf("row %d\n", ans);
		}
		else if (!flag1 && flag2)
		{
			printf("column %d\n", ans);
		}
		else if (!flag1 && !flag2)
		{
			printf("impossible\n");
		}
	}
	return 0;
}
