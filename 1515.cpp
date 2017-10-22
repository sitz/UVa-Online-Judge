#include <bits/stdc++.h>

using namespace std;

#define LL_INF 0x3fffffffffffffffll
#define EPS 1e-12
#define N 10010
#define E 100010

typedef long long LL;
typedef unsigned long long ULL;
typedef double DB;
struct Edge
{
	int en, next;
	double cap, flow;
} edge[E];
int head[N], tot, now[N];
int source, sink, tot_num;
int pre[N], gap[N], dis[N];
void add_edge(int st, int en, double cap)
{
	edge[tot].en = en;
	edge[tot].cap = cap;
	edge[tot].flow = 0;
	edge[tot].next = head[st];
	head[st] = tot++;

	edge[tot].en = st;
	edge[tot].cap = 0;
	edge[tot].flow = 0;
	edge[tot].next = head[en];
	head[en] = tot++;
}

void augment(double flow)
{
	for (int i = source; i != sink; i = edge[now[i]].en)
	{
		edge[now[i]].flow += flow;
		edge[now[i] ^ 1].flow -= flow;
	}
}
double sap()
{
	memset(dis, 0, sizeof(dis));
	memset(gap, 0, sizeof(gap));
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < tot_num; i++)
		now[i] = head[i];
	gap[0] = tot_num;
	int point = source;
	double flow = 0;
	double min_flow = LL_INF;
	while (dis[source] < tot_num)
	{
		bool fg = false;
		for (int i = now[point]; i != -1; i = edge[i].next)
			if (edge[i].cap - edge[i].flow > 0 && dis[point] == dis[edge[i].en] + 1)
			{
				min_flow = min(min_flow, edge[i].cap - edge[i].flow);
				now[point] = i;
				pre[edge[i].en] = point;
				point = edge[i].en;
				if (point == sink)
				{
					flow += min_flow;
					augment(min_flow);
					point = source;
					min_flow = LL_INF;
				}
				fg = true;
				break;
			}
		if (fg)
			continue;
		if (--gap[dis[point]] == 0)
			break;
		int Min = tot_num;
		for (int i = head[point]; i != -1; i = edge[i].next)
			if (edge[i].cap - edge[i].flow > 0 && Min > dis[edge[i].en])
			{
				Min = dis[edge[i].en];
				now[point] = i;
			}
		gap[dis[point] = Min + 1]++;
		if (point != source)
			point = pre[point];
	}
	return flow;
}
int n, m;
int val[N];
int a[E], b[E];
LL c[E];
bool pd;
int map[200][200];
int u, ans[10010];
bool vis[200];
void dfs(int now)
{
	vis[now] = true;
	for (int p = head[now]; p != -1; p = edge[p].next)
		if (!vis[edge[p].en] && edge[p].flow < edge[p].cap)
			dfs(edge[p].en);
}
char str[10000];
double A, B, C;
void build()
{
	memset(head, -1, sizeof(head));
	tot = 0;
	source = n * m, sink = n * m + 1, tot_num = 2 + n * m;
	swap(n, m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		for (int j = 0; j < m; j++)
		{
			if (i != 0 && j != 0 && i != n - 1 && j != m - 1)
			{
				if (str[j] == '#')
					add_edge(source, i * m + j, A);
				else
					add_edge(i * m + j, sink, B);
			}
			else
			{
				add_edge(source, i * m + j, LL_INF);
				if (str[j] == '.')
					add_edge(i * m + j, sink, B);
			}
			if (i)
			{
				add_edge((i - 1) * m + j, i * m + j, C);
				add_edge(i * m + j, (i - 1) * m + j, C);
			}
			if (j)
			{
				add_edge(i * m + j, i * m + j - 1, C);
				add_edge(i * m + j - 1, i * m + j, C);
			}
		}
	}
}
int T;
int main()
{
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		scanf("%lf%lf%lf", &A, &B, &C);
		build();
		printf("%.0f\n", sap());
	}
}
