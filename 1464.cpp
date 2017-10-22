#include <bits/stdc++.h>

using namespace std;

#define esp 1e-6
#define pi acos(-1.0)
#define pb push_back
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define mp(a, b) make_pair((a), (b))
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
#define print(a) printf("%d\n", (a));
#define bug puts("********))))))");
#define stop system("pause");
#define Rep(i, c) for (__typeof(c.end()) i = c.begin(); i != c.end(); i++)
#define inf 0x0f0f0f0f

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii> VII;
typedef vector<pii, int> VIII;
typedef VI::iterator IT;
#define eid first
#define vtx second

const int maxn = 10000 + 10000;
const int maxm = 100000 + 10000;
int pre[maxn], low[maxn], bccno[maxn], ebccno[maxm], iscut[maxn], vis[maxm], ans[maxn], pa[maxn], bcc_cnt, dfs_clock;
VI g[maxn], bcc[maxn];
VII adj[maxn], query[maxn];
struct edge
{
	int u, v;
} ee[maxm];
stack<int> S;

int dfs(int u, int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i].vtx;
		if (!pre[v])
		{
			S.push(adj[u][i].eid);
			child++;
			vis[adj[u][i].eid] = 1;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u])
			{
				iscut[u] = 1;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				for (;;)
				{
					int e = S.top();
					S.pop();
					bcc[bcc_cnt].pb(e);
					ebccno[e] = bcc_cnt;
					bccno[ee[e].u] = bccno[ee[e].v] = bcc_cnt;
					if (e == adj[u][i].eid)
					{
						break;
					}
				}
			}
		}
		else if (pre[v] < pre[u])
		{
			if (v != fa)
			{
				lowu = min(lowu, pre[v]);
				S.push(adj[u][i].eid);
				vis[adj[u][i].eid] = 1;
			}
			else
			{
				if (!vis[adj[u][i].eid])
				{
					lowu = min(lowu, pre[v]);
					S.push(adj[u][i].eid);
					vis[adj[u][i].eid] = 1;
				}
			}
		}
	}
	if (fa < 0 && child == 1)
	{
		iscut[u] = 0;
	}
	return low[u] = lowu;
}
void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(bccno, 0, sizeof(bccno));
	memset(iscut, 0, sizeof(iscut));
	memset(ebccno, 0, sizeof(ebccno));
	memset(vis, 0, sizeof(vis));
	while (!S.empty())
	{
		S.pop();
	}
	dfs_clock = bcc_cnt = 0;
	for (int i = 0; i < n; i++)
		if (!pre[i])
		{
			dfs(i, -1);
		}
}
int flag[maxn];
int dis[maxn];
int vv[maxn];
int findset(int x)
{
	return pa[x] == x ? x : pa[x] = findset(pa[x]);
}
void tarjan(int u, int d)
{
	vv[u] = 1;
	dis[u] = d;
	pa[u] = u;
	if (u > bcc_cnt)
	{
		dis[u]++;
	}
	for (int i = 0; i < query[u].size(); i++)
	{
		int v = query[u][i].first;
		int id = query[u][i].second;
		if (vis[v])
		{
			ans[id] = dis[u] + dis[v] - 2 * dis[findset(v)] + (findset(v) > bcc_cnt);
		}
	}
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (!vv[v])
		{
			tarjan(v, dis[u]);
			pa[v] = u;
		}
	}
}
int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m), n || m)
	{
		for (int i = 0; i < maxn; i++)
		{
			adj[i].clear(), g[i].clear(), query[i].clear();
		}
		memset(flag, -1, sizeof(flag));
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u].pb(mp(i, v));
			adj[v].pb(mp(i, u));
			ee[i].u = u, ee[i].v = v;
		}
		find_bcc(n);
		int cut_cnt = 0;
		for (int i = 0; i < n; i++)
			if (iscut[i])
			{
				cut_cnt++;
				int u = cut_cnt + bcc_cnt;
				for (int k = 0; k < adj[i].size(); k++)
				{
					int v = ebccno[adj[i][k].first];
					if (flag[v] != u)
					{
						flag[v] = u;
						g[v].pb(u);
						g[u].pb(v);
					}
				}
			}
		int q;
		for (int i = scanf("%d", &q); i <= q; i++)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			s = ebccno[s], t = ebccno[t];
			query[s].pb(mp(t, i));
			query[t].pb(mp(s, i));
		}
		memset(vv, 0, sizeof(vv));
		for (int i = 1; i <= bcc_cnt + cut_cnt; i++)
			if (!vv[i])
			{
				tarjan(i, 0);
			}
		for (int i = 1; i <= q; i++)
		{
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}
