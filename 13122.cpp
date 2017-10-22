#include <bits/stdc++.h>

using namespace std;

const double INF = 1e+30;

double dp[260][260] = {};

int main()
{
	int n, m;
	while (scanf("%d %d", &n, &m) == 2)
	{
		int x[260], y[260];
		for (int i = 0; i < n; i++)
			scanf("%d %d", &x[i], &y[i]);

		for (int i = 0; i < n; i++)
		{
			dp[i][1] = i == 0 ? 0 : INF;
			for (int j = 2; j <= n - m; j++)
				dp[i][j] = INF;
			for (int k = 0; k < i; k++)
			{
				double dist = hypot(x[i] - x[k], y[i] - y[k]);
				for (int j = 2; j <= n - m; j++)
					dp[i][j] = min(dp[i][j], dp[k][j - 1] + dist);
			}
		}
		double ret = dp[n - 1][n - m];
		printf("%.3lf\n", ret);
	}
	return 0;
}
