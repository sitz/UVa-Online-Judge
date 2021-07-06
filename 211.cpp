#include <bits/stdc++.h>

using namespace std;

int bones[7][7];
int pips[7][8], placed[7][8], used[29];
int layout, sol;
void Print(int board[7][8], int d)
{
	int r, c;
	for (r = 0; r < 7; r++)
	{
		if (d)
		{
			putchar(' ');
		}
		for (c = 0; c < 8; c++)
		{
			printf("%4d", board[r][c]);
		}
		putchar('\n');
	}
	putchar('\n');
}

void Place(int depth)
{
	if (depth == 56)
	{
		int c = 0;
		for (int i = 1; i < 29; i++)
			if (used[i])
			{
				c++;
			}
		if (c != 28)
		{
			return;
		}
		sol++;
		Print(placed, 1);
		return;
	}
	int b, r = depth / 8, c = depth % 8;
	if (placed[r][c])
	{
		return Place(depth + 1);
	}
	if (c < 7 && !placed[r][c + 1] && !used[bones[pips[r][c]][pips[r][c + 1]]])
	{
		int d = bones[pips[r][c]][pips[r][c + 1]];
		used[d] = true;
		placed[r][c] = placed[r][c + 1] = d;
		Place(depth + 1);
		used[d] = false;
		placed[r][c] = placed[r][c + 1] = 0;
	}
	if (r < 6 && !placed[r + 1][c] && !used[bones[pips[r][c]][pips[r + 1][c]]])
	{
		int d = bones[pips[r][c]][pips[r + 1][c]];
		used[d] = true;
		placed[r][c] = placed[r + 1][c] = d;
		Place(depth + 1);
		used[d] = false;
		placed[r][c] = placed[r + 1][c] = 0;
	}
	return;
}

int main()
{
	int r, c, i, j, b;
	for (b = 1, i = 0, j = 0; b < 29; b++)
	{
		bones[i][j] = bones[j][i] = b;
		if (++i == 7)
		{
			i = ++j;
		}
	}
	while (scanf("%d", &pips[0][0]) == 1)
	{
		if (layout++)
		{
			printf("\n\n\n");
		}
		sol = 0;
		for (r = 0; r < 7; r++)
		{
			for (c = 0; c < 8; c++)
			{
				if (r || c)
				{
					scanf("%d", &pips[r][c]);
				}
				placed[r][c] = 0;
			}
		}
		for (i = 1; i <= 28; i++)
		{
			used[i] = 0;
		}
		printf("Layout #%d:\n\n", layout);
		Print(pips, 0);
		printf("Maps resulting from layout #%d are:\n\n", layout);
		Place(0);
		printf("There are %d solution(s) for layout #%d.\n", sol, layout);
	}
	return 0;
}
