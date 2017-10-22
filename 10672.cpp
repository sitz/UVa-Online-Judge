#include <bits/stdc++.h>

using namespace std;

#define MAXN 10002
#define max(a, b) (a > b ? a : b)

struct ret
{
	int child, val;
};
struct node
{
	int nam;
	node *next;
};
struct Vertex
{
	int child;
	int total;
	char color;
	node *next;
};
Vertex V[MAXN];
queue<ret> Q;
int Cost, N;

void ReadCase()
{
	int i, u, ini, n, v, j;
	node *x;
	for (i = 1; i <= N; i++)
	{
		scanf("%d%d%d", &u, &ini, &n);
		V[u].total = ini;
		V[u].child = 1;
		for (j = 0; j < n; j++)
		{
			scanf("%d", &v);
			x = new node;
			x->nam = v;
			x->next = V[u].next;
			V[u].next = x;
			V[v].color = 1;
		}
	}
}
ret Set(int u)
{
	ret temp;
	node *x = V[u].next;
	int ch = 0, val = 0;
	while (x)
	{
		temp = Set(x->nam);
		V[u].child += temp.child;
		V[u].total += temp.val;
		x = x->next;
	}
	temp.child = V[u].child;
	temp.val = V[u].total;
	Cost += max(V[u].total - V[u].child, 0);
	return temp;
}
void BFS(int u)
{
	ret x, y;
	node *nd;
	int v, cost;
	x.child = u;
	x.val = 0;
	Q.push(x);
	while (!Q.empty())
	{
		y = Q.front();
		Q.pop();
		nd = V[y.child].next;
		while (nd)
		{
			v = nd->nam;
			if (V[v].child > V[v].total)
			{
				Cost += V[v].child - V[v].total;
			}
			y.child = v;
			Q.push(y);
			nd = nd->next;
		}
	}
}
int Root()
{
	int i;
	for (i = 1; i <= N; i++)
		if (!V[i].color)
		{
			break;
		}
	return i;
}
void Cal()
{
	int i, r;
	Cost = 0;
	r = Root();
	Set(r);
	BFS(r);
	printf("%d\n", Cost);
}
int main()
{
	while (scanf("%d", &N) && N)
	{
		ReadCase();
		Cal();
		for (int i = 1; i <= N; i++)
		{
			V[i].next = NULL;
			V[i].total = 0;
			V[i].color = 0;
		}
	}
	return 0;
}
