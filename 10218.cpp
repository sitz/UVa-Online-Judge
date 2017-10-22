#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;
double dp[MAX][MAX];
int m, w, c;

int main()
{
	while (true)
	{
		scanf("%d %d %d", &m, &w, &c);
		if (m == 0 && w == 0)
		{
			break;
		}
		double p = m / (double)(m + w);
		memset(dp, 0.0, MAX * MAX);
		dp[0][0] = 1.0;
		dp[0][1] = 0.0;
		for (int i = 0; i < c; ++i)
		{
			dp[i + 1][0] = dp[i][0] * (1 - p) + dp[i][1] * p;
			dp[i + 1][1] = dp[i][0] * p + dp[i][1] * (1 - p);
		}
		printf("%.7lf\n", dp[c][0]);
	}
	return 0;
}
