#include <bits/stdc++.h>

using namespace std;

char spac[10005], udl[10005];

int main()
{
	int cas, i, j, k, n, m, st;
	cas = 0;
	for (i = 0; i < 10005; i++)
	{
		spac[i] = ' ';
		udl[i] = '_';
	}
	udl[10004] = 0;
	spac[10004] = 0;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		printf("Triangular Museum %d\n", ++cas);
		for (i = 0, st = n * m; i < n; i++, st -= m)
		{
			for (j = 1; j <= m; j++)
			{
				printf("%.*s", st - j, spac);
				for (k = 0; k <= i; k++)
				{
					printf("/%.*s\\", (j - 1) << 1, j == m ? udl : spac);
					if (k != i)
					{
						printf("%.*s", (m << 1) - ((j) << 1), spac);
					}
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
