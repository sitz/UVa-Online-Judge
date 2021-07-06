#include <bits/stdc++.h>

using namespace std;

#define N 128
#define pii pair<int, int>
#define INF (1 << 29)

struct edge
{
	int leave, arrive, nextCity;
	edge(int _leave = 0, int _arrive = 0, int _nextCity = 0)
	{
		leave = _leave, arrive = _arrive, nextCity = _nextCity;
	}
};

int dist[N];
struct comp
{
	bool operator()(pii i, pii j) const
	{
		if (i.first != j.first)
		{
			return i.first > j.first;
		}
		return i.second < j.second;
	}
};

set<pii> dij;
map<string, int> tag;
vector<edge> adj[N], rev[N];

string toStr(int x)
{
	ostringstream oss;
	oss << x;
	return oss.str();
}
string toHour(int x)
{
	int h = x / 60;
	int m = x % 60;
	string s;
	if (h < 10)
	{
		s += '0';
		s += h + '0';
	}
	else
	{
		s += toStr(h);
	}
	if (m < 10)
	{
		s += '0';
		s += m + '0';
	}
	else
	{
		s += toStr(m);
	}
	return s;
}

int toInt(string &s)
{
	return ((s[0] - '0') * 10 + s[1] - '0') * 60 +
				 ((s[2] - '0') * 10 + s[3] - '0');
}

int main()
{
	int n, lines, src, dst;
	int stations, t1, t2, city1, city2, startTime;
	int srcLeave, dstArrive;
	string cityName, tt;
	while (cin >> n, n)
	{
		tag.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> cityName;
			tag[cityName] = i;
			dist[i] = INF;
			adj[i].clear();
			rev[i].clear();
		}
		cin >> lines;
		while (lines--)
		{
			cin >> stations;
			cin >> tt >> cityName;
			t1 = toInt(tt);
			city1 = tag[cityName];
			for (int i = 1; i < stations; i++)
			{
				cin >> tt >> cityName;
				t2 = toInt(tt);
				city2 = tag[cityName];
				adj[city1].push_back(edge(t1, t2, city2));
				rev[city2].push_back(edge(t2, t1, city1));
				t1 = t2;
				city1 = city2;
			}
		}
		cin >> tt;
		startTime = toInt(tt);
		cin >> cityName;
		src = tag[cityName];
		cin >> cityName;
		dst = tag[cityName];
		dij.clear();
		dist[src] = startTime;
		dij.insert(pii(dist[src], src));
		while (!dij.empty())
		{
			city1 = dij.begin()->second;
			dij.erase(dij.begin());
			for (int i = 0; i < adj[city1].size(); i++)
			{
				t1 = adj[city1][i].leave;
				t2 = adj[city1][i].arrive;
				city2 = adj[city1][i].nextCity;
				if (t1 >= dist[city1] && dist[city2] > t2)
				{
					dij.erase(pii(dist[city2], city2));
					dist[city2] = t2;
					dij.insert(pii(dist[city2], city2));
				}
			}
		}
		if (dist[dst] == INF)
		{
			cout << "No connection" << endl;
			continue;
		}
		set<pii, comp> revDij;
		dstArrive = dist[dst];
		startTime = dist[dst];
		for (int i = 0; i < n; i++)
		{
			dist[i] = -1;
		}
		revDij.clear();
		dist[dst] = startTime;
		revDij.insert(pii(dist[dst], dst));
		while (!revDij.empty())
		{
			city1 = revDij.begin()->second;
			revDij.erase(revDij.begin());
			for (int i = 0; i < rev[city1].size(); i++)
			{
				t1 = rev[city1][i].leave;
				t2 = rev[city1][i].arrive;
				city2 = rev[city1][i].nextCity;
				if (t1 <= dist[city1] && dist[city2] < t2)
				{
					revDij.erase(pii(dist[city2], city2));
					dist[city2] = t2;
					revDij.insert(pii(dist[city2], city2));
				}
			}
		}
		srcLeave = dist[src];
		cout << toHour(srcLeave) << " " << toHour(dstArrive) << endl;
	}
	return 0;
}
