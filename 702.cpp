#include <bits/stdc++.h>

using namespace std;

#define MAX 30

long long dp[MAX][MAX][2];
void build_dp(int n)
{
	int i, j, k, len, h;
	memset(dp, 0, sizeof(dp));
	for (i = 0; i <= n; ++i)
		dp[1][i][0] = dp[1][i][1] = i;
	for (len = 2; len <= n; ++len)
	{
		dp[len][0][0] = dp[len][0][1] = 0;
		for (h = 1; h <= len; ++h)
		{
			dp[len][h][0] = dp[len][h - 1][0] + dp[len - 1][len - h][1];
			dp[len][h][1] = dp[len][h - 1][1] + dp[len - 1][len - h][0];
		}
	}
}

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		switch (n)
		{
		case 0:
			printf("0\n");
			break;
		case 1:
		case 2:
			printf("1\n");
			break;
		default:
			if (m == 1)//Shortest..
			{
				//1 3 is limited.
				n -= 2;
				build_dp(n);
				printf("%lld\n", dp[n][1][n % 2]);
			}
			else
			{
				n -= 1;
				build_dp(n);
				printf("%lld\n", dp[n][m - 1][n % 2]);
			}
		}
	}
	return 0;
}
