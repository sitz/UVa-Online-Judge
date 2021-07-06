#include <bits/stdc++.h>

using namespace std;

#define maxn 1100

int n, m, num, dfs_closk, f[maxn], low[maxn], d[maxn], e[maxn];
vector<int> path[maxn];

int get_fa(int x)
{
	return f[x] == x ? x : f[x] = get_fa(f[x]);
}

void dfs(int x, int fa)
{
	int i, j;
	low[x] = d[x] = dfs_closk++;
	for (i = 0; i < path[x].size(); i++)
	{
		int y = path[x][i];
		if (y == fa)
			continue;
		if (d[y] > 0)
		{
			low[x] = min(low[x], d[y]);
			f[get_fa(x)] = get_fa(y);
		}
		else
		{
			dfs(y, x);
			low[x] = min(low[x], low[y]);
			if (low[y] < d[y])
				f[get_fa(x)] = get_fa(y);
		}
	}
}

int main()
{
	int i, j;
	while (scanf("%d %d", &n, &m) == 2)
	{
		for (i = 0; i < n; i++)
			path[i].clear();
		for (i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			a--, b--;
			path[a].push_back(b);
			path[b].push_back(a);
		}
		num = 0;
		memset(d, 0, sizeof(d));
		for (i = 0; i < n; i++)
			f[i] = i;
		for (i = 0; i < n; i++)
		{
			if (d[i] == 0)
			{
				dfs_closk = 1;
				dfs(i, -1);
				num++;
			}
		}
		for (i = 0; i < n; i++)
			get_fa(i);
		memset(e, 0, sizeof(e));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < path[i].size(); j++)
			{
				int y = path[i][j];
				if (f[i] != f[y] && i < y)
					e[f[i]]++, e[f[y]]++;
			}
		}
		int ans = 0;
		for (i = 0; i < n; i++)
		{
			if (f[i] == i)
			{
				if (e[i] == 1)
					ans++;
				if (e[i] == 0 && num > 1)
					ans += 2;
			}
		}
		printf("%d\n", (ans + 1) / 2);
	}
	return 0;
}
