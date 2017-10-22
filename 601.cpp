#include <bits/stdc++.h>

using namespace std;

/**
601
**/
#define MAXN 82
int MR[] = {0, 0, -1, 1};
int MC[] = {1, -1, 0, 0};
char B[MAXN][MAXN];
char Temp[MAXN][MAXN];
int N, ff, bla, whi;
int FW(int r, int c, char p)
{
	if (r >= N || r < 0 || c >= N || c < 0)
	{
		return 0;
	}
	if (Temp[r][c] != p)
	{
		return 0;
	}
	if (p == 'W' && c == N - 1)
	{
		return 1;
	}
	if (p == 'B' && r == N - 1)
	{
		return 1;
	}
	Temp[r][c] = 'X';
	for (int i = 0; i < 4; i++)
	{
		int nr = r + MR[i];
		int nc = c + MC[i];
		if (FW(nr, nc, p) == 1)
		{
			return 1;
		}
	}
	return 0;
}
int Win(char p, int n)
{
	int i, j;
	if (p == 'W' && whi > n)
	{
		return 1;
	}
	if (p == 'B' && bla > n)
	{
		return 1;
	}
	if (p == 'W')
	{
		j = 0;
		for (i = 0; i < N; i++)
			if (B[i][0] == 'W')
			{
				j++;
			}
		if (j > 1)
		{
			return 1;
		}
	}
	if (p == 'B')
	{
		j = 0;
		for (i = 0; i < N; i++)
			if (B[0][i] == 'B')
			{
				j++;
			}
		if (j > 1)
		{
			return 1;
		}
	}
	return 0;
}
int F(int r, int c, char p, int level)
{
	if (r >= N || r < 0 || c >= N || c < 0)
	{
		return 0;
	}
	if ((Temp[r][c] != p) && Temp[r][c] != 'U')
	{
		return 0;
	}
	if (Temp[r][c] == 'U' && ff == 0)
	{
		return 0;
	}
	if (Temp[r][c] == 'U')
	{
		ff = 0;
	}
	if (p == 'W' && c == N - 1 && Win(p, level))
	{
		return 1;
	}
	if (p == 'B' && r == N - 1 && Win(p, level))
	{
		return 1;
	}
	Temp[r][c] = 'X';
	for (int i = 0; i < 4; i++)
	{
		int nr = r + MR[i];
		int nc = c + MC[i];
		if (F(nr, nc, p, level + 1) == 1)
		{
			return 1;
		}
		if (Temp[nr][nc] == 'U')
		{
			ff = 1;
		}
	}
	return 0;
}
void Count()
{
	int i, j;
	bla = whi = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (B[i][j] == 'B')
			{
				bla++;
			}
			else if (B[i][j] == 'W')
			{
				whi++;
			}
		}
	}
}
void Cal()
{
	int i;
	for (i = 0; i < N; i++)
	{
		strcpy(Temp[i], B[i]);
	}
	for (i = 0; i < N; i++)
	{
		if (Temp[i][0] == 'W')
			if (FW(i, 0, 'W') == 1)
			{
				printf("White has a winning path.\n");
				return;
			}
	}
	for (i = 0; i < N; i++)
	{
		strcpy(Temp[i], B[i]);
	}
	for (i = 0; i < N; i++)
	{
		if (B[0][i] == 'B')
			if (FW(0, i, 'B') == 1)
			{
				printf("Black has a winning path.\n");
				return;
			}
	}
	Count();
	for (i = 0; i < N; i++)
	{
		strcpy(Temp[i], B[i]);
	}
	for (i = 0; i < N; i++)
	{
		ff = 1;
		if (Temp[i][0] == 'W')
			if (F(i, 0, 'W', 0) == 1)
			{
				printf("White can win in one move.\n");
				return;
			}
	}
	for (i = 0; i < N; i++)
	{
		strcpy(Temp[i], B[i]);
	}
	for (i = 0; i < N; i++)
	{
		ff = 1;
		if (Temp[0][i] == 'B')
			if (F(0, i, 'B', 0) == 1)
			{
				printf("Black can win in one move.\n");
				return;
			}
	}
	printf("There is no winning path.\n");
}
int main()
{
	int i;
	while (scanf("%d", &N) == 1)
	{
		if (!N)
		{
			break;
		}
		for (i = 0; i < N; i++)
		{
			scanf("%s", B[i]);
		}
		if (N == 1 && B[0][0] == 'U')
		{
			printf("White can win in one move.\n");
			continue;
		}
		Cal();
	}
	return 0;
}
