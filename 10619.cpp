#include <bits/stdc++.h>

using namespace std;

int *e[100001];
int ar[100001][3];
int cases, n, j, m, maxt, mint, tx;
bool cmp(int *p, int *q)
{
	return p[0] < q[0];
}
bool solve(int t)
{
	int v = 0, i = 0, x = e[0][0] - 2 * t;
	while (i < n)
	{
		while ((e[i][2] - e[i][1]) <= x && i < n)
		{
			++i;
		}
		++v;
		if (v > m)
		{
			break;
		}
		x = e[i][0] - 2 * t;
	}
	if (v <= m)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	for (int i = 0; i < 100001; ++i)
	{
		e[i] = ar[i];
	}
	scanf("%d", &cases);
	for (int k = 1; k <= cases; ++k)
	{
		int i = 0;
		maxt = 1000000;
		mint = -2000000;
		scanf("%d%d", &n, &m);
		for (int num = 0; num < n; ++num)
		{
			scanf("%d%d", &e[i][1], &e[i][2]);
			for (j = 0; j < i; ++j)
			{
				tx = e[i][2] > e[j][2] ? e[i][2] - e[j][2] : e[j][2] - e[i][2];
				if (e[i][1] >= e[j][1] + tx)
				{
					break;
				}
			}
			if (j < i)
			{
				continue;
			}
			e[i][0] = e[i][2] + e[i][1];
			if (e[i][1] < maxt)
			{
				maxt = e[i][1];
			}
			++i;
		}
		n = i;
		sort(e, e + n, cmp);
		while (mint < maxt)
		{
			int temp = (mint + maxt) / 2;
			if (solve(temp))
			{
				mint = temp + 1;
			}
			else
			{
				maxt = temp - 1;
			}
		}
		if (solve(maxt) == false)
		{
			--maxt;
		}
		printf("Case %d: %d\n", k, maxt);
	}
	return 0;
}
