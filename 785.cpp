#include <bits/stdc++.h>

using namespace std;

/*
785
Grid Colouring
*/
#define MAXN 3000
char grid[35][85];
char f[35][85];
int R, maxc;
struct Qu
{
	int r, c;
} Q[MAXN];
int qh, qt, sr, sc;
char C;
struct tt
{
	int r, c;
} st[1000];
int ind;
int isbreak(char tt[])
{
	int i, f = 1, d = 0;
	for (i = 0; tt[i]; i++)
	{
		d = 1;
		if (tt[i] != '_')
		{
			return 0;
		}
	}
	if (d)
	{
		return 1;
	}
	return 0;
}
int GetCon(char nn[])
{
	int i;
	for (i = 0; nn[i]; i++)
	{
		if (nn[i] != ' ')
		{
			C = nn[i];
			return 1;
		}
	}
	return 0;
}
int ReadCase()
{
	int i, f = 1, d = 1;
	maxc = ind = 0;
	R = 0;
	while (gets(grid[R]))
	{
		if (f)
		{
			if (GetCon(grid[R]))
			{
				f = 0;
			}
		}
		while (1)
		{
			if (isbreak(grid[R]))
			{
				return 0;
			}
			for (i = 0; grid[R][i]; i++)
			{
				if (grid[R][i] != C && grid[R][i] != ' ')
				{
					st[ind].r = R;
					st[ind++].c = i;
				}
			}
			int l = strlen(grid[R]);
			if (l > maxc)
			{
				maxc = l;
			}
			R++;
			gets(grid[R]);
			d = 0;
			if (f)
			{
				if (GetCon(grid[R]))
				{
					f = 0;
				}
			}
		}
	}
	if (d)
	{
		return 1;
	}
	return 0;
}
void Push(int r, int c)
{
	Q[qh].r = r;
	Q[qh++].c = c;
	qh %= MAXN;
}
Qu Pop()
{
	Qu temp;
	temp.r = Q[qt].r;
	temp.c = Q[qt++].c;
	return temp;
}
void Bfs(int rr, int cc, char nn)
{
	int x[] = {0, 0, 1, -1};
	int y[] = {1, -1, 0, 0};
	int i, nr, nc;
	Qu temp;
	qh = qt = 0;
	f[rr][cc] = 1;
	Push(rr, cc);
	while (qh != qt)
	{
		temp = Pop();
		for (i = 0; i < 4; i++)
		{
			nr = temp.r + x[i];
			nc = temp.c + y[i];
			if (nr > R || nr < 0 || nc < 0 || nc > maxc)
			{
				continue;
			}
			if (grid[nr][nc] == ' ')
			{
				grid[nr][nc] = nn;
				Push(nr, nc);
			}
		}
	}
}
void Print()
{
	int i;
	for (i = 0; i < R; i++)
	{
		printf("%s\n", grid[i]);
	}
	printf("%s\n", grid[R]);
}
void Cal()
{
	int i;
	for (i = 0; i < ind; i++)
	{
		Bfs(st[i].r, st[i].c, grid[st[i].r][st[i].c]);
	}
	Print();
}
int main()
{
	int kase;
	while (1)
	{
		kase = ReadCase();
		if (kase)
		{
			break;
		}
		Cal();
	}
	return 0;
}
