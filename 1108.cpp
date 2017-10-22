#include <bits/stdc++.h>

using namespace std;

const double pi = 4.0 * atan(1.0);

#define clr(x) memset(x, 0, sizeof(x))
#define clro(x) memset(x, -1, sizeof(x))
#define sf scanf
#define pf printf

typedef signed long long LL;
typedef pair<int, int> pii;

const int inf = 999999999;
const int maxn = 55555;
const int maxm = 200000;
struct Edge
{
	int v, nex;
	Edge(){};
	Edge(int _v, int _nex)
	{
		v = _v, nex = _nex;
	}
};
Edge edges[maxm];
int tot;

int pre[maxn], bccno[maxn], iscut[maxn], dfs_clock, bcc_cnt;
int g[maxn];
int n, T;

vector<int> bcc[maxn];
stack<pii> S;

void clear()
{
	tot = 0;
	for (int i = 0; i < maxn; ++i)
	{
		bcc[i].clear();
	}
	while (!S.empty())
	{
		S.pop();
	}
	clro(g);
	clr(pre);
	clr(iscut);
	clr(bccno);
	dfs_clock = bcc_cnt = 0;
}
void addedge(int u, int v)
{
	edges[tot] = Edge(v, g[u]);
	g[u] = tot++;
}
int dfs(int u, int fa)
{
	int lowu, child, i, v;
	lowu = pre[u] = ++dfs_clock;
	child = 0;
	for (i = g[u]; ~i; i = edges[i].nex)
	{
		v = edges[i].v;
		pii e(u, v);
		if (!pre[v])
		{
			S.push(e);
			child++;
			int lowv = dfs(v, u);
			lowu = min(lowv, lowu);
			if (lowv >= pre[u])
			{
				iscut[u] = true;
				++bcc_cnt;
				while (true)
				{
					pii x = S.top();
					S.pop();
					if (bccno[x.first] != bcc_cnt)
					{
						bccno[x.first] = bcc_cnt;
						bcc[bcc_cnt].push_back(x.first);
					}
					if (bccno[x.second] != bcc_cnt)
					{
						bccno[x.second] = bcc_cnt;
						bcc[bcc_cnt].push_back(x.second);
					}
					if (x.first == u && x.second == v)
					{
						break;
					}
				}
			}
		}
		else if (pre[v] < pre[u] && v != fa)
		{
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if (fa < 0 && child == 1)
	{
		iscut[u] = 0;
	}
	return lowu;
}
void find(int n)
{
	for (int i = 0; i < n; ++i)
		if (!pre[i])
		{
			dfs(i, -1);
		}
}
void input()
{
	int a, b, i;
	for (i = 0; i < n; ++i)
	{
		sf("%d%d", &a, &b);
		--a, --b;
		addedge(a, b);
		addedge(b, a);
	}
}
void solve()
{
	int i, j, cnt;
	LL ans1 = 0, ans2 = 1;
	find(n);
	for (i = 1; i <= bcc_cnt; ++i)
	{
		cnt = 0;
		for (j = 0; j < bcc[i].size(); ++j)
		{
			if (iscut[bcc[i][j]])
			{
				++cnt;
			}
		}
		if (cnt == 1)
		{
			++ans1;
			ans2 *= (LL)(bcc[i].size() - 1);
		}
	}
	if (bcc_cnt == 1)
	{
		ans1 = 2, ans2 = (LL)(bcc[1].size()) * (LL)(bcc[1].size() - 1) / 2;
	}
	pf("Case %d: %lld %lld\n", ++T, ans1, ans2);
}
int main()
{
	T = 0;
	while (sf("%d", &n) == 1)
	{
		if (0 == n)
		{
			break;
		}
		clear();
		input();
		solve();
	}
	return 0;
}
