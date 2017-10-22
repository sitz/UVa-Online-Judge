#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 5;
int s, k, n, fa[maxn];
bool covered[maxn];
vector<int> G[maxn], nodes[maxn];

void dfs(int u, int f, int d)
{
	fa[u] = f;
	int l = G[u].size();
	if (l == 1 && d > k)
		nodes[d].push_back(u);
	for (int i(0); i < l; ++i)
	{
		if (G[u][i] != f)
			dfs(G[u][i], u, d + 1);
	}
}

void dfs2(int u, int f, int d)
{
	covered[u] = true;
	int l = G[u].size();
	for (int i(0); i < l; ++i)
	{
		int v = G[u][i];
		if (v != f && d < k)
			dfs2(v, u, d + 1);
	}
}

int solve()
{
	int ans = 0;
	memset(covered, 0, sizeof(covered));
	for (int d(n - 1); d > k; --d)
		for (int i(0); i < nodes[d].size(); ++i)
		{
			int u = nodes[d][i];
			if (covered[u])
				continue;
			int v = u;
			for (int j(0); j < k; ++j)
				v = fa[v];
			dfs2(v, -1, 0);
			++ans;
		}
	return ans;
}

int main()
{
	//    freopen("in.txt","r",stdin);
	int casenum;
	scanf("%d", &casenum);
	while (casenum--)
	{
		for (int i(1); i <= n; ++i)
		{
			G[i].clear();
			nodes[i].clear();
		}
		scanf("%d%d%d", &n, &s, &k);
		int u, v;
		for (int i(1); i < n; ++i)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(s, -1, 0);
		printf("%d\n", solve());
	}
	return 0;
}
