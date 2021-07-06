#include <bits/stdc++.h>

using namespace std;

#define clear(A, X) memset(A, X, sizeof A)
#define copy(A, B) memcpy(A, B, sizeof A)

const int maxE = 3000000;
const int maxN = 100000;
const int maxQ = 3000000;
const int oo = 0x3f3f3f3f;

struct Edge
{
	int v, n, c;
} edge[maxE];

int adj[maxN], cntE;
int Q[maxQ], head, tail;
int d[maxN], cur[maxN], pre[maxN], num[maxN];
int s, t, nv, n, m;
int a[maxN];
char str[maxN];

void addedge(int u, int v, int c)
{
	edge[cntE].v = v;
	edge[cntE].c = c;
	edge[cntE].n = adj[u];
	adj[u] = cntE++;
	edge[cntE].v = u;
	edge[cntE].c = 0;
	edge[cntE].n = adj[v];
	adj[v] = cntE++;
}
void rev_bfs()
{
	clear(num, 0);
	clear(d, -1);
	d[t] = 0;
	num[0] = 1;
	head = tail = 0;
	Q[tail++] = t;
	while (head != tail)
	{
		int u = Q[head++];
		for (int i = adj[u]; ~i; i = edge[i].n)
		{
			int v = edge[i].v;
			if (~d[v])
			{
				continue;
			}
			d[v] = d[u] + 1;
			Q[tail++] = v;
			num[d[v]]++;
		}
	}
}
int ISAP()
{
	copy(cur, adj);
	rev_bfs();
	int flow = 0, u = pre[s] = s, i;
	while (d[s] < nv)
	{
		if (u == t)
		{
			int f = oo, neck;
			for (i = s; i != t; i = edge[cur[i]].v)
			{
				if (f > edge[cur[i]].c)
				{
					f = edge[cur[i]].c;
					neck = i;
				}
			}
			for (i = s; i != t; i = edge[cur[i]].v)
			{
				edge[cur[i]].c -= f;
				edge[cur[i] ^ 1].c += f;
			}
			flow += f;
			u = neck;
		}
		for (i = cur[u]; ~i; i = edge[i].n)
			if (d[edge[i].v] + 1 == d[u] && edge[i].c)
			{
				break;
			}
		if (~i)
		{
			cur[u] = i;
			pre[edge[i].v] = u;
			u = edge[i].v;
		}
		else
		{
			if (0 == (--num[d[u]]))
			{
				break;
			}
			int mind = nv;
			for (i = adj[u]; ~i; i = edge[i].n)
			{
				if (edge[i].c && mind > d[edge[i].v])
				{
					cur[u] = i;
					mind = d[edge[i].v];
				}
			}
			d[u] = mind + 1;
			num[d[u]]++;
			u = pre[u];
		}
	}
	return flow;
}
void init()
{
	clear(adj, -1);
	cntE = 0;
	s = maxN - 4;
	t = maxN - 3;
	nv = maxN - 2;
}
void work()
{
	int w, x, pos = 30000, sum = 0;
	init();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &w);
		addedge(s, i + pos, w);
		sum += w;
		fgets(str, maxN, stdin);
		x = 0;
		for (int j = 0; str[j]; ++j)
		{
			if (str[j] < '0' || str[j] > '9')
			{
				if (x)
				{
					addedge(i + pos, x, oo);
				}
				x = 0;
			}
			else
			{
				x = x * 10 + str[j] - '0';
			}
		}
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%d", &w);
		addedge(i + pos + n, t, w);
		sum += w;
		fgets(str, maxN, stdin);
		x = 0;
		for (int j = 0; str[j]; ++j)
		{
			if (str[j] < '0' || str[j] > '9')
			{
				if (x)
				{
					addedge(x, i + pos + n, oo);
				}
				x = 0;
			}
			else
			{
				x = x * 10 + str[j] - '0';
			}
		}
	}
	printf("%d\n", sum - ISAP());
}
int main()
{
	int cas, t;
	for (scanf("%d", &t), cas = 1; cas <= t; ++cas)
	{
		if (cas > 1)
		{
			printf("\n");
		}
		printf("Case %d:\n", cas);
		work();
	}
	return 0;
}
