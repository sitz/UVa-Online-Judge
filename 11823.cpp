#include <bits/stdc++.h>

using namespace std;

#define MAXN 700
#define MAXM 100000
#define INF 0x3f3f3f3f

struct Edge
{
	int u, v, e, c;
	Edge *link, *rev;
} edge[MAXM], *adj[MAXN], *prev_[MAXN];

int totE;
int n, s, t;
int dis[MAXN], flow[MAXN], q[MAXN];
bool inQ[MAXN];

void addEdge(int u, int v, int e, int c)
{
	Edge *p1 = &edge[totE++], *p2 = &edge[totE++];
	p1->u = u;
	p1->v = v;
	p1->e = e;
	p1->c = c;
	p1->link = adj[u];
	adj[u] = p1;
	p1->rev = p2;
	p2->u = v;
	p2->v = u;
	p2->e = 0;
	p2->c = -c;
	p2->link = adj[v];
	adj[v] = p2;
	p2->rev = p1;
}

bool spfa()
{
	memset(dis, INF, sizeof(dis));
	memset(inQ, false, sizeof(inQ));
	dis[s] = 0;
	inQ[s] = true;
	flow[s] = 1;
	int l = 0, r = 0;
	q[r++] = s;
	while (l != r)
	{
		int u = q[l++];
		inQ[u] = false;
		if (l == MAXN)
		{
			l = 0;
		}
		Edge *p = adj[u];
		while (p)
		{
			if (p->e && dis[u] + p->c < dis[p->v])
			{
				dis[p->v] = dis[u] + p->c;
				prev_[p->v] = p;
				flow[p->v] = flow[u] < p->e ? flow[u] : p->e;
				if (!inQ[p->v])
				{
					inQ[p->v] = true;
					q[r++] = p->v;
					if (r == MAXN)
					{
						r = 0;
					}
				}
			}
			p = p->link;
		}
	}
	return dis[t] != INF;
}

int minCostMaxFlow()
{
	int res = 0;
	for (int times = 0; times < 2; ++times)
	{
		if (!spfa())
		{
			break;
		}
		int u = t;
		while (u != s)
		{
			res += prev_[u]->c;
			prev_[u]->e -= 1;
			prev_[u]->rev->e += 1;
			u = prev_[u]->u;
		}
	}
	return res;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int caseT = 1; caseT <= cases; ++caseT)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		n = N * 2 + 2, s = 0, t = n - 1;
		totE = 0;
		memset(adj, NULL, sizeof(adj));
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			addEdge(N + u, v, 1, 0);
		}
		for (int i = 1; i <= N; ++i)
		{
			addEdge(s, i, 1, 0);
			addEdge(i, N + i, 1, -1);
			addEdge(N + i, t, 1, 0);
		}
		int res = -minCostMaxFlow();
		printf("%d\n", res);
	}
	return 0;
}
