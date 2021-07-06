#include <bits/stdc++.h>

using namespace std;

struct event_t
{
	int type;
	int a, b, iter;
	bool operator<(const event_t &other) const
	{
		if (type == other.type)
		{
			if (a == other.a)
			{
				return b < other.b;
			}
			return a < other.a;
		}
		return type < other.type;
	}
};
int R = 0, D = 1, L = 2, U = 3;
typedef long long ll;
const int MAXN = 1 << 20;
// valid positions are [1..MAXN], commented lines are hints for a 2D BIT
// MODES OF USE: point-insert range-query OR range-insert point-query
struct BITree
{
	ll freq[MAXN + 1];
	BITree()
	{
		memset(freq, 0, sizeof freq);
	}
	void insert(int x, ll cnt = 1)
	{
		for (; x <= MAXN; x += x & -x)
		{
			freq[x] += cnt;
		}
	}
	ll query(int x)
	{
		ll sum = 0;
		for (; x; x -= x & -x)
		{
			sum += freq[x];
		}
		return sum;
	}
	ll query_range(int xl, int xr)
	{
		return query(xr) - query(xl - 1);
	}
} T, TT[2];
vector<pair<int, int>> rs[1000001], cs[1000001];
int main()
{
	ios::sync_with_stdio(0);
	int r, c, m, n;
	int zz = 1;
	while (cin >> r >> c >> m >> n)
	{
		for (int i = 1; i <= r; i++)
		{
			rs[i].clear();
		}
		for (int i = 1; i <= c; i++)
		{
			cs[i].clear();
		}
		cout << "Case " << zz++ << ": ";
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			rs[a].push_back(make_pair(b, 1));
			cs[b].push_back(make_pair(a, 1));
		}
		for (int i = 0; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			rs[a].push_back(make_pair(b, 2));
			cs[b].push_back(make_pair(a, 2));
		}
		for (int i = 1; i <= r; i++)
		{
			sort(rs[i].begin(), rs[i].end());
		}
		for (int i = 1; i <= c; i++)
		{
			sort(cs[i].begin(), cs[i].end());
		}
		bool solved = false;
		vector<pair<int, event_t>> events;
		for (int iter = 0; iter < 2; iter++)
		{
			int cr = 1, cc = 0;
			int d = R;
			if (iter == 0)
			{
				cr = r;
				cc = c + 1;
				d = L;
			}
			bool done = false;
			int asdf = 0;
			while (!done)
			{
				event_t evt, evt2;
				evt.iter = evt2.iter = iter;
				if (d == R)
				{
					evt.type = 0;
					evt.a = cc + 1;
					int i = upper_bound(rs[cr].begin(), rs[cr].end(), make_pair(cc + 1, 0)) - rs[cr].begin();
					if (i >= rs[cr].size())
					{
						done = true;
						evt.b = c + 1;
					}
					else
					{
						cc = rs[cr][i].first;
						d = (rs[cr][i].second == 1 ? U : D);
						evt.b = cc - 1;
					}
					if (evt.a <= evt.b)
					{
						events.push_back(make_pair(cr, evt));
					}
				}
				else if (d == D)
				{
					evt.type = -1;
					evt.a = cc;
					evt.b = cr + 1;
					int i = upper_bound(cs[cc].begin(), cs[cc].end(), make_pair(cr + 1, 0)) - cs[cc].begin();
					if (i >= cs[cc].size())
					{
						done = true;
						events.push_back(make_pair(cr + 1, evt));
					}
					else
					{
						cr = cs[cc][i].first;
						d = (cs[cc][i].second == 1 ? L : R);
						evt2.type = 1;
						evt2.a = cc;
						if (evt.b <= cr - 1)
						{
							events.push_back(make_pair(evt.b, evt));
							events.push_back(make_pair(cr - 1, evt2));
						}
					}
				}
				else if (d == L)
				{
					evt.type = 0;
					evt.b = cc - 1;
					int i = lower_bound(rs[cr].begin(), rs[cr].end(), make_pair(cc, 0)) - 1 - rs[cr].begin();
					if (i < 0)
					{
						cc = 0;
						done = true;
						evt.a = 1;
					}
					else
					{
						cc = rs[cr][i].first;
						d = (rs[cr][i].second == 1 ? D : U);
						evt.a = cc + 1;
					}
					if (evt.a <= evt.b)
					{
						events.push_back(make_pair(cr, evt));
					}
				}
				else if (d == U)
				{
					evt.type = 1;
					evt.a = cc;
					evt.b = cr - 1;
					int i = lower_bound(cs[cc].begin(), cs[cc].end(), make_pair(cr, 0)) - 1 - cs[cc].begin();
					if (i < 0)
					{
						done = true;
						evt2.type = -1;
						evt2.a = cc;
						events.push_back(make_pair(1, evt2));
						events.push_back(make_pair(cr - 1, evt));
					}
					else
					{
						cr = cs[cc][i].first;
						d = (cs[cc][i].second == 1 ? R : L);
						evt2.type = -1;
						evt2.a = cc;
						if (cr + 1 <= evt.b)
						{
							events.push_back(make_pair(evt.b, evt));
							events.push_back(make_pair(cr + 1, evt2));
						}
					}
				}
			}
			if (iter == 0 && cr == 1 && cc == 0)
			{
				cout << 0 << endl;
				solved = true;
				break;
			}
		}
		if (solved)
		{
			continue;
		}
		sort(events.begin(), events.end());
		ll cnt = 0;
		int fr, fc;
		set<int> open[2];
		memset(T.freq, 0, sizeof T.freq);
		memset(TT[0].freq, 0, sizeof TT[0].freq);
		memset(TT[1].freq, 0, sizeof TT[1].freq);
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].second.type == -1)
			{
				open[events[i].second.iter].insert(events[i].second.a);
				T.insert(events[i].second.a, 1);
				TT[events[i].second.iter].insert(events[i].second.a, 1);
			}
			else if (events[i].second.type == 1)
			{
				open[events[i].second.iter].erase(events[i].second.a);
				T.insert(events[i].second.a, -1);
				TT[events[i].second.iter].insert(events[i].second.a, -1);
			}
			else
			{
				if (cnt == 0)
				{
					set<int>::iterator cand = open[1 - events[i].second.iter].lower_bound(events[i].second.a);
					if (cand != open[1 - events[i].second.iter].end() && *cand <= events[i].second.b)
					{
						fr = events[i].first;
						fc = *cand;
					}
				}
				cnt += T.query_range(events[i].second.a, events[i].second.b) - TT[events[i].second.iter].query_range(events[i].second.a, events[i].second.b);
			}
		}
		if (cnt == 0)
		{
			cout << "impossible" << endl;
		}
		else
		{
			cout << cnt << " " << fr << " " << fc << endl;
		}
	}
	return 0;
}
