#include <bits/stdc++.h>

using namespace std;

#define CLR(a, x) memset(a, x, sizeof(a))

typedef long long LL;

const int MAXN = 100005;
const int MOVE[2][5] = {{-1, 0, 1, 0, 0}, {0, 1, 0, -1, 0}};

char maze[10][10];
int win[2][66][66][66], deg[2][66][66][66], emt[66], M, A1, A2, c;

inline int get_x(int r, int c)
{
	return r * 8 + c;
}
inline int row(int x)
{
	return x / 8;
}
inline int col(int x)
{
	return x % 8;
}
bool in_range(int r, int c)
{
	return 0 <= r && r < 8 && 0 <= c && c < 8;
}

void input()
{
	for (int i = 0; i < 8; ++i)
	{
		scanf("%s", maze[i]);
	}
	M = A1 = A2 = -1;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (maze[i][j] == 'M')
			{
				M = get_x(i, j);
			}
			else if (maze[i][j] == 'A')
			{
				if (A1 == -1)
				{
					A1 = get_x(i, j);
				}
				else
				{
					A2 = get_x(i, j);
				}
			}
		}
	}
	CLR(deg, 0);
	c = 0;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (maze[i][j] == '#')
				continue;
			emt[c++] = get_x(i, j);
		}
	}
	CLR(win, -1);
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < c; ++k)
			{
				int x = emt[i], y = emt[j], z = emt[k];
				int r = row(x), c = col(x);
				if (maze[r][c] == 'P')
				{
					if (x == y || x == z)
					{
						win[1][x][y][z] = 1;
					}
					else
					{
						win[0][x][y][z] = 1, win[1][x][y][z] = 0;
					}
				}
				else if (x == y || x == z)
				{
					win[0][x][y][z] = 0, win[1][x][y][z] = 1;
				}
				else
				{
					for (int d = 0; d < 5; ++d)
					{
						int rr = r + MOVE[0][d];
						int cc = c + MOVE[1][d];
						if (!in_range(rr, cc) || maze[rr][cc] == '#')
						{
							continue;
						}
						++deg[0][x][y][z];
					}
					r = row(y), c = col(y);
					int r1 = row(z), c1 = col(z);
					for (int d = 0; d < 5; ++d)
					{
						int rr = r + MOVE[0][d];
						int cc = c + MOVE[1][d];
						if (!in_range(rr, cc) || maze[rr][cc] == '#')
						{
							continue;
						}
						for (int dd = 0; dd < 5; ++dd)
						{
							int rr1 = r1 + MOVE[0][dd];
							int cc1 = c1 + MOVE[1][dd];
							if (!in_range(rr1, cc1) || maze[rr1][cc1] == '#')
							{
								continue;
							}
							++deg[1][x][y][z];
						}
					}
				}
			}
		}
	}
}

struct State
{
	int m, a1, a2, player;
	State(int m = 0, int a1 = 0, int a2 = 0, int player = 0)
			: m(m), a1(a1), a2(a2), player(player)
	{
	}
};

void solve()
{
	queue<State> q;
	for (int i = 0; i < c; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			for (int k = 0; k < c; ++k)
			{
				int x = emt[i], y = emt[j], z = emt[k];
				if (win[0][x][y][z] != -1)
				{
					q.push(State(x, y, z, 0));
				}
				if (win[1][x][y][z] != -1)
				{
					q.push(State(x, y, z, 1));
				}
			}
		}
	}
	int c_m = 26, c_a1 = 25, c_a2 = 25, c_p = 0;
	while (q.size())
	{
		State t = q.front();
		q.pop();
		int p = t.player, m = t.m, a1 = t.a1, a2 = t.a2;
		if (p == 1)
		{
			int r = row(m), c = col(m);
			assert(win[p][m][a1][a2] != -1);
			if (win[p][m][a1][a2] == 0)
			{
				for (int d = 0; d < 5; ++d)
				{
					int rr = r + MOVE[0][d];
					int cc = c + MOVE[1][d];
					if (!in_range(rr, cc) || maze[rr][cc] == '#')
					{
						continue;
					}
					int y = get_x(rr, cc);
					assert(win[p ^ 1][a1][a2] != 0);
					if (win[p ^ 1][y][a1][a2] == -1)
					{
						win[p ^ 1][y][a1][a2] = 1;
						q.push(State(y, a1, a2, p ^ 1));
					}
				}
			}
			else if (win[p][m][a1][a2] == 1)
			{
				for (int d = 0; d < 5; ++d)
				{
					int rr = r + MOVE[0][d];
					int cc = c + MOVE[1][d];
					if (!in_range(rr, cc) || maze[rr][cc] == '#')
					{
						continue;
					}
					int y = get_x(rr, cc);
					if (win[p ^ 1][y][a1][a2] == -1)
					{
						--deg[p ^ 1][y][a1][a2];
						if (deg[p ^ 1][y][a1][a2] == 0)
						{
							q.push(State(y, a1, a2, p ^ 1));
							win[p ^ 1][y][a1][a2] = 0;
						}
					}
				}
			}
		}
		else
		{
			int r1 = row(a1), c1 = col(a1);
			int r2 = row(a2), c2 = col(a2);
			for (int d = 0; d < 5; ++d)
			{
				int rr1 = r1 + MOVE[0][d];
				int cc1 = c1 + MOVE[1][d];
				if (!in_range(rr1, cc1) || maze[rr1][cc1] == '#')
				{
					continue;
				}
				int y = get_x(rr1, cc1);
				for (int dd = 0; dd < 5; ++dd)
				{
					int rr2 = r2 + MOVE[0][dd];
					int cc2 = c2 + MOVE[1][dd];
					if (!in_range(rr2, cc2) || maze[rr2][cc2] == '#')
					{
						continue;
					}
					int z = get_x(rr2, cc2);
					if (win[p][m][a1][a2] == 0)
					{
						assert(win[p ^ 1][m][y][z] != 0);
						if (win[p ^ 1][m][y][z] == -1)
						{
							win[p ^ 1][m][y][z] = 1;
							q.push(State(m, y, z, p ^ 1));
						}
					}
					else if (win[p ^ 1][m][y][z] == -1)
					{
						--deg[p ^ 1][m][y][z];
						if (deg[p ^ 1][m][y][z] == 0)
						{
							win[p ^ 1][m][y][z] = 0;
							q.push(State(m, y, z, p ^ 1));
						}
					}
				}
			}
		}
	}
	if (win[0][M][A1][A2] == 1)
	{
		puts("You can escape.");
	}
	else if (win[0][M][A1][A2] == 0)
	{
		puts("You are eliminated.");
	}
	else
	{
		puts("You are trapped in the Matrix.");
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		input();
		solve();
	}
	return 0;
}
