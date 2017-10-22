#include <bits/stdc++.h>

using namespace std;

int n, m, lst[10], num[10], aryx[10][500], aryy[10][500];
char board[25][25], board2[25][25], board3[25][25], board4[25][25], used[10], buf[2008];
double ary[4];

int valid(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int dfs(int x, int y)
{
	int i, j, tx, ty, now;
	if (y == n)
	{
		board[x][y] = 0;
		y = 0;
		x++;
		if (x == n)
		{
			return 1;
		}
	}
	if (board[x][y] == -1)
	{
		for (i = 0; i < m; i++)
		{
			if (used[now = lst[i]] == 0)
			{
				for (j = 0; j < num[now]; j++)
				{
					if (valid(tx = x + aryx[now][j], ty = y + aryy[now][j]) == 0 || board[tx][ty] != -1)
					{
						break;
					}
				}
				if (j == num[now])
				{
					used[now] = 1;
					for (j = 0; j < num[now]; j++)
					{
						board[x + aryx[now][j]][y + aryy[now][j]] = now + 48;
					}
					if (dfs(x, y + 1))
					{
						return 1;
					}
					for (j = 0; j < num[now]; j++)
					{
						board[x + aryx[now][j]][y + aryy[now][j]] = -1;
					}
					used[now] = 0;
				}
			}
		}
	}
	else
	{
		return dfs(x, y + 1);
	}
	return 0;
}

int main()
{
	int i, j, k, p, q, temp, step;
	double dtemp, max;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		scanf("%d", &m);
		gets(buf);
		gets(buf);
		memset(num, 0, sizeof(num));
		for (i = 0; i < m; i++)
		{
			for (k = 0; buf[k] == ' '; k++)
				;
			temp = buf[k] - 48;
			lst[i] = temp;
			for (k = 0, step = -1; buf[k]; k++)
			{
				if (buf[k] != ' ')
				{
					if (step == -1)
					{
						step = k;
					}
					aryx[temp][num[temp]] = 0;
					aryy[temp][num[temp]++] = k - step;
				}
			}
			for (j = 1;; j++)
			{
				gets(buf);
				for (k = 0; buf[k] == ' '; k++)
					;
				if (temp != buf[k] - 48)
				{
					break;
				}
				for (; buf[k]; k++)
				{
					if (buf[k] != ' ')
					{
						aryx[temp][num[temp]] = j;
						aryy[temp][num[temp]++] = k - step;
					}
				}
			}
		}
		memset(used, 0, sizeof(used));
		memset(board, -1, sizeof(board));
		dfs(0, 0);
		for (i = 0, ary[0] = 0.0; i < n; i++)
		{
			sscanf(board[i], "%lf", &dtemp);
			ary[0] += dtemp;
		}
		for (i = 0, q = n - 1, ary[1] = 0.0; i < n; i++, q--)
		{
			for (j = 0, p = 0; j < n; j++, p++)
			{
				board2[p][q] = board[i][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			board2[i][n] = 0;
			sscanf(board2[i], "%lf", &dtemp);
			ary[1] += dtemp;
		}
		for (i = 0, p = n - 1, ary[2] = 0.0; i < n; i++, p--)
		{
			for (j = 0, q = n - 1; j < n; j++, q--)
			{
				board3[p][q] = board[i][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			board3[i][n] = 0;
			sscanf(board3[i], "%lf", &dtemp);
			ary[2] += dtemp;
		}
		for (i = 0, q = 0, ary[3] = 0.0; i < n; i++, q++)
		{
			for (j = 0, p = n - 1; j < n; j++, p--)
			{
				board4[p][q] = board[i][j];
			}
		}
		for (i = 0; i < n; i++)
		{
			board4[i][n] = 0;
			sscanf(board4[i], "%lf", &dtemp);
			ary[3] += dtemp;
		}
		for (i = 1, max = ary[0], temp = 0; i < 4; i++)
		{
			if (ary[i] > max)
			{
				max = ary[i];
				temp = i;
			}
		}
		if (temp == 0)
		{
			for (i = 0; i < n; i++)
			{
				puts(board[i]);
			}
		}
		else if (temp == 1)
		{
			for (i = 0; i < n; i++)
			{
				puts(board2[i]);
			}
		}
		else if (temp == 2)
		{
			for (i = 0; i < n; i++)
			{
				puts(board3[i]);
			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				puts(board4[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
