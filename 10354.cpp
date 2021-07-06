#include <bits/stdc++.h>

using namespace std;

#define MIN(A, B) (A < B ? A : B)
#define MAXN 103
#define INF 21474836

int D[MAXN][MAXN], Temp[MAXN][MAXN], P[MAXN][MAXN];
int Flag[MAXN], N, R, BH, OF, YH, M;
void Ini()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = i + 1; j <= N; j++)
		{
			D[i][j] = Temp[i][j] = INF;
			D[j][i] = Temp[j][i] = INF;
			P[i][j] = P[j][i] = -1;
		}
		D[i][i] = 0;
		Flag[i] = 0;
	}
}
void Flyod()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (D[i][j] > (D[i][k] + D[k][j]))
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[k][j];
				}
				else
				{
					D[i][j] = D[i][j];
					P[i][j] = P[i][j];
				}
			}
		}
	}
}
void Flyod_2()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		if (Flag[k])
		{
			continue;
		}
		for (i = 1; i <= N; i++)
		{
			if (Flag[i])
			{
				continue;
			}
			for (j = 1; j <= N; j++)
			{
				if (Flag[j])
				{
					continue;
				}
				if (Temp[i][j] > (Temp[i][k] + Temp[k][j]))
				{
					Temp[i][j] = Temp[i][k] + Temp[k][j];
				}
				else
				{
					Temp[i][j] = Temp[i][j];
				}
			}
		}
	}
}
void BossPath(int i, int j)
{
	if (i == j)
	{
		Flag[i] = 1;
	}
	else
	{
		BossPath(i, P[i][j]);
		Flag[j] = 1;
	}
}
int MyPath(int i, int j)
{
	if (i == j)
	{
		if (Flag[i])
		{
			return 1;
		}
	}
	else
	{
		if (MyPath(i, P[i][j]))
		{
			return 1;
		}
		if (Flag[j])
		{
			return 1;
		}
	}
	return 0;
}
void Mark()
{
	int k;
	for (k = 1; k <= N; k++)
	{
		if (Flag[k])
		{
			continue;
		}
		if (D[BH][k] + D[k][OF] == D[BH][OF])
		{
			BossPath(BH, k);
			BossPath(k, OF);
		}
	}
}
void Cal()
{
	if (BH == YH || BH == M || OF == YH || OF == M)
	{
		printf("MISSION IMPOSSIBLE.\n");
		return;
	}
	if (R == 0)
	{
		if (YH == M)
		{
			printf("0\n");
		}
		else
		{
			printf("MISSION IMPOSSIBLE.\n");
		}
		return;
	}
	Flyod();
	Mark();
	if (Flag[M] || Flag[YH])
	{
		printf("MISSION IMPOSSIBLE.\n");
		return;
	}
	if (!MyPath(YH, M))
	{
		printf("%d\n", D[YH][M]);
		return;
	}
	Flyod_2();
	if (Temp[YH][M] == INF)
	{
		printf("MISSION IMPOSSIBLE.\n");
		return;
	}
	printf("%d\n", Temp[YH][M]);
}
int main()
{
	int i, a, b, c;
	while (scanf("%d%d%d%d%d%d", &N, &R, &BH, &OF, &YH, &M) == 6)
	{
		Ini();
		for (i = 0; i < R; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			Temp[a][b] = Temp[b][a] = D[a][b] = D[b][a] = c;
			P[a][b] = a;
			P[b][a] = b;
		}
		Cal();
	}
	return 0;
}
