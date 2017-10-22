#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1010];
int vis[1010][2], d[1010][2], n, m;
#define DEBUG
int dp(int i, int j, int f)
{
	if (vis[i][j])
	{
		return d[i][j];
	}
	vis[i][j] = 1;
	int &ans = d[i][j];
	int k;
	ans = 2000;
	for (k = 0; k < adj[i].size(); k++)
		if (adj[i][k] != f)
		{
			ans += dp(adj[i][k], 1, i);
		}
	if (f >= 0 && !j)
	{
		ans++;
	}
	if (f < 0 || j)
	{
		int sum = 0;
		for (k = 0; k < adj[i].size(); k++)
			if (adj[i][k] != f)
			{
				sum += dp(adj[i][k], 0, i);
			}
		if (f >= 0)
		{
			sum++;
		}
		if (ans > sum)
		{
			ans = sum;
		}
	}
	return ans;
}
int main()
{
	int T, a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		int i;
		for (i = 0; i < n; i++)
		{
			adj[i].clear();
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		memset(vis, 0, sizeof(vis));
		int ans = 0;
		for (i = 0; i < n; i++)
			if (!vis[i][0])
			{
				ans += dp(i, 0, -1);
			}
		printf("%d %d %d\n", ans / 2000, m - ans % 2000, ans % 2000);
	}
	return 0;
}
