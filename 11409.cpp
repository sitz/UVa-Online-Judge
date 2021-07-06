#include <bits/stdc++.h>

using namespace std;

int map_[50][50];
double dp[50][50];

int main()
{
	int count, i, j, k, n, m, x, y, f, tar, val, ans;
	double urat, drat, rat;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		memset(map_, 0, sizeof(map_));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j <= i; j++)
			{
				scanf("%d", &map_[i][j]);
			}
		}
		for (i = 1; i < n; i++)
		{
			for (j = 0; j < n - i; j++)
			{
				scanf("%d", &map_[n + i - 1][j + i]);
			}
		}
		scanf("%d", &tar);
		m = n + n - 1;
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i = 0, urat = 0; i < m - 1; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (map_[i][j])
				{
					if (map_[i][j] == tar)
					{
						urat += dp[i][j];
						x = i;
						y = j;
						dp[i][j] = 0;
						continue;
					}
					f = 0;
					for (k = 0; k < n; k++)
					{
						if (map_[i + 1][k] && map_[i + 1][k] < map_[i][j])
						{
							f++;
						}
					}
					for (k = 0; k < n; k++)
					{
						if (map_[i + 1][k] && map_[i + 1][k] < map_[i][j])
						{
							dp[i + 1][k] += dp[i][j] / f;
						}
					}
					if (f)
					{
						dp[i][j] = 0;
					}
				}
			}
		}
		for (i = m - 1; i > 0; i--)
		{
			for (j = 0; j < n; j++)
			{
				if (map_[i][j])
				{
					if (map_[i][j] == tar)
					{
						urat += dp[i][j];
						break;
					}
					f = 0;
					for (k = 0; k < n; k++)
					{
						if (map_[i - 1][k] && map_[i - 1][k] < map_[i][j])
						{
							f++;
						}
					}
					for (k = 0; k < n; k++)
					{
						if (map_[i - 1][k] && map_[i - 1][k] < map_[i][j])
						{
							dp[i - 1][k] += dp[i][j] / f;
						}
					}
					if (f)
					{
						dp[i][j] = 0;
					}
				}
			}
			if (j < n)
			{
				break;
			}
		}
		/* Searate */
		memset(dp, 0, sizeof(dp));
		dp[m - 1][n - 1] = 1;
		for (i = m - 1, drat = 0; i > 0; i--)
		{
			for (j = 0; j < n; j++)
			{
				if (map_[i][j])
				{
					if (map_[i][j] == tar)
					{
						drat += dp[i][j];
						dp[i][j] = 0;
						continue;
					}
					f = 0;
					for (k = 0; k < n; k++)
					{
						if (map_[i - 1][k] && map_[i - 1][k] < map_[i][j])
						{
							f++;
						}
					}
					for (k = 0; k < n; k++)
					{
						if (map_[i - 1][k] && map_[i - 1][k] < map_[i][j])
						{
							dp[i - 1][k] += dp[i][j] / f;
						}
					}
					if (f)
					{
						dp[i][j] = 0;
					}
				}
			}
		}
		for (i = 0; i < m - 1; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (map_[i][j])
				{
					if (map_[i][j] == tar)
					{
						drat += dp[i][j];
						break;
					}
					f = 0;
					for (k = 0; k < n; k++)
					{
						if (map_[i + 1][k] && map_[i + 1][k] < map_[i][j])
						{
							f++;
						}
					}
					for (k = 0; k < n; k++)
					{
						if (map_[i + 1][k] && map_[i + 1][k] < map_[i][j])
						{
							dp[i + 1][k] += dp[i][j] / f;
						}
					}
					if (f)
					{
						dp[i][j] = 0;
					}
				}
			}
		}
		rat = urat + (1 - urat) * drat;
		ans = floor(rat * pow(10, 9)) + 1e-5;
		printf("%d\n", ans);
	}
	return 0;
}
