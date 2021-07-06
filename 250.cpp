#include <bits/stdc++.h>

using namespace std;

double ary[30][30];

double ab(double now)
{
	if (now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int cas, n, m, i, j, x, y;
	double d, diff;
	cas = 0;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (!n && !m)
		{
			break;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= m; j++)
			{
				scanf("%lf", &ary[i][j]);
				ary[i][j] += ary[i - 1][j] + ary[i][j - 1] - ary[i - 1][j - 1];
			}
		}
		for (i = n, diff = 1e30; i >= 1; i--)
		{
			d = ab(ary[i - 1][m] - ary[n][m] + ary[i][m]);
			if (d + 1e-8 < diff)
			{
				diff = d;
				x = i;
			}
		}
		for (i = m, diff = 1e30; i >= 1; i--)
		{
			d = ab(ary[n][i - 1] - ary[n][m] + ary[n][i]);
			if (d + 1e-8 < diff)
			{
				diff = d;
				y = i;
			}
		}
		printf("Case %d: center at (%d, %d)\n", ++cas, x, y);
	}
	return 0;
}
