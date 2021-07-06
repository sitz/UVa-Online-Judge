#include <bits/stdc++.h>

using namespace std;

char square[110][110];
int n, m;

bool isInTheSquare(int x, int y)
{
	if (x < 0 || x >= n)
	{
		return false;
	}
	if (y < 0 || y >= m)
	{
		return false;
	}
	return true;
}

int main()
{
	int kase = 1;
	int i, j;
	int f = 0;
	while (cin >> n >> m && n)
	{
		if (f)
		{
			cout << endl;
		}
		f = 1;
		for (i = 0; i < n; i++)
		{
			cin >> square[i];
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				if (square[i][j] == '.')
				{
					int cnt = 0;
					if (isInTheSquare(i - 1, j - 1) && square[i - 1][j - 1] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i - 1, j) && square[i - 1][j] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i - 1, j + 1) && square[i - 1][j + 1] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i, j - 1) && square[i][j - 1] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i, j + 1) && square[i][j + 1] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i + 1, j - 1) && square[i + 1][j - 1] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i + 1, j) && square[i + 1][j] == '*')
					{
						cnt++;
					}
					if (isInTheSquare(i + 1, j + 1) && square[i + 1][j + 1] == '*')
					{
						cnt++;
					}
					square[i][j] = '0' + cnt;
				}
			}
		cout << "Field #" << kase++ << ":" << endl;
		for (i = 0; i < n; i++)
		{
			cout << square[i] << endl;
		}
	}
	return 0;
}
