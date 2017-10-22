#include <bits/stdc++.h>

using namespace std;

static int tbl[20][200], sum[20][200], x, y, best[2];
static queue<int> path;

int main()
{
	while (scanf("%d%d", &x, &y) == 2)
	{
		// read tbl
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				scanf("%d", &tbl[i][j]);
			}
		}

		// prepare sum[]
		for (int i = 0; i < x; i++)
		{
			sum[i][y - 1] = tbl[i][y - 1];
		}

		// dp
		for (int j = y - 2; j >= 0; j--)
		{
			for (int i = 0; i < x; i++)
			{
				long a = sum[(i + x - 1) % x][j + 1], b = sum[i][j + 1], c = sum[(i + x + 1) % x][j + 1];
				sum[i][j] = min(a, min(b, c)) + tbl[i][j];
			}
		}

		// find min
		int min = sum[0][0];
		best[0] = 0;
		best[1] = 0;
		for (int i = 1; i < x; i++)
		{
			if (sum[i][0] < min)
			{
				min = sum[i][0];
				best[0] = i;
			}
		}

		// trk lexicographical path
		path.push(best[0]);
		for (int j = 1; j < y; j++)
		{
			long a = sum[best[0]][j - 1] - tbl[best[0]][j - 1];
			int m = x + 1;
			if (sum[(x + best[0] - 1) % x][j] == a)
			{
				if ((x + best[0] - 1) % x < m)
				{
					m = (x + best[0] - 1) % x;
				}
			}
			if (sum[(x + best[0] + 1) % x][j] == a)
			{
				if ((x + best[0] + 1) % x < m)
				{
					m = (x + best[0] + 1) % x;
				}
			}
			if (sum[best[0]][j] == a)
			{
				if (best[0] < m)
				{
					m = best[0];
				}
			}
			best[0] = m;
			path.push(m);
		}

		// print out path + min res
		int c = 0;
		while (!path.empty())
		{
			if (c > 0)
			{
				printf(" ");
			}
			c++;
			printf("%d", path.front() + 1);
			path.pop();
		}
		printf("\n%d\n", min);
	}
	return 0;
}
