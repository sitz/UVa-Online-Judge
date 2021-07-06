#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MAXN = 25;

int T, n, l, r;
LL dp[MAXN][MAXN][MAXN];

// dp[i][l][r] = dp[i-1][l-1][r] + dp[i-1][l][r-1] + (i-2)*dp[i-1][l][r]
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &l, &r);
		memset(dp, 0, sizeof(dp));
		dp[1][1][1] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= l; j++)
			{
				for (int k = 1; k <= r; k++)
				{
					dp[i][j][k] = dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] + (i - 2) * dp[i - 1][j][k];
				}
			}
		}
		printf("%lld\n", dp[n][l][r]);
	}
	return 0;
}
