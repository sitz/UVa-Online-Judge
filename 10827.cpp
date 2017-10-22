#include <bits/stdc++.h>

using namespace std;

#define MAXN 200
#define mx(a, b) (a > b ? a : b)

int N, B[MAXN][MAXN];

void ReadCase()
{
	int i, j, l = N + 1;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &B[i][j]);
			B[i][N + j] = B[i][j];
			B[l][j] = B[i][j];
			B[l][j + N] = B[i][j];
		}
		l++;
	}
}

void Set()
{
	int i, j;
	for (i = 1; i <= N * 2; i++)
		for (j = 1; j <= N * 2; j++)
			B[i][j] += B[i - 1][j];
}

void Cal()
{
	int i, j, k, l, sum, m;
	int max = 0, temp;
	if (N == 1)
	{
		printf("%d\n", mx(B[1][1], 0));
		return;
	}
	Set();
	for (i = 1; i <= N; i++)
		for (j = i; j < i + N; j++)
			for (k = 1; k <= N; k++)
			{
				m = 0;
				for (l = k; l < k + N; l++)
				{
					m += B[j][l] - B[i - 1][l];
					if (m < 0)
						m = 0;
					else if (m > max)
						max = m;
				}
			}
	printf("%d\n", max);
}

int main()
{
	int k;
	scanf("%d", &k);
	while (k--)
	{
		scanf("%d", &N);
		ReadCase();
		Cal();
	}
	return 0;
}
