#include <bits/stdc++.h>

using namespace std;

/****************
TITLE : FIRETRUCK
   NO : 208
****************/
#define MAXN 22
char F[MAXN];
int P[MAXN];
int CONECT[MAXN][MAXN];
int MAXC, N, C, kase;
struct node
{
	char cl;
} VER[MAXN], VV[MAXN];
void PRINT_PATH(int st, int en)
{
	if (st == en)
	{
		printf("%d", st);
		return;
	}
	else
	{
		PRINT_PATH(st, P[en]);
		printf(" %d", en);
	}
}
int REACH(int n)
{
	if (n == N)
	{
		return 1;
	}
	VV[n].cl = 'r';
	for (int i = 1; i < MAXN; i++)
		if (CONECT[n][i] && VV[i].cl == 'w' && !F[i])
			if (REACH(i) == 1)
			{
				return 1;
			}
}
void DFS(int st, int en)
{
	int i;
	if (st == N)
	{
		PRINT_PATH(1, N);
		printf("\n");
		C++;
		return;
	}
	F[st] = 1;
	for (i = 1; i <= MAXC; i++)
	{
		if (F[i] == 0)
		{
			for (int j = 1; j < MAXN; j++)
			{
				VV[j].cl = 'w';
			}
			if (CONECT[st][i] && (VER[i].cl == 'r' || REACH(i) == 1))
			{
				P[i] = st;
				VER[i].cl = 'r';
				DFS(i, en);
				F[i] = 0;
			}
		}
	}
}
void FRESH()
{
	int i, j;
	for (i = 1; i < MAXN; i++)
	{
		F[i] = 0;
		P[i] = 0;
		VER[i].cl = 'w';
		VV[i].cl = 'w';
		for (j = 1; j < MAXN; j++)
		{
			CONECT[i][j] = 0;
		}
	}
}
void COMPUTE()
{
	printf("CASE %d:\n", kase++);
	C = 0;
	DFS(1, N);
	printf("There are %d routes from the firestation to streetcorner %d.\n", C, N);
}
int main()
{
	int u, v;
	kase = 1;
	while (scanf("%d", &N) == 1)
	{
		FRESH();
		MAXC = 0;
		while (1)
		{
			scanf("%d%d", &u, &v);
			if (!u && !v)
			{
				break;
			}
			if (u > MAXC)
			{
				MAXC = u;
			}
			if (v > MAXC)
			{
				MAXC = v;
			}
			CONECT[u][v] = 1;
			CONECT[v][u] = 1;
		}
		COMPUTE();
	}
	return 0;
}
