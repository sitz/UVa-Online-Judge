#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>

#define REP(i, n) for (int i = 0; i < (int)n; ++i)
#define FOR(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()

using namespace std;

struct Packet
{
	int h, p, t;
	Packet(int _h, int _p, int _t)
			: h(_h), p(_p), t(_t)
	{
	}
};
bool operator<(Packet a, Packet b)
{
	if (a.h != b.h)
		return a.h < b.h;
	if (a.p != b.p)
		return a.p < b.p;
	return a.t < b.t;
}

int main(void)
{
	const int NODE = 10 + 1, INF = 1 << 20;
	int adj[NODE][NODE], tc = 0;
	for (int n;;)
	{
		cin >> n;
		if (n == 0)
			break;
		map<string, int> iland;
		map<int, int> host_iland;
		map<int, set<int> > group_hosts;
		int cnt = 0;
		fill(&adj[0][0], &adj[NODE - 1][NODE], INF);

		for (int i = 0; i < n; ++i)
		{// input
			string s, t;
			int m, h, cost;
			cin >> s >> m;
			if (iland.find(s) == iland.end())
			{
				iland[s] = cnt++;
			}
			for (int j = 0; j < m; ++j)
			{
				char c;
				cin >> c;
				if (c == 'H')
				{
					cin >> h;
					host_iland[h] = iland[s];
				}
				else
				{
					cin >> cost >> t;
					if (iland.find(t) == iland.end())
					{
						iland[t] = cnt++;
					}
					adj[iland[s]][iland[t]] = cost;
				}
			}
		}

		for (int k = 0; k < NODE; ++k)
		{
			for (int i = 0; i < NODE; ++i)
			{
				for (int j = 0; j < NODE; ++j)
				{
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		for (int i = 0; i < NODE; ++i)
		{
			adj[i][i] = 0;
		}

		vector<Packet> v;
		int query;
		cin >> query;
		for (int i = 0; i < query; ++i)
		{
			char c;
			int h, g, p, t;
			cin >> c;
			if (c == 'J')
			{
				cin >> h >> g;
				if (group_hosts.find(g) == group_hosts.end())
				{
					group_hosts[g] = set<int>();
				}
				group_hosts[g].insert(h);
			}
			else if (c == 'L')
			{
				cin >> h >> g;
				group_hosts[g].erase(h);
			}
			else
			{
				cin >> h >> g >> p >> t;
				set<int> group = group_hosts.find(g)->second;
				int src = host_iland[h];
				FOR(j, group)
				{
					int dst = host_iland[*j];
					if (t >= adj[src][dst])
					{
						v.push_back(Packet(*j, p, t - adj[src][dst]));
					}
				}
			}
		}

		sort(v.begin(), v.end());
		cout << "Network #" << ++tc << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i].h << ' ' << v[i].p << ' ' << v[i].t << endl;
		}

		cout << endl;
	}
	return 0;
}
