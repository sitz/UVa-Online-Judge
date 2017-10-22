#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

char s[77], t[77];

int dp[77][77][77][77];
int dfs(int i, int j, int k, int l)
{
	if (i > j || k > l)
	{
		return 0;
	}
	int &res = dp[i][j][k][l];
	if (res != -1)
	{
		return res;
	}
	if (s[i] == s[j] && t[k] == t[l] && s[i] == t[k])
	{
		return res = (i == j || k == l ? 1 : 2) + dfs(i + 1, j - 1, k + 1, l - 1);
	}
	return res = max(max(dfs(i + 1, j, k, l), dfs(i, j - 1, k, l)),
									 max(dfs(i, j, k + 1, l), dfs(i, j, k, l - 1)));
}

void solve()
{
	scanf("%s%s", s, t);
	int m = strlen(s), n = strlen(t);
	rep(j, m) rep(i, j + 1) rep(l, n) rep(k, l + 1) dp[i][j][k][l] = -1;
	printf("%d\n", dfs(0, m - 1, 0, n - 1));
}

int main()
{
	int T, t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case %d: ", t), solve();
	}
	return 0;
}
