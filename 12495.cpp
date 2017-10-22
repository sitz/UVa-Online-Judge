#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const int M = 1000000007;

int main()
{
	static int dp[10][1001][1001];
	for (int d = 1; d <= 10; d++)
	{
		rep(n, 1001) dp[d - 1][n][0] = (n == 0 ? d : 1);
		rep(n, 1000) rep(r, n + 1) dp[d - 1][n + 1][r + 1] = (dp[d - 1][n][r + 1] + dp[d - 1][n][r]) % M;
	}
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++)
	{
		int n, k, d;
		scanf("%d%d%d", &n, &k, &d);
		printf("Case %d: %d\n", cas, k == 1 ? n : dp[d - 1][max(n - (d - 1) * k, 0)][k]);
	}
	return 0;
}
