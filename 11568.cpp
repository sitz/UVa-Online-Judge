#include <bits/stdc++.h>

using namespace std;

#define MAX 10
#define REP(i, n) for (int i = 0; i < (int)n; i++)
#define EAST 0
#define NORTH 1
#define SOUTH 2
#define WEST 3

static const int dx[5] = {1, 0, 0, -1, 0};
static const int dy[5] = {0, -1, 1, 0, 0};
static const char direction[5] = {'E', 'N', 'S', 'W', 'X'};

class Robot
{
public:
	int x, y, d;

	void rotate()
	{
		if (d == EAST)
			d = SOUTH;
		else if (d == NORTH)
			d = EAST;
		else if (d == WEST)
			d = NORTH;
		else if (d == SOUTH)
			d = WEST;
	}

	void move(int px, int py, int Tx, int Ty, char G[MAX][MAX], int color_row[MAX][MAX], int color_col[MAX][MAX])
	{
		if (px == x && color_col[py][px] == color_col[y][px])
		{
			if (py < y)
			{
				d = NORTH;
				y--;
			}
			else
			{
				d = SOUTH;
				y++;
			}
		}
		else if (py == y && color_row[py][px] == color_row[py][x])
		{
			if (px < x)
			{
				d = WEST;
				x--;
			}
			else
			{
				d = EAST;
				x++;
			}
		}
		else
		{// normal wondering
			int nx = x + dx[d];
			int ny = y + dy[d];
			while (G[ny][nx] == '#' || ny == Ty && nx == Tx)
			{
				rotate();
				nx = x + dx[d];
				ny = y + dy[d];
			}
			x = nx;
			y = ny;
		}
		assert(G[y][x] != '#');
	}
};

class State
{
public:
	int x, y;
	Robot R[2];
	string path;

	State() {}
	State(int x, int y, Robot r1, Robot r2, string path) : x(x), y(y), path(path)
	{
		R[0] = r1;
		R[1] = r2;
	}

	bool operator<(const State &t) const
	{
		if (x != t.x)
			return x < t.x;
		if (y != t.y)
			return y < t.y;
		REP(r, 2)
		{
			if (R[r].x != t.R[r].x)
				return R[r].x < t.R[r].x;
			if (R[r].y != t.R[r].y)
				return R[r].y < t.R[r].y;
			if (R[r].d != t.R[r].d)
				return R[r].d < t.R[r].d;
		}
		return false;
	}
};

int N;
char G[MAX][MAX];
int color_row[MAX][MAX], color_col[MAX][MAX];

int x, y, Tx, Ty;
Robot R[2];

map<State, bool> V;

int bfs()
{
	queue<State> Q;
	V = map<State, bool>();

	State s = State(x, y, R[0], R[1], "");

	V[s] = true;
	Q.push(s);

	State u, v;
	int nx, ny;
	string path;

	while (!Q.empty())
	{
		u = Q.front();
		Q.pop();

		if (u.x == Tx && u.y == Ty)
		{
			cout << u.path << endl;
			return u.path.size();
		}

		for (int d = 0; d < 5; d++)
		{
			nx = u.x + dx[d];
			ny = u.y + dy[d];
			if (G[ny][nx] == '#' || nx == u.R[0].x && ny == u.R[0].y || nx == u.R[1].x && ny == u.R[1].y)
				continue;

			v = u;
			v.x = nx;
			v.y = ny;

			REP(r, 2)
			v.R[r].move(v.x, v.y, Tx, Ty, G, color_row, color_col);

			if (!(v.x == Tx && v.y == Ty) && (v.x == v.R[0].x && v.y == v.R[0].y || v.x == v.R[1].x && v.y == v.R[1].y))
				continue;
			if (V[v])
				continue;

			V[v] = true;
			v.path += direction[d];
			Q.push(v);
		}
	}
	return -1;
}

void compute()
{
	if (bfs() == -1)
		cout << "You can't escape..." << endl;
}

void setColor()
{
	REP(y, N)
	REP(x, N) { color_row[y][x] = color_col[y][x] = -1; }
	REP(y, N)
	{
		int color = 0;
		REP(x, N)
		{
			if (G[y][x] == '#' || y == Ty && x == Tx)
			{
				color_row[y][x] = -1;
				color++;
			}
			else
				color_row[y][x] = color;
		}
	}
	REP(x, N)
	{
		int color = 0;
		REP(y, N)
		{
			if (G[y][x] == '#' || y == Ty && x == Tx)
			{
				color_col[y][x] = -1;
				color++;
			}
			else
				color_col[y][x] = color;
		}
	}
}

int main()
{
	string line;
	while (cin >> N && N)
	{
		getline(cin, line);
		int nrobot = 0;
		for (int i = 0; i < N; i++)
		{
			getline(cin, line);
			for (int j = 0; j < N; j++)
			{
				G[i][j] = line[j];
				if (G[i][j] == 'X')
				{
					y = i;
					x = j;
					G[i][j] = ' ';
				}
				else if (G[i][j] == 'T')
				{
					Ty = i;
					Tx = j;
					G[i][j] = ' ';
				}
				else if (G[i][j] == '#' || G[i][j] == ' ')
				{
				}
				else
				{
					R[nrobot].y = i;
					R[nrobot].x = j;
					if (G[i][j] == 'E')
						R[nrobot].d = EAST;
					else if (G[i][j] == 'N')
						R[nrobot].d = NORTH;
					else if (G[i][j] == 'S')
						R[nrobot].d = SOUTH;
					else if (G[i][j] == 'W')
						R[nrobot].d = WEST;
					G[i][j] = ' ';
					nrobot++;
				}
			}
		}
		assert(nrobot == 2);
		setColor();
		compute();
	}
	return 0;
}
