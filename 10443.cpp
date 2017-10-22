#include <bits/stdc++.h>

using namespace std;

/***************************
Title : Rocks Scissors,Paper
No : 10443
****************************/
#define MAXN 101
char MAP1[MAXN][MAXN];
char MAP2[MAXN][MAXN];
char E;
int R, C, D;
void enemy(char c)
{
	if (c == 'R')
	{
		E = 'P';
	}
	else if (c == 'S')
	{
		E = 'R';
	}
	else
	{
		E = 'S';
	}
}
void REPLACE(char ch, int r, int c)
{
	enemy(ch);
	int i, j;
	j = c + 1;
	if ((r >= 0 && r < R) && (j >= 0 && j < C))
		if (MAP2[r][j] == E)
		{
			MAP1[r][c] = E;
			return;
		}
	j = c - 1;
	if (r >= 0 && r < R && j >= 0 && j < C)
		if (MAP2[r][j] == E)
		{
			MAP1[r][c] = E;
			return;
		}
	i = r + 1;
	if (i >= 0 && i < R && c >= 0 && c < C)
		if (MAP2[i][c] == E)
		{
			MAP1[r][c] = E;
			return;
		}
	i = r - 1;
	if (i >= 0 && i < R && c >= 0 && c < C)
		if (MAP2[i][c] == E)
		{
			MAP1[r][c] = E;
			return;
		}
}
void COM()
{
	int i, j;
	while (D--)
	{
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
			{
				REPLACE(MAP1[i][j], i, j);
			}
		for (i = 0; i < R; i++)
		{
			strcpy(MAP2[i], MAP1[i]);
		}
	}
}
void PRINT()
{
	int i;
	for (i = 0; i < R; i++)
	{
		puts(MAP1[i]);
	}
}
int main()
{
	int N, i;
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d%d%d", &R, &C, &D);
		for (i = 0; i < R; i++)
		{
			scanf("%s", MAP1[i]);
			strcpy(MAP2[i], MAP1[i]);
		}
		COM();
		PRINT();
		if (N)
		{
			printf("\n");
		}
	}
	return 0;
}
