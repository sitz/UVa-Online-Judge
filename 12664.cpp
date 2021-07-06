#include <bits/stdc++.h>

using namespace std;

int x, y;
int c[3][10], dp[105000], step[105000];

int main()
{
	int T = 0;
	while (scanf("%d%d", &x, &y) != EOF)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 10; j++)
			{
				scanf("%d", &c[i][j]);
			}
		memset(dp, 17, sizeof(dp));
		dp[x] = 0;
		step[x] = 0;
		if (x != 0)
		{
			dp[0] = c[2][0];
			step[0] = 1;
		}
		for (int i = 0; i < y; i++)
		{
			int k = 0;
			for (int j = 0; j < 10; j++)
			{
				k = i * 10 + j;
				if (k > y)
				{
					break;
				}
				if (dp[k] > dp[i] + c[0][j] || (dp[k] == dp[i] + c[0][j] && step[k] > step[i] + 1))
				{
					dp[k] = dp[i] + c[0][j];
					step[k] = step[i] + 1;
				}
			}
			for (int j = 0; j < 10; j++)
			{
				k = i + j;
				if (k > y)
				{
					break;
				}
				if (dp[k] > dp[i] + c[1][j] || (dp[k] == dp[i] + c[1][j] && step[k] > step[i] + 1))
				{
					dp[k] = dp[i] + c[1][j];
					step[k] = step[i] + 1;
				}
			}
			for (int j = 0; j < 10; j++)
			{
				k = i * j;
				if (k > y)
				{
					break;
				}
				if (dp[k] > dp[i] + c[2][j] || (dp[k] == dp[i] + c[2][j] && step[k] > step[i] + 1))
				{
					dp[k] = dp[i] + c[2][j];
					step[k] = step[i] + 1;
				}
			}
		}
		printf("Case %d: %d %d\n", ++T, dp[y], step[y]);
	}
	return 0;
}
