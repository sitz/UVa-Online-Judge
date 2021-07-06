#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define TOP 0
#define FRONT 1
#define RIGHT 2
#define BACK 3
#define LEFT 4
#define BOTTOM 5

#define NOMI true
#define NONOMI false
#define ROTATE_SOUTH 0
#define ROTATE_NORTH 1
#define ROTATE_EAST 2
#define ROTATE_WEST 3
#define MAX (1 << 26);
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r_table[4][6] =
		{
				{BACK, TOP, RIGHT, BOTTOM, LEFT, FRONT},
				{FRONT, BOTTOM, RIGHT, TOP, LEFT, BACK},
				{LEFT, FRONT, TOP, BACK, BOTTOM, RIGHT},
				{RIGHT, FRONT, BOTTOM, BACK, TOP, LEFT}};

class state
{
public:
	bool m[4][4];
	bool dice[6];
	int px, py;
	int cnt;
	int me;
	bool is_clear()
	{
		rep(i, 6) if (dice[i] == NONOMI)
		{
			return false;
		}
		return true;
	}
	void move(int d)
	{
		bool tmp[6];
		rep(i, 6) tmp[i] = dice[i];
		rep(i, 6) dice[i] = tmp[r_table[d][i]];
		px = px + dx[d];
		py = py + dy[d];
		if (m[py][px] == NOMI && dice[BOTTOM] == NOMI)
			;
		else if (m[py][px] == NOMI)
		{
			m[py][px] = NONOMI, dice[BOTTOM] = NOMI;
		}
		else if (dice[BOTTOM] == NOMI)
		{
			m[py][px] = NOMI, dice[BOTTOM] = NONOMI;
		}
		me = 0;
		rep(i, 6)
		{
			me = me << 1;
			if (dice[i])
			{
				me += 1;
			}
		}
		rep(i, 4)
		{
			rep(j, 4)
			{
				me = (me << 1);
				if (m[i][j])
				{
					me += 1;
				}
			}
		}
	}
	bool operator<(const state &a) const
	{
		//    if ( px != a.px)return px < a.px;
		//if ( py != a.py)return py < a.py;
		if (me != a.me)
		{
			return me < a.me;
		}
		return false;
	}
};

int solve(state ini)
{
	set<int> S[4][4];
	queue<state> Q;
	Q.push(ini);
	S[ini.py][ini.px].insert(ini.me);
	while (!Q.empty())
	{
		state now = Q.front();
		Q.pop();
		rep(i, 4)
		{
			state next = now;
			int nex = next.px + dx[i], ney = next.py + dy[i];
			if (nex < 0 || ney < 0 || nex >= 4 || ney >= 4)
			{
				continue;
			}
			next.move(i);
			next.cnt++;
			if (next.is_clear())
			{
				return next.cnt;
			}
			if (S[next.py][next.px].find(next.me) == S[next.py][next.px].end())
			{
				Q.push(next);
				S[next.py][next.px].insert(next.me);
			}
		}
	}
	return -1;
}

main()
{
	int te;
	state ini;
	char m[4][5];
	cin >> te;
	while (te--)
	{
		state ini;
		rep(i, 4) cin >> m[i];
		rep(i, 6) ini.dice[i] = NONOMI;
		ini.cnt = 0;
		rep(i, 4)
		{
			rep(j, 4)
			{
				if (m[i][j] == 'D')
				{
					ini.px = j, ini.py = i, ini.m[i][j] = NONOMI;
				}
				else if (m[i][j] == 'X')
				{
					ini.m[i][j] = NOMI;
				}
				else
				{
					ini.m[i][j] = NONOMI;
				}
			}
		}
		int ans = solve(ini);
		if (ans != -1)
		{
			cout << solve(ini) << endl;
		}
		else
		{
			puts("impossible");
		}
	}
}
