#include <bits/stdc++.h>

using namespace std;

#define NN 50000
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))

bool vis[NN];
int n, nxt[NN], n_ord, ord[NN], n_scc, scc[NN], i, dp[NN];
vector<int> rnxt[NN];

void dfs1(int u)
{
	vis[u] = true;
	int v = nxt[u];
	if (!vis[v])
	{
		dfs1(v);
	}
	ord[n_ord++] = u;
}
void dfs2(int u)
{
	vis[u] = true;
	rep(i, rnxt[u].size())
	{
		int v = rnxt[u][i];
		if (!vis[v])
		{
			dfs2(v);
		}
	}
	scc[u] = n_scc;
}
void SCC()
{
	n_ord = 0;
	rep(u, n) vis[u] = false;
	rep(u, n) if (!vis[u])
	{
		dfs1(u);
	}
	n_scc = 0;
	rep(u, n) vis[u] = false;
	for (int i = n - 1; i >= 0; i--)
	{
		int u = ord[i];
		if (!vis[u])
		{
			dfs2(u), n_scc++;
		}
	}
}
int dfs(int u)
{
	int v = u;
	dp[u] = 1;
	while (1)
	{
		v = nxt[v];
		if (v == u || scc[u] != scc[v])
		{
			break;
		}
		dp[u]++;
	}
	v = u;
	while (1)
	{
		v = nxt[v];
		if (v == u || scc[u] != scc[v])
		{
			break;
		}
		dp[v] = dp[u];
	}
	if (u != v)
	{
		dp[u] += dfs(v);
	}
	return dp[u];
}

int main()
{
	int T0;
	scanf("%d", &T0);
	for (int T = 1; T <= T0; T++)
	{
		scanf("%d", &n);
		rep(u, n) rnxt[u].clear();
		rep(i, n)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			nxt[u] = v;
			rnxt[v].push_back(u);
		}
		SCC();
		rep(u, n) dp[u] = -1;
		for (int i = n - 1; i >= 0; i--)
		{
			int u = ord[i];
			if (dp[u] == -1)
			{
				dfs(u);
			}
		}
		printf("Case %d: %ld\n", T, max_element(dp, dp + n) - dp + 1);
	}
	return 0;
}
