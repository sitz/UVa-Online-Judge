#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

struct node
{
	int nam;
	int cost;
	node *next;
	node *back;
};
struct Edge
{
	int cost;
	char color;
	node *next;
	node *back;
};
Edge *E;
int P, Q;
queue<int> que;
void MakeEdge()
{
	int i, u, v, c;
	node *x;
	E = new Edge[P + 1];
	for (i = 1; i <= P; i++)
	{
		E[i].next = E[i].back = NULL;
		E[i].color = 0;
		E[i].cost = INF;
	}
	for (i = 0; i < Q; i++)
	{
		scanf("%d%d%d", &u, &v, &c);
		x = new node;
		x->nam = v;
		x->cost = c;
		x->next = E[u].next;
		E[u].next = x;
		x = new node;
		x->nam = u;
		x->cost = c;
		x->back = E[v].back;
		E[v].back = x;
	}
}
void GetGo()
{
	int u, v;
	node *x;
	E[1].color = 1;
	E[1].cost = 0;
	que.push(1);
	while (!que.empty())
	{
		u = que.front();
		que.pop();
		E[u].color = 0;
		x = E[u].next;
		while (x != NULL)
		{
			v = x->nam;
			if (E[u].cost + x->cost < E[v].cost)
			{
				E[v].cost = E[u].cost + x->cost;
				if (E[v].color == 0)
				{
					que.push(v);
					E[v].color = 1;
				}
			}
			x = x->next;
		}
	}
}
void GetBack()
{
	int u, v;
	node *x;
	E[1].color = 1;
	E[1].cost = 0;
	que.push(1);
	while (!que.empty())
	{
		u = que.front();
		que.pop();
		E[u].color = 0;
		x = E[u].back;
		while (x)
		{
			v = x->nam;
			if (E[u].cost + x->cost < E[v].cost)
			{
				E[v].cost = E[u].cost + x->cost;
				if (E[v].color == 0)
				{
					que.push(v);
					E[v].color = 1;
				}
			}
			x = x->back;
		}
	}
}
void Cal()
{
	int total = 0, i;
	GetGo();
	for (i = 1; i <= P; i++)
	{
		total += E[i].cost;
		E[i].cost = INF;
		E[i].color = 0;
	}
	GetBack();
	for (i = 1; i <= P; i++)
		total += E[i].cost;
	printf("%d\n", total);
}

int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d%d", &P, &Q);
		MakeEdge();
		Cal();
		delete[] E;
	}
	return 0;
}
