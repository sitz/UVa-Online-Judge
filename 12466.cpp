#include <bits/stdc++.h>

using namespace std;

#define inf 1e9
#define maxn 100005

int en;
struct EDGE
{
	int v, next;
} edge[maxn];
int head[maxn], w[maxn], dp[maxn][105];
int n, m, cn[maxn];

void addedge(int u, int v)
{
	edge[en].v = v, edge[en].next = head[u];
	head[u] = en++;
}

void dfs(int u)
{
	cn[u] = 1;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		dfs(v);
		cn[u] += cn[v];
	}
	dp[u][0] = 0;
	for (int i = head[u]; i != -1; i = edge[i].next)
	{
		int v = edge[i].v;
		int child = min(cn[u] - 1, m);
		for (int j = child; j > 0; j--)
		{
			for (int k = 1; k <= j && k < cn[v]; k++)
			{
				dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
			}
			if (j)
			{
				dp[u][j] = max(dp[u][j], dp[u][j - 1] + w[v]);
			}
		}
	}
	dp[u][1] = max(dp[u][1], w[u]);
}

int main()
{
	int v;
	while (scanf("%d%d", &n, &m) && n)
	{
		en = 0;
		memset(head, -1, sizeof(head));
		memset(cn, 0, sizeof(cn));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &w[i]);
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &v);
			addedge(v, i);
		}
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
			{
				dp[i][j] = -inf;
			}
		dfs(0);
		int ans = -inf;
		for (int j = 1; j <= m; j++)
		{
			ans = max(ans, dp[0][j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}
