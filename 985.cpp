#include <bits/stdc++.h>

using namespace std;

char str[1000];
int n, m, hash_[127], map_[501][501][4], used[4][501][501], queuex[1000001], queuey[1000001], step[1000001];
int wayx[4] = {-1, 0, 1, 0}, wayy[4] = {0, 1, 0, -1};

int valid(int x, int y)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int main()
{
	int i, j, k, s, x, y, tx, ty, temp;
	hash_['N'] = 0;
	hash_['E'] = 1;
	hash_['S'] = 2;
	hash_['W'] = 3;
	while (scanf("%d%d", &n, &m) == 2)
	{
		gets(str);
		memset(map_, 0, sizeof(map_));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (i == n - 1 && j == m - 1)
				{
					break;
				}
				gets(str);
				for (k = 0; str[k]; k++)
				{
					map_[i][j][hash_[str[k]]] = 1;
				}
			}
		}
		memset(used, 0, sizeof(used));
		queuex[0] = 0;
		queuey[0] = 0;
		step[0] = 0;
		for (i = 0, j = 1; i < j; i++)
		{
			x = queuex[i];
			y = queuey[i];
			s = step[i];
			for (k = 0; k < 4; k++)
			{
				if (map_[x][y][k])
				{
					temp = s % 4;
					tx = x + wayx[(temp + k) % 4];
					ty = y + wayy[(temp + k) % 4];
					if (valid(tx, ty) && !used[temp][tx][ty])
					{
						if (tx == n - 1 && ty == m - 1)
						{
							break;
						}
						used[temp][tx][ty] = 1;
						queuex[j] = tx;
						queuey[j] = ty;
						step[j++] = s + 1;
					}
				}
			}
			if (k < 4)
			{
				break;
			}
		}
		if (i == j)
		{
			printf("no path to exit\n");
		}
		else
		{
			printf("%d\n", s + 1);
		}
	}
	return 0;
}
