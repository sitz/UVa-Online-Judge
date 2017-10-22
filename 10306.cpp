#include <bits/stdc++.h>

using namespace std;

#define N 301
#define INF 10000

int min_[N][N], v1[41], v2[41];

int main()
{
	int c, m, S, square, least, i, j, k;
	scanf("%d", &c);
	while (c--)
	{
		scanf("%d%d", &m, &S);
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", v1 + i, v2 + i);
		}
		for (i = 0; i <= S; i++)
		{
			for (j = 0; j <= S; j++)
			{
				min_[i][j] = INF;
			}
		}
		min_[0][0] = 0;
		for (i = 0; i < m; i++)
		{
			for (j = v1[i]; j <= S; j++)
			{
				for (k = v2[i]; k <= S; k++)
				{
					min_[j][k] = min(min_[j][k], 1 + min_[j - v1[i]][k - v2[i]]);
				}
			}
		}
		square = S * S;
		least = INF;
		for (i = 0; i <= S; i++)
		{
			for (j = 0; j <= S; j++)
			{
				if (i * i + j * j == square)
				{
					least = min(least, min_[i][j]);
				}
			}
		}
		if (least == INF)
		{
			puts("not possible");
		}
		else
		{
			printf("%d\n", least);
		}
	}
	return 0;
}
