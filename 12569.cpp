#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

int n;

pair<int, int> encode(int u1, int S1, int u2, int S2)
{
	if (u1 != u2)
		return make_pair(u1, u2);

	rep(u, n) if ((S1 >> u & 1) && !(S2 >> u & 1))
			rep(v, n) if (!(S1 >> v & 1) && (S2 >> v & 1)) return make_pair(u, v);
}

void solve()
{
	int m, s, t;
	scanf("%d%d%d%d", &n, &m, &s, &t);
	s--;
	t--;
	int S0 = 0;
	rep(i, m)
	{
		int u;
		scanf("%d", &u);
		u--;
		S0 |= 1 << u;
	}
	vector<int> T[15];
	rep(i, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		T[u].push_back(v);
		T[v].push_back(u);
	}
	static int dp[15][1 << 15];
	static pair<int, int> path[15][1 << 15];
	memset(dp, -1, sizeof dp);
	dp[s][S0] = 0;
	int head = 0, tail = 0;
	static pair<int, int> Q[15 * (1 << 15)];
	Q[tail++] = make_pair(s, S0);
	int u_ans = -1, S_ans;
	while (head < tail)
	{
		int u = Q[head].first, S = Q[head].second;
		head++;
		if (u == t)
		{
			u_ans = u;
			S_ans = S;
			break;
		}
		rep(i, T[u].size())
		{
			int v = T[u][i];
			if ((S >> v & 1) == 0 && dp[v][S] == -1)
			{
				Q[tail++] = make_pair(v, S);
				dp[v][S] = dp[u][S] + 1;
				path[v][S] = make_pair(u, S);
			}
		}
		rep(v, n) if (S >> v & 1)
		{
			rep(i, T[v].size())
			{
				int w = T[v][i], S2 = S & ~(1 << v) | (1 << w);
				if ((S >> w & 1) == 0 && w != u && dp[u][S2] == -1)
				{
					Q[tail++] = make_pair(u, S2);
					dp[u][S2] = dp[u][S] + 1;
					path[u][S2] = make_pair(u, S);
				}
			}
		}
	}
	if (u_ans == -1)
	{
		puts("-1\n");
		return;
	}
	printf("%d\n", dp[u_ans][S_ans]);
	int u = u_ans, S = S_ans;
	vector<pair<int, int>> p_ans;
	while (u != s || S != S0)
	{
		pair<int, int> a = path[u][S];
		p_ans.push_back(encode(a.first, a.second, u, S));
		u = a.first;
		S = a.second;
	}
	reverse(p_ans.begin(), p_ans.end());
	rep(i, p_ans.size()) printf("%d %d\n", p_ans[i].first + 1, p_ans[i].second + 1);
	puts("");
}

int main()
{
	int T;
	scanf("%d ", &T);
	for (int cas = 1; cas <= T; cas++)
		printf("Case %d: ", cas), solve();
	return 0;
}
