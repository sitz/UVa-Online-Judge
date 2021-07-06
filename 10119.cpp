#include <bits/stdc++.h>

using namespace std;

#define MAXN 21

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

char map_[MAXN][MAXN], kind[MAXN][MAXN];
int n, k, m, c, depth, candidates[MAXN * MAXN], qx[MAXN * MAXN], qy[MAXN * MAXN];

int check();

void preprocess()
{
	int visited[MAXN][MAXN];
	int qx[MAXN * MAXN], qy[MAXN * MAXN];
	int i, j, x, y, px, py, get, put;
	// flood-fill
	get = 0;
	put = 2;
	qx[0] = 0;
	qy[0] = 0;
	qx[1] = n - 1;
	qy[1] = n - 1;
	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;
	visited[n - 1][n - 1] = 1;
	while (get != put)
	{
		x = qx[get];
		y = qy[get++];
		for (i = 0; i < 4; i++)
		{
			px = x + dx[i];
			py = y + dy[i];
			if (px >= 0 && px <= n - 1 && py >= 0 && py <= n - 1)
				if (!visited[px][py] && map_[px][py] == '.')
				{
					qx[put] = px;
					qy[put++] = py;
					visited[px][py] = 1;
				}
		}
	}
	c = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i + j >= m && 2 * n - 2 - i - j >= m && visited[i][j])
			{
				candidates[++c] = i * n + j;
			}
}

int cantforall(int s)
{
	int i, ret;
	for (i = s; i <= c; i++)
	{
		map_[candidates[i] / n][candidates[i] % n] = '*';
	}
	ret = !check();
	for (i = s; i <= c; i++)
	{
		map_[candidates[i] / n][candidates[i] % n] = '.';
	}
	return ret;
}

int check()
{
	int i, j, x, y, px, py, get, put;
	memcpy(kind, map_, sizeof(kind));
	/* flood-fill from liz's house */
	get = 0;
	put = 1;
	qx[0] = 0;
	qy[0] = 0;
	kind[0][0] = '1';
	while (get != put)
	{
		x = qx[get];
		y = qy[get++];
		for (i = 0; i < 4; i++)
		{
			px = x + dx[i];
			py = y + dy[i];
			if (px >= 0 && px <= n - 1 && py >= 0 && py <= n - 1)
				if (kind[px][py] == '.')
				{
					if (px == n - 1 && py == n - 1)
					{
						return 0; /* can go directly there! */
					}
					qx[put] = px;
					qy[put++] = py;
					kind[px][py] = '1';
				}
		}
	}
	/* flood-fill from lily's house with check */
	get = 0;
	put = 1;
	qx[0] = n - 1;
	qy[0] = n - 1;
	kind[n - 1][n - 1] = '2';
	while (get != put)
	{
		x = qx[get];
		y = qy[get++];
		for (i = 0; i < 4; i++)
		{
			px = x + dx[i];
			py = y + dy[i];
			if (px >= 0 && px <= n - 1 && py >= 0 && py <= n - 1)
				if (kind[px][py] == '.')
				{
					qx[put] = px;
					qy[put++] = py;
					kind[px][py] = '2';
					/* check: for speed reason, we do not use constants here */
					/* up */
					if (px > 0)
					{
						if (kind[px - 1][py] == 'O')
							for (j = 2; j <= k; j++)
							{
								if (px - j < 0)
								{
									break;
								}
								if (kind[px - j][py] == '1')
								{
									return 0;
								}
								if (kind[px - j][py] == '*')
								{
									break;
								}
							}
					}
					/* down */
					if (px < n - 1)
					{
						if (kind[px + 1][py] == 'O')
							for (j = 2; j <= k; j++)
							{
								if (px + j > n - 1)
								{
									break;
								}
								if (kind[px + j][py] == '1')
								{
									return 0;
								}
								if (kind[px + j][py] == '*')
								{
									break;
								}
							}
					}
					/* left */
					if (py > 0)
					{
						if (kind[px][py - 1] == 'O')
							for (j = 2; j <= k; j++)
							{
								if (py - j < 0)
								{
									break;
								}
								if (kind[px][py - j] == '1')
								{
									return 0;
								}
								if (kind[px][py - j] == '*')
								{
									break;
								}
							}
					}
					/* right */
					if (py < n - 1)
					{
						if (kind[px][py + 1] == 'O')
							for (j = 1; j <= k; j++)
							{
								if (py + j > n - 1)
								{
									break;
								}
								if (kind[px][py + j] == '1')
								{
									return 0;
								}
								if (kind[px][py + j] == '*')
								{
									break;
								}
							}
					}
				} /* if kind[px][py]=='.' */
		}
	}
	return 1;
}

/* now depth, starting candidate number */

int search(int d, int s)
{
	int i;
	if (d == depth + 1)
	{
		if (check())
		{
			return 1;
		}
		return 0;
	}
	else
		for (i = c + d - depth; i >= s; i--)
		{
			map_[candidates[i] / n][candidates[i] % n] = '*';
			if (!cantforall(i + 1)) /* a big prune */
				if (search(d + 1, i + 1))
				{
					return 1;
				}
			map_[candidates[i] / n][candidates[i] % n] = '.';
		}
	return 0;
}

int main()
{
	int i;
	char buf[100];
	while (1)
	{
		scanf("%d%d%d", &n, &k, &m);
		if (n == 0 && k == 0 && m == 0)
		{
			break;
		}
		gets(buf);
		for (i = 0; i < n; i++)
		{
			gets(map_[i]);
		}
		preprocess();
		if (cantforall(1))
		{
			printf("-1\n");
		}
		else
			for (depth = 0; depth <= n * n; depth++)
			{
				if (search(1, 1))
				{
					printf("%d\n", depth);
					break;
				}
			}
	}
	return 0;
}
