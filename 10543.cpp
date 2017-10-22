#include <bits/stdc++.h>

using namespace std;

/****
10543
****/
#define MAXN 52
int MAP[MAXN][MAXN];
int Dummy[MAXN][MAXN];
int Temp[MAXN][MAXN];
int Node, Vertex, Sp;
void Copy()
{
	int i, j;
	for (i = 0; i < Node; i++)
		for (j = 0; j < Node; j++)
		{
			Dummy[i][j] = Temp[i][j];
		}
}
void MULT()
{
	int i, j, k;
	int sum;
	for (i = 0; i < Node; i++)
	{
		for (j = 0; j < Node; j++)
		{
			sum = 0;
			for (k = 0; k < Node - 1; k++)
			{
				sum += MAP[i][k] * Dummy[k][j];
			}
			Temp[i][j] = sum;
		}
	}
	Copy();
}
void Cal()
{
	int i, limit;
	limit = Sp - 2;
	for (i = 1; i <= 20; i++)
	{
		MULT();
		if (i >= limit && Dummy[0][Node - 1] != 0)
		{
			printf("%d\n", i + 2);
			return;
		}
	}
	printf("LOSER\n");
}
int main()
{
	int i, u, v, j;
	while (scanf("%d%d%d", &Node, &Vertex, &Sp) == 3)
	{
		if (!Node && !Vertex && !Sp)
		{
			break;
		}
		for (i = 0; i < Vertex; i++)
		{
			scanf("%d%d", &u, &v);
			MAP[u][v] = 1;
			Dummy[u][v] = 1;
		}
		if (Sp == 2 && Dummy[0][Node - 1] == 1)
		{
			printf("2\n");
			continue;
		}
		Cal();
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
			{
				MAP[i][j] = Dummy[i][j] = 0;
			}
	}
	return 0;
}
