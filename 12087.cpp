#include <bits/stdc++.h>

using namespace std;

int sum1[600][600], sum2[600][600], c[600][600], n, m, q;
int a[600];
int Abs(int x)
{
	if (x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}
long long jisuan(int x, int n)
{
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += (long long)a[i] * Abs(i - x);
	}
	return sum;
}
long long sanfen(int n)
{
	int l = 1, r = n;
	while (l < r - 3)
	{
		int x1 = (l + l + r) / 3, x2 = (l + r + r) / 3;
		if (jisuan(x1, n) < jisuan(x2, n))
		{
			r = x2;
		}
		else
		{
			l = x1;
		}
	}
	long long ma = (long long)1000000 * 1000000;
	int k = 0;
	for (int i = l; i <= r; ++i)
	{
		long long s = jisuan(i, n);
		if (s < ma)
		{
			ma = s;
			k = i;
		}
	}
	return ma;
}
int main()
{
	int ttt;
	cin >> ttt;
	for (int tl = 1; tl <= ttt; ++tl)
	{
		printf("Test Case %d:\n", tl);
		scanf("%d%d%d", &n, &m, &q);
		memset(c, 0, sizeof(c));
		memset(sum1, 0, sizeof(sum1));
		memset(sum2, 0, sizeof(sum2));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &c[i][j]);
			}
		for (int i = 1; i <= n; ++i)
		{
			sum1[i][0] = 0;
			for (int j = 1; j <= m; ++j)
			{
				sum1[i][j] = sum1[i][j - 1] + c[i][j];
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			sum2[0][i] = 0;
			for (int j = 1; j <= n; ++j)
			{
				sum2[j][i] = sum2[j - 1][i] + c[j][i];
			}
		}
		for (int tt = 1; tt <= q; ++tt)
		{
			int x, y, xx, yy;
			scanf("%d%d%d%d", &x, &y, &xx, &yy);
			memset(a, 0, sizeof(a));
			for (int i = x; i <= xx; ++i)
			{
				a[i - x + 1] = sum1[i][yy] - sum1[i][y - 1];
			}
			long long ans = sanfen(xx - x + 1);
			memset(a, 0, sizeof(a));
			for (int i = y; i <= yy; ++i)
			{
				a[i - y + 1] = sum2[xx][i] - sum2[x - 1][i];
			}
			ans += sanfen(yy - y + 1);
			printf("%d %lld\n", tt, ans);
		}
		puts("");
	}
	return 0;
}
