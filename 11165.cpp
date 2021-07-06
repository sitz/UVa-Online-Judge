#include <bits/stdc++.h>

using namespace std;

struct LinkList
{
	int v;
	LinkList *next;
	LinkList(int s) : v(s) {}
} *link;

struct Edge
{
	int V1, V2;
	Edge(int v1, int v2) : V1(v1), V2(v2) {}
	Edge *next;
} * e[100000];

int queue_[100000], front, rear, dist[100000], n, k, S, T;

void clearlist(LinkList *&p)
{
	if (p)
	{
		clearlist(p->next);
		delete p;
		p = NULL;
	}
}
bool canvisit(int s, int from)
{
	bool flag = true;
	for (Edge *p = e[from]; p && flag; p = p->next)
		if (p->V1 <= s && p->V2 >= s)
		{
			flag = false;
		}
	return flag;
}
void freeEdge(Edge *&p)
{
	if (p)
	{
		freeEdge(p->next);
		delete p;
		p = NULL;
	}
}
int main()
{
	int cases, U, V1, V2;
	scanf("%d", &cases);
	for (int x = 1; x <= cases; x++)
	{
		scanf("%d", &n);
		scanf("%d", &k);
		for (int i = 0; i < n; i++)
		{
			e[i] = NULL;
		}
		for (int i = 0; i < k; i++)
		{
			scanf("%d %d-%d", &U, &V1, &V2);
			Edge *p = new Edge(V1, V2);
			p->next = e[U];
			e[U] = p;
		}
		scanf("%d %d", &S, &T);
		for (int i = 0; i < n; i++)
		{
			dist[i] = 99999999;
		}
		dist[S] = 0;
		queue_[0] = S;
		front = -1;
		rear = 0;
		link = NULL;
		for (int i = n - 1; i >= 0; i--)
		{
			if (i == S)
			{
				continue;
			}
			LinkList *p = new LinkList(i);
			p->next = link;
			link = p;
		}
		while (front < rear)
		{
			int node = queue_[++front];
			if (node == T)
			{
				break;
			}
			if (e[node] == NULL)
			{
				for (LinkList *p = link; p; p = p->next)
				{
					dist[p->v] = dist[node] + 1;
					queue_[++rear] = p->v;
				}
				clearlist(link);
			}
			else
			{
				for (LinkList *p = link, *prev = NULL; p;)
				{
					if (!canvisit(p->v, node))
					{
						prev = p;
						p = p->next;
						continue;
					}
					dist[p->v] = dist[node] + 1;
					queue_[++rear] = p->v;
					if (p == link)
					{
						prev = p;
						link = p->next;
						delete p;
						p = link;
						prev = NULL;
					}
					else
					{
						prev->next = p->next;
						delete p;
						p = prev->next;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			freeEdge(e[i]);
		}
		clearlist(link);
		if (dist[T] != 99999999)
		{
			printf("Case #%d: %d\n", x, dist[T]);
		}
		else
		{
			printf("Case #%d: Impossible\n", x);
		}
	}
}
