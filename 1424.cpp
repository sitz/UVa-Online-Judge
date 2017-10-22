#include <bits/stdc++.h>

using namespace std;

#define maxn 110
#define inf 2139062143

int n, m, len, g[110][110], dp[210][110], path[210];

int main()
{
	int i, j, k, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		memset(g, 0, sizeof(g));
		for (i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			g[a][b] = g[b][a] = 1;
		}
		for (i = 1; i <= n; i++)
			g[i][i] = 1;
		memset(dp, 0x7f, sizeof(dp));
		scanf("%d", &len);
		for (i = 1; i <= len; i++)
			scanf("%d", &path[i]);
		for (i = 1; i <= n; i++)
			dp[1][i] = 1;
		dp[1][path[1]] = 0;
		for (i = 2; i <= len; i++)
			for (j = 1; j <= n; j++)
			{
				if (dp[i - 1][j] == inf)
					continue;
				for (k = 1; k <= n; k++)
					if (g[j][k])
						dp[i][k] = min(dp[i][k], dp[i - 1][j] + (path[i] != k));
			}
		int ans = inf;
		for (i = 1; i <= n; i++)
			ans = min(ans, dp[len][i]);
		printf("%d\n", ans);
	}
	return 0;
}
