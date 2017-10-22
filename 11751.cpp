#include <bits/stdc++.h>

using namespace std;

#define N 1005
bool inst[N];
bool g[N][N];
int main()
{
	int n, m, i, j, x, y;
	while (cin >> n >> m)
	{
		if ((n == 0) && (m == 0))
		{
			break;
		}
		memset(g, 0, sizeof(g));
		for (i = 0; i <= n; i++)
		{
			inst[i] = 0;
		}
		for (i = 1; i <= m; i++)
		{
			scanf("%d%d", &x, &y);
			g[x][y] = g[y][x] = 1;
		}
		for (i = n - 2; i >= 0; i--)
		{
			for (j = i + 1; j < n; j++)
				if (g[i][j] && !inst[j])
				{
					inst[i] = 1;
					break;
				}
		}
		for (i = 0; i < n; i++)
		{
			printf("%d", inst[i]);
		}
		printf("\n");
	}
}
