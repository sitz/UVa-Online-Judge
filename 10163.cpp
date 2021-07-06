#include <bits/stdc++.h>

using namespace std;

#define MAXN 110
#define MAXM 40
#define INF 0x3f3f3f3f

int N, M, P, f[MAXM][MAXN], p[MAXM];

int init()
{
	int i;
	scanf("%d%d", &N, &M);
	if (!N && !M)
	{
		return 0;
	}
	P = 0;
	for (i = 1; i <= M; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] > P)
		{
			P = p[i];
		}
	}
	return 1;
}

void solve()
{
	int i, j, k, min, mid, max;
	min = 0, max = P + 1;
	for (;;)
	{
		mid = (min + max) / 2;// binary search
		for (i = 1; i <= N; i++)
		{
			f[0][i] = INF;
		}
		for (i = 0; i <= M; i++)
		{
			f[i][0] = 0;
		}
		for (i = 1; i <= M; i++)
			for (j = 1; j <= N; j++)
			{
				f[i][j] = f[i - 1][j];
				for (k = 0; k < j; k++)
					if (p[i] / (j - k) >= mid && f[i - 1][k] + p[i] < f[i][j])
					{
						f[i][j] = f[i - 1][k] + p[i];
					}
			}
		if (min == mid)
		{
			break;
		}
		if (f[M][N] == INF)
		{
			max = mid;
		}
		else
		{
			min = mid;
		}
	}

	if (min == 0)
		printf("0 0\n");
	else
		printf("%d %d\n", mid, f[M][N]);
}

int main()
{
	while (init())
	{
		solve();
	}
	return 0;
}
