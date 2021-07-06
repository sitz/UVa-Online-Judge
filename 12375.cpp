#include <bits/stdc++.h>

using namespace std;

const int fl[4][2] = {-1, -1, -1, 1, 1, 1, 1, -1}, f[4][2] = {-1, -1, -1, 0, 0, 0, 0, -1};

double ans[10001];
int i, j, n, m, le, ri, l[10001][2], ma[105][105], map_[105][105], s, q, x, y, x0, y0_, nx, ny, ans0;

int main()
{
	int k;
	scanf("%d", &k);
	s = 0;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		s++;
		ans0 = -1;
		getchar();
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				k = getchar();
				map_[i][j] = k - '0';
			}
			getchar();
		}
		for (i = 0; i <= n; i++)
			for (j = 0; j <= m; j++)
			{
				ma[i][j] = -1;
			}
		printf("Case %d:\n", s);
		scanf("%d", &q);
		for (k = 1; k <= q; k++)
		{
			scanf("%d%d", &x, &y);
			if ((x + y) % 2 == 1)
			{
				printf("0.0000\n");
				continue;
			}
			if (x % 2 == 1)
			{
				if (map_[x / 2][y / 2])
				{
					x--;
					y--;
				}
				else
				{
					x--;
					y++;
				}
			}
			if (ma[x / 2][y / 2] == -1)
			{
				ans0++;
				ans[ans0] = 0.0;
				l[1][0] = x / 2;
				l[1][1] = y / 2;
				le = 1;
				ri = 1;
				ma[x / 2][y / 2] = ans0;
				while (le <= ri)
				{
					for (i = 0; i < 4; i++)
					{
						nx = l[le][0] + f[i][0];
						ny = l[le][1] + f[i][1];
						x0 = l[le][0] + fl[i][0];
						y0_ = l[le][1] + fl[i][1];
						if (nx >= n || nx < 0)
						{
							continue;
						}
						if (ny >= m || ny < 0)
						{
							continue;
						}
						if ((map_[nx][ny] ^ (i % 2)) && (ma[x0][y0_] == -1))
						{
							ri++;
							l[ri][0] = x0;
							l[ri][1] = y0_;
							ma[x0][y0_] = ans0;
						}
						if (map_[nx][ny] ^ (i % 2))
						{
							ans[ans0] += 2.0f - M_PI / 4.0f;
						}
						else
						{
							ans[ans0] += M_PI / 4.0f;
						}
					}
					le++;
				}
			}
			printf("%.4lf\n", ans[ma[x / 2][y / 2]]);
		}
	}
	return 0;
}
