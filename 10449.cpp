#include <bits/stdc++.h>

using namespace std;

struct Edge
{
	int to, cost;
	Edge *next;
} * g[200];
int busy[200], dist[200], n, m;
bool label[200], visited[200];
void addEdge(int f, int t, int c)
{
	Edge *p = new Edge;
	p->to = t;
	p->cost = c;
	p->next = g[f];
	g[f] = p;
}
void freemem(Edge *&p)
{
	if (p)
	{
		freemem(p->next);
		delete p;
	}
}
void DFS(int s)
{
	visited[s] = true;
	for (Edge *p = g[s]; p; p = p->next)
		if (!visited[p->to])
		{
			label[p->to] = true;
			DFS(p->to);
		}
}
void BellmanFord()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (Edge *p = g[j]; p; p = p->next)
				if (dist[j] != 999999999 && dist[p->to] > dist[j] + p->cost)
				{
					dist[p->to] = dist[j] + p->cost;
					if (i == n - 1)
					{
						label[j] = label[p->to] = true;
					}
				}
	for (int i = 0; i < n; i++)
		if (label[i] && !visited[i])
		{
			DFS(i);
		}
	for (int i = 0; i < n; i++)
		if (dist[i] == 999999999 || label[i])
		{
			dist[i] = 0;
		}
}
int main()
{
	int caseno = 1;
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &busy[i]);
		}
		for (int i = 0; i < n; i++)
		{
			dist[i] = (i == 0) ? 0 : 999999999;
			g[i] = NULL;
			label[i] = visited[i] = false;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			scanf("%d %d", &a, &b);
			a--;
			b--;
			c = busy[b] - busy[a];
			addEdge(a, b, c * c * c);
		}
		BellmanFord();
		printf("Set #%d\n", caseno++);
		int q;
		scanf("%d", &q);
		while (q--)
		{
			int node;
			scanf("%d", &node);
			if (label[node - 1] || dist[node - 1] < 3)
			{
				printf("?\n");
			}
			else
			{
				printf("%d\n", dist[node - 1]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			freemem(g[i]);
		}
	}
	return 0;
}
