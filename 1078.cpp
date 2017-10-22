#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> PII;
const int N = 105;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int m, n;
int r1, c1, r2, c2;
int R[N][N];
int D[N][N];
int d[N][N][4][2];

struct Node
{
	int x, y, d, mul;
	Node() { x = y = d = mul = 0; }
	Node(int x, int y, int d, int mul) : x(x), y(y), d(d), mul(mul) {}
	bool operator<(const Node oth) const
	{
		return x < oth.x;
	}
};

bool inRange(int x, int y)
{
	return 0 <= x && x < m && 0 <= y && y < n;
}

int getW(int x, int y, int o)
{
	if (!inRange(x + dx[o], y + dy[o]))
		return 0;
	switch (o)
	{
	case 0:
		return D[x - 1][y];
	case 1:
		return D[x][y];
	case 2:
		return R[x][y - 1];
	case 3:
		return R[x][y];
	}
	while (1)
		;
	return 0;
}

bool up(int &cur, int x)
{
	if (cur == -1 || x < cur)
	{
		cur = x;
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int Tc = 0;
	while (scanf("%d%d%d%d%d%d", &m, &n, &r1, &c1, &r2, &c2) != EOF && m + n + r1 + r2 + c1 + c2)
	{
		printf("Case %d: ", ++Tc);
		r1--;
		r2--;
		c1--;
		c2--;
		rep(i, m)
		{
			rep(j, n - 1)
					scanf("%d", &R[i][j]);
			if (i + 1 == m)
				continue;
			rep(j, n)
					scanf("%d", &D[i][j]);
		}
		memset(d, 0xff, sizeof(d));
		priority_queue<pair<int, Node>> Q;
		rep(o, 4)
		{
			int x = r1 + dx[o];
			int y = c1 + dy[o];
			if (inRange(x, y) && getW(r1, c1, o))
			{
				d[x][y][o][1] = 2 * getW(r1, c1, o);
				Q.push(make_pair(-d[x][y][o][1], Node(x, y, o, 1)));
			}
		}
		if (r1 == r2 && c1 == c2)
		{
			puts("0");
			continue;
		}
		while (!Q.empty())
		{
			int curd = -Q.top().first;
			Node t = Q.top().second;
			Q.pop();
			if (curd != d[t.x][t.y][t.d][t.mul])
				continue;
			int ori = getW(t.x - dx[t.d], t.y - dy[t.d], t.d);
			if (t.mul)
			{
				rep(o, 4)
				{
					int x = t.x + dx[o];
					int y = t.y + dy[o];
					int w = getW(t.x, t.y, o);
					if (!w)
						continue;
					if (o == t.d)
					{
						if (up(d[x][y][o][0], curd + w))
						{
							Q.push(make_pair(-d[x][y][o][0], Node(x, y, o, 0)));
						}
						if (up(d[x][y][o][1], curd + 2 * w))
						{
							Q.push(make_pair(-d[x][y][o][1], Node(x, y, o, 1)));
						}
					}
					else
					{
						if (up(d[x][y][o][1], curd + 2 * w))
						{
							Q.push(make_pair(-d[x][y][o][1], Node(x, y, o, 1)));
						}
					}
				}
			}
			else
			{
				rep(o, 4)
				{
					int x = t.x + dx[o];
					int y = t.y + dy[o];
					int w = getW(t.x, t.y, o);
					if (!w)
						continue;
					if (o == t.d)
					{
						if (up(d[x][y][o][0], curd + w))
						{
							Q.push(make_pair(-d[x][y][o][0], Node(x, y, o, 0)));
						}
						if (up(d[x][y][o][1], curd + 2 * w))
						{
							Q.push(make_pair(-d[x][y][o][1], Node(x, y, o, 1)));
						}
					}
					else
					{
						if (up(d[x][y][o][1], curd + 2 * w + ori))
						{
							Q.push(make_pair(-d[x][y][o][1], Node(x, y, o, 1)));
						}
					}
				}
			}
		}
		int ans = -1;
		rep(o, 4)
		{
			if (d[r2][c2][o][1] != -1)
			{
				up(ans, d[r2][c2][o][1]);
			}
		}
		if (ans == -1)
		{
			puts("Impossible");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
}
