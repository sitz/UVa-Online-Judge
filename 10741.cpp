#include <bits/stdc++.h>

using namespace std;

int cube[25][25][25], n;
int main()
{
	int caseno = 0;
	while (scanf("%d", &n), n)
	{
		if (caseno++)
		{
			puts("");
		}
		memset(cube, 0, sizeof(cube));
		int n2 = n * n, n3 = n2 * n;
		int x = n / 2, y = n / 2, z = n - 1, nx, ny, nz;
		for (int i = 0; i < n2; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cube[z][y][x] = i * n + j;
				z = (z + 1) % n;
				x = (x + 1) % n;
			}
			ny = (y + n - 1) % n;
			nx = (x + n - 1) % n;
			if (!cube[z][ny][nx])
			{
				y = ny;
				x = nx;
			}
			else
			{
				z = (z + n - 2) % n;
				x = (x + n - 1) % n;
			}
		}
		for (int i = 0; i < n; i++)
		{
			if (i)
			{
				puts("");
			}
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (k)
					{
						putchar(' ');
					}
					printf("%5d", cube[i][j][k]);
				}
				printf("\n");
			}
		}
	}
}
