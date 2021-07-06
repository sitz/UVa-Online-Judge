#include <bits/stdc++.h>

using namespace std;

/*
The Hybrid Knight
10447
*/
#define MAX 12500
#define INF 2147480
struct Queue
{
	int move;
	int pice;
	int r, c;
} que[MAX];
struct Board
{
	int pice[3];
} B[22][22];
int qh, qt, Size, Min, tr, tc;
int maximum;
int kx[] = {-2, -2, -1, -1, 2, 2, 1, 1};
int ky[] = {-1, 1, -2, 2, -1, 1, -2, 2};
int mx[] = {-3, -3, -1, -1, 3, 3, 1, 1};
int my[] = {1, -1, -3, 3, -1, 1, -3, 3};
int dx[] = {1, 1, -1, -1};
int dy[] = {-1, 1, -1, 1};
int px[] = {0, 0, -1, 1};
int py[] = {-1, 1, 0, 0};
void Ini()
{
	int i, j;
	for (i = 0; i <= Size; i++)
	{
		for (j = 0; j <= Size; j++)
		{
			B[i][j].pice[0] = B[i][j].pice[1] = B[i][j].pice[2] = 0;
		}
	}
}
void Push(int pice, int r, int c, int move)
{
	if (B[r][c].pice[pice])
	{
		return;
	}
	B[r][c].pice[pice] = 1;
	que[qh].c = c;
	que[qh].r = r;
	que[qh].pice = pice;
	que[qh].move = move;
	qh++;
	if (qh > maximum)
	{
		maximum = qh;
	}
	qh %= MAX;
}
Queue Pop()
{
	int temp = qt;
	qt++;
	qt %= MAX;
	return que[temp];
}
void PushK(int r, int c, int move)
{
	int i, nr, nc;
	for (i = 0; i < 8; i++)
	{
		nr = kx[i] + r;
		nc = ky[i] + c;
		if (nr >= Size || nr < 0 || nc >= Size || nc < 0)
		{
			continue;
		}
		if (nr == tr && nc == tc)
		{
			if (Min > move)
			{
				Min = move;
			}
		}
		else
		{
			Push(0, nr, nc, move);
		}
	}
}
void PushM(int r, int c, int move)
{
	int i, nr, nc;
	for (i = 0; i < 8; i++)
	{
		nr = mx[i] + r;
		nc = my[i] + c;
		if (nr >= Size || nr < 0 || nc >= Size || nc < 0)
		{
			continue;
		}
		if (nr == tr && nc == tc)
		{
			if (Min > move)
			{
				Min = move;
			}
		}
		else
		{
			Push(1, nr, nc, move);
		}
	}
}
void PushP(int r, int c, int move)
{
	int i, nr, nc;
	for (i = 0; i < 4; i++)
	{
		nr = px[i] + r;
		nc = py[i] + c;
		if (nr >= Size || nr < 0 || nc >= Size || nc < 0)
		{
			continue;
		}
		if (nr == tr && nc == tc)
		{
			if (Min > move)
			{
				Min = move;
			}
		}
		else
		{
			Push(2, nr, nc, move);
		}
	}
}
void PushD(int r, int c, int move)
{
	int i, nr, nc;
	for (i = 0; i < 4; i++)
	{
		nr = dx[i] + r;
		nc = dy[i] + c;
		if (nr >= Size || nr < 0 || nc >= Size || nc < 0)
		{
			continue;
		}
		if (nr == tr && nc == tc)
		{
			Min = move;
			return;
		}
	}
}
void BFS(int sr, int sc)
{
	Queue temp;
	int pice, move;
	qh = qt = 0;
	Push(0, sr, sc, 0);
	Push(1, sr, sc, 0);
	Push(2, sr, sc, 0);
	Min = INF;
	while (qh != qt)
	{
		temp = Pop();
		pice = temp.pice + 1;
		pice %= 3;
		move = temp.move + 1;
		if (pice == 0)
		{
			PushK(temp.r, temp.c, move);
		}
		if (Min != INF)
		{
			return;
		}
		if (pice == 1)
		{
			PushM(temp.r, temp.c, move);
		}
		if (Min != INF)
		{
			return;
		}
		if (pice == 2)
		{
			PushP(temp.r, temp.c, move);
		}
		if (Min != INF)
		{
			return;
		}
		if (pice == 2)
		{
			PushD(temp.r, temp.c, move);
		}
		if (Min != INF)
		{
			return;
		}
	}
}
void Cal()
{
	int q, b, e;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d%d", &b, &e);
		b--;
		e--;
		tr = e / Size;
		tc = e % Size;
		Ini();
		maximum = 0;
		BFS(b / Size, b % Size);
		if (Min == INF)
		{
			printf("?\n");
		}
		else
		{
			printf("%d\n", Min);
		}
	}
}
int main()
{
	int set = 1;
	while (scanf("%d", &Size) == 1)
	{
		if (!Size)
		{
			break;
		}
		printf("Set %d:\n", set++);
		Cal();
	}
	return 0;
}
