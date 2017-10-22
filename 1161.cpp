#include <bits/stdc++.h>

using namespace std;

struct node1
{
	int u, v, num, st, et;
} link[5010];
struct node2
{
	int u, v, flow, next;
} edge[1000010];
map<string, int> match;
queue<int> qu;
int n, m, END;
char str[1010];
int Head[10010], d[10010], s, t, tot, INF = 1e9;
int get_num()
{
	int k = match[str];
	if (k > 0)
	{
		return k;
	}
	match[str] = ++n;
	return n;
}
void add(int u, int v, int f)
{
	edge[tot].u = u;
	edge[tot].v = v;
	edge[tot].flow = f;
	edge[tot].next = Head[u];
	Head[u] = tot++;
}
void init()
{
	tot = 0;
	memset(Head, -1, sizeof(Head));
	int i, j, k, u, v;
	for (i = 1; i <= m; i++)
	{
		add(i * 2, i * 2 ^ 1, link[i].num);
		add(i * 2 ^ 1, i * 2, 0);
	}
	for (i = 1; i <= m; i++)
		for (j = 1; j <= m; j++)
			if (link[i].v == link[j].u && link[i].et + 30 <= link[j].st)
			{
				//printf("i=%d j=%d\n",i,j);
				add(i * 2 ^ 1, j * 2, INF);
				add(j * 2, i * 2 ^ 1, 0);
			}
	for (i = 1; i <= m; i++)
	{
		if (link[i].u == 1)
		{
			add(0, i * 2, INF);
			add(i * 2, 0, 0);
		}
		if (link[i].v == 2 && link[i].et <= END)
		{
			add(i * 2 ^ 1, 1, INF);
			add(1, i * 2 ^ 1, 0);
		}
	}
}
int bfs()
{
	int i, j, k, u, v;
	memset(d, -1, sizeof(d));
	while (!qu.empty())
	{
		qu.pop();
	}
	qu.push(s);
	d[s] = 0;
	while (!qu.empty())
	{
		u = qu.front();
		qu.pop();
		for (i = Head[u]; i != -1; i = edge[i].next)
		{
			v = edge[i].v;
			if (edge[i].flow > 0 && d[v] == -1)
			{
				d[v] = d[u] + 1;
				if (v == t)
				{
					return 1;
				}
				qu.push(v);
			}
		}
	}
	return 0;
}
int dfs(int u, int f)
{
	if (u == t || f == 0)
	{
		return f;
	}
	int ans = 0, i, j, k, v;
	for (i = Head[u]; i != -1; i = edge[i].next)
	{
		v = edge[i].v;
		if (edge[i].flow > 0 && d[v] == d[u] + 1)
		{
			k = dfs(v, min(edge[i].flow, f));
			edge[i].flow -= k;
			edge[i ^ 1].flow += k;
			f -= k;
			ans += k;
			if (f == 0)
			{
				break;
			}
		}
	}
	d[u] = -1;
	return ans;
}
int dinic()
{
	init();
	int ans = 0;
	while (bfs())
	{
		ans += dfs(0, INF);
	}
	return ans;
}
int main()
{
	int i, j, k, u, v, ans;
	while (~scanf("%d", &n))
	{
		n = 0;
		m = 0;
		match.clear();
		scanf("%s", str);
		get_num();
		scanf("%s", str);
		get_num();
		scanf("%d", &END);
		END = END / 100 * 60 + END % 100;
		scanf("%d", &m);
		for (i = 1; i <= m; i++)
		{
			scanf("%s", str);
			link[i].u = get_num();
			scanf("%s", str);
			link[i].v = get_num();
			scanf("%d%d%d", &link[i].num, &link[i].st, &link[i].et);
			link[i].st = link[i].st / 100 * 60 + link[i].st % 100;
			link[i].et = link[i].et / 100 * 60 + link[i].et % 100;
		}
		s = 0;
		t = 1;
		ans = dinic();
		printf("%d\n", ans);
	}
}
