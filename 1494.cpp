#include <bits/stdc++.h>

using namespace std;

const int maxn = 10e5 + 1000;
struct node
{
	int u;
	int v;
	double cost;
	bool operator<(const node &a) const
	{
		return cost < a.cost;
	}
} a[maxn];
struct Tree
{
	int u;
	double val;
	int next;
} t[maxn * 3];
int n, m, x[1001], y[1001], val[1001], head[1001], p[1001];
double maxcost[1001][1001];
bool vis[1001];
int find(int x)
{
	if (x == p[x])
	{
		return x;
	}
	return p[x] = find(p[x]);
}
double Dis(int x1, int y1, int x2, int y2)
{
	return sqrt((x1 - x2) * (x1 - x2) * 1.0 + (y1 - y2) * (y1 - y2) * 1.0);
}
void DFS(int x, int root)
{
	vis[x] = 1;
	for (int i = head[x]; i != -1; i = t[i].next)
	{
		if (!vis[t[i].u])
		{
			maxcost[root][t[i].u] = max(t[i].val, maxcost[root][x]);
			DFS(t[i].u, root);
		}
	}
}
void Deal()
{
	memset(head, -1, sizeof(head));
	for (int i = 0; i <= n; i++)
	{
		p[i] = i;
	}
	sort(a, a + m);
	double sum = 0;
	int num;
	for (int i = 0; i < m; i++)
	{
		int ita = find(a[i].u);
		int itb = find(a[i].v);
		if (ita != itb)
		{
			p[ita] = itb;
			sum += a[i].cost;
			t[num].u = a[i].u;
			t[num].val = a[i].cost;
			t[num].next = head[a[i].v];
			head[a[i].v] = num++;
			t[num].u = a[i].v;
			t[num].val = a[i].cost;
			t[num].next = head[a[i].u];
			head[a[i].u] = num++;
		}
	}
	memset(maxcost, 0, sizeof(maxcost));
	for (int i = 1; i <= n; i++)
	{
		memset(vis, 0, sizeof(vis));
		DFS(i, i);
	}
	double ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			ans = max(ans, (val[i] + val[j]) / (sum - maxcost[i][j]));
		}
	printf("%.2lf\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		m = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &x[i], &y[i], &val[i]);
			for (int j = i - 1; j >= 1; j--)
			{
				a[m].u = i;
				a[m].v = j;
				a[m++].cost = Dis(x[i], y[i], x[j], y[j]);
			}
		}
		Deal();
	}
	return 0;
}
