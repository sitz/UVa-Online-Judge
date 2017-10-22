#include <bits/stdc++.h>

using namespace std;

#define LL long long

//ä¸ºèªå·±å æ²¹O(â©_â©)O~

const long long mod = 21092013;//è¿ä¸ªå¿é¡»æ¯è´¨æ°
int n;

vector<int> v[14111];
int L[11111], R[11111];
LL dp[11111][2];
LL ans[52];
void dfs(int pos, int fa, int g)
{
	for (int j = 0; j < v[pos].size(); j++)
	{
		int k = v[pos][j];
		if (k == fa)
		{
			continue;
		}
		dfs(k, pos, g);
	}
	int ha = 0;
	for (int j = L[pos]; j <= R[pos]; j++)
		if (j % g == 0)
		{
			ha++;
		}
	vector<int> c;
	c.clear();
	dp[pos][0] = dp[pos][1] = 0;
	for (int j = 0; j < v[pos].size(); j++)
	{
		int k = v[pos][j];
		if (k == fa)
		{
			continue;
		}
		c.push_back(k);
		dp[pos][0] += dp[k][1] + dp[k][0];
		dp[pos][0] %= mod;
	}
	if (ha > 0)
	{
		dp[pos][1] = 1;
		for (int j = 0; j < c.size(); j++)
		{
			dp[pos][1] += dp[c[j]][1];
			dp[pos][1] %= mod;
		}
		for (int j = 0; j < c.size(); j++)
		{
			for (int k = j + 1; k < c.size(); k++)
			{
				dp[pos][0] += dp[c[j]][1] * dp[c[k]][1] * ha;
				dp[pos][0] %= mod;
			}
		}
		dp[pos][1] *= ha;
		dp[pos][1] %= mod;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	int t = T;
	while (T--)
	{
		scanf("%d", &n);
		for (int j = 1; j <= n; j++)
		{
			v[j].clear();
		}
		for (int j = 0; j < n - 1; j++)
		{
			int g, h;
			scanf("%d%d", &g, &h);
			v[g].push_back(h);
			v[h].push_back(g);
		}
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &L[j]);
		}
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &R[j]);
		}
		memset(ans, 0, sizeof(ans));
		for (int j = 50; j >= 1; j--)
		{
			dfs(1, 0, j);
			ans[j] = dp[1][0] + dp[1][1];
			ans[j] %= mod;
			for (int k = j + j; k <= 50; k += j)
			{
				ans[j] = (mod + ans[j] - ans[k]) % mod;
			}
		}
		printf("Case %d:\n", t - T);
		for (int j = 1; j <= 50; j++)
		{
			printf("%d: %lld\n", j, (ans[j] + mod) % mod);
		}
	}
	return 0;
}
