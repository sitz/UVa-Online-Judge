#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

typedef long long ll;

#define TOP 0
#define FRONT 1
#define BOTTOM 2
#define BACK 3
#define LEFT 4
#define RIGHT 5

//table for rotate
int table[12][12] =
		{
				TOP, FRONT, BOTTOM, BACK, 0, 1, 0, 1, 0, 1, 0, 1,
				TOP, FRONT, BOTTOM, BACK, 2, 3, 2, 3, 2, 3, 2, 3,
				TOP, BACK, BOTTOM, FRONT, 0, 1, 0, 1, 0, 1, 0, 1,
				TOP, BACK, BOTTOM, FRONT, 2, 3, 2, 3, 2, 3, 2, 3,

				TOP, LEFT, BOTTOM, RIGHT, 0, 2, 0, 2, 3, 1, 0, 2,
				TOP, LEFT, BOTTOM, RIGHT, 1, 3, 1, 3, 2, 0, 1, 3,
				TOP, RIGHT, BOTTOM, LEFT, 0, 2, 0, 2, 3, 1, 0, 2,
				TOP, RIGHT, BOTTOM, LEFT, 1, 3, 1, 3, 2, 0, 1, 3,

				FRONT, LEFT, BACK, RIGHT, 0, 2, 2, 3, 3, 1, 1, 0,
				FRONT, LEFT, BACK, RIGHT, 1, 3, 0, 1, 2, 0, 3, 2,
				FRONT, RIGHT, BACK, LEFT, 0, 2, 1, 0, 3, 1, 2, 3,
				FRONT, RIGHT, BACK, LEFT, 1, 3, 3, 2, 2, 0, 0, 1,
};

int table2[12][5] =
		{
				LEFT, 2, 0, 3, 1,
				RIGHT, 1, 3, 0, 2,
				LEFT, 1, 3, 0, 2,
				RIGHT, 2, 0, 3, 1,

				BACK, 2, 0, 3, 1,
				FRONT, 1, 3, 0, 2,
				BACK, 1, 3, 0, 2,
				FRONT, 2, 0, 3, 1,

				TOP, 2, 0, 3, 1,
				BOTTOM, 1, 3, 0, 2,
				TOP, 1, 3, 0, 2,
				BOTTOM, 2, 0, 3, 1,
};

int getp[6][4] =
		{
				0, 2, 1, 3,
				0, 2, 1, 3,
				0, 2, 1, 3,
				3, 1, 2, 0,
				2, 3, 0, 1,
				1, 0, 3, 2,
};

class state
{
public:
	char in[6][4];
	int cnt;
	ll val;
	ll convert();

	bool operator<(const state &a) const
	{
		return val < a.val;
	}
};

ll state::convert()
{
	val = 0;
	rep(i, 6)
	{
		rep(j, 4)
		{
			val = (val << 2);
			val += in[i][j];
		}
	}
	return val;
}

int make_all(state, bool, set<state> &S, vector<state> &a);
vector<state> dummy;

inline void rotate(int a, state &now)
{
	static int in[4];
	rep(i, 4) in[i] = table[a][i];
	char tmp[2] = {now.in[in[0]][table[a][4]],
								 now.in[in[0]][table[a][5]]};
	rep(i, 3)
	{
		now.in[in[i]][table[a][4 + i * 2]] = now.in[in[i + 1]][table[a][4 + (i + 1) * 2]];
		now.in[in[i]][table[a][4 + i * 2 + 1]] = now.in[in[i + 1]][table[a][4 + (i + 1) * 2 + 1]];
	}
	now.in[in[3]][table[a][10]] = tmp[0];
	now.in[in[3]][table[a][11]] = tmp[1];
	rep(i, 4) in[i] = now.in[table2[a][0]][table2[a][i + 1]];
	rep(i, 4) now.in[table2[a][0]][i] = in[i];
}

