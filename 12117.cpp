#include <bits/stdc++.h>

using namespace std;

#define MAX 1 << 29

long long dp[2005][8];

int main()
{
	memset(dp, 0, sizeof(dp));
	int i, j, N, cnt = 1, n;
	dp[1][0] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[2][3] = 1;
	dp[2][4] = 1;
	dp[2][5] = 1;
	dp[2][6] = 1;
	for (n = 3; n < 2001; n++)
	{
		dp[n][0] = (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2] + dp[n - 1][3] + dp[n - 1][4] + dp[n - 1][5] + dp[n - 1][6]) % 1000000000000;
		dp[n][1] = (dp[n - 2][0] + dp[n - 2][4]) % 1000000000000;
		dp[n][2] = (dp[n - 2][0] + dp[n - 2][5]) % 1000000000000;
		dp[n][3] = dp[n - 2][0];
		dp[n][4] = (dp[n - 1][2] + dp[n - 2][0]) % 1000000000000;
		if (n - 3 > 0)
		{
			dp[n][4] = (dp[n][4] + dp[n - 3][2]) % 1000000000000;
		}
		dp[n][5] = (dp[n - 1][1] + dp[n - 2][0]) % 1000000000000;
		if (n - 3 > 0)
		{
			dp[n][5] = (dp[n][5] + dp[n - 3][1]) % 1000000000000;
		}
		dp[n][6] = (dp[n - 2][0] + dp[n - 2][3]) % 1000000000000;
	}
	while (scanf(" %d", &N) == 1 && N)
	{
		printf("Case %d: %lld\n", cnt++, dp[N][0]);
	}
	return 0;
}
