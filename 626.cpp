#include <bits/stdc++.h>

using namespace std;

/**
626
**/
#define MAXN 102
int N, total;
char Link[MAXN][MAXN];
struct ss
{
	int parent;
	char colour;
} V[MAXN];
void Print(int n, int key)
{
	if (key == n)
	{
		printf("%d", n);
		return;
	}
	Print(V[n].parent, key);
	printf(" %d", n);
}
void DFS_A(int n, int pre, int level, int key)
{
	int i;
	if (n <= pre)
	{
		return;
	}
	if (level == 2)
	{
		if (Link[n][key])
		{
			Print(n, key);
			putchar('\n');
			total++;
		}
		return;
	}
	V[n].colour = 'r';
	for (i = 1; i <= N; i++)
	{
		if (Link[n][i] && V[i].colour == 'w')
		{
			V[i].parent = n;
			DFS_A(i, n, level + 1, key);
		}
	}
	V[n].colour = 'w';
}
void DFS_D(int n, int pre, int level, int key)
{
	int i;
	if (n >= pre)
	{
		return;
	}
	if (level == 2)
	{
		if (Link[n][key])
		{
			Print(n, key);
			putchar('\n');
			total++;
		}
		return;
	}
	V[n].colour = 'r';
	for (i = 1; i <= N; i++)
	{
		if (Link[n][i] && V[i].colour == 'w')
		{
			V[i].parent = n;
			DFS_D(i, n, level + 1, key);
		}
	}
	V[n].colour = 'w';
}
void Cal()
{
	int i;
	total = 0;
	for (i = 1; i <= N; i++)
	{
		V[i].colour = 'w';
	}
	for (i = 1; i <= N; i++)
	{
		if (i >= 3)
		{
			DFS_D(i, 200, 0, i);
		}
		if (N - i >= 2)
		{
			DFS_A(i, 0, 0, i);
		}
	}
	printf("total:%d\n", total);
}
int main()
{
	int i, j, f = 0;
	while (scanf("%d", &N) == 1)
	{
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &Link[i][j]);
			}
		Cal();
		//printf("\n");
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
			{
				Link[i][j] = 0;
			}
		putchar('\n');
	}
	return 0;
}
