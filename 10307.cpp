#include <bits/stdc++.h>

using namespace std;

#define MAXN 52
#define MAX 10000

char Maze[MAXN][MAX], Flag[MAXN][MAX], flg[102][102];
int node[MAXN][MAX], p[102], rank_[102], R, C, edg, ali, QH, QT;

int X[] = {-1, 0, 0, 1};
int Y[] = {0, -1, 1, 0};

struct queue_
{
	int r, c, dis;
} Q[MAX];

struct ss
{
	int r, c;
} st[106];

struct edge
{
	int u, v;
	int weight;
} E[100000];

int cmp(const void *a, const void *b)
{
	edge *x = (edge *)a;
	edge *y = (edge *)b;
	return x->weight - y->weight;
}
void Push(int r, int c, int dis)
{
	Q[QH].r = r;
	Q[QH].dis = dis;
	Q[QH++].c = c;
	QH %= MAX;
}
queue_ Pop()
{
	queue_ temp;
	temp.r = Q[QT].r;
	temp.dis = Q[QT].dis;
	temp.c = Q[QT++].c;
	QT %= MAX;
	return temp;
}
int IsEmpty()
{
	return QH == QT;
}
void BFS(int r, int c, int in)
{
	int i, j, k, dis, nr, nc, co = 0;
	queue_ t;
	QH = QT = 0;
	for (i = 0; i < R; i++)
	{
		for (j = 0; j < C; j++)
		{
			Flag[i][j] = 0;
			Q[i * C + j].dis = 0;
		}
	}
	Push(r, c, 0);
	Flag[r][c] = 1;
	while (!IsEmpty())
	{
		t = Pop();
		r = t.r;
		c = t.c;
		dis = t.dis;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				nr = X[i] + r;
				nc = Y[i] + c;
				if (nc > C || nc < 0 || nr > R || nr < 0)
				{
					continue;
				}
				if (Flag[nr][nc] == 1 || Maze[nr][nc] == '#')
				{
					continue;
				}
				if (Maze[nr][nc] == 'A' || Maze[nr][nc] == 'S')
				{
					k = node[nr][nc];
					if (!flg[in][k])
					{
						E[edg].u = in;
						E[edg].v = k;
						E[edg++].weight = dis + 1;
						flg[in][k] = flg[k][in] = 1;
						co++;
						if (co == ali - 1)
						{
							return;
						}
					}
				}
				Flag[nr][nc] = 1;
				Push(nr, nc, dis + 1);
			}
		}
	}
}
void Ini()
{
	int i;
	for (i = 1; i <= ali; i++)
	{
		p[i] = i;
		rank_[i] = 0;
	}
}
int FindSet(int s)
{
	if (s != p[s])
	{
		p[s] = FindSet(p[s]);
	}
	return p[s];
}
void Link(int x, int y)
{
	if (rank_[x] > rank_[y])
	{
		p[y] = x;
	}
	else
	{
		p[x] = y;
		if (rank_[x] == rank_[y])
		{
			rank_[y]++;
		}
	}
}
void krukal()
{
	int i, sum = 0, mstLen = 0;
	int x, y;
	Ini();
	qsort(E, edg, sizeof(E[0]), cmp);
	for (i = 0; i < edg; i++)
	{
		x = FindSet(E[i].u);
		y = FindSet(E[i].v);
		if (x != y)
		{
			mstLen++;
			Link(x, y);
			sum += E[i].weight;
			if (mstLen == ali - 1)
			{
				break;
			}
		}
	}
	printf("%d", sum);
}
void Cal()
{
	int i;
	for (i = 0; i < ali - 1; i++)
	{
		BFS(st[i].r, st[i].c, i + 1);
	}
	krukal();
}
int main()
{
	int kase, i, j;
	char input[100];
	gets(input);
	sscanf(input, "%d", &kase);
	while (kase--)
	{
		gets(input);
		sscanf(input, "%d%d", &C, &R);
		ali = edg = 0;
		for (i = 0; i < R; i++)
		{
			gets(Maze[i]);
			for (j = 0; Maze[i][j]; j++)
			{
				if (Maze[i][j] == 'A' || Maze[i][j] == 'S')
				{
					node[i][j] = ali + 1;
					st[ali].r = i;
					st[ali].c = j;
					ali++;
				}
			}
		}
		Cal();
		putchar('\n');
		if (kase)
		{
			for (i = 1; i < ali; i++)
			{
				for (j = i + 1; j <= ali; j++)
				{
					flg[i][j] = flg[j][i] = 0;
				}
			}
		}
	}
	return 0;
}
