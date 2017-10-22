#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int cas = 1, n, m, d, a, b;
double p[4];
double dp[110][110][110];
int s[40];

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		memset(s, 0, sizeof(s));
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &a);
			s[a] |= 1;
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", &b);
			s[b] |= 2;
		}
		for (int i = 0; i < 4; i++)
		{
			p[i] = 0;
		}
		for (int i = 1; i <= n; i++)
		{
			p[s[i]]++;
		}
		for (int i = 0; i < 4; i++)
		{
			p[i] /= n;
		}
		scanf("%d", &d);
		memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;
		for (int i = 0; i < d; i++)
			for (int j = 0; j <= i; j++)
				for (int k = 0; k <= i; k++)
				{
					dp[i + 1][j][k] += dp[i][j][k] * p[0];
					dp[i + 1][j + 1][k] += dp[i][j][k] * p[1];
					dp[i + 1][j][k + 1] += dp[i][j][k] * p[2];
					dp[i + 1][j + 1][k + 1] += dp[i][j][k] * p[3];
				}
		double ans = 0;
		for (int i = 0; i * 2 <= d; i++)
		{
			ans += dp[d][i][i * 2];
		}
		printf("Case %d: %.5lf\n", cas++, ans);
	}
	return 0;
}
