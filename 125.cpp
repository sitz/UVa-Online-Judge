#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

int Max;
struct ss
{
	int path;
} M[MAXN][MAXN];

void Floyd()
{
	int i, j, k, temp;
	for (k = 0; k <= Max; k++)
	{
		for (i = 0; i <= Max; i++)
		{
			for (j = 0; j <= Max; j++)
			{
				temp = M[i][k].path * M[k][j].path;
				if (temp)
				{
					if (M[i][k].path < 0 || M[k][j].path < 0)
					{
						M[i][j].path = -1;
					}
					else
					{
						M[i][j].path += temp;
					}
				}
				if (M[i][j].path && M[j][i].path)
				{
					M[i][j].path = M[j][i].path = -1;
				}
			}
		}
	}
}

void Cal()
{
	int i, j;
	Floyd();
	for (i = 0; i <= Max; i++)
	{
		printf("%d", M[i][0]);
		for (j = 1; j <= Max; j++)
		{
			printf(" %d", M[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int i, u, v, n, j, m = 0;
	while (scanf("%d", &n) == 1)
	{
		Max = -1;
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &u, &v);
			M[u][v].path = 1;
			if (u > Max)
			{
				Max = u;
			}
			if (v > Max)
			{
				Max = v;
			}
		}
		printf("matrix for city %d\n", m++);
		Cal();
		for (i = 0; i <= Max; i++)
		{
			for (j = 0; j <= Max; j++)
			{
				M[i][j].path = 0;
			}
		}
	}
	return 0;
}
