#include <bits/stdc++.h>

using namespace std;

#define maxn 10002

struct ss
{
	int node;
	int edge;
};
struct St
{
	int indeg;
	int outdeg;
	int distime;
	int fintime;
};
struct Edge
{
	int u, v;
};
list<ss> Link[maxn];
St Node[maxn];
Edge edge[maxn];
ss P[maxn];
int N, E, cover, Fg, Time;
char NFg[maxn];
char EFg[maxn];

void Free()
{
	int i;
	for (i = 0; i <= N; i++)
	{
		Link[i].clear();
		Node[i].distime = Node[i].fintime = 0;
		Node[i].indeg = Node[i].outdeg = 0;
		NFg[i] = EFg[i] = 0;
	}
	for (i = N + 1; i <= E; i++)
		EFg[i] = 0;
}
int Tra(int n)
{
	int v;
	ss t;
	cover++;
	list<ss>::iterator p;
	Node[n].distime = ++Time;
	NFg[n] = 1;
	for (p = Link[n].begin(); p != Link[n].end(); p++)
	{
		t = *p;
		v = t.node;
		if (NFg[v] == 1)
		{
			if (Node[v].distime > Node[n].distime)
				return 1;
			continue;
		}
		if (Tra(v))
			return 1;
	}
	Node[n].fintime = ++Time;
	return 0;
}
int IsEuler()
{
	int i, d, u, v;
	cover = 0;
	Time = 0;
	d = Tra(0);
	if (d)
		return d;
	if (cover < N)
		return 1;
	for (i = 0; i < N; i++)
		if (Node[i].indeg != Node[i].outdeg)
			return 1;
	for (i = 0; i < E; i++)
	{
		u = edge[i].u;
		v = edge[i].v;
		if (Node[u].distime > Node[v].distime)
			if (Node[u].fintime > Node[v].fintime)
				return 1;
		if (Node[u].distime < Node[v].distime)
			if (Node[u].fintime < Node[v].fintime)
				return 1;
	}
	return 0;
}
int Mark(int v, int key)
{
	int u, edge;
	if (v == key)
		return 0;
	if (v == -1)
		return 1;
	u = P[v].node;
	edge = P[v].edge;
	if (EFg[edge])
		return 1;
	EFg[edge] = 1;
	return Mark(u, key);
}
int DFS(int u)
{
	int v;
	ss tmp;
	list<ss>::iterator p;
	NFg[u] = 1;
	for (p = Link[u].begin(); p != Link[u].end(); p++)
	{
		v = p->node;
		if (NFg[v] == 1)
		{
			if (EFg[p->edge] == 1)
				return 1;
			EFg[p->edge] = 1;
			if (Mark(u, v))
				return 1;
		}
		else
		{
			tmp.node = u;
			tmp.edge = p->edge;
			P[v] = tmp;
			if (DFS(v))
				return 1;
		}
	}
	return 0;
}
void Cal()
{
	int d;
	if (N <= 1)
	{
		printf("YES\n");
		return;
	}
	if (!E || IsEuler())
	{
		printf("NO\n");
		return;
	}
	P[0].node = -1;
	for (d = 0; d < N; d++)
		NFg[d] = 0;
	if (DFS(0))
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main()
{
	int i, k, c = 1;
	ss t;
	Edge ed;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d%d", &N, &E);
		for (i = 0; i < E; i++)
		{
			scanf("%d%d", &ed.u, &ed.v);
			t.node = ed.v;
			t.edge = i;
			Link[ed.u].push_back(t);
			edge[i] = ed;
			Node[ed.u].outdeg++;
			Node[ed.v].indeg++;
		}
		Cal();
		Free();
	}
	return 0;
}
