#include <bits/stdc++.h>

using namespace std;

// can walk on edge of rect
// split pt(x, y) to 3x3 sq.; 2 rect shared common edge will proc gap

#define MAXN 64
#define MAXW 512

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
const int ddx[] = {1, 1, -1, -1};
const int ddy[] = {1, -1, 1, -1};

int g[MAXW][MAXW], dist[MAXW][MAXW][4];
map<int, int> RX, RY;

int relbl_map(map<int, int> &R)
{
	int sz = 1;
	for (map<int, int>::iterator it = R.begin(); it != R.end(); it++)
	{
		it->second = sz++;
	}
	return sz;
}

void fill_map(int lx, int ly, int rx, int ry, int val)
{
	int tx, ty, vx, vy;
	int a = RX[lx] * 3 + 2;
	int b = RX[rx] * 3;
	int p = RY[ly] * 3 + 2;
	int q = RY[ry] * 3;
	for (int i = a; i <= b; i++)
	{
		for (int j = p; j <= q; j++)
		{
			g[i][j] = val;
			// fill gap
			for (int k = 0; k < 4; k++)
			{
				tx = i + dx[k] * 2, ty = j + dy[k] * 2;
				vx = i + dx[k] * 1, vy = j + dy[k] * 1;
				if (g[tx][ty] == val)
				{
					g[vx][vy] = val;
				}
				tx = i + ddx[k] * 2, ty = j + ddy[k] * 2;
				vx = i + ddx[k] * 1, vy = j + ddy[k] * 1;
				if (g[tx][ty] == val)
				{
					g[vx][vy] = val;
				}
			}
		}
	}
}

pair<int, int> fill_pt_map(int lx, int ly, int val)
{
	int a = RX[lx] * 3 + 1;
	int b = RY[ly] * 3 + 1;
	g[a][b] = val;
	return make_pair(a, b);
}

void bfs(int sx, int sy, int ex, int ey)
{
	pair<int, int> st, ed;
	int x, y, d, tx, ty;
	queue<int> X, Y, D;

	st = fill_pt_map(sx, sy, 2);
	ed = fill_pt_map(ex, ey, 3);
	memset(dist, 63, sizeof(dist));
	int INF = dist[0][0][0];
	for (int i = 0; i < 4; i++)
	{
		X.push(st.first), Y.push(st.second), D.push(i);
		dist[st.first][st.second][i] = 0;
	}

	int ret = INF;
	while (!X.empty())
	{
		x = X.front();
		X.pop();
		y = Y.front();
		Y.pop();
		d = D.front();
		D.pop();
		if (dist[x][y][d] >= ret)
		{
			continue;
		}
		for (int i = 0; i < 4; i++)
		{
			int w = (d != i);
			tx = x + dx[i], ty = y + dy[i];
			if (tx < 0 || ty < 0 || tx >= MAXW || ty >= MAXW || g[tx][ty] == 1)
			{
				continue;
			}
			if (dist[tx][ty][i] > dist[x][y][d] + w)
			{
				dist[tx][ty][i] = dist[x][y][d] + w;
				if (tx == ed.first && ty == ed.second)
				{
					ret = min(ret, dist[tx][ty][i]);
					continue;
				}
				X.push(tx);
				Y.push(ty);
				D.push(i);
			}
		}
	}
	printf("%d\n", ret == INF ? -1 : ret);
}

int main()
{
	int sx, sy, ex, ey, N, lx[MAXN], ly[MAXN], rx[MAXN], ry[MAXN];
	while (scanf("%d%d%d%d", &sx, &sy, &ex, &ey) == 4)
	{
		if (sx == 0 && sy == 0 && ex == 0 && ey == 0)
		{
			return 0;
		}
		RX.clear();
		RY.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d%d%d%d", &lx[i], &ly[i], &rx[i], &ry[i]);
			if (lx[i] > rx[i])
			{
				swap(lx[i], rx[i]);
			}
			if (ly[i] > ry[i])
			{
				swap(ly[i], ry[i]);
			}
			RX[lx[i]] = RX[rx[i]] = 1;
			RY[ly[i]] = RY[ry[i]] = 1;
		}
		RX[sx] = RX[ex] = 1;
		RY[sy] = RY[ey] = 1;
		relbl_map(RX);
		relbl_map(RY);
		memset(g, 0, sizeof(g));
		for (int i = 0; i < N; i++)
		{
			fill_map(lx[i], ly[i], rx[i], ry[i], 1);
		}
		bfs(sx, sy, ex, ey);
	}
	return 0;
}
