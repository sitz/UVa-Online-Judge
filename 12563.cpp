#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const int INF = 1 << 29;

void solve()
{
	int n, T;
	scanf("%d%d", &n, &T);
	int a[51];
	rep(i, n) scanf("%d", a + i);
	a[n++] = 678;
	sort(a, a + n);
	int last = a[--n];
	static int dp[51][10000];
	rep(i, n + 1)
			rep(j, T + 1)
					dp[i][j] = (i == 0 && j == 0 ? 0 : -INF);

	rep(i, n) for (int j = T; j >= 0; j--)
	{
		if (j + a[i] <= T)
			dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + 1);
		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
	}

	int ans1 = 0;
	rep(i, n + 1)
			rep(j, T)
					ans1 = max(ans1, dp[i][j]);

	int ans2 = 0;
	rep(i, n + 1)
			rep(j, T) if (dp[i][j] == ans1)
					ans2 = max(ans2, j);

	ans1++;
	ans2 += last;
	printf("%d %d\n", ans1, ans2);
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
		printf("Case %d: ", cas), solve();
	return 0;
}
