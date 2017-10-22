#include <bits/stdc++.h>

using namespace std;

char g[105][105];
int n, m, r, c;

int main()
{
	while (scanf("%d%d%d%d", &n, &m, &r, &c) == 4)
	{
		if (n + m + r + c == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%s", g[i]);
		}
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (g[i][j] == '0')
				{
					continue;
				}
				if (i + r - 1 >= n || j + c - 1 >= m)
				{
					ret = -1;
					j = m, i = n;
					continue;
				}
				ret++;
				for (int p = 0; p < r; p++)
				{
					for (int q = 0; q < c; q++)
					{
						if (g[i + p][j + q] == '1')
						{
							g[i + p][j + q] = '0';
						}
						else
						{
							g[i + p][j + q] = '1';
						}
					}
				}
			}
		}
		printf("%d\n", ret);
	}
	return 0;
}
