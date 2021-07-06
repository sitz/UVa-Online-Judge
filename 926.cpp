#include <bits/stdc++.h>

using namespace std;

#define maxn 32

typedef long long LONG;

int Sx, Sy, Tx, Ty, N;
char Visited[maxn][maxn];
LONG Ways[maxn][maxn];

struct ss
{
	bool up, left;
};
ss No[maxn][maxn];

void setNo()
{
	int i, j;
	for (i = 0; i <= N; i++)
		for (j = 0; j <= N; j++)
			No[i][j].left = No[i][j].up = true;
}

void setDir(int x, int y, char dir)
{
	switch (dir)
	{
	case 'S':
		No[x][y - 1].up = false;
		break;
	case 'W':
		No[x - 1][y].left = false;
		break;
	case 'E':
		No[x][y].left = false;
		break;
	case 'N':
		No[x][y].up = false;
		break;
	}
}

LONG countWays(int x, int y)
{
	if (Tx == x && y == Ty)
		return 1;
	if (x > N || y > N)
		return 0;
	if (x > Tx || y > Ty)
		return 0;
	LONG ways = 0;
	if (Visited[x][y] == 1)
		return Ways[x][y];
	Visited[x][y] = 1;
	if (No[x][y].left)
		ways += countWays(x + 1, y);
	if (No[x][y].up)
		ways += countWays(x, y + 1);
	Ways[x][y] = ways;
	return ways;
}

int isPossible()
{
	if (Sx > Tx || Sy > Ty)
		return 0;
	return 1;
}

void Cal()
{
	if (isPossible() == 0)
	{
		printf("0\n");
		return;
	}
	LONG ways = countWays(Sx, Sy);
	printf("%lld\n", ways);
}

void makeFree()
{
	int i, j;
	for (i = 0; i <= N; i++)
	{
		for (j = 0; j <= N; j++)
		{
			Visited[i][j] = 0;
			Ways[i][j] = 0;
		}
	}
}

void readCase()
{
	int w, x, y;
	char dir[10];
	scanf("%d", &N);
	setNo();
	scanf("%d%d", &Sx, &Sy);
	scanf("%d%d", &Tx, &Ty);
	scanf("%d", &w);
	while (w--)
	{
		scanf("%d%d", &x, &y);
		scanf("%s", dir);
		setDir(x, y, dir[0]);
	}
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		readCase();
		Cal();
		makeFree();
	}
	return 0;
}
