#include <bits/stdc++.h>

using namespace std;

int cost[1000], h[1000], l[1000][20];
int n, m, kk;
int t;
int dist(int x, int y)
{
	return x * x + y * y;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
int min(int a, int b)
{
	return (a < b) ? a : b;
}
int cross(int x1, int y1, int x2, int y2)
{
	return x1 * y2 - y1 * x2;
}
bool intersect(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	if (x2 >= x3 && x4 >= x1 && cross(x3 - x1, y3 - y1, x2 - x1, y2 - y1) * cross(x4 - x1, y4 - y1, x2 - x1, y2 - y1) <= 0 && cross(x1 - x3, y1 - y3, x4 - x3, y4 - y3) * cross(x2 - x3, y2 - y3, x4 - x3, y4 - y4) <= 0)
	{
		return true;
	}
	return false;
}
bool check(int x1, int y1, int x2, int y2, int t1, int t2)
{
	int p = min(y1, y2), q = max(y1, y2);
	for (int i = p + 1; i < q; i++)
	{
		if (l[t1][i] && intersect(x1, y1, x2, y2, 0, i, l[t1][i], i))
		{
			return false;
		}
		if (l[t2][i] && intersect(x1, y1, x2, y2, m - l[t2][i], i, m, i))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &t);
	for (; t; t--)
	{
		scanf("%d %d %d", &n, &m, &kk);
		memset(l, 0, sizeof(l));
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &h[i]);
			for (int j = 0; j < h[i]; j++)
			{
				scanf("%d", &l[i][j]);
			}
		}
		for (int i = 1; i < n; i++)
		{
			cost[i] = cost[i - 1] + m;
			for (int j = 0; j < h[i - 1]; j++)
			{
				for (int k = 0; k < h[i]; k++)
				{
					if (dist(j - k, m - l[i - 1][j] - l[i][k]) > kk * kk)
					{
						continue;
					}
					if (!check(l[i - 1][j], j, m - l[i][k], k, i - 1, i))
					{
						continue;
					}
					if (cost[i - 1] + l[i - 1][j] + l[i][k] < cost[i])
					{
						cost[i] = cost[i - 1] + l[i - 1][j] + l[i][k];
					}
				}
			}
		}
		printf("%d\n", cost[n - 1]);
	}
	return 0;
}
