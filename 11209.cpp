#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define N 201
typedef struct
{
	int t, c;
} Edge;
vector<Edge> edge[N];
int path[N];
int cost[N];//cost on path
bool visited[N];
int ans = 0;
int anspath[N], anspointer, anspnum;

inline void check_data(int n, int total)
{
	int tmp = 0;
	rep(i, n && tmp < total)
	{
		tmp += cost[i];
		if (tmp == total)
		{
			anspointer = i;
			rep(j, n) anspath[j] = path[j];
			ans = tmp;
			anspnum = n;
		}
	}
	return;
}

void solve(int now, int goal, int tcost, int pnum)
{
	if (now == goal)
	{
		if (tcost % 2 == 0 && tcost < ans * 2)
		{
			check_data(pnum, tcost / 2);
		}
		return;
	}
	visited[now] = true;
	rep(i, edge[now].size())
	{
		if (visited[edge[now][i].t] == false)
		{
			path[pnum] = edge[now][i].t;
			cost[pnum] = edge[now][i].c;
			solve(edge[now][i].t, goal, tcost + cost[pnum], pnum + 1);
		}
	}
	visited[now] = false;
	return;
}

main()
{
	int n, m, s, g;
	int tc = 1;
	while (cin >> n >> m >> s >> g && n)
	{
		ans = (1 << 21);
		rep(i, n + 1) edge[i].clear(), visited[i] = false;
		Edge tmp;
		rep(i, m)
		{
			int f, t, c;
			cin >> f >> t >> c;
			tmp.t = t;
			tmp.c = c;
			edge[f].push_back(tmp);
			tmp.t = f;
			edge[t].push_back(tmp);
		}
		cout << "Case " << tc++ << ": ";
		path[0] = s;
		cost[0] = 0;
		solve(s, g, 0, 1);
		cout << ans << endl;
		cout << anspointer + 1;
		rep(j, anspointer + 1) cout << ' ' << anspath[j];
		cout << endl;
		cout << anspnum - anspointer;
		for (int j = anspnum - 1; j >= anspointer; j--)
		{
			cout << ' ' << anspath[j];
		}
		cout << endl;
		puts("");
	}
	return false;
}
