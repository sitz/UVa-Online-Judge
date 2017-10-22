#include <bits/stdc++.h>

using namespace std;

#define MAX 1001

typedef struct NODE
{
	int son[MAX];
	int size;
	int used;
} NODE;

NODE node[MAX];
int bfs[MAX];
int dfs[MAX];
int n;

void print_tree()
{
	int i, j;
	for (i = 1; i <= n; i++)
	{
		printf("%d:", i);
		for (j = 0; j < node[i].size; j++)
		{
			printf(" %d", node[i].son[j]);
		}
		printf("\n");
	}
}

int inside(int t, int b)
{
	int i;
	for (i = 1; i < b; i++)
		if (dfs[i] == t)
		{
			return 1;
		}
	return 0;
}

int loc(int b)
{
	int i;
	for (i = 1; i <= n; i++)
		if (dfs[i] == b)
		{
			return i;
		}
}

void reconstruct(int now, int b)
{
	int i, prev;
	for (i = now + 1; i <= n; i++)
		if (!node[bfs[i]].used && inside(bfs[i], b))
		{
			break;
		}
	if (i > n)
	{
		return;
	}
	node[bfs[now]].son[node[bfs[now]].size++] = bfs[i];
	node[bfs[i]].used = 1;
	prev = i;
	for (i = i + 1; inside(bfs[i], b) && !node[bfs[i]].used && bfs[prev] < bfs[i]; i++)
	{
		node[bfs[now]].son[node[bfs[now]].size++] = bfs[i];
		node[bfs[i]].used = 1;
		reconstruct(prev, loc(bfs[i]));
		prev = i;
	}
	reconstruct(prev, b);
}

void ini()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		node[i].used = 0;
		node[i].size = 0;
	}
}

int main()
{
	int i;
	while (scanf("%d", &n) != EOF)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &bfs[i]);
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &dfs[i]);
		}
		ini();
		reconstruct(1, n + 1);
		print_tree();
	}
	return 0;
}
