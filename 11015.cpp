#include <bits/stdc++.h>

using namespace std;

#define INF 100000000
int main()
{
	int t, n, m, i, j, k, x, y, P[30][30], D[30], min;
	char name[30][15];
	for (t = 1; scanf("%d%d", &n, &m) == 2; t++)
	{
		if ((n | m) == 0)
		{
			break;
		}
		for (i = 1; i <= n; i++)
		{
			scanf("%s", name[i]);
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				P[i][j] = INF;
			}
		}
		while (m--)
		{
			scanf("%d%d%d", &i, &j, &k);
			P[i][j] = P[j][i] = k;
		}
		for (j = 1; j <= n; j++)
		{
			for (i = 1; i <= n; i++)
			{
				if (P[i][j] == INF)
				{
					continue;
				}
				for (k = 1; k <= n; k++)
				{
					if (P[j][k] == INF || i == k)
					{
						continue;
					}
					if (P[i][j] + P[j][k] < P[i][k])
					{
						P[i][k] = P[i][j] + P[j][k];
					}
				}
			}
		}
		min = 2 * INF;
		for (i = 1; i <= n; i++)
		{
			D[i] = 0;
			for (j = 1; j <= n; j++)
			{
				D[i] += P[i][j];
			}
			if (D[i] < min)
			{
				min = D[i];
			}
		}
		for (i = 1; i <= n; i++)
		{
			if (min == D[i])
			{
				break;
			}
		}
		printf("Case #%d : %s\n", t, name[i]);
	}
	return 0;
}
