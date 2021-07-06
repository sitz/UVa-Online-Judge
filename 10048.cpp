#include <bits/stdc++.h>

using namespace std;

#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a > b ? b : a)
#define INF 21474836
#define MAXN 102

int N, M, Q, A[MAXN][MAXN];

void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				A[i][j] = MIN(A[i][j], MAX(A[i][k], A[k][j]));
			}
		}
	}
}
void Cal()
{
	int a, b;
	Floyd();
	while (Q--)
	{
		scanf("%d%d", &a, &b);
		if (A[a][b] == INF)
		{
			printf("no path\n");
		}
		else
		{
			printf("%d\n", A[a][b]);
		}
	}
}
void INI()
{
	int i, j;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			A[i][j] = INF;
		}
		A[i][i] = 0;
	}
}

int main()
{
	int i, kase = 1;
	int a, b, c;
	while (scanf("%d%d%d", &N, &M, &Q) == 3)
	{
		if (!N && !M && !Q)
		{
			break;
		}
		INI();
		for (i = 0; i < M; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			A[a][b] = A[b][a] = c;
		}
		if (kase > 1)
		{
			putchar('\n');
		}
		printf("Case #%d\n", kase++);
		Cal();
	}
	return 0;
}
