#include <bits/stdc++.h>

using namespace std;

#define MAXN 15
char Link[MAXN][MAXN];
struct SS
{
	char cl;
	int p;
} V[MAXN];
int N, L, F;
void Print(int st, int en)
{
	if (st == en)
	{
		printf("%d", en);
		return;
	}
	Print(st, V[en].p);
	printf(",%d", en);
}
void DFS(int n, int level)
{
	V[n].cl = 'r';
	if (level == L)
	{
		printf("(");
		Print(1, n);
		printf(")\n");
		F = 1;
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (Link[n][i] == 1 && V[i].cl == 'w')
		{
			V[i].p = n;
			DFS(i, level + 1);
			V[i].cl = 'w';
		}
	}
}
void Solvedcase()
{
	int i;
	for (i = 1; i <= N; i++)
	{
		V[i].cl = 'w';
	}
	F = 0;
	DFS(1, 0);
	if (F == 0)
	{
		printf("no walk of length %d\n", L);
	}
}
void Readcase()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &Link[i][j]);
		}
	}
}
int main()
{
	int fal = 0;
	while (scanf("%d%d", &N, &L) == 2)
	{
		Readcase();
		if (fal != 0)
		{
			printf("\n");
		}
		Solvedcase();
		scanf("%d", &fal);
		for (int i = 0; i < MAXN - 1; i++)
			for (int j = 0; j < MAXN; j++)
			{
				Link[i][j] = 0;
			}
	}
	return 0;
}
