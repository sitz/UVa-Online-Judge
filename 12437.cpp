#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
const int INF = 1 << 29;

int n;
vector<int> G[10000];

int ans[10001];
bool vis[10000];

int sz;// 木の頂点数
pair<int, int> dfs(int u, int pre)
{
	pair<int, int> res(0, u);
	vis[u] = true;
	sz++;
	rep(i, G[u].size())
	{
		int v = G[u][i];
		if (v != pre)
		{
			pair<int, int> tmp = dfs(v, u);
			tmp.first++;
			res = max(res, tmp);
		}
	}
	return res;
}

void f(int u)
{
	pair<int, int> tmp = dfs(u, -1);
	sz = 0;
	int diam = dfs(tmp.second, -1).first;
	int i;
	// 最長パス上は辺を一度だけ通ればいい
	for (i = 1; i <= diam; i++)
	{
		ans[i] = min(ans[i], i - 1);
	}
	// 最長パスに乗っていない辺は二度通る
	for (; i <= sz; i++)
	{
		ans[i] = min(ans[i], diam + 2 * (i - 1 - diam));
	}
}

int main()
{
	int T0;
	scanf("%d", &T0);
	for (int T = 1; T <= T0; T++)
	{
		int m;
		scanf("%d%d", &n, &m);
		rep(u, n) G[u].clear();
		rep(i, m)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		rep(i, 10001) ans[i] = INF;
		rep(u, n) vis[u] = false;
		rep(u, n) if (!vis[u])
		{
			f(u);
		}
		printf("Case %d:\n", T);
		int q;
		scanf("%d", &q);
		while (q--)
		{
			int k;
			scanf("%d", &k);
			if (ans[k] < INF)
			{
				printf("%d\n", ans[k]);
			}
			else
			{
				puts("impossible");
			}
		}
	}
	return 0;
}
