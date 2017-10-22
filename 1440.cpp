#include <bits/stdc++.h>

using namespace std;

#define MAXN 111
#define MAXM 55555
#define INF 1000000007

struct EDGE
{
	int v, next;
	int w;
} edge[MAXM];
int head[MAXN], e;
void init()
{
	memset(head, -1, sizeof(head));
	e = 0;
}
void add(int u, int v, int w)
{
	edge[e].v = v;
	edge[e].w = w;
	edge[e].next = head[u];
	head[u] = e++;
	edge[e].v = u;
	edge[e].w = 0;
	edge[e].next = head[v];
	head[v] = e++;
}
int n, nt;
int h[MAXN];
int gap[MAXN];
int src, des;
int dfs(int pos, int cost)
{
	if (pos == des)
	{
		return cost;
	}
	int j, minh = n - 1;
	int lv = cost, d;
	for (j = head[pos]; j != -1; j = edge[j].next)
	{
		int v = edge[j].v;
		int w = edge[j].w;
		if (w > 0)
		{
			if (h[v] + 1 == h[pos])
			{
				if (lv < edge[j].w)
				{
					d = lv;
				}
				else
				{
					d = edge[j].w;
				}
				d = dfs(v, d);
				edge[j].w -= d;
				edge[j ^ 1].w += d;
				lv -= d;
				if (h[src] >= n)
				{
					return cost - lv;
				}
				if (lv == 0)
				{
					break;
				}
			}
			if (h[v] < minh)
			{
				minh = h[v];
			}
		}
	}
	if (lv == cost)
	{
		--gap[h[pos]];
		if (gap[h[pos]] == 0)
		{
			h[src] = n;
		}
		h[pos] = minh + 1;
		++gap[h[pos]];
	}
	return cost - lv;
}
int sap()
{
	int ret = 0;
	memset(gap, 0, sizeof(gap));
	memset(h, 0, sizeof(h));
	gap[0] = n;
	while (h[src] < n)
	{
		ret += dfs(src, INF);
	}
	return ret;
}
int d[MAXN];
typedef pair<int, int> PII;
vector<PII> g[MAXN];
int ans[MAXN];
int cnt, flag;
void dfs(int u)
{
	int f = 0;
	ans[cnt++] = u;
	for (int i = 0; i < g[u].size(); i++)
	{
		if (flag)
		{
			return;
		}
		int v = g[u][i].first;
		if (!g[u][i].second)
		{
			continue;
		}
		f = 1;
		--g[u][i].second;
		dfs(v);
	}
	if (!f)
	{
		d[u]--, flag = 1;
	}
}
int main()
{
	int u, v, t;
	while (scanf("%d", &nt) != EOF)
	{
		init();
		memset(d, 0, sizeof(d));
		for (int i = 1; i <= nt; i++)
		{
			scanf("%d", &t);
			while (t--)
			{
				scanf("%d", &v);
				d[i]--;
				d[v]++;
				add(i, v, INF);
			}
		}
		src = nt + 1;
		des = nt + 2;
		n = nt + 2;
		int res = 0;
		for (int i = 1; i <= nt; i++)
		{
			if (d[i] > 0)
			{
				add(src, i, d[i]);
			}
			else if (d[i] < 0)
			{
				add(i, des, -d[i]), res -= d[i];
			}
		}
		printf("%d\n", res - sap());
		for (int i = 1; i <= nt; i++)
		{
			g[i].clear();
		}
		for (int i = 1; i <= nt; i++)
		{
			for (int j = head[i]; j != -1; j = edge[j].next)
			{
				if ((j & 1) || edge[j].v > nt)
				{
					continue;
				}
				g[i].push_back(make_pair(edge[j].v, edge[j ^ 1].w + 1));
				d[i] -= edge[j ^ 1].w;
				d[edge[j].v] += edge[j ^ 1].w;
			}
		}
		for (int i = 1; i <= nt; i++)
		{
			while (d[i] < 0)
			{
				cnt = 0;
				flag = 0;
				d[i]++;
				dfs(i);
				for (int j = 0; j < cnt; j++)
				{
					printf("%d", ans[j]);
					if (j == cnt - 1)
					{
						printf("\n");
					}
					else
					{
						printf(" ");
					}
				}
			}
		}
	}
	return 0;
}
