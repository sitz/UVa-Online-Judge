#include <bits/stdc++.h>

using namespace std;

#define MAXSTATE 1 << 13
#define MAXN 13
#define oo 0xfffffffffLL

int A[MAXN], AD[MAXN], best;
long long DP[MAXSTATE][MAXN], map_[51][51];

int TSP(int state, int n, int last)
{
	if (state == 0)
	{
		return 0;
	}
	if (DP[state][last] != -oo)
	{
		return DP[state][last];
	}
	int i;
	long long max = -oo, tmp;
	for (i = 0; i <= n; i++)
	{
		if ((state & (1 << i)) != 0 && last != i)
		{
			tmp = TSP(state - (1 << last), n, i);
			tmp -= map_[A[i]][A[last]];
			tmp += AD[last];
			if (max < tmp)
			{
				max = tmp;
			}
		}
	}
	if (state == (1 << last))
	{
		max = -map_[A[last]][0] + AD[last];
	}
	if (best < max - map_[A[last]][0])
	{
		best = max - map_[A[last]][0];
	}
	DP[state][last] = max;
	return DP[state][last];
}
long long min(long long a, long long b)
{
	return a < b ? a : b;
}

int main()
{
	int T, x, y, n, m, p, i, j, k, a, b;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				map_[i][j] = oo;
			}
		}
		for (i = 0; i < m; i++)
		{
			scanf("%d %d %d.%d", &x, &y, &a, &b);
			map_[x][y] = min(100 * a + b, map_[x][y]);
			map_[y][x] = min(100 * a + b, map_[y][x]);
		}
		scanf("%d", &p);
		int newp, tmpAD[51];
		memset(tmpAD, 0, sizeof(tmpAD));
		for (i = 1; i <= p; i++)
		{
			scanf("%d %d.%d", &A[i], &a, &b);
			tmpAD[A[i]] += 100 * a + b;
		}
		newp = 0;
		for (i = 1; i <= n; i++)
		{
			if (tmpAD[i])
			{
				newp++, A[newp] = i, AD[newp] = tmpAD[i];
			}
		}
		p = newp;
		for (k = 0; k <= n; k++)
		{
			for (i = 0; i <= n; i++)
			{
				for (j = 0; j <= n; j++)
				{
					if (map_[i][j] > map_[i][k] + map_[k][j])
					{
						map_[i][j] = map_[i][k] + map_[k][j];
					}
				}
			}
		}
		int final = (1 << (p + 1)) - 1;
		for (i = 0; i <= final; i++)
		{
			for (j = 0; j <= p; j++)
			{
				DP[i][j] = -oo;
			}
		}
		map_[0][0] = 0;
		best = 0;
		TSP(final, p, 0);
		if (best == 0)
		{
			puts("Don't leave the house");
		}
		else
		{
			printf("Daniel can save $%d.%02d\n", best / 100, best % 100);
		}
	}
	return 0;
}
