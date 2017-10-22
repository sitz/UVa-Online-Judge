#include <bits/stdc++.h>

using namespace std;

#pragma warning(disable : 4786)

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define rep(i, n) for (i = 0; i < (n); i++)
#define i64 long long
//#define i64 __int64
#define MAXN 100005
#define MAXS 11
typedef pair<int, int> ii;
typedef vector<ii> vii;

i64 INF;

int n, m;
int ns;
int s[MAXS];
vector<pair<int, int>> adj[MAXN];
priority_queue<ii, vii, greater<ii>> pq;
i64 d[MAXS][MAXN];

i64 dp[MAXS][(1 << MAXS)];

void dijkstra(int st, int dex)
{
	int i;
	pair<int, int> t;
	rep(i, n) d[dex][i] = INF;
	d[dex][st] = 0;
	while (!pq.empty())
	{
		pq.pop();
	}
	pq.push(make_pair(st, 0));
	while (!pq.empty())
	{
		t = pq.top();
		pq.pop();
		if (d[dex][t.first] >= t.second)
		{
			rep(i, adj[t.first].size())
			{
				if (d[dex][t.first] + adj[t.first][i].second < d[dex][adj[t.first][i].first])
				{
					d[dex][adj[t.first][i].first] = d[dex][t.first] + adj[t.first][i].second;
					pq.push(make_pair(adj[t.first][i].first, d[dex][adj[t.first][i].first]));
				}
			}
		}
	}
}

i64 go(int cur, int state)
{
	if (state == 0)
	{
		return d[cur][s[ns - 1]];
	}
	if (dp[cur][state] != -1)
	{
		return dp[cur][state];
	}
	i64 &ret = dp[cur][state];
	int i;
	ret = INF;
	rep(i, ns) if (state & (1 << i))
	{
		ret = min(ret, go(i, state - (1 << i)) + d[cur][s[i]]);
	}
	return ret;
}

int main()
{
	int T;
	int u, v, d, i;
	scanf(" %d", &T);
	INF = (1 << 30);
	INF *= INF;
	while (T--)
	{
		scanf(" %d %d", &n, &m);
		rep(i, n) adj[i].clear();
		rep(i, m)
		{
			scanf(" %d %d %d", &u, &v, &d);
			adj[u].push_back(make_pair(v, d));
			adj[v].push_back(make_pair(u, d));
		}
		scanf(" %d", &ns);
		rep(i, ns) scanf(" %d", &s[i]);
		s[ns++] = 0;
		rep(i, ns)
		{
			dijkstra(s[i], i);
		}
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", go(ns - 1, (1 << ns) - 1));
	}
	return 0;
}
