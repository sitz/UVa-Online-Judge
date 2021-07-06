#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

#define UNDEFINE -1
#define WHITE 0
#define V2 1
#define V3 2
#define H2 3
#define H3 4
#define PLUS 0
#define MINUS 1

#define SOLVED 2
#define MOVABLE 1
#define FAILED 0

int block_len[] = {2, 2, 3, 2, 3};
int direc[] = {1, -1};
int dx[] = {1, 0, 0, 1, 1};
int dy[] = {0, 1, 1, 0, 0};

class state
{
public:
	vector<short> p[5];//pos
	short m[6][6];
	int cnt;
	void print();
	void put(int, int, int);
	int is_movable(int d, int type, int me);
	bool operator<(const state &a) const
	{
		rep(i, 6) rep(j, 6) if (m[i][j] != a.m[i][j])
		{
			return m[i][j] < a.m[i][j];
		}
		return false;
	}
};
void state::print()
{
	puts("begin");
	cout << "now " << cnt << endl;
	rep(i, 6)
	{
		rep(j, 6)
		{
			if (m[i][j] == -1)
			{
				putchar('*');
			}
			else
			{
				cout << m[i][j];
			}
		}
		cout << endl;
	}
	puts("end");
}

void state::put(int type, int x, int y)
{
	rep(i, block_len[type]) m[y + i * dy[type]][x + i * dx[type]] = type;
}

//true can move
//false not solve
//x,y len=length to move
int state::is_movable(int d, int type, int me)
{
	int x = p[type][me] % 6, y = p[type][me] / 6;
	int nex = x + direc[d] * dx[type], ney = y + direc[d] * dy[type];
	if (d == MINUS)
	{
		nex = x + -dx[type], ney = y - dy[type];
	}
	else if (d == PLUS)
	{
		nex = x + (block_len[type]) * dx[type];
		ney = y + (block_len[type]) * dy[type];
	}
	if (ney < 0 || ney >= 6 || nex < 0)
	{
		return FAILED;
	}
	if (nex >= 6)
	{
		if (type == WHITE)
		{
			return SOLVED;
		}
		else
		{
			return FAILED;
		}
	}
	if (m[ney][nex] != UNDEFINE)
	{
		return FAILED;
	}
	//actual move
	if (d == MINUS)
	{
		m[ney][nex] = type;
		m[y + (block_len[type] - 1) * dy[type]][x + (block_len[type] - 1) * dx[type]] = UNDEFINE;
	}
	else if (d == PLUS)
	{
		m[y][x] = UNDEFINE;
		m[ney][nex] = type;
	}
	p[type][me] = (y + dy[type] * direc[d]) * 6 + x + dx[type] * direc[d];
	return MOVABLE;
}

int bfs(state &ini)
{
	state now, tmp;
	queue<state> Q;
	set<state> S;
	S.insert(ini);
	Q.push(ini);
	while (!Q.empty())
	{
		now = Q.front();
		Q.pop();
		rep(i, 5)//type
		{
			rep(j, now.p[i].size())
			{
				rep(k, 2)//direc
				{
					tmp = now;
					tmp.cnt++;
					while (true)
					{
						int val = tmp.is_movable(k, i, j);
						if (val == SOLVED)
						{
							return now.cnt + 1;
						}
						else if (val == MOVABLE)
							;
						else
						{
							break;
						}
						if (S.find(tmp) == S.end())
						{
							Q.push(tmp), S.insert(tmp);
						}
					}
				}
			}
		}
	}
	return -1;
}

main()
{
	int te, tc = 1;
	scanf("%d", &te);
	while (te--)
	{
		state ini;
		ini.cnt = 0;
		rep(i, 6) rep(j, 6) ini.m[i][j] = UNDEFINE;
		int x, y;
		scanf("%d%d", &y, &x);
		ini.p[WHITE].push_back(x + y * 6);
		ini.put(WHITE, x, y);
		REP(i, 1, 5)
		{
			int num;
			scanf("%d", &num);
			rep(j, num)
			{
				scanf("%d%d", &y, &x);
				ini.put(i, x, y);
				ini.p[i].push_back(x + y * 6);
			}
		}
		//ini.print();
		int ans = bfs(ini);
		printf("The minimal number of moves to solve puzzle %d is %d.\n", tc++, ans);
	}
	return false;
}
