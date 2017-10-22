#include <bits/stdc++.h>

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES 202
#define oo 1 << 30

int cap[MAX_NODES][MAX_NODES];
int flow[MAX_NODES][MAX_NODES];
int color[MAX_NODES];
int pred[MAX_NODES];
int b, d, head, i, increment, j, m, n, tail, x, y, z, lim_sup;
int q[MAX_NODES];

void enqueue(int x)
{
	q[tail] = x;
	tail++;
	color[x] = GRAY;
}
int dequeue()
{
	int x = q[head];
	head++;
	color[x] = BLACK;
	return x;
}
int bfs(int start, int target)
{
	for (i = 0; i < lim_sup; i++)
	{
		color[i] = WHITE;
	}
	head = tail = 0;
	enqueue(start);
	pred[start] = -1;
	while (head != tail)
	{
		i = dequeue();
		for (j = 0; j < lim_sup; j++)
		{
			if (color[j] == WHITE && cap[i][j] - flow[i][j] > 0)
			{
				enqueue(j);
				pred[j] = i;
			}
		}
	}
	return color[target] == BLACK;
}
int min(int x, int y)
{
	return x < y ? x : y;
}
int max_flow(int source, int sink)
{
	int max_flow = 0;
	for (i = 0; i < lim_sup; i++)
		for (j = 0; j < lim_sup; j++)
		{
			flow[i][j] = 0;
		}
	while (bfs(source, sink))

	{
		increment = oo;
		for (i = lim_sup - 1; pred[i] != -1; i = pred[i])
		{
			increment = min(increment, cap[pred[i]][i] - flow[pred[i]][i]);
		}
		for (i = lim_sup - 1; pred[i] != -1; i = pred[i])
		{
			flow[pred[i]][i] += increment;
			flow[i][pred[i]] -= increment;
		}
		max_flow += increment;
	}
	return max_flow;
}

int main()
{
	while (scanf("%d", &n) != EOF)
	{
		lim_sup = (n + 1) << 1;
		for (i = 0; i < lim_sup; i++)
		{
			for (j = 0; j < lim_sup; j++)
			{
				cap[i][j] = 0;
			}
		}
		for (i = 1; i <= n; scanf("%d", &cap[i][n + i]), i++)
			;
		scanf("%d", &m);
		for (i = 0; i < m; cap[n + x][y] = z, i++)
		{
			scanf("%d %d %d", &x, &y, &z);
		}
		scanf("%d %d", &b, &d);
		for (i = 0; i < b; cap[0][x] = oo, i++)
		{
			scanf("%d", &x);
		}
		for (i = 0; i < d; cap[n + x][2 * n + 1] = oo, i++)
		{
			scanf("%d", &x);
		}
		printf("%d\n", max_flow(0, 2 * n + 1));
	}
	return 0;
}
