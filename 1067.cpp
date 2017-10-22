#include <bits/stdc++.h>

using namespace std;

#define clr(a, x) memset(a, x, sizeof(a))
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, v) for (__typeof((v).end()) it = (v).begin(); it != (v).end(); it++)

const int N = 55;
const int M = 200005;
const int INF = 1000000000;

template <class T>
void checkmin(T &t, T x)
{
	if (x < t)
	{
		t = x;
	}
}

struct edge
{
	int x, y, c;
	edge *next, *op;
} g[M], *ls[N], *cur[N], *fa[N];
int d[N], num[N], e, vis[N];

void addedge(int x, int y, int c)
{
	g[e].x = x;
	g[e].y = y;
	g[e].c = c;
	g[e].next = ls[x];
	ls[x] = &g[e];
	g[e].op = &g[e + 1];
	++e;
	g[e].x = y;
	g[e].y = x;
	g[e].c = c;
	g[e].next = ls[y];
	ls[y] = &g[e];
	g[e].op = &g[e - 1];
	++e;
}

int sap(int S, int T, int n)
{
	rep(i, e)
	{
		if (i & 1)
		{
			int sum = g[i - 1].c + g[i].c;
			g[i - 1].c = g[i].c = sum / 2;
		}
	}
	rep(i, n + 1) d[i] = -1;
	int cnt = 0;
	int flow = 0;
	while (1)
	{
		++cnt;
		queue<int> Q;
		Q.push(S);
		d[S] = cnt;
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for (edge *t = ls[x]; t; t = t->next)
			{
				if (t->c && d[t->y] != cnt && !vis[t->y])
				{
					d[t->y] = cnt;
					Q.push(t->y);
					fa[t->y] = t;
				}
			}
		}
		if (d[T] != cnt)
		{
			return flow;
		}
		int nf = INF;
		for (int i = T; i != S; i = fa[i]->x)
		{
			checkmin(nf, fa[i]->c);
		}
		for (int i = T; i != S; i = fa[i]->x)
		{
			fa[i]->c -= nf;
			fa[i]->op->c += nf;
		}
		flow += nf;
	}
	return flow;
}

int main()
{
	int n, m, Tc = 0;
	while (scanf("%d%d", &n, &m) && n + m)
	{
		printf("Case %d: ", ++Tc);
		e = 0;
		clr(ls, 0);
		map<pair<int, int>, int> mp;
		rep(i, m)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x > y)
			{
				swap(x, y);
			}
			if (x == y)
			{
				continue;
			}
			mp[make_pair(x, y)]++;
		}
		foreach (it, mp)
		{
			addedge(it->first.first, it->first.second, it->second);
		}
		clr(vis, 0);
		int w[N];
		rep(i, n)
		{
			w[i + 1] = sap(0, i + 1, n + 1);
		}
		while (1)
		{
			int best = INF;
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i] && w[i] < best)
				{
					best = w[i];
				}
			}
			if (best == INF)
			{
				break;
			}
			for (int i = 1; i <= n; i++)
				if (w[i] == best)
				{
					vis[i] = 1;
				}
			for (int i = 1; i <= n; i++)
			{
				if (!vis[i])
				{
					int flow = sap(0, i, n + 1);
					if (flow + best < w[i])
					{
						w[i] = flow + best;
					}
				}
			}
		}
		printf("%d\n\n", w[1]);
	}
}
