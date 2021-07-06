#include <bits/stdc++.h>

using namespace std;

#define N 205
#define INF 1 << 28

int g[N][N], mk[N];
int cap[N][N], dis[N], pre[N], cnt[N];

int ISAP(int src, int sink, int n)
{
	int maxflow = 0, flow, u = src, v, d;
	memset(dis, 0, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));
	pre[src] = src;
	cnt[src] = n;
	while (dis[src] < n)
	{
		if (u == sink)
		{
			flow = INF;
			for (int i = sink; i != src; i = pre[i])
				if (cap[pre[i]][i] < flow)
				{
					flow = cap[pre[i]][i];
				}
			maxflow += flow;
			u = src;
			for (int i = sink; i != src; i = pre[i])
			{
				cap[pre[i]][i] -= flow;
				cap[i][pre[i]] += flow;
			}
		}
		for (d = n, v = 0; v < n; v++)
		{
			if (!cap[u][v])
			{
				continue;
			}
			d = d < dis[v] ? d : dis[v];
			if (dis[v] + 1 == dis[u])
			{
				break;
			}
		}
		if (v < n)
		{
			pre[v] = u, u = v;
		}
		else
		{
			if (!(--cnt[dis[u]]))
			{
				break;
			}
			++cnt[dis[u] = d + 1];
			if (u != src)
			{
				u = pre[u];
			}
		}
	}
	return maxflow;
}

int parent[N], cut[N][N];

void dfs(int u, int n)
{
	mk[u] = 1;
	for (int i = 0; i < n; i++)
	{
		if (!mk[i] && cap[u][i])
		{
			dfs(i, n);
		}
	}
}

void Solve(int n)
{
	memset(parent, 0, sizeof(parent));
	memset(cut, 127, sizeof(cut));
	for (int i = 1; i < n; i++)
	{
		memset(mk, 0, sizeof(mk));
		memcpy(cap, g, sizeof(g));
		int mincut = ISAP(i, parent[i], n);
		dfs(i, n);
		for (int j = i + 1; j < n; j++)
			if (mk[j] && parent[j] == parent[i])
			{
				parent[j] = i;
			}
		cut[i][parent[i]] = cut[parent[i]][i] = mincut;
		for (int j = 0; j < i; j++)
		{
			cut[i][j] = cut[j][i] = min(mincut, cut[parent[i]][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				cut[i][j] = 0;
			}
			printf("%d", cut[i][j]);
			if (j != n - 1)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

int main()
{
	int t, n, cas = 1;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &g[i][j]);
			}
		printf("Case #%d:\n", cas++);
		Solve(n);
	}
	return 0;
}
