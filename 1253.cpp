#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) FOR(i, j, 0, -1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define tr(cont, it) for (__typeof(cont.begin()) it = cont.begin(); it != cont.end(); it++)

#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef unsigned long long ll;

typedef pair<ii, string> state;

queue<state> q;
map<state, int> dist;
int n;
char line[5];
ii car;
string s, field, temp;
state ss;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool boundaries(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

bool done(string field)
{
	tr(field, it)
	{
		if (*it == '#')
		{
			return false;
		}
	}
	return true;
}

int adjacent(string field, int x, int y)
{
	int s = 0, nx, ny;
	REP(d, 8)
	{
		nx = (x + dx[d]);
		ny = (y + dy[d]);
		if (boundaries(nx, ny) && (field[n * nx + ny] == '#' || field[n * nx + ny] == '@'))
		{
			s++;
		}
	}
	return s;
}

string calculate(state u, int d)
{
	int x, y, nx, ny;
	x = u.first.first;
	y = u.first.second;
	nx = x + dx[d];
	ny = y + dy[d];
	string field = u.second, nfield;
	nfield.assign(n * n, '.');
	nfield[n * nx + ny] = '@';
	nfield[n * x + y] = '.';
	field[n * nx + ny] = '@';
	field[n * x + y] = '.';
	REP(i, n)
	{
		REP(j, n)
		{
			int adj = adjacent(field, i, j);
			if (adj == 3)
			{
				if (field[n * i + j] != '@')
				{
					nfield[n * i + j] = '#';
				}
			}
			else if (adj == 2 && field[n * i + j] == '#')
			{
				nfield[n * i + j] = '#';
			}
		}
	}
	return nfield;
}

int bfs()
{
	ss = state(car, s);
	dist[ss] = 0;
	q.push(ss);
	while (!q.empty())
	{
		state u = q.front();
		q.pop();
		REP(d, 8)
		{
			int nx = u.first.first + dx[d];
			int ny = u.first.second + dy[d];
			if (boundaries(nx, ny) && u.second[n * nx + ny] != '#')
			{
				string nfield = calculate(u, d);
				int x, y;
				x = u.first.first + dx[d];
				y = u.first.second + dy[d];
				state j = make_pair(ii(x, y), nfield);
				if (!dist.count(j))
				{
					dist[j] = dist[u] + 1;
					if (done(j.second))
					{
						return dist[j];
					}
					q.push(j);
				}
			}
		}
	}
	return -1;
}

int main()
{
	while (scanf("%d\n", &n), n)
	{
		dist.clear();
		s.clear();
		while (!q.empty())
		{
			q.pop();
		}
		REP(i, n)
		{
			cin >> temp;
			s += temp;
			REP(j, n)
			if (s[n * i + j] == '@')
			{
				car = ii(i, j);
			}
		}
		if (done(s))
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", bfs());
		}
	}
}
