#include <bits/stdc++.h>

using namespace std;

/*
Walking on the safe side
825
*/
#define MAXN 200
char Road[MAXN][MAXN];
char f[MAXN][MAXN];
char str[MAXN];
struct ss
{
	int r, c;
	int move;
} q[MAXN * MAXN];
int qh, qt, R, C, Count;
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};
void Push(int r, int c, int move)
{
	q[qh].r = r;
	q[qh].c = c;
	q[qh].move = move;
	qh++;
	qh %= MAXN * MAXN;
}
ss Pop()
{
	ss p;
	p.move = q[qt].move;
	p.r = q[qt].r;
	p.c = q[qt++].c;
	qt %= MAXN * MAXN;
	return p;
}
int Bfs()
{
	int i, tr, tc;
	ss temp;
	f[0][0] = 1;
	qh = qt = 0;
	Push(0, 0, 0);
	while (qh != qt)
	{
		temp = Pop();
		for (i = 0; i < 4; i++)
		{
			tr = temp.r + mx[i];
			tc = temp.c + my[i];
			if (tr >= R || tr < 0 || tc >= C || tc < 0)
			{
				continue;
			}
			if (tr == R - 1 && tc == C - 1)
			{
				return temp.move + 1;
			}
			if (f[tr][tc] == 1 || Road[tr][tc])
			{
				continue;
			}
			f[tr][tc] = 1;
			Push(tr, tc, temp.move + 1);
		}
	}
	return 0;
}
void Ids(int r, int c, int min, int level)
{
	int i;
	int nr, nc;
	if (r == R - 1 && c == C - 1)
	{
		Count++;
		return;
	}
	if (level >= min)
	{
		return;
	}
	f[r][c] = 1;
	for (i = 0; i < 4; i++)
	{
		nr = r + mx[i];
		nc = c + my[i];
		if (nr >= R || nr < 0 || nc >= C || nc < 0)
		{
			continue;
		}
		//if(nr<r || nc<c) continue;
		if (f[nr][nc] || Road[nr][nc])
		{
			continue;
		}
		Ids(nr, nc, min, level + 1);
	}
	f[r][c] = 0;
}
void Cal()
{
	int min, i, j;
	min = Bfs();
	if (!min)
	{
		printf("0\n");
		return;
	}
	Count = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			f[i][j] = 0;
		}
	}
	Ids(0, 0, min, 0);
	printf("%d\n", Count);
}
void Reset()
{
	int i, j;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			f[i][j] = Road[i][j] = 0;
		}
	}
}
void ReadCase()
{
	int i, j;
	char *p;
	gets(str);
	sscanf(str, "%d%d", &R, &C);
	Reset();
	for (i = 0; i < R; i++)
	{
		gets(str);
		p = strtok(str, " ");
		p = strtok(NULL, " ");
		while (p)
		{
			j = atoi(p);
			Road[i][j - 1] = 1;
			p = strtok(NULL, " ");
		}
	}
}
int main()
{
	char input[100];
	int kase;
	gets(input);
	sscanf(input, "%d", &kase);
	gets(input);
	while (kase--)
	{
		ReadCase();
		Cal();
		if (kase)
		{
			gets(input);
			putchar('\n');
		}
	}
	return 0;
}
