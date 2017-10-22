#include <bits/stdc++.h>

using namespace std;

#define INF 0x7ff00000

char grid[1010][11];
int x, f[1010][11];

int doit()
{
	int i, j;
	f[0][0] = 0;
	for (i = 1; i < x; i++)
	{
		for (j = 1; j < 9; j++)
		{
			f[i][j] = min(30 - (int)grid[i - 1][j] + f[i - 1][j],
					min(20 - (int)grid[i - 1][j + 1] + f[i - 1][j + 1],
							60 - (int)grid[i - 1][j - 1] + f[i - 1][j - 1]));
		}
		f[i][9] = min(30 - (int)grid[i - 1][9] + f[i - 1][9],
					60 - (int)grid[i - 1][8] + f[i - 1][8]);
	}
	i = x;
	f[i][0] = min(20 - (int)grid[i - 1][1] + f[i - 1][1], INF);
	return f[x][0];
}

int main()
{
	int nu;
	cin >> nu;
	while (nu--)
	{
		cin >> x;
		x /= 100;
		int i, j;
		for (i = 9; i >= 0; i--)
		{
			for (j = 0; j < x; j++)
			{
				int k;
				cin >> k;
				grid[j][i] = k;
				f[j][i] = INF;
			}
			f[j][i] = INF;
		}
		cout << doit() << endl << endl;
	}
	return 0;
}
