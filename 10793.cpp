#include <bits/stdc++.h>

using namespace std;

#define MAXN 105
#define INF 21474478
#define MIN(a, b) (a > b ? b : a)

int Cost[MAXN][MAXN], N, E;

void Ini()
{
	int i, j;
	for (i = 1; i <= 100; i++)
	{
		for (j = 1 + i; j <= 100; j++)
		{
			Cost[i][j] = Cost[j][i] = INF;
		}
		Cost[i][i] = 0;
	}
}
void Floyd()
{
	int i, j, k;
	for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
				Cost[i][j] = MIN(Cost[i][j], Cost[i][k] + Cost[k][j]);
}
void Cal()
{
	int A[100], ta = 0, i, j, f;
	int max = 0, min = INF;
	Floyd();
	for (i = 6; i <= N; i++)
	{
		f = 1;
		for (j = 2; j < 6; j++)
		{
			if (Cost[i][j] != Cost[i][j - 1] || Cost[i][j] == INF)
			{
				f = 0;
				break;
			}
		}
		if (f)
			A[ta++] = i;
	}
	for (i = 0; i < ta; i++)
	{
		max = 0;
		f = A[i];
		for (j = 1; j <= N; j++)
			if (Cost[f][j] > max)
				max = Cost[f][j];
		min = MIN(min, max);
	}
	min != INF ? printf("%d\n", min) : printf("-1\n");
}

int main()
{
	int ks, k = 1, u, v, c;
	scanf("%d", &ks);
	while (ks--)
	{
		scanf("%d%d", &N, &E);
		Ini();
		while (E--)
		{
			scanf("%d%d%d", &u, &v, &c);
			if (Cost[u][v] > c)
			{
				Cost[u][v] = Cost[v][u] = c;
			}
		}
		printf("Map %d: ", k++);
		Cal();
	}
	return 0;
}
