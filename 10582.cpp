#include <bits/stdc++.h>

using namespace std;

char buf[10000], temp[3][10000], temp2[4][4];
int map_[65][65], state[65][65], used[65][65], r, c, total;

void back(int row, int col, int row2, int col2)
{
	int type = map_[row][col], i, j;
	if (row == r - 1 && col == c - 1)
	{
		++total;
		return;
	}
	if (used[row][col] || row > r || row < 0 || col > c || col < 0)
	{
		return;
	}
	if (type == -1)
	{
		return;
	}
	if (!row && !col)
	{
		if (!type)
		{
			used[row][col] = 1;
			back(row, col + 1, row, col);
			back(row, col - 1, row, col);
			back(row + 1, col, row, col);
			back(row - 1, col, row, col);
			used[row][col] = 0;
		}
		else
		{
			used[row][col] = 1;
			/*
			_|
			*/
			back(row, col - 1, row, col);
			back(row - 1, col, row, col);
			/*
			|_
			*/
			back(row, col + 1, row, col);
			back(row - 1, col, row, col);
			/*
			_
			 |
			*/
			back(row, col - 1, row, col);
			back(row + 1, col, row, col);
			used[row][col] = 0;
		}
		return;
	}
	if (!type)
	{
		used[row][col] = 1;
		if (col - 1 == col2)
		{
			back(row, col + 1, row, col);
		}
		else if (col + 1 == col2)
		{
			back(row, col - 1, row, col);
		}
		else if (row - 1 == row2)
		{
			back(row + 1, col, row, col);
		}
		else if (row + 1 == row2)
		{
			back(row - 1, col, row, col);
		}
		used[row][col] = 0;
	}
	else
	{
		used[row][col] = 1;
		/*
		_|
		*/
		if (row - 1 == row2)
		{
			back(row, col - 1, row, col);
		}
		if (col - 1 == col2)
		{
			back(row - 1, col, row, col);
		}
		/*
		|_
		*/
		if (row - 1 == row2)
		{
			back(row, col + 1, row, col);
		}
		if (col + 1 == col2)
		{
			back(row - 1, col, row, col);
		}
		/*
		 _
		|
		*/
		if (row + 1 == row2)
		{
			back(row, col + 1, row, col);
		}
		if (col + 1 == col2)
		{
			back(row + 1, col, row, col);
		}
		/*
		_
		 |
		*/
		if (row + 1 == row2)
		{
			back(row, col - 1, row, col);
		}
		if (col - 1 == col2)
		{
			back(row + 1, col, row, col);
		}
		used[row][col] = 0;
	}
}

int main()
{
	int t, i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &r, &c);
		getchar();
		gets(buf);
		for (i = 0; i < r * 4; i += 4)
		{
			gets(temp[0]);
			gets(temp[1]);
			gets(temp[2]);
			gets(buf);
			for (j = 0; j < c * 4; j += 4)
			{
				temp2[0][0] = temp[0][j + 1];
				temp2[0][1] = temp[0][j + 2];
				temp2[0][2] = temp[0][j + 3];
				temp2[1][0] = temp[1][j + 1];
				temp2[1][1] = temp[1][j + 2];
				temp2[1][2] = temp[1][j + 3];
				temp2[2][0] = temp[2][j + 1];
				temp2[2][1] = temp[2][j + 2];
				temp2[2][2] = temp[2][j + 3];
				if (temp2[0][0] == temp2[0][1] && temp2[0][1] == temp2[0][2] &&
						temp2[0][2] == temp2[1][0] && temp2[1][0] == temp2[1][1] &&
						temp2[1][1] == temp2[1][2] && temp2[1][2] == temp2[2][0] &&
						temp2[2][0] == temp2[2][1] && temp2[2][1] == temp2[2][2])
				{
					map_[i / 4][j / 4] = -1;
				}
				else if (temp2[1][0] == temp2[1][1] && temp2[1][1] == temp2[1][2] && temp2[1][0] == '*')
				{
					map_[i / 4][j / 4] = 0;
				}
				else if (temp2[0][1] == temp2[1][1] && temp2[1][1] == temp2[2][1] && temp2[0][1] == '*')
				{
					map_[i / 4][j / 4] = 0;
				}
				else
				{
					map_[i / 4][j / 4] = 1;
				}
			}
		}

		for (i = 0; i < r; ++i)
		{
			memset(used, 0, sizeof(int) * c);
		}
		total = 0;
		back(0, 0, 0, 0);
		printf("Number of solutions: %d\n", total);
	}
	return 0;
}
