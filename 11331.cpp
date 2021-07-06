#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 2000
#define mp make_pair

vector<int> edge[N];
bool visited[N];
int cost[N];
typedef pair<int, int> pii;

pii bfs(int s)
{
	int cnt[2] = {0};
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	cost[s] = 0;
	cnt[0]++;
	while (!Q.empty())
	{
		int now = Q.front();
		Q.pop();
		rep(i, edge[now].size())
		{
			int next = edge[now][i];
			if (visited[next] == true)
			{
				if (cost[next] == cost[now])
				{
					return mp(-1, -1);
				}
				continue;
			}
			visited[next] = true;
			cost[next] = cost[now] + 1;
			cnt[cost[next] % 2]++;
			Q.push(next);
		}
	}
	return mp(cnt[0], cnt[1]);
}

bool dp(int bull, vector<pii> data)
{
	static bool table[N][N + 1];
	rep(i, data.size()) rep(j, bull + 1) table[i][j] = false;
	table[0][data[0].first] = table[0][data[0].second] = true;
	REP(i, 1, data.size())
	{
		rep(j, bull + 1)
		{
			table[i][j] |= table[i - 1][j];
			if (j - data[i].first >= 0)
			{
				table[i][j] = table[i][j] | table[i - 1][j - data[i].first];
			}
			if (j - data[i].second >= 0)
			{
				table[i][j] = table[i][j] | table[i - 1][j - data[i].second];
			}
		}
	}
	/*
	rep(i,data.size()){
	  rep(j,bull+1)cout << table[i][j];
	  cout << endl;
	}
	*/
	return table[data.size() - 1][bull];
}

bool solve(int n, int b, int c)
{
	if (b == 0 && c == 0)
	{
		return true;
	}
	vector<pii> in;
	rep(i, n) cost[i] = -1, visited[i] = false;
	rep(i, n)
	{
		pii tmp;
		if (visited[i] == false)
		{
			tmp = bfs(i);
			if (tmp.first == -1)
			{
				return false;
			}
			in.push_back(tmp);
		}
	}
	return dp(max(b, c), in);
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int b, c, m;
		cin >> b >> c >> m;
		int n = b + c;
		rep(i, n) edge[i].clear();
		rep(i, m)
		{
			int f, t;
			cin >> f >> t;
			f--;
			t--;
			edge[f].push_back(t);
			edge[t].push_back(f);
		}
		if (m == 0 || solve(n, b, c))
		{
			puts("yes");
		}
		else
		{
			puts("no");
		}
	}
}
