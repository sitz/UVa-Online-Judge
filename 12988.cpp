#include <bits/stdc++.h>

using namespace std;

char c[4][5];
bool row[4][5], col[4][5], blk[4][5];

bool DFS(int O)
{
	if (O == 16)
	{
		for (int i = 0; i < 4; i++)
			puts(c[i]);

		return true;
	}
	else
	{
		int x = O / 4, y = O % 4, z = x / 2 * 2 + y / 2;

		if (c[x][y] != '*')
			return DFS(O + 1);
		else
		{
			for (int i = 1; i <= 4; i++)
			{
				if (row[x][i] || col[y][i] || blk[z][i])
					continue;

				row[x][i] = col[y][i] = blk[z][i] = true;
				c[x][y] = '0' + i;

				if (DFS(O + 1))
					return true;

				row[x][i] = col[y][i] = blk[z][i] = false;
			}

			c[x][y] = '*';
			return false;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int Ti = 1; Ti <= T; Ti++)
	{
		for (int i = 0; i < 4; i++)
			scanf("%s", c[i]);

		printf("Case #%d:\n", Ti);

		fill(row[0], row[3] + 5, false);
		fill(col[0], col[3] + 5, false);
		fill(blk[0], blk[3] + 5, false);

		for (int i = 0; i < 16; i++)
		{
			int x = i / 4, y = i % 4, z = x / 2 * 2 + y / 2, n = c[x][y] - '0';

			if (c[x][y] == '*')
				continue;

			row[x][n] = col[y][n] = blk[z][n] = true;
		}

		DFS(0);
	}
}
