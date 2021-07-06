#include <bits/stdc++.h>

using namespace std;

#define get(i, j, m) (((1 << (i * c + j)) & m) != 0)
#define flip(i, j, m) (m ^= 1 << (i * c + j))
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
int r, c;
int dp[4][4][1 << 16];
int nWays(int mask)
{
	if (dp[r - 1][c - 1][mask] != -1)
	{
		return dp[r - 1][c - 1][mask];
	}
	int i, j, k, x1, x2, y1, y2, res = 0, mask2;
	for (i = 0; i < r; i++)
		for (j = 0; j < c; j++)
			if (get(i, j, mask))
				for (k = 0; k < 8; k++)
				{
					x1 = i + dx[k];
					y1 = j + dy[k];
					x2 = i + 2 * dx[k];
					y2 = j + 2 * dy[k];
					if (x1 >= 0 && y1 >= 0 && x2 >= 0 && y2 >= 0 && x1 < r && x2 < r && y1 < c && y2 < c && get(x1, y1, mask) && !get(x2, y2, mask))
					{
						mask2 = mask;
						flip(i, j, mask2);
						flip(x1, y1, mask2);
						flip(x2, y2, mask2);
						res += nWays(mask2);
					}
				}
	return dp[r - 1][c - 1][mask] = res;
}
int main(int argc, char *argv[])
{
	int tc, tcc = 1, blobs, i, j, k, x, y, x1, y1, x2, y2, mask, mask2;
	scanf("%d", &tc);
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
		{
			for (k = 0; k < 1 << 16; k++)
			{
				dp[i][j][k] = -1;
			}
			for (k = 0; k < 16; k++)
			{
				dp[i][j][1 << k] = 1;
			}
			dp[i][j][0] = 0;
		}
	for (tcc = 1; tcc <= tc; tcc++)
	{
		scanf("%d %d %d", &r, &c, &blobs);
		mask = 0;
		for (i = 0; i < blobs; i++)
		{
			scanf("%d %d", &x, &y);
			x--;
			y--;
			flip(x, y, mask);
		}
		printf("Case %d: %d\n", tcc, nWays(mask));
	}
	return 0;
}
