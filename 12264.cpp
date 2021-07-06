#include <bits/stdc++.h>

using namespace std;

#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) | 1)
#define MID(i) ((l[i] + r[i]) >> 1)
#define CC(i, v) memset(i, v, sizeof(i))
#define REP(i, l, n) for (int i = l; i < int(n); ++i)
#define FOREACH(con, i) for (__typeof(con.begin()) i = con.begin(); i != con.end(); ++i)
#define OP(i) (((i) - (pool)) ^ 1)

const int INF = 100000000;

struct sap
{
	const static int V = 2010, E = 1000000, INF = 100000000;

	bool reachS[V], reachT[V];
	int dis[V], numdis[V];

	struct edge
	{
		int v, cap;
		edge *nxt;
	} pool[E], *g[V], *pp;
	edge *e[V], *pree[V];

	int pre[V], maxflow;

	void bfs(int v, int n)
	{
		int que[V], tail = 0;
		bool vst[V] = {0};
		memset(numdis, 0, sizeof(numdis));
		fill(dis, dis + n, n);
		dis[v] = 0, vst[v] = 1, que[0] = v;
		for (int j = 0; j <= tail; j++)
		{
			int tmp = que[j % n];
			for (edge *i = g[tmp]; i != NULL; i = i->nxt)
			{
				if (pool[OP(i)].cap > 0 && !vst[i->v])
				{
					tail++;
					vst[i->v] = 1;
					que[tail % n] = i->v;
					dis[i->v] = dis[tmp] + 1;
					numdis[dis[i->v]]++;
				}
			}
		}
	}
	int augment_path(int &v, int s, int t)
	{
		while (e[v] != NULL)
		{
			if (e[v]->cap > 0 && dis[v] == dis[e[v]->v] + 1)
			{
				pre[e[v]->v] = v, pree[e[v]->v] = e[v], v = e[v]->v;
				if (v == t)
				{
					int minf = INF;
					for (int i = t; i != s; i = pre[i])
					{
						minf = min(minf, pree[i]->cap);
					}
					for (int i = t; i != s; i = pre[i])
					{
						pree[i]->cap -= minf;
						pool[OP(pree[i])].cap += minf;
					}
					v = s;
					return minf;
				}
			}
			else
			{
				e[v] = e[v]->nxt;
			}
		}
		return 0;
	}

	int maxflow(int n, int s, int t)
	{
		bfs(t, n);
		int v = s;
		copy(g, g + n, e);
		while (dis[s] < n)
		{
			int add = augment_path(v, s, t);
			maxflow += add;
			if (add == 0)
			{
				int mindis = n;
				numdis[dis[v]]--;
				if (!numdis[dis[v]])
				{
					break;
				}
				for (edge *i = g[v]; i != NULL; i = i->nxt)
				{
					if (i->cap > 0)
					{
						mindis = min(mindis, dis[i->v] + 1);
					}
				}
				dis[v] = mindis;
				numdis[dis[v]]++;
				e[v] = g[v];
				if (v != s)
				{
					v = pre[v];
				}
			}
		}
		return maxflow;
	}
	void firststart()
	{
		pp = pool;
		maxflow = 0;
		memset(g, 0, sizeof(g));
	}
	void add_edge(int i, int j, int cap)
	{
		pp->v = j;
		pp->cap = cap;
		pp->nxt = g[i];
		g[i] = pp++;
	}
	void dfss(int x)
	{
		reachS[x] = true;
		for (edge *i = g[x]; i != NULL; i = i->nxt)
			if (i->cap && !reachS[i->v])
			{
				dfss(i->v);
			}
	}
	void dfst(int x)
	{
		reachT[x] = true;
		for (edge *i = g[x]; i != NULL; i = i->nxt)
			if (pool[OP(i)].cap && !reachT[i->v])
			{
				dfst(i->v);
			}
	}
} flow;

#define FIRST(i) ((i))
#define SECOND(i) ((i) + n)

const int N = 110;

char maps[N][N];
int a[N], eni[N];

void find_adj(int n)
{
	memset(eni, 0, sizeof(eni));
	for (int i = 1; i <= n; i++)
	{
		if (a[i])
		{
			continue;
		}
		for (int j = 1; j <= n; j++)
		{
			if (maps[j][i] == 'Y' && a[j])
			{
				eni[j] = true;
			}
		}
	}
}
int build(int n, int mid, int s, int t)
{
	int ff = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 0)
		{
			continue;
		}
		flow.add_edge(s, FIRST(i), a[i]);
		flow.add_edge(FIRST(i), s, 0);
		flow.add_edge(FIRST(i), SECOND(i), INF);
		flow.add_edge(SECOND(i), FIRST(i), 0);
		if (eni[i])
		{
			flow.add_edge(SECOND(i), t, mid);
			flow.add_edge(t, SECOND(i), 0);
			ff += mid;
		}
		else
		{
			flow.add_edge(SECOND(i), t, 1);
			flow.add_edge(t, SECOND(i), 0);
			ff++;
		}
		for (int j = 1; j <= n; j++)
		{
			if (a[j] == 0 || maps[i][j] == 'N')
			{
				continue;
			}
			flow.add_edge(FIRST(i), SECOND(j), INF);
			flow.add_edge(SECOND(j), FIRST(i), 0);
		}
	}
	return ff;
}
int ans(int n)
{
	int low = 2, high = INF, ans = 1;
	int s = 0, t = n * 2 + 1;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		flow.firststart();
		int tmp = build(n, mid, s, t);
		int f = flow.maxflow(t + 1, s, t);
		if (f == tmp)
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return ans;
}

int main()
{
	int T, n;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf(" %c", &maps[i][j]);
			}
		}
		find_adj(n);
		printf("%d\n", ans(n));
	}
	return 0;
}
