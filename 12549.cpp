#include <bits/stdc++.h>

using namespace std;

#define M 50000
#define oo 1000000000

int head[M], work[M], mark[M], Q[M * 10], dist[M], tot, src, dest;

struct node
{
	int to, cap, next;
} edge[M * 10];

void add(int a, int b, int c)
{
	edge[tot].to = b, edge[tot].cap = c, edge[tot].next = head[a], head[a] = tot++;
	edge[tot].to = a, edge[tot].cap = 0, edge[tot].next = head[b], head[b] = tot++;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

bool BFS()
{
	int i, j, k, l, h, y;
	for (i = 0; i <= dest; i++)
	{
		dist[i] = -1;
	}
	dist[src] = 0;
	l = h = 0;
	Q[l++] = src;
	while (h < l)
	{
		k = Q[h++];
		for (i = head[k]; i != -1; i = edge[i].next)
		{
			y = edge[i].to;
			if (edge[i].cap > 0 && dist[y] == -1)
			{
				dist[y] = dist[k] + 1;
				Q[l++] = y;
			}
		}
	}
	return (dist[dest] >= 0);
}
int DFS(int x, int exp)
{
	mark[x] = 1;
	if (x == dest)
	{
		return exp;
	}
	for (int temp, y, &i = work[x]; i != -1; i = edge[i].next)
	{
		y = edge[i].to;
		if (edge[i].cap > 0 && dist[y] == dist[x] + 1 && !mark[y])
		{
			if ((temp = DFS(y, min(edge[i].cap, exp))) > 0)
			{
				edge[i].cap -= temp;
				edge[i ^ 1].cap += temp;
				return temp;
			}
		}
	}
	return 0;
}
int Dinic_flow()
{
	int ans = 0, flow, i;
	while (BFS())
	{
		for (i = 0; i <= dest; i++)
			work[i] = head[i];
		while (1)
		{
			for (i = 0; i <= dest; i++)
				mark[i] = 0;
			flow = DFS(src, oo);
			if (flow == 0)
				break;
			ans += flow;
		}
	}
	return ans;
}

int row[11000], col[11000], mrow, mcol;
char mp[110][110];

int main()
{
	int i, j, n, m, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				mp[i][j] = '.';
		int c, a, b;
		scanf("%d", &c);
		for (i = 1; i <= c; i++)
		{
			scanf("%d%d", &a, &b);
			mp[a][b] = '*';
		}
		scanf("%d", &c);
		for (i = 1; i <= c; i++)
		{
			scanf("%d%d", &a, &b);
			mp[a][b] = '#';
		}
		for (i = 1; i <= n; i++)
			row[i] = i;
		for (i = 1; i <= m; i++)
			col[i] = i;
		mrow = n, mcol = m;
		src = 0, tot = 0, dest = 20020;
		for (i = src; i <= dest; i++)
			head[i] = -1;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				if (mp[i][j] == '#')
				{
					row[i] = ++mrow;
					col[j] = ++mcol;
				}
				if (mp[i][j] == '*')
					add(row[i], col[j] + 10005, 1);
			}
		}
		for (i = 1; i <= mrow; i++)
			add(src, i, 1);
		for (i = 1; i <= mcol; i++)
			add(i + 10005, dest, 1);
		printf("%d\n", Dinic_flow());
	}
	return 0;
}
