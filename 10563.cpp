#include <bits/stdc++.h>

using namespace std;

char board[110][110];

char find(int n, int i, int j)
{
	char color = 'A';
	while (1)
	{
		if ((!i || board[i - 1][j] != color) &&
				(!j || board[i][j - 1] != color) &&
				(j == n - 1 || board[i][j + 1] != color))
		{
			break;
		}
		color++;
	}
	return color;
}

int isok(int m, int n, int i, int j, int len)
{
	int k;
	if (i + len < m && j + len < n)
	{
		for (k = 0; k <= len; k++)
			if (board[i + k][j + len] != '?' || board[i + len][j + k] != '?')
			{
				return 0;
			}
		return 1;
	}
	else
	{
		return 0;
	}
}

void search(int m, int n, int i, int j)
{
	char c1, c2;
	int len, k;
	c1 = find(n, i, j);
	board[i][j] = c1;
	len = 0;
	while (++len)
	{
		if (j + len >= n || board[i][j + len] != '?')
		{
			break;
		}
		c2 = find(n, i, j + len);
		if (c2 < c1)
		{
			break;
		}
		if (isok(m, n, i, j, len) && (j + len + 1 >= n || board[i][j + len + 1] != c1) && (!i || board[i - 1][j + len] != c1))
		{
			for (k = 0; k <= len; k++)
			{
				board[i + k][j + len] = board[i + len][j + k] = c1;
			}
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int m, n, i, j;
	int first = 0;
	while (1)
	{
		cin >> m >> n;
		if (!n && !m)
		{
			break;
		}
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++)
			{
				if (board[i][j] == '?')
				{
					search(m, n, i, j);
				}
			}
		if (first++)
		{
			cout << endl;
		}
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				cout << board[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
