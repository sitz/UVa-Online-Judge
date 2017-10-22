#include <bits/stdc++.h>

using namespace std;

#define MAXN 101

int Snow[MAXN][MAXN];
int R, C;
int MAXD, Temp;
int MoveX[] = {0, 0, 1, -1};
int MoveY[] = {1, -1, 0, 0};

struct ss
{
	char f;
	char c;
} V[MAXN][MAXN];
void Find(int r, int c)
{
	int i;
	V[r][c].f = 'y';
	V[r][c].c = 'b';
	Temp++;
	if (Temp > MAXD)
	{
		MAXD = Temp;
	}
	for (i = 0; i < 4; i++)
	{
		int nr = MoveX[i] + r;
		int nc = MoveY[i] + c;
		if (nr < 0 || nc < 0 || nr >= R || nc >= C || Snow[r][c] <= Snow[nr][nc])
		{
			continue;
		}
		if (V[nr][nc].c != 'b')
		{
			Find(nr, nc);
			Temp--;
			V[nr][nc].c = 'w';
		}
	}
	V[r][c].c = 'w';
}
void Cal()
{
	int i, j;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
		{
			if (V[i][j].f == 'n')
			{
				Temp = 0;
				Find(i, j);
			}
		}
}

int main()
{
	int i, j, kase;
	char name[100];
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%s%d%d", name, &R, &C);
		MAXD = 0;
		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				scanf("%d", &Snow[i][j]);
				V[i][j].f = 'n';
				V[i][j].c = 'w';
			}
		}
		Cal();
		printf("%s: %d\n", name, MAXD);
	}
	return 0;
}
