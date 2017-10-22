#include <bits/stdc++.h>

using namespace std;

int map_[605][605], tbl[605][605], stl[605], stx[605];

int main()
{
	int n, m, i, j, k, p, q, c, sn, nx, ans, len, tar;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", &map_[i][0]);
			tbl[i][0] = 0;
			for (j = 0; j < m;)
			{
				for (k = j + 1; k < m; k++)
				{
					scanf("%d", &map_[i][k]);
					if (map_[i][k] > map_[i][k - 1])
					{
						tbl[i][k] = j;
					}
					else
					{
						tbl[i][k] = k;
						break;
					}
				}
				j = k;
			}
		}
		for (j = m - 1, ans = 1; j >= 0; j--)
		{
			for (i = 0, sn = -1; i < n; i++)
			{
				len = j - tbl[i][j] + 1;
				if (i)
				{
					for (p = j - len + 1, q = j, tar = j + 1; p <= q;)
					{
						c = ((p + q) >> 1);
						if (map_[i][c] <= map_[i - 1][j])
						{
							p = c + 1;
						}
						else
						{
							tar = c;
							q = c - 1;
						}
					}
					tar = j - tar + 1;
				}
				for (k = sn, nx = i; k >= 0; k--)
				{
					if (stl[k] >= len)
					{
						if (stl[k] * (i - stx[k]) > ans)
						{
							ans = stl[k] * (i - stx[k]);
						}
						if (map_[i][j - len + 1] > map_[i - 1][j])
						{
							nx = stx[k];
						}
						else if (tar && (k == 0 || stl[k - 1] < tar))
						{
							stl[k] = tar;
							break;
						}
					}
					else if (map_[i][j - stl[k] + 1] <= map_[i - 1][j])
					{
						if (stl[k] * (i - stx[k]) > ans)
						{
							ans = stl[k] * (i - stx[k]);
						}
						if (tar && (k == 0 || stl[k - 1] < tar))
						{
							stl[k] = tar;
							break;
						}
					}
					else
					{
						break;
					}
				}
				k++;
				stl[k] = len;
				stx[k] = nx;
				sn = k;
			}
			for (k = sn; k >= 0; k--)
			{
				if (stl[k] * (i - stx[k]) > ans)
				{
					ans = stl[k] * (i - stx[k]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
