#include <bits/stdc++.h>

using namespace std;

// map_[][]: 0-white, -1-black, -2-wall, >0-number
int m, n, map_[32][32];

void Fill(int x, int y)
{
	if (map_[y][x] == -1)
	{
		map_[y][x] = -2;
		Fill(x + 1, y);
		Fill(x - 1, y);
		Fill(x, y + 1);
		Fill(x, y - 1);
	}
}

char output[32 * 3 + 1][32 * 5 + 1];

int main()
{
	while (scanf("%d %d", &m, &n) == 2)
	{
		if (m == 0 && n == 0)
		{
			break;
		}
		int i, j, counter = 1;
		for (i = 0; i < m + 2; i++)
		{
			for (j = 0; j < n + 2; j++)
			{
				map_[i][j] = -1;
			}
		}
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int t;
				scanf("%d", &t);
				map_[i][j] = -t;
			}
		}
		Fill(0, 0);
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (map_[i][j] != 0)
				{
					continue;
				}
				if ((map_[i][j - 1] < 0 && map_[i][j + 1] >= 0) ||
						(map_[i - 1][j] < 0 && map_[i + 1][j] >= 0))
				{
					map_[i][j] = counter++;
				}
			}
		}
		memset(output, ' ', (32 * 5 + 1) * (32 * 3 + 1));
		for (i = 1; i <= m; i++)
		{
			for (j = 1; j <= n; j++)
			{
				int a, b;
				int ox = (j - 1) * 5, oy = (i - 1) * 3;
				if (map_[i][j] == -2)
				{
					continue;
				}
				for (a = 0; a < 6; a++)
				{
					output[oy][ox + a] = output[oy + 3][ox + a] = '+';
				}
				for (a = 0; a < 4; a++)
				{
					output[oy + a][ox] = output[oy + a][ox + 5] = '+';
				}
				if (map_[i][j] == -1)
					for (a = 0; a < 4; a++)
						for (b = 0; b < 6; b++)
						{
							output[oy + a][ox + b] = '+';
						}
				if (map_[i][j] > 0)
				{
					output[oy + 1][ox + 1 + 0] = '0' + map_[i][j] / 100;
					output[oy + 1][ox + 1 + 1] = '0' + (map_[i][j] / 10) % 10;
					output[oy + 1][ox + 1 + 2] = '0' + map_[i][j] % 10;
				}
			}
		}
		// 1.no skip 2.skip empty 3.skip upper/lower empty
		int o_width = n * 5 + 1, o_height = m * 3 + 1;
		int start = 0, end = o_height - 1;
		for (i = start; i <= end; i++)
		{
			int r;
			for (r = o_width - 1; r >= 0 && output[i][r] == ' '; r--)
				;
			for (j = 0; j <= r; j++)
			{
				putchar(output[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');
	}
}
