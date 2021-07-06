#include <bits/stdc++.h>

using namespace std;

#define INF 0x7FFFFFFF
int l, r, c, x, y, z, X[6] = {1, -1, 0, 0, 0, 0}, Y[6] = {0, 0, 1, -1, 0, 0}, Z[6] = {0, 0, 0, 0, 1, -1}, Qx[28000], Qy[28000], Qz[28000], ptr, len, L[35][35][35];
char D[35][35][35];
void push(int tx, int ty, int tz, int ll)
{
	if (D[tx][ty][tz] == '#' || L[tx][ty][tz] != INF)
	{
		return;
	}
	L[Qx[len] = tx][Qy[len] = ty][Qz[len] = tz] = ll + 1;
	len++;
}
void pop()
{
	x = Qx[ptr];
	y = Qy[ptr];
	z = Qz[ptr];
}
int main()
{
	int i, j, k;
	for (i = 0; i < 35; i++)
	{
		for (j = 0; j < 35; j++)
		{
			D[0][i][j] = D[j][0][i] = D[i][j][0] = '#';
		}
	}
	while (scanf("%d%d%d", &l, &r, &c) == 3)
	{
		if ((l | r | c) == 0)
		{
			break;
		}
		for (i = 1; i <= l; i++)
		{
			for (j = 1; j <= r; j++)
			{
				scanf("%s", D[i][j] + 1);
				for (k = 1; k <= c; k++)
				{
					L[i][j][k] = INF;
					if (D[i][j][k] != 'S')
					{
						continue;
					}
					x = i;
					y = j;
					z = k;
				}
			}
		}
		for (i = 1; i <= l; i++)
		{
			for (j = 1; j <= r; j++)
			{
				D[i][j][c + 1] = '#';
			}
		}
		for (j = 1; j <= r; j++)
		{
			for (k = 1; k <= c; k++)
			{
				D[l + 1][j][k] = '#';
			}
		}
		for (k = 1; k <= c; k++)
		{
			for (i = 1; i <= l; i++)
			{
				D[i][r + 1][k] = '#';
			}
		}
		len = 0;
		push(x, y, z, -1);
		for (ptr = 0; ptr < len; ptr++)
		{
			pop();
			if (D[x][y][z] == 'E')
			{
				break;
			}
			for (i = 0; i < 6; i++)
			{
				push(x + X[i], y + Y[i], z + Z[i], L[x][y][z]);
			}
		}
		if (D[x][y][z] == 'E')
		{
			printf("Escaped in %d minute(s).\n", L[x][y][z]);
		}
		else
		{
			printf("Trapped!\n");
		}
	}
	return 0;
}
