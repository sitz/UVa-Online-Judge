#include <bits/stdc++.h>

using namespace std;

int B[1005][1005] = {0}, D[1005][1005], X[1000005], Y[1000005], ptr, len, SX[4] = {0, 1, 0, -1}, SY[4] = {1, 0, -1, 0};
int main()
{
	int t, r, c, rn, i, j, cn, x, y, nx, ny, ex, ey;
	for (t = 1; scanf("%d%d", &r, &c) == 2; t++)
	{
		if ((r | c) == 0)
		{
			break;
		}
		scanf("%d", &rn);
		while (rn--)
		{
			scanf("%d%d", &i, &cn);
			while (cn--)
			{
				scanf("%d", &j);
				B[i][j] = t;
			}
		}
		scanf("%d%d%d%d", &X, &Y, &ex, &ey);
		D[X[0]][Y[0]] = 0, B[X[0]][Y[0]] = t, len = 1;
		for (ptr = 0; ptr < len; ptr++)
		{
			x = X[ptr], y = Y[ptr];
			if (x == ex && y == ey)
			{
				break;
			}
			for (i = 0; i < 4; i++)
			{
				nx = x + SX[i], ny = y + SY[i];
				if (nx < 0 || ny < 0 || nx >= r || ny >= c || B[nx][ny] == t)
				{
					continue;
				}
				B[nx][ny] = t, D[nx][ny] = D[x][y] + 1;
				X[len] = nx, Y[len] = ny, len++;
			}
		}
		printf("%d\n", D[x][y]);
	}
	return 0;
}
