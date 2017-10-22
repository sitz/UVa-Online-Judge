#include <bits/stdc++.h>

using namespace std;

char way[6][3] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};

char ary[10][10][11], queue_[1001][3], chk[21][21][21], rgb[3] = {'R', 'G', 'B'}, ans, color;
int conum[3], n;

char valid(int x, int y, int z)
{
	return x > -1 && x < n && y > -1 && y < n && z > -1 && z < n;
}

char chkmov(int x, int y, int z, char col)
{
	return !ary[x][y][z] || ary[x][y][z] == col;
}

char chkvalid(int x, int y, int z)
{
	return x >= -n && x <= n && y >= -n && y <= n && z >= -n && z <= n;
}

char movable(int type, char col)
{
	int i, j, k, it, jt, kt;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (ary[i][j][k] == col)
				{
					it = i + way[type][0];
					jt = j + way[type][1];
					kt = k + way[type][2];
					if (valid(it, jt, kt) && ary[it][jt][kt] != col)
					{
						return 0;
					}
				}
			}
		}
	}
	return 1;
}

void remove(char col)
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (ary[i][j][k] == col)
				{
					ary[i][j][k] = 0;
				}
			}
		}
	}
}

void move(char col, int num)
{
	int i, j, k, l, p, q, x, y, z, xt, yt, zt, c;
	for (p = 0, q = 1; p < q; p++)
	{
		x = queue_[p][0];
		y = queue_[p][1];
		z = queue_[p][2];
		for (l = 0; l < 6; l++)
		{
			xt = x + way[l][0];
			yt = y + way[l][1];
			zt = z + way[l][2];
			if (chkvalid(xt, yt, zt) && chk[xt + 10][yt + 10][zt + 10])
			{
				chk[xt + 10][yt + 10][zt + 10] = 0;
				for (i = 0, c = 0; i < n; i++)
				{
					for (j = 0; j < n; j++)
					{
						for (k = 0; k < n; k++)
						{
							if (ary[i][j][k] == col)
							{
								if (valid(i + xt, j + yt, k + zt))
								{
									if (!chkmov(i + xt, j + yt, k + zt, col))
									{
										break;
									}
								}
								else
								{
									c++;
								}
							}
						}
						if (k < n)
						{
							break;
						}
					}
					if (j < n)
					{
						break;
					}
				}
				if (i == n)
				{
					if (c == num)
					{
						ans = 3;
						return;
					}
					else
					{
						queue_[q][0] = xt;
						queue_[q][1] = yt;
						queue_[q++][2] = zt;
					}
				}
			}
		}
	}
}

int main()
{
	int i, j, k;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0, conum[0] = conum[1] = conum[2] = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				scanf("%s", &ary[i][j]);
				for (k = 0; k < n; k++)
				{
					if (ary[i][j][k] == 'R')
					{
						conum[0]++;
					}
					else if (ary[i][j][k] == 'G')
					{
						conum[1]++;
					}
					else
					{
						conum[2]++;
					}
				}
			}
		}
		ans = 0;
		for (i = 0; i < 6; i++)
		{
			if (movable(i, 'R'))
			{
				ans++;
				color = 'R';
				conum[0] = 0;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (movable(i, 'G'))
			{
				ans++;
				color = 'G';
				conum[1] = 0;
				break;
			}
		}
		for (i = 0; i < 6; i++)
		{
			if (movable(i, 'B'))
			{
				ans++;
				color = 'B';
				conum[2] = 0;
				break;
			}
		}
		if (ans)
		{
			if (ans > 1)
			{
				printf("RGB\n");
			}
			else
			{
				remove(color);
				for (i = 0, j = 1001; i < 3; i++)
				{
					if (conum[i])
					{
						if (conum[i] < j)
						{
							j = conum[i];
							k = i;
						}
					}
				}
				memset(chk, 1, sizeof(chk));
				queue_[0][0] = queue_[0][1] = queue_[0][2] = chk[10][10][10] = 0;
				move(rgb[k], conum[k]);
				if (ans == 3)
				{
					printf("RGB\n");
				}
				else
				{
					printf("%c\n", color);
				}
			}
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}
