#include <bits/stdc++.h>

using namespace std;

#define OLD 1000010

bool xmap[OLD], ymap[OLD];
int X[OLD], Y[OLD], xv[2015], yv[4015], x1[1015], y1_[1015], x2[1015], y2[1015], xn[2015], yn_[2015], grid[2015][4015], m, n, w;

int main()
{
	int t = 1;
	while (true)
	{
		scanf("%d%d%d", &m, &n, &w);
		if (n == 0 && m == 0 && w == 0)
		{
			break;
		}
		memset(x1, 0, sizeof(x1));
		memset(y1_, 0, sizeof(y1_));
		memset(x2, 0, sizeof(x2));
		memset(y2, 0, sizeof(y2));
		memset(X, 0, sizeof(X));
		memset(xv, 0, sizeof(xv));
		memset(Y, 0, sizeof(Y));
		memset(yv, 0, sizeof(yv));
		memset(xmap, false, sizeof(xmap));
		memset(ymap, false, sizeof(ymap));

		// append start and end cell to the end of the arr[]
		// to get unique x, y coords
		x1[w] = m - 1;
		y1_[w] = 0;
		x2[w] = 0;
		y2[w] = n - 1;

		for (int i = 0; i < w + 1; i++)
		{
			if (i != w)
			{
				scanf("%d%d%d%d", &y1_[i], &x1[i], &y2[i], &x2[i]);
				x1[i] = m - 1 - x1[i];
				x2[i] = m - 1 - x2[i];
			}
			// mark all x,y coords
			xmap[x1[i]] = true;
			xmap[x2[i]] = true;
			ymap[y1_[i]] = true;
			ymap[y2[i]] = true;
		}

		// get lst of unique x,y coords
		memset(xn, 0, sizeof(xn));
		memset(yn_, 0, sizeof(yn_));
		int xsz = 0, ysz = 0;
		for (int i = 0; i < OLD; i++)
		{
			if (xmap[i])
				xn[xsz++] = i;
			if (ymap[i])
				yn_[ysz++] = i;
		}
		sort(xn, xn + xsz);
		sort(yn_, yn_ + ysz);

		// map x coords (xn[]) to new coords
		// set corresponding compressed val of new coord
		X[xn[0]] = 0;
		xv[0] = 1;
		int xind = 1;
		for (int i = 1; i < xsz; i++)
		{
			if (xn[i] - xn[i - 1] > 1)
			{
				xv[xind++] = xn[i] - xn[i - 1] - 1;
			}
			X[xn[i]] = xind;
			xv[xind++] = 1;
		}

		// map y coords (yn_[]) to new coords
		// set corresponding compressed val of new coord
		Y[yn_[0]] = 0;
		yv[0] = 1;
		int yind = 1;
		for (int i = 1; i < ysz; i++)
		{
			if (yn_[i] - yn_[i - 1] > 1)
			{
				yv[yind++] = yn_[i] - yn_[i - 1] - 1;
			}
			Y[yn_[i]] = yind;
			yv[yind++] = 1;
		}

		memset(grid, 0, sizeof(grid));
		long long total = ((long long)m) * ((long long)n);
		// mark all walls in grid after grid compression
		for (int i = 0; i < w; i++)
		{
			int a1 = X[x1[i]];
			int b1 = Y[y1_[i]];
			int b2 = Y[y2[i]];
			for (int j = b1; j <= b2; j++)
			{
				total -= ((long long)xv[a1]) * ((long long)yv[j]);
				grid[a1][j] = -1;
			}
		}

		// dst == blk: all empty cells ~ unreachable
		if (grid[0][yind - 1] == -1)
		{
			printf("Case %d: %lld\n", t++, total);
			continue;
		}

		long long sum = 0LL;
		grid[0][yind - 1] = 1; // mark dst

		// loop over all cells and mark either reachable or not according to i-1,j
		// and i,j+1 and if not reachable, add actual value of this cell to total sum
		for (int i = 0; i < xind; i++)
		{
			for (int j = yind - 1; j >= 0; j--)
			{
				if (i == 0 && j == yind - 1)
				{
					continue;
				}
				if (grid[i][j] == -1)
				{
					continue;
				}
				if (i - 1 >= 0 && grid[i - 1][j] == 1)
				{
					grid[i][j] = 1;
				}
				if (j + 1 < yind && grid[i][j + 1] == 1)
				{
					grid[i][j] = 1;
				}
				if (grid[i][j] == 0)
				{
					sum += ((long long)xv[i]) * ((long long)yv[j]);
				}
			}
		}
		printf("Case %d: %lld\n", t++, sum);
	}
	return 0;
}
