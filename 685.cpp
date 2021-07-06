#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
const int INF = (1 << 28);

class edge
{
public:
	int t, c;
	edge(){};
	edge(int tt, int tc)
	{
		t = tt;
		c = tc;
	}
};

int ans;
vector<edge> E[400];
int en[400][400];
int deg[400];
bool degvisited[400];

void solve(int n, int now, int k, int cost, int lastcost, bool flag)
{
	if (cost > ans)
	{
		return;
	}
	if (deg[now] == 1 && flag)
	{
		ans = cost;
		degvisited[now] = true;
		return;
	}
	rep(i, E[now].size())
	{
		if (en[now][E[now][i].t] == 0)
		{
			continue;
		}
		int tmp = E[now][i].c;
		en[now][E[now][i].t]--;
		en[E[now][i].t][now]--;
		solve(n, E[now][i].t, k, cost + max(lastcost, tmp) - min(lastcost, tmp) + k, tmp, true);
		en[E[now][i].t][now]++;
		en[now][E[now][i].t]++;
	}
}

main()
{
	int te;
	scanf("%d", &te);
	while (te--)
	{
		int k, m, n;
		scanf("%d%d%d", &m, &n, &k);
		rep(i, n)
		{
			E[i].clear();
			rep(j, n) en[i][j] = 0;
			deg[i] = 0, degvisited[i] = false;
		}
		rep(i, m)
		{
			int f, t, c;
			scanf("%d%d%d", &f, &t, &c);
			f--;
			t--;
			E[f].push_back(edge(t, c));
			E[t].push_back(edge(f, c));
			en[f][t]++;
			en[t][f]++;
			deg[f]++;
			deg[t]++;
		}
		ans = INF;
		rep(i, n)
		{
			if (deg[i] == 1)
			{
				int tmp = E[i][0].c;
				en[i][E[i][0].t]--;
				en[E[i][0].t][i]--;
				solve(n, E[i][0].t, k, k, tmp, false);
				en[i][E[i][0].t]++;
				en[E[i][0].t][i]++;
			}
		}
		printf("%d\n", ans);
	}
}
