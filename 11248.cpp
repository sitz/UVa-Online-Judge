#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int inf = 2000000005;
const int N = 105;

struct Road
{
	int u, v, w;
	friend bool operator<(const Road &a, const Road &b)
	{
		if (a.u != b.u)
		{
			return a.u < b.u;
		}
		return a.v < b.v;
	}
} road[99999], ans[99999];
struct Edge
{
	int b, c, nxt;
} e[99999], ee[99999];
int p[N];
int cnt, ct;
int n, m, cap;
int flow[2][N];

int pre[N], dis[N], gap[N], cur[N];
int sap(int s, int t, int n)
{
	int i, v, u, c;
	int aug = -1, maxflow = 0;
	for (i = 0; i <= n; i++)
	{
		cur[i] = p[i];
	}
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	u = pre[s] = s,
	gap[0] = n;
	while (dis[s] < n)
	{
	loop:
		for (int &ee = cur[u]; ee != -1; ee = e[ee].nxt)
		{
			v = e[ee].b;
			c = e[ee].c;
			if (c > 0 && dis[u] == dis[v] + 1)
			{
				if (aug == -1 || aug > c)
				{
					aug = c;
				}
				pre[v] = u;
				u = v;
				if (v == t)
				{
					maxflow += aug;
					if (maxflow >= cap)
					{
						return maxflow;
					}
					for (u = pre[u]; v != s; v = u, u = pre[u])
					{
						e[cur[u]].c -= aug, e[cur[u] ^ 1].c += aug;
					}
					aug = -1;
				}
				goto loop;
			}
		}
		int mindis = n;
		for (i = p[u]; i != -1; i = e[i].nxt)
		{
			v = e[i].b;
			if (e[i].c > 0 && mindis > dis[v])
			{
				cur[u] = i, mindis = dis[v];
			}
		}
		if ((--gap[dis[u]]) == 0)
		{
			break;
		}
		gap[dis[u] = mindis + 1]++;
		u = pre[u];
	}
	return maxflow;
}
void addedge(int a, int b, int c)
{
	e[cnt].b = b;
	e[cnt].c = c;
	e[cnt].nxt = p[a];
	p[a] = cnt++;
	e[cnt].b = a;
	e[cnt].c = 0;
	e[cnt].nxt = p[b];
	p[b] = cnt++;
}
void init()
{
	memset(p, -1, sizeof(p));
	cnt = 0;
}

int main()
{
	int i, j, t, cas = 0;
	while (scanf("%d%d%d", &n, &m, &cap), n || m || cap)
	{
		init();
		for (i = 0; i < m; i++)
		{
			scanf("%d%d%d", &road[i].u, &road[i].v, &road[i].w);
		}
		sort(road, road + m);
		for (i = 0; i < m; i++)
		{
			addedge(road[i].u, road[i].v, road[i].w);
		}
		int S = 1, T = n;
		int ret = sap(S, T, T);
		printf("Case %d: ", ++cas);
		if (ret >= cap || n == 1)
		{
			puts("possible");
			continue;
		}
		for (i = 0; i < cnt; i++)
		{
			ee[i] = e[i];
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 0; j < cnt; j++)
			{
				e[j] = ee[j];
			}
			if (i == 1)
			{
				flow[0][i] = cap;
			}
			else
			{
				flow[0][i] = sap(1, i, n);
			}
			for (j = 0; j < cnt; j++)
			{
				e[j] = ee[j];
			}
			if (i == n)
			{
				flow[1][i] = cap;
			}
			else
			{
				flow[1][i] = sap(i, n, n);
			}
		}
		ct = 0;
		for (i = 0; i < m; i++)
		{
			int u = road[i].u;
			int v = road[i].v;
			int w = min(flow[0][u], flow[1][v]);
			if (ret + w >= cap)
			{
				ct++;
				ans[ct].u = u;
				ans[ct].v = v;
			}
		}
		if (ct == 0)
		{
			puts("not possible");
		}
		else
		{
			printf("possible option:");
			printf("(%d,%d)", ans[1].u, ans[1].v);
			for (i = 2; i <= ct; i++)
			{
				printf(",(%d,%d)", ans[i].u, ans[i].v);
			}
			puts("");
		}
	}
	return 0;
}
