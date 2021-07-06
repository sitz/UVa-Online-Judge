#include <bits/stdc++.h>

using namespace std;

char board[15][15], boardcopy[15][15];

bool inside(int x, int y)
{
	return !(x < 0 || x > 9 || y < 0 || y > 9);
}

void setLight(int x, int y)
{
	if (board[x][y] == '#')
	{
		board[x][y] = 'O';
	}
	else
	{
		board[x][y] = '#';
	}
}

void on(int x, int y)
{
	if (inside(x, y))
	{
		board[x][y] = 'O';
		if (inside(x - 1, y))
		{
			setLight(x - 1, y);
		}
		if (inside(x + 1, y))
		{
			setLight(x + 1, y);
		}
		if (inside(x, y - 1))
		{
			setLight(x, y - 1);
		}
		if (inside(x, y + 1))
		{
			setLight(x, y + 1);
		}
	}
}

void off(int x, int y)
{
	if (inside(x, y))
	{
		board[x][y] = '#';
		if (inside(x - 1, y))
		{
			setLight(x - 1, y);
		}
		if (inside(x + 1, y))
		{
			setLight(x + 1, y);
		}
		if (inside(x, y - 1))
		{
			setLight(x, y - 1);
		}
		if (inside(x, y + 1))
		{
			setLight(x, y + 1);
		}
	}
}

bool check()
{
	for (int i = 0; i < 10; i++)
		if (board[9][i] == 'O')
		{
			return false;
		}
	return true;
}

int solve()
{
	int i, j;
	int cnt = 0;
	for (i = 1; i < 10; i++)
		for (j = 0; j < 10; j++)
			if (board[i - 1][j] == 'O')
			{
				if (board[i][j] == '#')
				{
					on(i, j);
				}
				else
				{
					off(i, j);
				}
				cnt++;
			}
	if (check())
	{
		return cnt;
	}
	else
	{
		return 100000000;
	}
}

int main()
{
	char name[100];
	while (cin >> name && strcmp(name, "end"))
	{
		int i, j;
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
			{
				cin >> board[i][j];
				boardcopy[i][j] = board[i][j];
			}
		int state;
		int min = 100000000;
		for (state = 0; state < 1024; state++)
		{
			int temp = state;
			int index = 0;
			int cntStep = 0;
			while (temp)
			{
				if (temp % 2 == 1)
				{
					if (board[0][index] == '#')
					{
						on(0, index);
					}
					else
					{
						off(0, index);
					}
					cntStep++;
				}
				temp /= 2;
				index++;
			}
			int r = solve();
			if (r + cntStep < min)
			{
				min = r + cntStep;
			}
			for (i = 0; i < 10; i++)
				for (j = 0; j < 10; j++)
				{
					board[i][j] = boardcopy[i][j];
				}
		}
		if (min == 100000000)
		{
			cout << name << " " << 0 << endl;
		}
		else
		{
			cout << name << " " << min << endl;
		}
	}
	return 0;
}
