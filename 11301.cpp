#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

const int N = 1000;
const int inf = (1 << 29);

class state
{
public:
	int now, bit, vis;
	int cost;
	bool operator<(const state &a) const
	{
		return cost > a.cost;
	}
};

string m[5];

int d[2] = {-1, 1};

int dijkstra(int n, int ini)
{
	static int cost[N][(1 << 5)][(1 << 5)];
	rep(i, n) rep(j, (1 << 5)) rep(k, (1 << 5)) cost[i][j][k] = inf;
	priority_queue<state> Q;
	Q.push((state){
			0, ini, ini, 0});
	while (!Q.empty())
	{
		state now = Q.top();
		Q.pop();
		state next;
		if (cost[now.now][now.bit][now.vis] != inf)
		{
			continue;
		}
		cost[now.now][now.bit][now.vis] = now.cost;
		if (now.now == n - 1)
		{
			return now.cost;
		}
		rep(i, 5)
		{
			if ((now.bit & (1 << i)) == 0)
			{
				continue;
			}
			rep(j, 2)
			{
				int nec = i + d[j];
				if (nec == -1 || nec == 5 || (now.vis & (1 << nec)) != 0)
				{
					continue;
				}
				next = now;
				next.bit += (1 << nec);
				next.bit -= (1 << i);
				next.vis += (1 << nec);
				next.cost += m[nec][next.now] - '0';
				Q.push(next);
			}
		}
		//move all
		next = now;
		rep(i, 5)
		{
			if ((next.bit & (1 << i)) != 0)
			{
				next.cost += m[i][next.now + 1] - '0';
			}
		}
		next.vis = next.bit;
		next.now++;
		Q.push(next);
	}
	return -1;
}

main()
{
	int n;
	while (cin >> n && n)
	{
		rep(i, 5) cin >> m[i];
		int ini = 0;
		int cnt = 0;
		rep(i, 5)
		{
			if (m[i][0] == '@')
			{
				ini |= (1 << i);
				m[i][0] = 0;
				cnt++;
			}
		}
		cout << dijkstra(n, ini) << endl;
	}
}
