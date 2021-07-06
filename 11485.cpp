#include <bits/stdc++.h>

using namespace std;

int ary[105];
long long dp[105][95];

int main()
{
	int n, i, j, k;
	double t;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &t);
			ary[i] = (int)floor(t * 10 + 1e-8);
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1;
		for (i = 1; i <= 8; i++)
		{
			for (j = 0; j < n; j++)
			{
				for (k = ary[j] % 10; k < 90; k++)
				{
					dp[i][k] += dp[i - 1][k - ary[j] % 10];
				}
			}
		}
		for (i = 0, ans = 0; i < 90; i++)
		{
			ans += dp[8][i] * (i / 10);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
