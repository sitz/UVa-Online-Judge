#include <bits/stdc++.h>

using namespace std;

#define IN(x, y) ((y)*Y + (x))
#define OUT(x, y) (IN(x, y) + (X * Y))

const int INF = 99999999;

struct Edge
{
	int from, to, cap, flow;
	Edge *BackEdge, *next;
};
Edge *graph[1802], *p[1802];

char map_[31][31];
int X, Y, P, source, sink, D[1802], v[1802];

void AddEdge(int from, int to, int cap)
{
	Edge *p = new Edge, *q = new Edge;
	p->from = from;
	q->from = to;
	p->to = to;
	q->to = from;
	p->cap = cap;
	q->cap = 0;
	p->flow = q->flow = 0;
	p->BackEdge = q;
	q->BackEdge = p;
	p->next = graph[from];
	graph[from] = p;
	q->next = graph[to];
	graph[to] = q;
}
void init()
{
	for (int i = 0; i < 1802; i++)
	{
		D[i] = 0;
		p[i] = NULL;
		v[i] = 0;
	}
	D[source] = INF;
}
bool FindPath(int s)
{
	v[s] = 1;
	if (s == sink)
	{
		return true;
	}
	for (Edge *ptr = graph[s]; ptr; ptr = ptr->next)
	{
		if (!v[ptr->to] && ptr->cap - ptr->flow > 0)
		{
			p[ptr->to] = ptr;
			D[ptr->to] = min(D[s], ptr->cap - ptr->flow);
			if (FindPath(ptr->to))
			{
				return true;
			}
		}
	}
	return false;
}
void UpdatePath(int s, int e, int f)
{
	Edge *ptr = p[e];
	do
	{
		ptr->flow += f;
		ptr->BackEdge->flow = -ptr->flow;
		ptr = p[ptr->from];
	} while (ptr);
}
int MaxFlow()
{
	int result = 0;
	while (true)
	{
		init();
		if (!FindPath(source))
		{
			break;
		}
		result += D[sink];
		UpdatePath(source, sink, D[sink]);
	}
	return result;
}
void DeleteList(Edge *&p)
{
	if (p)
	{
		DeleteList(p->next);
		delete p;
	}
}
int main()
{
	while (scanf("%d %d %d", &X, &Y, &P) == 3)
	{
		for (int i = 0; i < 1802; i++)
		{
			graph[i] = NULL;
		}
		for (int i = 0; i < X; i++)
		{
			scanf("%s", map_[i]);
		}
		source = 2 * X * Y;
		sink = source + 1;
		for (int i = 0; i < X; i++)
			for (int j = 0; j < Y; j++)
			{
				if (map_[i][j] == '~')
				{
					continue;
				}
				if (map_[i][j] == '*')
				{
					AddEdge(source, IN(j, i), 1);
				}
				if (map_[i][j] == '#')
				{
					AddEdge(OUT(j, i), sink, P);
				}
				if (map_[i][j] == '@' || map_[i][j] == '#')
				{
					AddEdge(IN(j, i), OUT(j, i), INF);
				}
				else
				{
					AddEdge(IN(j, i), OUT(j, i), 1);
				}
				if (i && map_[i - 1][j] != '~')
				{
					AddEdge(OUT(j, i), IN(j, i - 1), INF);
				}
				if (i + 1 < X && map_[i + 1][j] != '~')
				{
					AddEdge(OUT(j, i), IN(j, i + 1), INF);
				}
				if (j && map_[i][j - 1] != '~')
				{
					AddEdge(OUT(j, i), IN(j - 1, i), INF);
				}
				if (j + 1 < Y && map_[i][j + 1] != '~')
				{
					AddEdge(OUT(j, i), IN(j + 1, i), INF);
				}
			}
		int sol = MaxFlow();
		printf("%d\n", sol);
		for (int i = 0; i < 1802; i++)
		{
			DeleteList(graph[i]);
		}
	}
}
