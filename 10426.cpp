#include <bits/stdc++.h>

using namespace std;

#define maxn 17
#define INF 999999

int R, C, mx, my;
int X[] = {1, 2, -1, -2, -1, -2, 1, 2};
int Y[] = {-2, -1, -2, 1, 2, -1, 2, 1};

struct ss
{
	int with;
	int without;
};
ss B[4][maxn][maxn];
ss P[4];
struct xx
{
	int r, c, t;
	char d;
};
queue<xx> Q;

void Ini()
{
	int k, j;
	for (j = 1; j <= R; j++)
	{
		for (k = 1; k <= C; k++)
		{
			B[0][j][k].with = B[0][j][k].without = INF;
			B[1][j][k].with = B[1][j][k].without = INF;
			B[2][j][k].with = B[2][j][k].without = INF;
			B[3][j][k].with = B[3][j][k].without = INF;
		}
	}
}
void BFS(int r, int c, int ind)
{
	xx t, d;
	int nx, ny, i, f;
	t.r = r;
	t.c = c;
	t.d = t.t = 0;
	B[ind][r][c].with = B[ind][r][c].without = 0;
	Q.push(t);
	while (!Q.empty())
	{
		t = Q.front();
		Q.pop();
		for (i = 0; i < 8; i++)
		{
			nx = X[i] + t.r;
			ny = Y[i] + t.c;
			f = 0;
			if (nx > R || nx < 1 || ny > C || ny < 1)
				continue;
			if (t.d == 0)
			{
				if (B[ind][nx][ny].without > t.t + 1)
				{
					B[ind][nx][ny].without = t.t + 1;
					f = 1;
				}
				if (B[ind][nx][ny].with > t.t + 1)
				{
					B[ind][nx][ny].with = t.t + 1;
					f = 1;
				}
				if (f)
				{
					d.d = 0;
					if (nx == mx && my == ny)
						d.d = 1;
					d.t = t.t + 1;
					d.r = nx;
					d.c = ny;
					Q.push(d);
				}
			}
			else
			{
				if (nx == mx && ny == my)
					continue;
				if (B[ind][nx][ny].with > t.t + 1)
				{
					B[ind][nx][ny].with = t.t + 1;
					d.t = t.t + 1;
					d.r = nx;
					d.c = ny;
					d.d = 1;
					Q.push(d);
				}
			}
		}
	}
}
int FindMin()
{
	int i, min = INF, d, k, j, l, sum;
	for (j = 1; j <= R; j++)
	{
		for (l = 1; l <= C; l++)
		{
			if (j == mx && l == my)
				continue;
			sum = 0;
			for (i = 0; i < 4; i++)
				sum += B[i][j][l].without;
			k = sum;
			d = k - B[0][j][l].without + B[0][j][l].with;
			if (d < sum)
				sum = d;
			d = k - B[1][j][l].without + B[1][j][l].with;
			if (d < sum)
				sum = d;
			d = k - B[2][j][l].without + B[2][j][l].with;
			if (d < sum)
				sum = d;
			d = k - B[3][j][l].without + B[3][j][l].with;
			if (d < sum)
				sum = d;
			if (min > sum)
				min = sum;
		}
	}
	return min;
}
void Cal()
{
	int i;
	Ini();
	for (i = 0; i < 4; i++)
		BFS(P[i].with, P[i].without, i);
	i = FindMin();
	if (i >= INF)
		cout << "Meeting is impossible.\n";
	else
		cout << "Minimum time required is " << i << " minutes.\n";
}

int main()
{
	char str[100];
	int i;
	while (cin >> str)
	{
		cout << str << endl;
		cin >> R >> C;
		for (i = 0; i < 4; i++)
			cin >> P[i].with >> P[i].without;
		cin >> mx >> my;
		Cal();
	}
	return 0;
}
