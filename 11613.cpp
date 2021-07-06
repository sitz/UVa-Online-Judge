#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MAXN 220
#define MAXM MAXN *MAXN * 2
#define INF 100000000

struct node
{
	int v, cap, cost;
	node *next, *back;
};
node *adj[MAXN], edge[MAXM], *cnt;

bool vis[MAXN];
int dist[MAXN], prev_[MAXN], aug[MAXN], n, m, s, t, kase;

void addedge(int i, int j, int k, int cost)
{
	node *p = ++cnt, *q = ++cnt;
	p->v = j;
	p->cap = k;
	p->cost = cost;
	p->back = q;
	p->next = adj[i];
	adj[i] = p;
	q->v = i;
	q->cap = 0;
	q->cost = -cost;
	q->back = p;
	q->next = adj[j];
	adj[j] = q;
}
void Read()
{
	int i, procost, maxpro, sellcost, maxsell, maxsave, j;
	cnt = &edge[0];
	memset(adj, 0, sizeof(adj));
	scanf("%d%d", &n, &m);
	t = n * 2 + 1;
	s = 0;
	for (i = 1; i <= n; i++)
	{
		scanf("%d%d%d%d%d", &procost, &maxpro, &sellcost, &maxsell, &maxsave);
		addedge(s, i, maxpro, procost);
		addedge(i + n, t, maxsell, -sellcost);
		for (j = 0; j <= maxsave && i + j <= n; j++)
		{
			addedge(i, i + j + n, INF, m * j);
		}
	}
}
bool Spfa()
{
	memset(aug, 0, sizeof(aug));
	memset(dist, 0x3f, sizeof(dist));
	vis[s] = true;
	aug[s] = INF;
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	int u, v;
	node *p;
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		vis[u] = false;
		for (p = adj[u]; p; p = p->next)
		{
			v = p->v;
			if (p->cap > 0 && dist[u] + p->cost < dist[v])
			{
				dist[v] = dist[u] + p->cost;
				prev_[v] = u;
				aug[v] = min(aug[u], p->cap);
				if (!vis[v])
				{
					vis[v] = true;
					q.push(v);
				}
			}
		}
	}
	return dist[t] <= 0;
}
void Work()
{
	LL sum = 0, ans = INF;
	int u, v;
	node *p;
	while (Spfa())
	{
		sum += LL(aug[t]) * dist[t];
		ans = min(ans, sum);
		for (v = t; v != s; v = u)
		{
			u = prev_[v];
			for (p = adj[u]; p; p = p->next)
				if (p->v == v && dist[u] + p->cost == dist[v] && p->cap >= aug[t])
				{
					p->cap -= aug[t];
					p->back->cap += aug[t];
					break;
				}
		}
	}
	printf("Case %d: %lld\n", ++kase, ans > 0 ? 0 : -ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		Read();
		Work();
	}
	return 0;
}
