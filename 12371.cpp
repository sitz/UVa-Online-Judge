#include <bits/stdc++.h>

using namespace std;

const int maxn = 100100;
const int mod = 1000000007;

long long powmod(long long a, long long b)
{
	long long ret = 1;
	while (b)
	{
		if (b & 1)
			ret = ret * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return ret;
}
long long mi[maxn];

long long C(int n, int m)
{
	return mi[n] * powmod(mi[m], mod - 2) % mod * powmod(mi[n - m], mod - 2) % mod;
}
int dp[maxn][51];
int dp1[maxn];

int main()
{
	int i, j, k, n, m;

	dp[3][1] = 2;
	for (i = 4; i <= 100000; i++)
		for (j = 1; j <= 50 && j * 3 <= i; j++)
			dp[i][j] = (dp[i - 3][j - 1] * (i - 1ll) % mod * (i - 2ll) % mod + dp[i - 1][j] * (i - 1ll) % mod) % mod;
	for (mi[0] = i = 1; i < maxn; i++)
		mi[i] = mi[i - 1] * i % mod;
	dp1[0] = 1;
	for (i = 1; i <= 50; i++)
		dp1[i] = dp1[i - 1] * (i * 2 - 1ll) % mod;
	for (i = 1; i <= 50; i++)
	{
		for (j = 1; j <= i; j++)
			dp1[i] = dp1[i] * C(i * 2 - j * 2 + 2, 2) % mod;
	}

	int t, ii = 0;

	dp[0][0] = 1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &m);

		long long ans = 0;
		if (m * 2 <= n)
		{
			for (i = 0; i <= m; i++)
				ans = (ans + (C(n, i * 2) * dp1[i] % mod * (dp[n - i * 2][m - i] * powmod(powmod(2, m - i), mod - 2) % mod) % mod) * (C(n, i * 2) * mi[n - i * 2] % mod) % mod) % mod;
		}
		printf("Case %d: %lld\n", ++ii, ans);
	}
}
