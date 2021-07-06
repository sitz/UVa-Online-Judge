#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m, t = 0;
	char map_[20][20];
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%s", map_[i]);
		}
		if (t)
		{
			printf("\n");
		}
		printf("puzzle #%d:\n", ++t);
		int num[20][20] = {}, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i - 1 < 0 || map_[i - 1][j] == '*' || j - 1 < 0 || map_[i][j - 1] == '*')
				{
					if (map_[i][j] != '*')
					{
						num[i][j] = ++cnt;
					}
				}
			}
		}
		puts("Across");
		for (int i = 0; i < n; i++)
		{
			int g = 0;
			for (int j = 0; j < m; j++)
			{
				if (map_[i][j] != '*')
				{
					if (g == 0)
					{
						printf("%3d.", num[i][j]);
					}
					printf("%c", map_[i][j]);
					g = 1;
				}
				else
				{
					if (g)
					{
						printf("\n");
						g = 0;
					}
				}
			}
			if (g)
			{
				printf("\n");
			}
		}
		printf("Down\n");
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((i - 1 < 0 || map_[i - 1][j] == '*') && map_[i][j] != '*')
				{
					int ti = i;
					printf("%3d.", num[i][j]);
					while (ti < n && map_[ti][j] != '*')
					{
						printf("%c", map_[ti++][j]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}
