#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const int N = 50;
const int M = 50001;
const int inf = (1 << 21);

struct Edge
{
	int t, c;
};
vector<Edge> edge[N];
bool vis[N];
bool findPath(int now, vector<int> &cost, int &ans, int tar)
{
	if (now == tar)
	{
		return true;
	}
	if (vis[now])
	{
		return false;
	}
	vis[now] = true;
	rep(i, edge[now].size())
	{
		if (findPath(edge[now][i].t, cost, ans, tar))
		{
			cost.push_back(edge[now][i].c);
			ans -= edge[now][i].c;
			return true;
		}
	}
	return false;
}

int dp[50][M];
int solve(int n, int s, int t, int ans)
{
	rep(i, n) vis[i] = false;
	vector<int> cost;
	if (!findPath(s, cost, ans, t))
	{
		return inf;
	}
	if (ans < 0 || ans % 2 == 1)
	{
		return inf;
	}
	if (ans == 0)
	{
		return cost.size();
	}
	cost.erase(cost.begin());
	if (cost.size() == 0)
	{
		return inf;
	}
	ans /= 2;
	rep(i, cost.size()) rep(j, ans + 1) dp[i][j] = inf;
	dp[0][0] = 0;
	rep(i, cost.size())
	{
		rep(j, ans + 1)
		{
			if (j - cost[i] >= 0)
			{
				dp[i][j] = min(dp[i][j], dp[i][j - cost[i]] + 1);
			}
			if (i - 1 >= 0)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j]);
			}
		}
	}
	if (dp[cost.size() - 1][ans] == inf)
	{
		return inf;
	}
	return dp[cost.size() - 1][ans] * 2 + cost.size() + 1;
}

main()
{
	int te;
	cin >> te;
	rep(tc, te)
	{
		if (tc)
		{
			cout << endl;
		}
		int n, m;
		cin >> n >> m;
		rep(i, n) edge[i].clear();
		rep(i, m)
		{
			int f, t, c;
			cin >> f >> t >> c;
			f--;
			t--;
			edge[f].push_back((Edge){
					t, c});
			edge[t].push_back((Edge){
					f, c});
		}
		int q;
		cin >> q;
		rep(i, q)
		{
			int f, t, c;
			cin >> f >> t >> c;
			f--;
			t--;
			int ans = solve(n, f, t, c);
			if (ans == inf)
			{
				cout << "No" << endl;
			}
			else
			{
				cout << "Yes " << ans << endl;
			}
		}
	}
	return false;
}
