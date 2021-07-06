#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < (int)n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define FOR(it, o) for (__typeof((o).begin()) it = (o).begin(); it != (o).end(); ++it)

const double EPS = 0.00000001;
const int INF = 1000000000;
typedef long long lli;

const int MAX_V = 1000;

int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v)
{
	G[u].push_back(v);
	G[v].push_back(u);
}

bool dfs(int v)
{
	used[v] = true;
	rep(i, (int)G[v].size())
	{
		int u = G[v][i], w = match[u];
		if (w < 0 || (!used[w] && dfs(w)))
		{
			match[v] = u;
			match[u] = v;
			return true;
		}
	}
	return false;
}

int bipartite_matching()
{
	int res = 0;
	memset(match, -1, sizeof(match));
	rep(i, V)
	{
		if (match[i] < 0)
		{
			memset(used, 0, sizeof(used));
			if (dfs(i))
			{
				res++;
			}
		}
	}
	return res;
}

int main()
{
	int T;
	cin >> T;
	rep(tc, T)
	{
		rep(i, 1000)
		{
			G[i].clear();
		}
		int t[2][1000];
		int n[2];
		rep(i, 2)
		{
			cin >> n[i];
			rep(j, n[i])
			{
				cin >> t[i][j];
			}
		}
		rep(i, n[0])
		{
			rep(j, n[1])
			{
				if (t[1][j] == 0)
				{
					add_edge(i, n[0] + j);
				}
				else if (t[0][i] == 0)
				{
					continue;
				}
				else if (t[1][j] % t[0][i] == 0)
				{
					add_edge(i, n[0] + j);
				}
			}
		}
		V = n[0] + n[1];
		printf("Case %d: %d\n", tc + 1, bipartite_matching());
	}
	return 0;
}
