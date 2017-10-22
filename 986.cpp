#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x, y, r, k, _n, _r, _k;
ll c[40][21][21][20][2];
int main()
{
	while (scanf("%lld %lld %lld\n", &_n, &_r, &_k) == 3)
	{
		memset(c, 0, sizeof c);
		for (k = 1; k < 20; k++)
		{
			c[1][1][0][k][1] = 1;
		}
		for (x = 2; x < 40; x++)
		{
			for (r = 0; r < 20; r++)
			{
				for (k = 1; k < 20; k++)
				{
					c[x][1][r][k][1] += c[x - 1][0][r][k][0];
				}
				for (y = 1; y < 20; y++)
				{
					for (k = 1; k < y; k++)
					{
						c[x][y - 1][r][k][0] += c[x - 1][y][r][k][1];
					}
					c[x][y - 1][r + 1][y][0] += c[x - 1][y][r][k][1];
					for (k = y + 1; k < 20; k++)
					{
						c[x][y - 1][r][k][0] += c[x - 1][y][r][k][1];
					}
					for (k = 1; k < 20; k++)
					{
						c[x][y - 1][r][k][0] += c[x - 1][y][r][k][0];
						c[x][y + 1][r][k][1] += c[x - 1][y][r][k][0];
						c[x][y + 1][r][k][1] += c[x - 1][y][r][k][1];
					}
				}
			}
		}
		printf("%lld\n", c[_n << 1][0][_r][_k][0]);
	}
	return 0;
}
