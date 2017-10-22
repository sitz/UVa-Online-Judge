#include <bits/stdc++.h>

using namespace std;

/*
Robot
314
*/

#define MAXN 55
#define MAX MAXN *MAXN * 4
int B[MAXN][MAXN];
int D[] = {0, 1, 2, 3};
int X[] = {1, 0, -1, 0};
int Y[] = {0, -1, 0, 1};
char G[MAXN][MAXN];
char ff[MAXN][MAXN][4];
char Side[4][7] = {"south", "west", "north", "east"};
int R, C, sr, sc, er, ec;
struct Queue
{
	int r, c, s;
	int count;
} Q[MAX];
int QH, QT;
void Set()
{
	int i, j;
	for (i = 0; i <= R; i++)
	{
		memset(G[i], 0, C);
	}
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			if (B[i][j])
			{
				G[i][j] = 1;
				G[i][j + 1] = 1;
				G[i + 1][j] = 1;
				G[i + 1][j + 1] = 1;
			}
			for (int k = 0; k < 4; k++)
			{
				ff[i][j][k] = 0;
			}
		}
	}
}
void Push(int r, int c, int s, int count)
{
	if (ff[r][c][s])
	{
		return;
	}
	Q[QH].r = r;
	Q[QH].c = c;
	Q[QH].count = count;
	Q[QH++].s = s;
	QH %= MAX;
	ff[r][c][s] = 1;
}
Queue Pop()
{
	Queue temp;
	temp.r = Q[QT].r;
	temp.c = Q[QT].c;
	temp.s = Q[QT].s;
	temp.count = Q[QT].count;
	QT++;
	QT %= MAX;
	return temp;
}
int IsEmpty()
{
	return QH == QT;
}
int Bfs(int side)
{
	int i, sd, r, c;
	int nr, nc, count, nd1, nd2;
	Queue temp;
	QH = QT = 0;
	if (G[er][ec])
	{
		return -1;
	}
	if (G[sr][sc])
	{
		return -1;
	}
	if (sr == er && sc == ec)
	{
		return 0;
	}
	Push(sr, sc, side, 0);
	ff[sr][sc][side] = 1;
	while (!IsEmpty())
	{
		temp = Pop();
		sd = temp.s;
		r = temp.r;
		c = temp.c;
		count = temp.count + 1;
		nd1 = sd + 1;
		nd2 = sd - 1 + 4;
		Push(r, c, nd1 % 4, count);
		Push(r, c, nd2 % 4, count);
		nd1++;
		Push(r, c, nd1 % 4, count + 1);
		nr = r;
		nc = c;
		for (i = 0; i < 3; i++)
		{
			nr += X[sd];
			nc += Y[sd];
			if (nr >= R || nc >= C || nr <= 0 || nc <= 0)
			{
				continue;
			}
			if (G[nr][nc])
			{
				break;
			}
			if (nr == er && nc == ec)
			{
				return count;
			}
			Push(nr, nc, sd, count);
		}
	}
	return -1;
}
int Search(char ss[])
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (!strcmp(Side[i], ss))
		{
			break;
		}
	}
	return i;
}
void Cal(char ss[])
{
	int p, d;
	p = Search(ss);
	d = Bfs(p);
	cout << d << endl;
}
int main()
{
	int i, j;
	char ss[10];
	while (1)
	{
		cin >> R >> C;
		if (!R && !C)
		{
			break;
		}
		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				cin >> B[i][j];
			}
		}
		cin >> sr >> sc >> er >> ec >> ss;
		Set();
		Cal(ss);
	}
	return 0;
}
