#include <bits/stdc++.h>

using namespace std;

#define mod 1000007
#define maxn 100000

int f[6][3][2] = {1, 2, 3, 1, 2, -1,
									1, 2, 3, 3, 2, 1,
									1, 2, 2, 0, 1, -2,
									2, 1, 4, 0, 2, -1,
									2, 1, 3, -1, 1, -2,
									2, -1, 3, -3, 1, -2};
int n, m, c;

int check(int x, int y)
{
	if (x >= 1 && x <= n && y >= 1 && y <= m)
	{
		return 1;
	}
	return 0;
}

int check1(int id, int x, int y)
{
	int j;
	for (j = 0; j < 3; j++)
	{
		int a = f[id][j][0], b = f[id][j][1];
		if (!check(x + a, y + b))
		{
			return 0;
		}
	}
	return 1;
}

long long mp[maxn * 32];
int nn;

int main()
{
	int i, j, k;
	int t, cas;
	long long res, tag = 1;
	scanf("%d", &t);
	for (cas = 1; cas <= t; cas++)
	{
		scanf("%d%d%d", &n, &m, &c);
		res = 0;
		memset(mp, 0, sizeof(mp));
		for (i = 0; i < 6; i++)
		{
			int lx, rx, ly, ry;
			lx = 1;
			rx = n;
			ly = 1;
			ry = m;
			int cnt = 0;
			for (j = 0; j < 3; j++)
			{
				int a = f[i][j][0], b = f[i][j][1];
				lx = max(lx, 1 - a);
				rx = min(rx, n - a);
				ly = max(ly, 1 - b);
				ry = min(ry, m - b);
			}
			if (lx <= rx && ly <= ry)
			{
				res += tag * (rx - lx + 1) * (ry - ly + 1), cnt = (rx - lx + 1) * (ry - ly + 1);
			}
		}
		nn = 0;
		while (c--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			long long tmp = x * tag * (m + 1) + y;
			tmp *= 10;
			for (i = 0; i < 6; i++)
			{
				if (check1(i, x, y))
				{
					mp[++nn] = (tmp + i);
				}
			}
			for (i = 0; i < 6; i++)
			{
				for (j = 0; j < 3; j++)
				{
					int a = f[i][j][0], b = f[i][j][1];
					if (check(x - a, y - b) && check1(i, x - a, y - b))
					{
						long long tmp = (x - a) * tag * (m + 1) + (y - b);
						tmp = tmp * 10 + i;
						mp[++nn] = tmp;
					}
				}
			}
		}
		sort(mp + 1, mp + nn + 1);
		nn = unique(mp + 1, mp + nn + 1) - mp - 1;
		res -= nn;
		res *= 8;
		printf("Case %d: ", cas);
		cout << res << endl;
	}
	return 0;
}
