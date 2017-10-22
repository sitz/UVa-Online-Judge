#include <bits/stdc++.h>

using namespace std;

const int N = 105;

char g[N][N];
bool u[N][N];

bool ok(char c)
{
	return c == '#' || c == '.';
}

int main()
{
	int T, m, n, r, i, j, cnt;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &m, &n, &cnt);
		for (i = 0; i < m; i++)
			scanf("%s", g[i]);
		r = 0;
		memset(u, true, sizeof(u));
		for (i = 0; i < n; i++)
			u[0][i] = u[m - 1][i] = false;
		for (i = 0; i < m; i++)
			u[i][0] = u[i][n - 1] = false;
		for (i = 1; i < m - 1; i++)
		{
			for (j = 1; j < n - 1; j++)
			{
				int flag = 0;
				if (j < n - 2)
				{
					if (g[i][j] == '.' && g[i][j + 1] == '.' && u[i][j] && u[i][j + 1])
					{
						if (g[i][j - 1] == '+' || g[i][j - 1] == '-' || g[i][j - 1] == '|')
							flag = 1;
						if (g[i][j + 2] == '+' || g[i][j + 2] == '-' || g[i][j + 2] == '|')
							flag = 1;
						if (!flag)
						{
							if (ok(g[i - 1][j]) && ok(g[i - 1][j + 1]) && g[i + 1][j] == '-' && g[i + 1][j + 1] == '-')
							{
								r++;
								u[i][j] = u[i][j + 1] = u[i][j - 1] = u[i][j + 2] = false;
							}
							else if (ok(g[i + 1][j]) && ok(g[i + 1][j + 1]) && g[i - 1][j] == '-' && g[i - 1][j + 1] == '-')
							{
								r++;
								u[i][j] = u[i][j + 1] = u[i][j - 1] = u[i][j + 2] = false;
							}
						}
					}
				}
				flag = 0;
				if (i < m - 2)
				{
					if (g[i][j] == '.' && g[i + 1][j] == '.' && u[i + 1][j] && u[i][j])
					{
						if (g[i - 1][j] == '+' || g[i - 1][j] == '-' || g[i - 1][j] == '|')
							flag = 1;
						if (g[i - 1][j] == '+' || g[i + 2][j] == '-' || g[i + 2][j] == '|')
							flag = 1;
						if (!flag)
						{
							if (ok(g[i][j - 1]) && ok(g[i + 1][j - 1]) && g[i][j + 1] == '|' && g[i + 1][j + 1] == '|')
							{
								r++;
								u[i][j] = u[i + 1][j] = u[i + 2][j] = u[i - 1][j] = false;
							}
							if (ok(g[i][j + 1]) && ok(g[i + 1][j + 1]) && g[i][j - 1] == '|' && g[i + 1][j - 1] == '|')
							{
								r++;
								u[i][j] = u[i + 1][j] = u[i + 2][j] = u[i - 1][j] = false;
							}
						}
					}
				}
			}
		}

		if (r >= cnt)
			puts("LOCATION OKAY");
		else
			puts("CHOOSE ANOTHER LOCATION");
	}
	return 0;
}
