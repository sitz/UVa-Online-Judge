#include <bits/stdc++.h>

using namespace std;

/**
10667
**/
#define Dif(i, j, k) (Table[i + k][j] - Table[i][j])
#define MAXN 110
int N, M, MAX;
int Table[MAXN][MAXN];
void ReadCase()
{
	int i, j, k, a, b, c, d;
	scanf("%d", &N);
	scanf("%d", &k);
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			Table[i][j] = 1;
		}
	}
	while (k--)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		for (i = a; i <= c; i++)
		{
			for (j = b - 1; j < d; j++)
			{
				Table[i][j] = -10000;
			}
		}
	}
}
void Cal()
{
	int i, j, k, t;
	if (N == 1)
	{
		if (Table[N][N - 1] < 0)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
		}
		return;
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 0; j < N; j++)
		{
			Table[i][j] = Table[i][j] + Table[i - 1][j];
		}
	}
	MAX = Table[1][0];
	for (k = 1; k <= N; k++)
	{
		for (i = 0; i <= N - k; i++)
		{
			for (t = 0, j = 0; j < N; j++)
			{
				if (t >= 0)
				{
					t += Dif(i, j, k);
				}
				else
				{
					t = Dif(i, j, k);
				}
				if (t > MAX)
				{
					MAX = t;
				}
			}
		}
	}
	if (MAX <= 0)
	{
		printf("0\n");
	}
	else
	{
		printf("%d\n", MAX);
	}
}
void FREE()
{
	int i, j;
	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
		{
			Table[i][j] = 1;
		}
}
int main()
{
	int f = 0, kase;
	scanf("%d", &kase);
	while (kase--)
	{
		ReadCase();
		Cal();
		if (kase)
		{
			FREE();
		}
	}
	return 0;
}
