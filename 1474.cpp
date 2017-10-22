#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : Nero
Created Time: 2013-9-1 7:38:36
Problem id  : LA 4987
Problem Name: Evacuation Plan
*********************************************** */

#define REP(i, a, b) for (int i = (a); i < (int)(b); i++)
#define clr(a, b) memset(a, b, sizeof(a))
typedef long long lld;

const lld INF = (lld)1e15;
lld dp[2][4001];// åiä¸ªé¿é¾æåå«åjä¸ªéçæå°è·ç¦»
struct She
{
	int pos, id;
	bool operator<(const She &tt) const
	{
		return pos < tt.pos;
	}
} b[4001], a[4001];
int n, m;
int ans[4001];
bool path[4001][4001];

void dfs(int x, int y)
{
	if (x == 0 || y == 0)
		return;
	ans[a[y].id] = b[x].id;
	dfs(x - path[x][y], y - 1);
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i].pos), a[i].id = i;
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", &b[i].pos), b[i].id = i;
		sort(a + 1, a + n + 1);
		sort(b + 1, b + m + 1);
		for (int i = 0; i <= n; i++)
			dp[0][i] = INF;
		dp[0][0] = 0;
		for (int i = 1; i <= m; i++)
		{
			int now = i & 1;
			int pre = !now;
			dp[now][i - 1] = INF;
			for (int j = i; j <= n; j++)
			{
				dp[now][j] = abs(a[j].pos - b[i].pos);
				if (dp[now][j - 1] <= dp[pre][j - 1])
				{
					dp[now][j] += dp[now][j - 1];
					path[i][j] = 0;
				}
				else
				{
					dp[now][j] += dp[pre][j - 1];
					path[i][j] = 1;
				}
			}
		}
		printf("%lld\n", dp[m & 1][n]);
		//      for(int i = 1; i <= m; i ++) {
		//          for(int j = 1; j <= n; j ++) printf("%20lld", dp[i][j]);
		//          printf("\n");
		//      }
		dfs(m, n);
		for (int i = 1; i <= n; i++)
			printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}
