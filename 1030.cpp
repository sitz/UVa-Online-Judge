#include <bits/stdc++.h>

using namespace std;

char view[6][15][15], mp[15][15][15], n;

void get(int i, int j, int k, int dep, int &x, int &y, int &z)
{
	switch (i)
	{
	case 0:
		x = j;
		y = k;
		z = dep;
		break;
	case 1:
		x = j;
		y = dep;
		z = n - k - 1;
		break;
	case 2:
		x = j;
		y = n - k - 1;
		z = n - dep - 1;
		break;
	case 3:
		x = j;
		y = n - dep - 1;
		z = k;
		break;
	case 4:
		x = dep;
		y = k;
		z = n - j - 1;
		break;
	case 5:
		x = n - dep - 1;
		y = k;
		z = j;
		break;
	}
}

char read_char()
{
	char ch;
	while (true)
	{
		ch = getchar();
		if ((ch >= 'A' && ch <= 'Z') || ch == '.')
		{
			return ch;
		}
	}
}

int main()
{
	int x, y, z;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					view[j][i][k] = read_char();
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					mp[i][j][k] = '#';
				}
			}
		}
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					if (view[i][j][k] == '.')
					{
						for (int dep = 0; dep < n; ++dep)
						{
							get(i, j, k, dep, x, y, z);
							mp[x][y][z] = '.';
						}
					}
				}
			}
		}

		while (true)
		{
			bool done(true);
			for (int i = 0; i < 6; ++i)
				for (int j = 0; j < n; ++j)
					for (int k = 0; k < n; ++k)
						if (view[i][j][k] != '.')
							for (int dep = 0; dep < n; ++dep)
							{
								get(i, j, k, dep, x, y, z);
								if (mp[x][y][z] == '.')
								{
									continue;
								}
								if (mp[x][y][z] == '#')
								{
									mp[x][y][z] = view[i][j][k];
									break;
								}
								if (mp[x][y][z] == view[i][j][k])
								{
									break;
								}
								mp[x][y][z] = '.';
								done = false;
							}
			if (done)
			{
				break;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int k = 0; k < n; ++k)
				{
					if (mp[i][j][k] != '.')
					{
						++ans;
					}
				}
			}
		}
		printf("Maximum weight: %d gram(s)\n", ans);
	}
	return 0;
}
