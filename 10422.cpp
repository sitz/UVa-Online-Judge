#include <bits/stdc++.h>

using namespace std;

/****
10422
****/
char Terget[6][6] = {{1, 1, 1, 1, 1}, {0, 1, 1, 1, 1}, {0, 0, 2, 1, 1}, {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0}};
char Board[6][6];
int MAX, F;
int MOVEX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int MOVEY[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int OK()
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (Board[i][j] != Terget[i][j])
			{
				return 0;
			}
	return 1;
}
void Recur(int level, int r, int c, int prer, int prec)
{
	if (level > 10)
	{
		return;
	}
	if (level >= MAX)
	{
		return;
	}
	if (OK())
	{
		MAX = level;
		F = 1;
		return;
	}
	for (int i = 0; i < 8; i++)
	{
		int nr = MOVEX[i] + r;
		int nc = MOVEY[i] + c;
		if (nr >= 5 || nc >= 5 || nr < 0 || nc < 0)
		{
			continue;
		}
		if (nr == prer && nc == prec)
		{
			continue;
		}
		Board[r][c] = Board[nr][nc];
		Board[nr][nc] = 2;
		Recur(level + 1, nr, nc, r, c);
		Board[nr][nc] = Board[r][c];
		Board[r][c] = 2;
	}
}
int main()
{
	int kase, i, j, t;
	int sr, sc;
	char input[100];
	gets(input);
	sscanf(input, "%d", &kase);
	while (kase--)
	{
		MAX = 100;
		for (t = 0; t < 5; t++)
		{
			gets(input);
			for (i = 0; input[i]; i++)
			{
				if (input[i] == ' ')
				{
					Board[t][i] = 2;
					sr = t;
					sc = i;
					continue;
				}
				j = input[i] - '0';
				Board[t][i] = j;
			}
		}
		F = 0;
		Recur(0, sr, sc, -1, -1);
		if (F == 0)
		{
			printf("Unsolvable in less than 11 move(s).\n");
		}
		else
		{
			printf("Solvable in %d move(s).\n", MAX);
		}
	}
	return 0;
}
