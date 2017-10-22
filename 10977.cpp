#include <bits/stdc++.h>

using namespace std;

#define maxn 200

int R, C, B[maxn + 3][maxn + 3];
char Fg[maxn + 3][maxn + 3];

struct ss
{
	int r, c;
	int time;
};
queue<ss> Q;

void Recur(int x, int y, int limit)
{
	int i, j, rl, cl, d, k = limit * limit, q;
	int rf, cf;
	rl = x - limit;
	if (rl < 1)
		rl = 1;
	rf = x + limit;
	if (rf > R)
		rf = R;
	cl = y - limit;
	if (cl < 1)
		cl = 1;
	cf = y + limit;
	if (cf > C)
		cf = C;
	for (i = rl; i <= rf; i++)
	{
		d = i - x;
		d *= d;
		for (j = cl; j <= cf; j++)
		{
			q = j - y;
			q *= q;
			if (d + q <= k)
				B[i][j] = 1;
		}
	}
	j = y + limit;
	if (j <= C)
		B[x][j] = 1;
	j = y - limit;
	if (j > 0)
		B[x][j] = 1;
	j = x - limit;
	if (j > 0)
		B[j][y] = 1;
	j = x + limit;
	if (j <= R)
		B[j][y] = 1;
}

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int BFS()
{
	ss t, d;
	int i, nx, ny;
	if (B[1][1])
		return -1;
	t.r = 1;
	t.c = 1;
	t.time = 0;
	Q.push(t);
	Fg[1][1] = 1;
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		for (i = 0; i < 4; i++)
		{
			nx = t.r + X[i];
			ny = t.c + Y[i];
			if (nx > R || nx < 1 || ny > C || ny < 1)
				continue;
			if (Fg[nx][ny] || B[nx][ny])
				continue;
			if (nx == R && ny == C)
				return t.time + 1;
			d.r = nx;
			d.c = ny;
			d.time = t.time + 1;
			Fg[nx][ny] = 1;
			Q.push(d);
		}
	}
	return -1;
}

void Cal()
{
	int i, j;
	if (R == 1 && C == 1)
	{
		if (B[1][1] == 1)
		{
			printf("Impossible.\n");
			return;
		}
		printf("0\n");
		return;
	}
	if (B[R][C])
	{
		printf("Impossible.\n");
		return;
	}
	j = BFS();
	if (j < 0)
		printf("Impossible.\n");
	else
		printf("%d\n", j);
}

void Free()
{
	int i, j;
	for (i = 1; i <= R; i++)
		for (j = 1; j <= C; j++)
		{
			B[i][j] = 0;
			Fg[i][j] = 0;
		}
	while (!Q.empty())
		Q.pop();
}

int main()
{
	int n, i, x, y;
	while (scanf("%d%d", &R, &C) == 2)
	{
		if (!R && !C)
			break;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d", &x, &y);
			B[x][y] = 1;
		}
		scanf("%d", &n);
		while (n--)
		{
			scanf("%d%d%d", &x, &y, &i);
			Recur(x, y, i);
		}
		Cal();
		Free();
	}
	return 0;
}
