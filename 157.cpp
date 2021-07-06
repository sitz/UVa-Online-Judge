#include <bits/stdc++.h>

using namespace std;

const int MAX_ALPHA = 'z' - 'a' + 1;

struct Station
{
	int _line; // 'A' - 'Z'
	int _index;// 'a' - 'z'

public:
	Station()
			: _line(0)
	{
	}
	Station(int _Line, int _Index)
			: _line(_Line), _index(_Index)
	{
		// ASSERT('A' <= _line && _line <= 'Z');
		// ASSERT('a' <= _index && _index <= 'z');
	}
	bool valid() const
	{
		return _line > 0;
	}
	int line() const
	{
		return _line;
	}
	int index() const
	{
		return _index;
	}
	int code() const
	{
		return (_line - 'A') * MAX_ALPHA + (_index - 'a');
	}
	bool operator==(const Station &_Rhs) const
	{
		return code() == _Rhs.code();
	}
	bool operator<(const Station &_Rhs) const
	{
		return code() < _Rhs.code();
	}
};

int main()
{
	int i, lines;
	typedef set<Station> Connection;
	map<Station, Connection> con;
	Connection::iterator it_con1, it_con2;
	scanf("%d", &lines);
	for (i = 0; i < lines; ++i)
	{
		int line;
		do
		{
			line = getchar();
		} while (line < 'A' || 'Z' < line);
		const int colon = getchar();
		// ASSERT(colon == ':');
		Station st0;
		while (true)
		{
			const int tmp = getchar();
			if ('a' <= tmp && tmp <= 'z')
			{
				const Station st(line, tmp);
				if (st0.valid())
				{
					con[st].insert(st0);
					con[st0].insert(st);
				}
				st0 = st;
			}
			else if (tmp == '=')
			{
				// ASSERT(st0.valid());
				const int c_line = getchar();
				// ASSERT('A' <= c_line && c_line <= 'Z');
				const int c_index = getchar();
				// ASSERT('a' <= c_index && c_index <= 'z');
				const Station st(c_line, c_index);
				Connection &con_st = con[st], con_st0 = con[st0];
				con_st.insert(st0);
				for (it_con2 = con_st0.begin();
						 it_con2 != con_st0.end(); ++it_con2)
				{
					if (it_con2->line() != st0.line())
					{
						con_st.insert(*it_con2);
					}
				}
				for (it_con1 = con_st.begin();
						 it_con1 != con_st.end(); ++it_con1)
				{
					if (it_con1->line() != st.line())
					{
						con[*it_con1].insert(st0);
						for (it_con2 = con_st0.begin();
								 it_con2 != con_st0.end(); ++it_con2)
						{
							if (it_con2->line() != st0.line())
							{
								con[*it_con1].insert(*it_con2);
							}
						}
					}
				}
				con_st0.insert(st);
				for (it_con2 = con_st.begin();
						 it_con2 != con_st.end(); ++it_con2)
				{
					if (it_con2->line() != st.line())
					{
						con_st0.insert(*it_con2);
					}
				}
				for (it_con1 = con_st0.begin();
						 it_con1 != con_st0.end(); ++it_con1)
				{
					if (it_con1->line() != st0.line())
					{
						con[*it_con1].insert(st);
						for (it_con2 = con_st.begin();
								 it_con2 != con_st.end(); ++it_con2)
						{
							if (it_con2->line() != st.line())
							{
								con[*it_con1].insert(*it_con2);
							}
						}
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	typedef vector<Station> Route;
	typedef pair<int, Route> RouteAndDist;
	map<Station, map<Station, RouteAndDist>> routes;
	map<Station, set<Station>>::iterator it_st0, it_st1, it_st2;
	for (it_st1 = con.begin(); it_st1 != con.end(); ++it_st1)
	{
		const Station st1 = it_st1->first;
		for (it_st2 = con.begin(); it_st2 != con.end(); ++it_st2)
		{
			const Station st2 = it_st2->first;
			if (st1 == st2)
			{
				continue;
			}
			if (con[st1].count(st2))
			{
				Route route;
				route.push_back(st1);
				route.push_back(st2);
				const int dist = st1.line() == st2.line() ? 1 : 3;
				routes[st1][st2] = RouteAndDist(dist, route);
				reverse(route.begin(), route.end());
				routes[st2][st1] = RouteAndDist(dist, route);
			}
		}
	}
	for (it_st0 = con.begin(); it_st0 != con.end(); ++it_st0)
	{
		const Station st0 = it_st0->first;
		for (it_st1 = con.begin(); it_st1 != con.end(); ++it_st1)
		{
			const Station st1 = it_st1->first;
			if (st0 == st1)
			{
				continue;
			}
			for (it_st2 = con.begin(); it_st2 != con.end(); ++it_st2)
			{
				const Station st2 = it_st2->first;
				if (st0 == st2 || st1 == st2)
				{
					continue;
				}
				const RouteAndDist &rad1 = routes[st1][st0];
				const RouteAndDist &rad2 = routes[st0][st2];
				if (rad1.second.size() > 0 && rad2.second.size() > 0)
				{
					const int dist = rad1.first + rad2.first;
					RouteAndDist &rad0 = routes[st1][st2];
					if (rad0.second.size() == 0 || rad0.second.size() > dist)
					{
						rad0.first = dist;
						rad0.second.clear();
						rad0.second.insert(rad0.second.end(),
															 rad1.second.begin(), rad1.second.end());
						rad0.second.pop_back();
						rad0.second.insert(rad0.second.end(),
															 rad2.second.begin(), rad2.second.end());
					}
				}
			}
		}
	}
	char query[5];
	while (scanf("%s", query) == 1)
	{
		if (query[0] == '#')
		{
			break;
		}
		const Station st1(query[0], query[1]);
		const Station st2(query[2], query[3]);
		// ASSERT(!(st1 == st2));
		const RouteAndDist &ans = routes[st1][st2];
		// ASSERT(ans.second.size() > 0);
		printf("%3d: ", ans.first);
		for (i = 0; i < ans.second.size(); ++i)
		{
			if (i == 0 || ans.second[i].line() != ans.second[i - 1].line())
			{
				if (i != 0)
				{
					printf("=");
				}
				printf("%c", ans.second[i].line());
			}
			printf("%c", ans.second[i].index());
		}
		printf("\n");
	}
	return 0;
}
