#include <bits/stdc++.h>

using namespace std;

const int N = 40000;
const int MAXE = 2000;
const int inf = 1 << 30;
int ha[15], li[15], n;
struct pp
{
	int x, y;
} a[20];

int head[N], s, t, cnt;
int d[N], pre[N];
bool vis[N];
int q[MAXE];
struct Edge
{
	int u, v, c, w, next;
} edge[MAXE];
void add(int u, int v, int w, int c)
{
	edge[cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].w = w;
	edge[cnt].c = c;
	edge[cnt].next = head[u];
	head[u] = cnt++;
	edge[cnt].v = u;
	edge[cnt].u = v;
	edge[cnt].w = -w;
	edge[cnt].c = 0;
	edge[cnt].next = head[v];
	head[v] = cnt++;
}
int SPFA()
{
	int l, r;
	memset(pre, -1, sizeof(pre));
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i <= t; i++)
	{
		d[i] = inf;
	}
	d[s] = 0;
	l = 0;
	r = 0;
	q[r++] = s;
	vis[s] = 1;
	while (l < r)
	{
		int u = q[l++];
		vis[u] = 0;
		for (int j = head[u]; j != -1; j = edge[j].next)
		{
			int v = edge[j].v;
			if (edge[j].c > 0 && d[u] + edge[j].w < d[v])
			{
				d[v] = d[u] + edge[j].w;
				pre[v] = j;
				if (!vis[v])
				{
					vis[v] = 1;
					q[r++] = v;
				}
			}
		}
	}
	if (d[t] == inf)
	{
		return 0;
	}
	return 1;
}
int MCMF()
{
	int flow = 0;
	int ans = 0;
	while (SPFA())
	{
		ans += d[t];
		int u = t;
		int mini = inf;
		while (u != s)
		{
			if (edge[pre[u]].c < mini)
			{
				mini = edge[pre[u]].c;
			}
			u = edge[pre[u]].u;
		}
		flow += mini;
		u = t;
		while (u != s)
		{
			edge[pre[u]].c -= mini;
			edge[pre[u] ^ 1].c += mini;
			u = edge[pre[u]].u;
		}
	}
	return ans;
}

int cc(int x, int y, int x1, int y1)
{
	return abs(x - x1) + abs(y - y1);
}

int main()
{
	int i, j, mi, sum, ans, cas = 0, k;
	while (scanf("%d", &n) != EOF)
	{
		cas++;
		if (n == 0)
		{
			break;
		}
		memset(ha, 0, sizeof(ha));
		memset(li, 0, sizeof(li));
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].x, &a[i].y);
		}
		mi = 1000000000;
		s = 0;
		t = 2 * n + 1;
		for (i = 1; i <= n; i++)
		{
			memset(head, -1, sizeof(head));
			cnt = 0;
			for (j = 1; j <= n; j++)
			{
				add(s, j, 0, 1);
				add(j + n, t, 0, 1);
			}
			for (j = 1; j <= n; j++)
			{
				for (k = 0; k < n; k++)
				{
					int cost = cc(a[k].x, a[k].y, i, j);
					add(k + 1, j + n, cost, 1);
				}
			}
			ans = MCMF();
			if (ans < mi)
			{
				mi = ans;
			}
		}
		for (i = 1; i <= n; i++)
		{
			memset(head, -1, sizeof(head));
			cnt = 0;
			for (j = 1; j <= n; j++)
			{
				add(s, j, 0, 1);
				add(j + n, t, 0, 1);
			}
			for (j = 1; j <= n; j++)
			{
				for (k = 0; k < n; k++)
				{
					int cost = cc(a[k].x, a[k].y, j, i);
					add(k + 1, j + n, cost, 1);
				}
			}
			ans = MCMF();
			if (ans < mi)
			{
				mi = ans;
			}
		}
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			add(s, i, 0, 1);
			add(i + n, t, 0, 1);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int cost = cc(a[i].x, a[i].y, j, j);
				add(i + 1, j + n, cost, 1);
			}
		}
		ans = MCMF();
		if (ans < mi)
		{
			mi = ans;
		}
		memset(head, -1, sizeof(head));
		cnt = 0;
		for (i = 1; i <= n; i++)
		{
			add(s, i, 0, 1);
			add(i + n, t, 0, 1);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int cost = cc(a[i].x, a[i].y, j, n + 1 - j);
				add(i + 1, j + n, cost, 1);
			}
		}
		ans = MCMF();
		if (ans < mi)
		{
			mi = ans;
		}
		printf("Board %d: %d moves required.\n\n", cas, mi);
	}
}
