#include <bits/stdc++.h>

using namespace std;

int n, d, s;
char list_[81], list_x[81], list_y[81], temp[2][81],
	row[10][10], column[10][10], area[4][4][10],
	map_[10][10];

int dfs(int depth)
{
	int i, l, x, y;
	if (depth == -1)
	{
		memcpy(temp[s++], list_, sizeof(list_));
		return 1;
	}
	x = list_x[depth];
	y = list_y[depth];
	if (map_[x][y] != '.')
	{
		return dfs(depth - 1);
	}
	for (i = 9, l = 0; i >= 1; i--)
	{
		if (row[x][i] == 0 && column[y][i] == 0 && area[x / 3][y / 3][i] == 0)
		{
			row[x][i] = column[y][i] = area[x / 3][y / 3][i] = 1;
			list_[depth] = i;
			if (dfs(depth - 1))
			{
				if (s == 2)
				{
					row[x][i] = column[y][i] = area[x / 3][y / 3][i] = 0;
					return 1;
				}
				l = 1;
			}
			row[x][i] = column[y][i] = area[x / 3][y / 3][i] = 0;
		}
	}
	return l;
}

int main()
{
	int cnt, i, j, k, x, y;
	scanf("%d", &cnt);
	while (cnt--)
	{
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(area, 0, sizeof(area));
		for (i = 0, n = 0; i < 9; i++)
		{
			scanf("%s", map_[i]);
			for (j = 0; j < 9; j++)
			{
				if (map_[i][j] == '.')
				{
					list_x[n] = i;
					list_y[n] = j;
					n++;
				}
				else
				{
					row[i][map_[i][j] - '0'] = 1;
					column[j][map_[i][j] - '0'] = 1;
					area[i / 3][j / 3][map_[i][j] - '0'] = 1;
				}
			}
		}
		for (;;)
		{
			s = 0;
			dfs(n - 1);
			if (s < 2)
			{
				break;
			}
			for (i = n - 1; i >= 0; i--)
			{
				if (temp[0][i] != temp[1][i])
				{
					x = list_x[i];
					y = list_y[i];
					map_[x][y] = (j = temp[0][i]) + '0';
					row[x][j] = column[y][j] = area[x / 3][y / 3][j] = 1;
					temp[0][i] = temp[1][i] = 0;
					break;
				}
			}
		}
		for (i = 0; i < 9; i++)
		{
			printf("%s\n", map_[i]);
		}
		if (cnt)
		{
			printf("\n");
		}
	}
	return 0;
}
