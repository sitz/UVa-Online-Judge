#include <bits/stdc++.h>

using namespace std;

#define inf 1 << 20
#define ll long long
#define maxn 2100 * 2

vector<int> g[maxn], scc[maxn], ans[maxn], woman[maxn];
int n, dfs_clock, scc_cnt, pre[maxn], sccno[maxn], lowlink[maxn];
stack<int> s;

void dfs(int u)
{
	int i, j;
	pre[u] = lowlink[u] = ++dfs_clock;
	s.push(u);
	for (i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (!pre[v])
		{
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if (!sccno[v])
			lowlink[u] = min(lowlink[u], pre[v]);
	}
	if (lowlink[u] == pre[u])
	{
		scc_cnt++;
		scc[scc_cnt].clear();
		while (true)
		{
			int x = s.top();
			s.pop();
			sccno[x] = scc_cnt;
			scc[scc_cnt].push_back(x);
			if (x == u)
				break;
		}
	}
}

void find_scc()
{
	int i, j;
	scc_cnt = dfs_clock = 0;
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	for (i = 0; i < n; i++)
		if (!pre[i])
			dfs(i);
}

int main()
{
	int i, j;
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 0; i < 2 * n; i++)
			g[i].clear();
		for (i = 0; i < n; i++)
		{
			int tt;
			scanf("%d", &tt);
			woman[i].clear();
			while (tt--)
			{
				int x;
				scanf("%d", &x);
				x = x - 1 + n;
				woman[i].push_back(x);
				g[i].push_back(x);
			}
		}
		for (i = 0; i < n; i++)
		{
			int x;
			scanf("%d", &x);
			x = x - 1 + n;
			g[x].push_back(i);
		}
		n = n * 2;
		find_scc();
		n = n / 2;
		for (i = 0; i < n; i++)
		{
			ans[i].clear();
			for (j = 0; j < woman[i].size(); j++)
				if (sccno[i] == sccno[woman[i][j]])
					ans[i].push_back(woman[i][j] - n + 1);
		}
		for (i = 0; i < n; i++)
		{
			printf("%d", ans[i].size());
			for (j = 0; j < ans[i].size(); j++)
				printf(" %d", ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}
