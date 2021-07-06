#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define mp make_pair

const int N = 10000;
const int inf = (1 << 21);
const int M = 20;

vector<int> edge[N];
bool visited[N];
int dp[N][M];

void dfs(int n, int now)
{
	visited[now] = true;
	vector<int> child;
	rep(i, edge[now].size())
	{
		if (visited[edge[now][i]])
		{
			continue;
		}
		dfs(n, edge[now][i]);
		child.push_back(edge[now][i]);
	}
	sort(ALL(child));
	REP(i, 1, M)
	{
		int tmp = i;
		rep(j, child.size())
		{
			int tmp2 = inf;
			rep(k, M)
			{
				if (i == k)
				{
					continue;
				}
				tmp2 = min(tmp2, dp[child[j]][k]);
			}
			tmp += tmp2;
		}
		dp[now][i] = tmp;
	}
	return;
}

int solve(int n)
{
	rep(i, n) rep(j, M) dp[i][j] = inf;
	dfs(n, 0);
	int ret = inf;
	rep(i, M) ret = min(ret, dp[0][i]);
	return ret;
}

main()
{
	int n;
	while (cin >> n && n)
	{
		rep(i, n) edge[i].clear(), visited[i] = false;
		rep(i, n)
		{
			int now, t;
			char dummy;
			cin >> now >> dummy;
			string tmp;
			getline(cin, tmp);
			stringstream sin(tmp);
			while (sin >> t)
			{
				edge[now].push_back(t), edge[t].push_back(now);
			}
		}
		cout << solve(n) << endl;
	}
}
