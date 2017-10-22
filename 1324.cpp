#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : JayYe
Created Time: 2013/8/26 15:17:45
File Name   : JayYe.cpp
*********************************************** */

const int maxn = 50 + 10;

struct Edge
{
	int u, to, c, next;
} edge[888888];

int E, head[100010], gap[100010], dis[100010], cur[100010], pre[100010];

void init(int n)
{
	for (int i = 0; i <= n; i++)
		head[i] = -1;
	E = 0;
}

void addedge(int u, int to, int c, int cc)
{
	edge[E].u = u;
	edge[E].to = to;
	edge[E].c = c;
	edge[E].next = head[u];
	head[u] = E++;
	edge[E].u = to;
	edge[E].to = u;
	edge[E].c = cc;
	edge[E].next = head[to];
	head[to] = E++;
}

int SAP(int s, int t, int n)
{
	for (int i = 0; i <= n; i++)
	{
		dis[i] = gap[i] = 0;
		cur[i] = head[i];
	}

	gap[0] = n;
	int u = pre[s] = s, maxflow = 0, aug = -1, to;
	while (dis[s] < n)
	{
	loop:
		for (int i = cur[u]; i != -1; i = edge[i].next)
		{
			to = edge[i].to;
			if (edge[i].c > 0 && dis[u] == dis[to] + 1)
			{
				aug = (aug == -1 || aug > edge[i].c) ? edge[i].c : aug;
				pre[to] = u;
				cur[u] = i;
				u = to;
				if (u == t)
				{
					for (u = pre[u]; to != s; to = u, u = pre[u])
					{
						edge[cur[u]].c -= aug;
						edge[cur[u] ^ 1].c += aug;
					}
					maxflow += aug;
					aug = -1;
				}
				goto loop;
			}
		}

		int mindis = n;
		for (int i = head[u]; i != -1; i = edge[i].next)
		{
			to = edge[i].to;
			if (edge[i].c > 0 && dis[to] < mindis)
			{
				cur[u] = i;
				mindis = dis[to];
			}
		}
		if ((--gap[dis[u]]) == 0)
			break;
		gap[dis[u] = mindis + 1]++;
		u = pre[u];
	}
	return maxflow;
}

struct PP
{
	int id, to;
	PP() {}
	PP(int id, int to) : id(id), to(to) {}
	bool operator<(const PP &a) const
	{
		return id < a.id;
	}
} print[maxn];

int n, m, k, s, t;
int mp[maxn][maxn], pos[maxn], ti[maxn];

int solve()
{
	init(n);
	addedge(0, s, 1111111, 0);
	addedge(t, 100000, 1111111, 0);
	head[100000] = -1;
	int ans = 0, maxflow = 0;
	while (maxflow < k)
	{
		ans++;
		for (int i = 1; i <= n; i++)
			head[i + ans * n] = -1;
		addedge(0, s + ans * n, 1111111, 0);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (mp[i][j])
				{
					addedge((ans - 1) * n + i, ans * n + j, 1, 0);
					addedge((ans - 1) * n + j, ans * n + i, 1, 0);
				}
		}
		addedge(ans * n + t, 100000, 1111111, 0);
		maxflow += SAP(0, 100000, (ans + 1) * n + 2);
	}
	return ans;
}

int main()
{
	while (scanf("%d%d%d%d%d", &n, &m, &k, &s, &t) != -1)
	{
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < m; i++)
		{
			int u, to;
			scanf("%d%d", &u, &to);
			mp[u][to] = 1;
		}
		int ans = solve();
		printf("%d\n", ans);
		for (int i = 1; i <= k; i++)
			pos[i] = s, ti[i] = 0;
		for (int i = 0; i < ans; i++)
		{
			int tot = 0;
			for (int j = i * n + 1; j <= (i + 1) * n; j++)
				for (int l = head[j]; l != -1; l = edge[l].next)
				{
					int to = edge[l].to;
					if (to == 100000 || to == j + n || to == 0)
						continue;
					int tt = to / n + 1;
					if (to % n == 0)
						tt--;
					if (edge[l].c == 0 && tt == i + 2)
					{
						int u = j % n;
						if (u == 0)
							u = n;
						to = to % n;
						if (to == 0)
							to = n;
						for (int ii = 1; ii <= k; ii++)
							if (pos[ii] == u && ti[ii] == i)
							{
								print[tot++] = PP(ii, to);
								pos[ii] = to;
								ti[ii] = i + 1;
								break;
							}
					}
				}
			for (int j = 1; j <= k; j++)
				ti[j] = i + 1;
			sort(print, print + tot);
			printf("%d", tot);
			for (int j = 0; j < tot; j++)
				printf(" %d %d", print[j].id, print[j].to);
			puts("");
		}
	}
	return 0;
}
