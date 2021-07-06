#include <bits/stdc++.h>

using namespace std;

#define MAXN 102
#define MAX MAXN * 201

char Link[MAXN][MAXN], fg[MAXN][210];
struct ss
{
	int node, move;
} Q[MAX];
int qh, qt, C, D, S, E;

void Push(int n, int move)
{
	if (fg[n][move])
	{
		return;
	}
	fg[n][move] = 1;
	Q[qh].node = n;
	Q[qh++].move = move;
	qh %= MAX;
}
ss Pop()
{
	ss temp;
	temp.node = Q[qt].node;
	temp.move = Q[qt++].move;
	qt %= MAX;
	return temp;
}
int Bfs()
{
	int i, move, n;
	ss temp;
	qh = qt = 0;
	Push(S, 0);
	while (qh != qt)
	{
		temp = Pop();
		n = temp.node;
		move = temp.move + 1;
		for (i = 1; i <= C; i++)
		{
			if (Link[n][i])
			{
				if (move == D && i == E)
					return 1;
				if (move < D)
					Push(i, move);
			}
		}
	}
	return 0;
}
void Cal()
{
	if ((D == 1 && Link[S][E]) || (S == E && D == 0) || Bfs())
	{
		printf("Yes, Teobaldo can travel.\n");
	}
	else
	{
		printf("No, Teobaldo can not travel.\n");
	}
}
void Free()
{
	int i, j;
	for (i = 1; i <= C; i++)
	{
		for (j = i + 1; j <= C; j++)
			Link[i][j] = Link[j][i] = 0;
		for (j = 0; j <= D + 1; j++)
			fg[i][j] = 0;
	}
}

int main()
{
	int i, u, v, L, f = 0;
	while (scanf("%d%d", &C, &L) == 2)
	{
		if (!L && !C)
			break;
		if (f++)
			Free();
		for (i = 0; i < L; i++)
		{
			scanf("%d%d", &u, &v);
			Link[u][v] = Link[v][u] = 1;
		}
		scanf("%d%d%d", &S, &E, &D);
		Cal();
	}
	return 0;
}
