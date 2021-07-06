#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define pb push_back
#define mp make_pair

typedef long long lld;

#define INF 0xfffffff

struct Node
{
	int flag, val, used;
	Node() {}
	Node(int flag0, int val0, int used0) : flag(flag0), val(val0), used(used0) {}
};
Node queue_[400010];

bool is;
int mod, ax, ay, dp[2][100010][2], rear, front, pp[110], qq;
pair<int, pair<int, int>> pre[2][100010][2];

int bfs(int x, int y, int &nx, int &ny)
{
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < mod; j++)
			for (int k = 0; k < 2; k++)
			{
				dp[i][j][k] = INF;
			}
	dp[0][x % mod][0] = 1;
	rear = front = 0;
	queue_[front++] = Node(0, x % mod, 0);
	while (rear != front)
	{
		int flag = queue_[rear].flag;
		int val = queue_[rear].val;
		int used = queue_[rear].used;
		if (!is && flag == 0 && val == 0 && used == 1)
		{
			break;
		}
		if (flag == 1 && val == 0 && used == 1)
		{
			break;
		}
		rear++;
		int tmp = dp[flag][val][used];
		int to1 = (val * 10 + x) % mod;
		int to2 = (val * 10 + y) % mod;
		if (used == 0)
		{
			if (x < y)
			{
				if (dp[0][to1][0] == INF)
				{
					dp[0][to1][0] = tmp + 1;
					queue_[front++] = Node(0, to1, 0);
					pre[0][to1][0] = mp(flag, mp(val, used));
				}
				else if (dp[1][to1][0] == INF)
				{
					dp[1][to1][0] = tmp + 1;
					queue_[front++] = Node(1, to1, 0);
					pre[1][to1][0] = mp(flag, mp(val, used));
				}
				if (dp[0][to2][1] == INF)
				{
					dp[0][to2][1] = tmp + 1;
					queue_[front++] = Node(0, to2, 1);
					pre[0][to2][1] = mp(flag, mp(val, used));
				}
				else if (dp[1][to2][1] == INF)
				{
					dp[1][to2][1] = tmp + 1;
					queue_[front++] = Node(1, to2, 1);
					pre[1][to2][1] = mp(flag, mp(val, used));
				}
			}
			else
			{
				if (dp[0][to2][1] == INF)
				{
					dp[0][to2][1] = tmp + 1;
					queue_[front++] = Node(0, to2, 1);
					pre[0][to2][1] = mp(flag, mp(val, used));
				}
				else if (dp[1][to2][1] == INF)
				{
					dp[1][to2][1] = tmp + 1;
					queue_[front++] = Node(1, to2, 1);
					pre[1][to2][1] = mp(flag, mp(val, used));
				}
				if (dp[0][to1][0] == INF)
				{
					dp[0][to1][0] = tmp + 1;
					queue_[front++] = Node(0, to1, 0);
					pre[0][to1][0] = mp(flag, mp(val, used));
				}
				else if (dp[1][to1][0] == INF)
				{
					dp[1][to1][0] = tmp + 1;
					queue_[front++] = Node(1, to1, 0);
					pre[1][to1][0] = mp(flag, mp(val, used));
				}
			}
		}
		else
		{
			if (dp[0][to2][1] == INF)
			{
				dp[0][to2][1] = tmp + 1;
				queue_[front++] = Node(0, to2, 1);
				pre[0][to2][1] = mp(flag, mp(val, used));
			}
			else if (dp[1][to2][1] == INF)
			{
				dp[1][to2][1] = tmp + 1;
				queue_[front++] = Node(1, to2, 1);
				pre[1][to2][1] = mp(flag, mp(val, used));
			}
		}
	}
	if (dp[0][0][1] == INF)
	{
		return INF;
	}
	int a, b, c;
	a = 0;
	b = 0;
	c = 1;
	nx = 1;
	ny = 0;
	while (dp[a][b][c] != 1)
	{
		if (c == 0)
		{
			nx++;
		}
		else
		{
			ny++;
		}
		int na = pre[a][b][c].X;
		int nb = pre[a][b][c].Y.X;
		int nc = pre[a][b][c].Y.Y;
		a = na;
		b = nb;
		c = nc;
	}
	bool same = false;
	if (dp[0][0][1] <= 6)
	{
		lld now = 0;
		for (int i = 0; i < nx; i++)
		{
			now = now * 10 + x;
		}
		for (int i = 0; i < ny; i++)
		{
			now = now * 10 + y;
		}
		if (now == mod)
		{
			same = true;
		}
	}
	if (same)
	{
		if (dp[1][0][1] == INF)
		{
			return INF;
		}
		a = 1;
		b = 0;
		c = 1;
		nx = 1;
		ny = 0;
		while (dp[a][b][c] != 1)
		{
			if (c == 0)
			{
				nx++;
			}
			else
			{
				ny++;
			}
			int na = pre[a][b][c].X;
			int nb = pre[a][b][c].Y.X;
			int nc = pre[a][b][c].Y.Y;
			a = na;
			b = nb;
			c = nc;
		}
		return dp[1][0][1];
	}
	return dp[0][0][1];
}

void init()
{
	is = false;
	int T = mod;
	qq = 0;
	while (T)
	{
		pp[qq++] = T % 10;
		T /= 10;
	}
	int tmp = 0;
	for (int i = 1; i < qq; i++)
		if (pp[i - 1] != pp[i])
		{
			tmp++;
		}
	if (tmp == 1)
	{
		is = true;
	}
}

int main()
{
	while (scanf("%d", &mod) != EOF)
	{
		if (mod == 0)
		{
			break;
		}
		init();
		int sx, sy, numx, numy;
		int ans = INF;
		for (int x = 1; x <= 9; x++)
		{
			for (int y = 0; y <= 9; y++)
			{
				if (x == y)
				{
					continue;
				}
				int nx, ny;
				int tmp = bfs(x, y, nx, ny);
				if (tmp < ans)
				{
					ans = tmp;
					sx = x;
					sy = y;
					numx = nx;
					numy = ny;
				}
				else if (tmp == ans)
				{
					string old = "";
					old += '0' + sx;
					if (numx > nx)
					{
						old += '0' + sx;
					}
					else
					{
						old += '0' + sy;
					}
					old += '0' + sy;
					string newnew = "";
					newnew += '0' + x;
					if (numx < nx)
					{
						newnew += '0' + x;
					}
					else
					{
						newnew += '0' + y;
					}
					newnew += '0' + y;
					if (newnew < old)
					{
						ans = tmp;
						sx = x;
						sy = y;
						numx = nx;
						numy = ny;
					}
				}
			}
		}
		printf("%d: %d %d %d %d\n", mod, numx, sx, numy, sy);
	}
	return 0;
}
