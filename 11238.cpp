#include <bits/stdc++.h>

using namespace std;

long long dp[4][12][350], ans[301];

int main()
{
	int n, i, j, k, l, p, q;
	dp[0][0][0] = 1;
	for (i = 1; i < 11; i++)
	{
		for (j = 0; j < 301; j++)
		{
			for (p = 0; p < 10; p++)
			{
				for (q = 0; q + p < 10; q++)
				{
					dp[0][i][j + p + q] += dp[0][i - 1][j];
					dp[0][i][j + p + p + q] += dp[1][i - 1][j];
					dp[0][i][j + p + p + q + q] += dp[2][i - 1][j];
					dp[0][i][j + p + p + p + q + q] += dp[3][i - 1][j];
				}
				dp[1][i][j + p + q] += dp[0][i - 1][j];
				dp[1][i][j + p + p + q] += dp[1][i - 1][j];
				dp[1][i][j + p + p + q + q] += dp[2][i - 1][j];
				dp[1][i][j + p + p + p + q + q] += dp[3][i - 1][j];
			}
			dp[2][i][j + p] += dp[0][i - 1][j];
			dp[2][i][j + p + p] += dp[1][i - 1][j];
			dp[3][i][j + p + p] += dp[2][i - 1][j];
			dp[3][i][j + p + p + p] += dp[3][i - 1][j];
		}
	}
	for (j = 0; j < 301; j++)
	{
		dp[0][i][j] += dp[0][i - 1][j];
		for (p = 0; p < 10; p++)
		{
			dp[0][i][j + p] += dp[1][i - 1][j];
			for (q = 0; q + p < 11; q++)
			{
				dp[0][i][j + p + q] += dp[2][i - 1][j];
				dp[0][i][j + p + p + q] += dp[3][i - 1][j];
			}
		}
		dp[0][i][j + p] += dp[1][i - 1][j];
		for (q = 0; q < 11; q++)
		{
			dp[0][i][j + p + q] += dp[2][i - 1][j];
			dp[0][i][j + p + p + q] += dp[3][i - 1][j];
		}
	}
	for (j = 0; j < 301; j++)
	{
		ans[j] = dp[0][i][j];
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == -1)
		{
			break;
		}
		printf("%lld\n", ans[n]);
	}
	return 0;
}