bool cangoal(state &now, vector<state> &in)
{
	rep(k, in.size())
	{
		bool isok = true;
		rep(i, 6) rep(j, 4) if (now.in[i][j] != in[k].in[i][j])
		{
			isok = false;
		}
		if (isok)
		{
			return true;
		}
	}
	return false;
}

bool isin(state &next, set<state> &S)
{
	int tmp = make_all(next, true, S, dummy);
	if (tmp == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

inline void make(state &in, queue<state> &Q, set<state> &S)
{
	rep(i, 6)
	{
		state next = in;
		next.cnt++;
		rotate(i * 2, next);
		next.convert();
		if (isin(next, S))
		{
			S.insert(next);
			Q.push(next);
		}
	}
}

void bfs2(state ini, set<state> &S)
{
	int tmp = 0;
	queue<state> Q;
	Q.push(ini);
	while (!Q.empty())
	{
		state now = Q.front();
		Q.pop();
		//if (now.cnt != tmp)tmp=now.cnt,cout << S.size() <<" " << tmp<<endl;
		if (now.cnt >= 7)
		{
			return;
		}
		make(now, Q, S);
	}
}

int bfs(state ini, vector<state> &goal, set<state> &S2)
{
	queue<state> Q;
	set<state> S;
	Q.push(ini);
	S.insert(ini);
	while (!Q.empty())
	{
		state now = Q.front();
		Q.pop();
		if (cangoal(now, goal))
		{
			return now.cnt;
		}
		int tmp = make_all(now, true, S2, dummy);
		if (tmp != -1)
		{
			return tmp;
		}
		if (now.cnt == 6)
		{
			continue;
		}
		make(now, Q, S);
	}
	return 14;
	return -1;
}

main()
{
	state goal;
	static int getinp[] = {TOP, FRONT, RIGHT, BOTTOM, BACK, LEFT};
	rep(i, 4)
	{
		goal.in[TOP][i] = 'W';
		goal.in[BOTTOM][i] = 'B';
		goal.in[FRONT][i] = 'R';
		goal.in[BACK][i] = 'O';
		goal.in[RIGHT][i] = 'Y';
		goal.in[LEFT][i] = 'G';
	}
	goal.cnt = 0;
	vector<state> allgoal;
	set<state> S;
	bfs2(goal, S);
	make_all(goal, false, S, allgoal);
	int te;
	cin >> te;
	while (te--)
	{
		state in;
		in.cnt = 0;
		rep(i, 6)
		{
			rep(j, 4)
			{
				cin >> in.in[getinp[i]][getp[getinp[i]][j]];
			}
		}
		cout << bfs(in, allgoal, S) << endl;
	}
}

int make_all(state now, bool checkSet, set<state> &S,
						 vector<state> &a)
{
	set<state>::iterator itr;
	rep(i, 4)
	{
		rep(j, 4)
		{
			//ret.push_back(now);
			now.convert();
			if (checkSet)
			{
				itr = S.find(now);
				if (itr != S.end())
				{
					return now.cnt + itr->cnt;
				}
			}
			else
			{
				a.push_back(now);
			}
			rotate(8, now);
			rotate(9, now);
		}
		rotate(0, now);
		rotate(1, now);
	}
	rotate(4, now);
	rotate(5, now);
	rep(i, 4)
	{
		//    ret.push_back(now);
		now.convert();
		if (checkSet)
		{
			itr = S.find(now);
			if (itr != S.end())
			{
				return now.cnt + itr->cnt;
			}
		}
		else
		{
			a.push_back(now);
		}
		rotate(8, now);
		rotate(9, now);
	}
	rep(i, 2)
	{
		rotate(4, now);
		rotate(5, now);
	}
	rep(i, 4)
	{
		//    ret.push_back(now);
		now.convert();
		if (checkSet)
		{
			itr = S.find(now);
			if (itr != S.end())
			{
				return now.cnt + itr->cnt;
			}
		}
		else
		{
			a.push_back(now);
		}
		rotate(8, now);
		rotate(9, now);
	}
	return -1;
}
