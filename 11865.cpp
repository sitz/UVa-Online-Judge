#include <bits/stdc++.h>

using namespace std;

#define MAXN 101
#define INF 1e10

struct POINT
{
	int x, y;
} poi[MAXN];
double gmap[MAXN][MAXN], ans;
int n, m, father[MAXN];
bool vis[MAXN], circle[MAXN];

double length(POINT &a, POINT &b)
{
	return sqrt(double((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

void dfs(int x)
{
	vis[x] = true;
	for (int i = 1; i <= n; ++i)
		if (!vis[i] && gmap[x][i] < INF)
			dfs(i);
}

bool connect()
{
	memset(vis, 0, sizeof(vis));
	dfs(1);
	for (int i = 1; i <= n; ++i)
		if (!vis[i])
			return false;
	return true;
}

int exist_circle()
{
	father[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!circle[i])
		{
			father[i] = i;
			gmap[i][i] = INF;
			for (int j = 1; j <= n; ++j)
				if (!circle[j] && gmap[j][i] < gmap[father[i]][i])
					father[i] = j;
		}
	}
	for (int i = 2; i <= n; ++i)
	{
		if (circle[i])
			continue;
		memset(vis, 0, sizeof(vis));
		int j = i;
		while (!vis[j])
		{
			vis[j] = true;
			j = father[j];
		}
		if (j == 1)
			continue;
		else
			return j;
	}
	return -1;
}

void update(int t)
{
	ans += gmap[father[t]][t];
	for (int i = father[t]; i != t; i = father[i])
	{
		ans += gmap[father[i]][i];
		circle[i] = true;
	}
	for (int i = 1; i <= n; ++i)
		if (!circle[i] && gmap[i][t] != INF)
			gmap[i][t] -= gmap[father[t]][t];
	for (int i = father[t]; i != t; i = father[i])
	{
		for (int j = 1; j <= n; ++j)
		{
			if (circle[j])
				continue;
			if (gmap[j][i] != INF)
				gmap[j][t] = min(gmap[j][t], gmap[j][i] - gmap[father[i]][i]);
			gmap[t][j] = min(gmap[i][j], gmap[t][j]);//更新出边权
		}
	}
}

void solve()
{
	memset(circle, 0, sizeof(circle));
	int t;
	while ((t = exist_circle()) != -1)
		update(t);
	for (t = 2; t <= n; ++t)
		if (!circle[t])
			ans += gmap[father[t]][t];//把所有不成环的边权加上去
}

struct Edge
{
	int u, v, flow, cost;
	void get()
	{
		scanf("%d %d %d %d", &u, &v, &flow, &cost);
		v++, u++;
	}
} edge[11000];

int max_cost;

bool build(int mid)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			gmap[i][j] = INF;
	for (int i = 0; i < m; i++)
	{
		if (edge[i].flow >= mid)
		{
			int u = edge[i].u, v = edge[i].v, cost = edge[i].cost;
			if (gmap[u][v] > cost)
				gmap[u][v] = cost;
		}
	}
	if (!connect())
		return false;
	ans = 0;
	solve();
	return ans <= max_cost;
}

void binary_search()
{
	int left = 1, right = 1000100;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (build(mid))
			left = mid + 1;
		else
			right = mid - 1;
	}
	if (right)
		printf("%d kbps\n", right);
	else
		puts("streaming not possible.");
}

int main()
{
	int i, T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d %d", &n, &m, &max_cost);
		for (i = 0; i < m; ++i)
			edge[i].get();
		binary_search();
	}
	return 0;
}
