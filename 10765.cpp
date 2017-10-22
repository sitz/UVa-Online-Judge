#include <bits/stdc++.h>

using namespace std;

#define maxn 10010

int low[maxn], pre[maxn], n, m, dfs_clock;
struct node
{
	int id;
	int val;
} p[maxn];
vector<int> g[maxn];

bool cmp(node x, node y)
{
	if (x.val == y.val)
		return x.id < y.id;
	return x.val > y.val;
}

void init()
{
	int i;
	for (i = 0; i < n; i++)
	{
		g[i].clear();
		p[i].id = i;
		p[i].val = 1;
	}
}

int dfs(int u, int fa)
{
	int i, j;
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (!pre[v])
		{
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u])
				p[u].val++;
		}
		else if (pre[v] < pre[u] && v != fa)
			lowu = min(lowu, pre[v]);
	}
	if (fa < 0 && child == 1)
		p[u].val = 1;
	low[u] = lowu;
	return lowu;
}

int main()
{
	int i, j;
	while (scanf("%d %d", &n, &m) == 2 && n + m)
	{
		init();
		while (true)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			g[a].push_back(b);
			g[b].push_back(a);
			if (a == -1 && b == -1)
				break;
		}
		memset(pre, 0, sizeof(pre));
		dfs(0, -1);
		if (p[0].val > 1)
			p[0].val--;
		sort(p, p + n, cmp);
		for (i = 0; i < m; i++)
			printf("%d %d\n", p[i].id, p[i].val);
		puts("");
	}
	return 0;
}
