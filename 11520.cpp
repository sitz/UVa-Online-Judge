#include <bits/stdc++.h>

using namespace std;

/**
 *  Algorithm:
 *      Simple problem. Greedy will work.
 *      For each grid, enum every char from 'A' to 'Z'.
 *      If it does not cause conflict, then print it.
 **/

char maze[15][15];
int RC;

int isColorable(int r, int c, char ch)
{
	if (r != 0)
	{
		if (maze[r - 1][c] == ch)
		{
			return 0;
		}
	}
	if (r != RC - 1)
	{
		if (maze[r + 1][c] == ch)
		{
			return 0;
		}
	}
	if (c != 0)
	{
		if (maze[r][c - 1] == ch)
		{
			return 0;
		}
	}
	if (c != RC - 1)
	{
		if (maze[r][c + 1] == ch)
		{
			return 0;
		}
	}
	return 1;
}

void Cal()
{
	int i, j, k;
	for (i = 0; i < RC; i++)
	{
		for (j = 0; j < RC; j++)
		{
			if (maze[i][j] != '.')
			{
				printf("%c", maze[i][j]);
				continue;
			}
			for (k = 0; k < 26; k++)
			{
				if (isColorable(i, j, k + 'A'))
				{
					maze[i][j] = k + 'A';
					printf("%c", k + 'A');
					break;
				}
			}
		}
		printf("\n");
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &RC);
		for (int j = 0; j < RC; j++)
		{
			scanf("%s", maze[j]);
		}
		printf("Case %d:\n", i);
		Cal();
	}
	return 0;
}
