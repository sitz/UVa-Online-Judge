#include <bits/stdc++.h>

using namespace std;

#define esp 1e-6
#define pb push_back
#define mp(a, b) make_pair((a), (b))
#define in freopen("in.txt", "r", stdin);
#define out freopen("out.txt", "w", stdout);
#define print(a) printf("%d\n", (a));
#define bug puts("********))))))");
#define stop system("pause");
#define Rep(i, c) for (__typeof(c.end()) i = c.begin(); i != c.end(); i++)
#define inf 0x0f0f0f0f
#pragma comment(linker, "/STACK:102400000,102400000")

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;
typedef vector<pii, int> VII;
typedef vector<int>::iterator IT;

const int maxn = 1111;
const int maxm = 1000100;
int pre[maxn], iscut[maxn], bccno[maxn], bcc_cnt, dfs_clock;
int odd[maxn], color[maxn], low[maxn];
VI g[maxn], bcc[maxn];
struct Edge
{
	int u, v;
	Edge(int u, int v) : u(u), v(v) {}
};
stack<Edge> S;
bool bipartite(int u, int b)
{
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (bccno[v] != b)
			continue;
		if (color[v] == color[u])
			return false;
		if (!color[v])
		{
			color[v] = 3 - color[u];
			if (!bipartite(v, b))
				return false;
		}
	}
	return true;
}
int dfs(int u, int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for (int i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		Edge e = Edge(u, v);
		if (!pre[v])
		{
			S.push(e);
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowu, lowv);
			if (lowv >= pre[u])
			{
				iscut[u] = 1;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				for (;;)
				{
					Edge x = S.top();
					S.pop();
					if (bccno[x.u] != bcc_cnt)
					{
						bcc[bcc_cnt].pb(x.u);
						bccno[x.u] = bcc_cnt;
					}
					if (bccno[x.v] != bcc_cnt)
					{
						bcc[bcc_cnt].pb(x.v);
						bccno[x.v] = bcc_cnt;
					}
					if (x.u == u && x.v == v)
						break;
				}
			}
		}
		else if (pre[v] < pre[u] && v != fa)
		{
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (child == 1 && fa < 0)
		iscut[u] = 0;
	return low[u] = lowu;
}
void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	for (int i = 0; i < n; i++)
		if (!pre[i])
			dfs(i, -1);
}
int A[maxn][maxn];
int main(void)
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2 && n)
	{
		memset(A, 0, sizeof(A));
		for (int i = 0; i < maxn; i++)
			g[i].clear();
		for (int i = 0; i < m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			A[u][v] = A[v][u] = 1;
		}
		for (int u = 0; u < n; u++)
		{
			for (int v = u + 1; v < n; v++)
				if (!A[u][v])
					g[u].pb(v), g[v].pb(u);
		}
		memset(odd, 0, sizeof(odd));

		find_bcc(n);
		for (int i = 1; i <= bcc_cnt; i++)
		{
			memset(color, 0, sizeof(color));
			memset(bccno, 0, sizeof(bccno));
			for (int j = 0; j < bcc[i].size(); j++)
				bccno[bcc[i][j]] = i;
			int v = bcc[i][0];
			color[v] = 1;
			if (!bipartite(v, i))
				for (int j = 0; j < bcc[i].size(); j++)
					odd[bcc[i][j]] = 1;
		}
		int ans = n;
		for (int i = 0; i < n; i++)
			if (odd[i])
				ans--;
		printf("%d\n", ans);
	}
	return 0;
}
