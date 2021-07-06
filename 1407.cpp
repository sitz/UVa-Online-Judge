#include <bits/stdc++.h>

using namespace std;

#define maxn 510
#define inf 1 << 26

struct Edge
{
	int from, to, len;
	int next;
	void assign(int a, int b, int c, int d)
	{
		from = a, to = b, len = c, next = d;
	}
} edges[maxn * 2];
int n;
int dp[maxn][maxn][2];
int cnt;
int head[maxn];
int son[maxn];

void init()
{
	int i, j;
	cnt = 0;
	memset(head, -1, sizeof(head));
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			dp[i][j][0] = dp[i][j][1] = inf;
		}
	}
}

void addedge(int x, int y, int z)
{
	edges[cnt].assign(x, y, z, head[x]);
	head[x] = cnt++;
}

void dfs(int root, int fa)
{
	// cout<<root<<"**"<<endl;
	dp[root][1][0] = dp[root][1][1] = 0;
	son[root] = 1;
	int i, j, k;
	for (i = head[root]; i != -1; i = edges[i].next)
	{
		Edge e = edges[i];
		if (e.to == fa)
		{
			continue;
		}
		dfs(e.to, root);
		son[root] += son[e.to];
		//  cout<<son[root]<<"  "<<root<<"  "<<e.to<<endl;
		for (j = son[root]; j > 1; j--)
		{
			for (k = 1; k <= j && k <= son[e.to]; k++)
			{
				dp[root][j][0] = min(dp[root][j][0], dp[root][j - k][0] + dp[e.to][k][0] + e.len * 2);
				dp[root][j][1] = min(dp[root][j][1], dp[root][j - k][0] + dp[e.to][k][1] + e.len * 1);
				dp[root][j][1] = min(dp[root][j][1], dp[root][j - k][1] + dp[e.to][k][0] + e.len * 2);
			}
		}
	}
}

int main()
{
	int i, j;
	int test = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		init();
		for (i = 0; i < n - 1; i++)
		{
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			addedge(a, b, c);
			addedge(b, a, c);
		}
		dfs(0, -1);
		int m;
		scanf("%d", &m);
		// cout<<m<<"**"<<endl;
		printf("Case %d:\n", ++test);
		while (m--)
		{
			int temp;
			int ans;
			scanf("%d", &temp);
			//cout<<temp<<"**"<<endl;
			for (i = 1; i <= n; i++)
			{
				if (dp[0][i][0] <= temp || dp[0][i][1] <= temp)
				{
					ans = i;
				}
				else
				{
					break;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
