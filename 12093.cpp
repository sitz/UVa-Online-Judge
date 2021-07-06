#include <bits/stdc++.h>

using namespace std;

const int N = 100050;

struct edge
{
	int u, v, next;
} e[N << 1];

int dp[N][5], n, x, y;
int head[N], tot;

void add_edge(int u, int v)
{
	e[tot].u = u, e[tot].v = v;
	e[tot].next = head[u], head[u] = tot++;
}

void dfs(int f, int u)
{
	// printf("f:%d  u:%d\n",f,u);
	bool leaf = true;
	dp[u][0] = x, dp[u][1] = y;
	dp[u][2] = 0, dp[u][3] = dp[u][4] = 0;
	int sum = 0, spe = int(1e9);
	for (int i = head[u]; i != -1; i = e[i].next)
	{
		int v = e[i].v;
		if (v == f)
		{
			continue;
		}
		dfs(u, v);
		dp[u][0] += min(min(dp[v][0], dp[v][1]), min(dp[v][2], dp[v][3]));
		dp[u][1] += min(min(dp[v][0], dp[v][1]), min(dp[v][2], min(dp[v][4], dp[v][3])));
		dp[u][3] += min(min(dp[v][0], dp[v][1]), dp[v][2]);
		dp[u][4] += min(min(dp[v][0], dp[v][1]), min(dp[v][2], dp[v][3]));
		int superSonMin = (int)1e9;
		superSonMin = min(min(dp[v][2], dp[v][3]), min(dp[v][0], dp[v][1]));
		sum += superSonMin;
		spe = min(spe, dp[v][1] - superSonMin);
		leaf = false;
	}
	dp[u][2] = sum + spe;
	if (leaf)
	{
		dp[u][0] = x, dp[u][1] = y;
		dp[u][2] = (int)1e9, dp[u][3] = 0;
		dp[u][4] = 0;
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	while (scanf("%d%d%d", &n, &x, &y) != EOF && n + x + y)
	{
		memset(head, -1, sizeof(head));
		tot = 0;
		// printf("n:%d  x:%d  y:%d\n",n,x,y);
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		memset(dp, 0, sizeof(dp));
		dfs(-1, 1);
		/*for(int i = 1;i <= n;i ++){
			printf("i:%d  0:%d  1:%d  2:%d  3:%d  4:%d\n",i,dp[i][0],dp[i][1],dp[i][2],dp[i][3],dp[i][4]);
		}*/
		int ans = min(dp[1][0], dp[1][1]);
		ans = min(ans, dp[1][2]);
		ans = min(ans, dp[1][3]);
		printf("%d\n", ans);
	}
	return 0;
}
