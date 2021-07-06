#include <bits/stdc++.h>

using namespace std;

/*
Wormholes
558
algorithm : Bellman-Ford
*/
#define MAXN 1001
int N, M;
struct sss
{
	int waight;
	int ind, add;
	int list[1001];
} node[MAXN];
struct edge
{
	int u, v, cost;
} Edge[MAXN * 2];
int link[MAXN][MAXN];
void Bellman(int max)
{
	int i, j, v, t;
	node[0].waight = 0;// may be max = N-2
	for (t = 0; t < max + 1; t++)
	{
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < node[i].ind; j++)
			{
				v = node[i].list[j];
				if (node[v].waight > (node[i].waight + link[i][v]))
				{
					node[v].waight = node[i].waight + link[i][v];
				}
			}
		}
	}
}
int Cal()
{
	int i, u, v, max = 0;
	for (i = 0; i < N; i++)
		if (node[i].add > max)
		{
			max = node[i].add;
		}
	Bellman(max);
	for (i = 0; i < M; i++)
	{
		u = Edge[i].u;
		v = Edge[i].v;
		if (node[v].waight > node[u].waight + Edge[i].cost)
		{
			return 1;
		}
	}
	return 0;
}
void Free()
{
	int i;
	for (i = 0; i < N; i++)
	{
		node[i].add = node[i].ind = 0;
	}
}
int main()
{
	int kases, u, v, c;
	scanf("%d", &kases);
	while (kases--)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d", &u, &v, &c);
			node[u].list[node[u].ind++] = v;
			node[u].waight = node[v].waight = 214748364;
			Edge[i].u = u;
			Edge[i].v = v;
			Edge[i].cost = c;
			link[u][v] = c;
			node[v].add++;
		}
		if (Cal())
		{
			printf("possible\n");
		}
		else
		{
			printf("not possible\n");
		}
		if (kases)
		{
			Free();
		}
	}
	return 0;
}
