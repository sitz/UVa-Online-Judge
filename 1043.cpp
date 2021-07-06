#include <bits/stdc++.h>

using namespace std;

int dist[2010][2010];
bool inq[2010][2010];
int Q[2][2010 * 2010];
int forb[2010][2010][4];
int l[2], r[2];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int T;
bool isin(int x, int y)
{
	return x >= 0 && x < T && y >= 0 && y < T;
}
void push(int no, int x, int y)
{
	if (inq[x][y])
	{
		return;
	}
	inq[x][y] = 1;
	Q[no][r[no]++] = x * T + y;
}
int srcx, srcy, destx, desty;
int bfs()
{
	int i, j, dir;
	for (i = 0; i < T; i++)
		for (j = 0; j < T; j++)
		{
			dist[i][j] = -1, inq[i][j] = 0;
		}
	l[0] = l[1] = r[0] = r[1] = 0;
	int now = 0, then = 1;
	push(0, srcx, srcy);
	int cross = 0;
	while (1)
	{
		for (; l[now] < r[now]; l[now]++)
		{
			int nx = Q[now][l[now]] / T, ny = Q[now][l[now]] % T;
			//printf("%d : %d %d\n",cross,nx,ny);
			dist[nx][ny] = cross;
			if (nx == destx && ny == desty)
			{
				goto gotit;
			}
			for (dir = 0; dir < 4; dir++)
			{
				int tx = nx + dx[dir], ty = ny + dy[dir];
				if (!isin(tx, ty))
				{
					continue;
				}
				if (dir == 0 || dir == 3)
				{
					if (!forb[nx][ny][dir])
					{
						push(now, tx, ty);
					}
					else
					{
						push(then, tx, ty);
					}
				}
				else
				{
					if (!forb[tx][ty][(dir + 2) % 4])
					{
						push(now, tx, ty);
					}
					else
					{
						push(then, tx, ty);
					}
				}
			}
		}
		cross++;
		now ^= 1, then ^= 1;
	}
gotit:
	return cross;
}

int num[10000], order[10000];

int main()
{
	int N, i, j, tcas = 1;
	while (scanf("%d", &N) && N)
	{
		for (i = 0; i < 4 * N + 4; i += 2)
		{
			scanf("%d%d", &num[i], &num[i + 1]);
			order[i] = num[i], order[i + 1] = num[i + 1];
		}
		int tot = 4 * N + 4;
		sort(order, order + tot);
		T = unique(order, order + tot) - order;
		T++;
		for (i = 0; i < tot; i++)
		{
			num[i] = lower_bound(order, order + T - 1, num[i]) - order + 1;
		}
		memset(forb, 0, sizeof(forb));
		for (i = 0; i < 4 * N; i += 4)
		{
			int x1 = num[i], y1 = num[i + 1], x2 = num[i + 2], y2 = num[i + 3];
			if (y1 > y2)
			{
				swap(y1, y2);
			}
			if (x1 > x2)
			{
				swap(x1, x2);
			}
			//printf("%d %d --- %d %d\n",x1,y1,x2,y2);
			if (x1 == x2)
				for (j = y1 + 1; j <= y2; j++)
				{
					forb[x1][j][3] = 1;
				}
			else if (y1 == y2)
				for (j = x1; j < x2; j++)
				{
					forb[j][y1][0] = 1;
				}
		}
		srcx = num[i], srcy = num[i + 1], destx = num[i + 2], desty = num[i + 3];
		int res = bfs();
		printf("City %d\nPeter has to cross %d streets\n", tcas++, res);
	}
}
