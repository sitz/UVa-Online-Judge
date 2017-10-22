#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define pb push_back
const int N = 16;
vector<int> edge[N];
int dp[(1 << N)];
int can[(1 << N)];
bool cancover(int n, int now)
{
	int vis = now;
	rep(i, n)
	{
		if (((1 << i) & now) == 0)
		{
			continue;
		}
		rep(j, edge[i].size()) vis |= (1 << edge[i][j]);
	}
	return vis == ((1 << n) - 1);
}

int solve(int n, int now)
{
	if (now == 0)
	{
		return 0;
	}
	int &ret = dp[now];
	if (ret == -1)
	{
		ret = 0;
		int sub = now;
		do
		{
			if (can[sub])
			{
				ret = max(ret, solve(n, now ^ sub) + 1);
			}
			sub = (sub - 1) & now;
		} while (sub != now);
	}
	return ret;
}

main()
{
	int n, tc = 1;
	while (cin >> n && n)
	{
		rep(i, n) edge[i].clear();
		rep(i, (1 << n)) dp[i] = -1;
		rep(i, n)
		{
			int m, t;
			cin >> m;
			rep(j, m) cin >> t, edge[i].pb(t);
		}
		rep(i, (1 << n))
		{
			can[i] = cancover(n, i);
		}
		int ans = solve(n, (1 << n) - 1);
		cout << "Case " << tc++ << ": " << ans << endl;
	}
	return 0;
}
