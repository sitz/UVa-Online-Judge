#include <bits/stdc++.h>

using namespace std;

char map_[1000][1001];
char walk[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int n, m, dp[1000][100];

char check(int x, int y)
{
	if (x > -1 && x < n && y > -1 && y < m)
	{
		if (map_[x][y] == '#')
		{
			return 1;
		}
	}
	return 0;
}

void floodfill(int x, int y)
{
	int i, xtmp, ytmp;
	for (i = 0; i < 4; i++)
	{
		xtmp = x + walk[i][0];
		ytmp = y + walk[i][1];
		if (check(xtmp, ytmp))
		{
			map_[xtmp][ytmp] = '@';
			floodfill(xtmp, ytmp);
		}
	}
}

int main()
{
	int b, s, i, j, k, len;
	while (scanf("%d%d", &n, &m) == 2)
	{
		scanf("%d%d", &b, &s);
		for (i = 0; i < n; i++)
		{
			scanf("%s", map_[i]);
		}
		floodfill(0, 0);
		memset(dp, 0, sizeof(dp));
		for (j = 0; j < m; j++)
		{
			for (i = 0; i < n; i++)
			{
				if (map_[i][j] == '@')
				{
					len = i;
				}
				else if (map_[i][j] == '#')
				{
					len = i - len - 1;
					break;
				}
			}
			dp[j][0] = len;
			if (j && dp[j - 1][0] < dp[j][0])
			{
				dp[j][0] = dp[j - 1][0];
			}
			i = j - s - 1;
			if (i < 0)
			{
				continue;
			}
			for (k = 1; k < b; k++)
			{
				if (!dp[i][k - 1])
				{
					break;
				}
				dp[j][k] = len + dp[i][k - 1];
				if (dp[j - 1][k] && dp[j - 1][k] < dp[j][k])
				{
					dp[j][k] = dp[j - 1][k];
				}
			}
		}
		printf("%d\n", dp[m - 1][b - 1]);
	}
	return 0;
}
