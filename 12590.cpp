#include <bits/stdc++.h>

using namespace std;

const int Mod = 1e9 + 7;

int c[10001][401], f[101][101][101];

inline int add(int a, int b)
{
	a = a + b;
	if (a >= Mod)
	{
		a -= Mod;
	}
	return a;
}

inline int mul(int a, int b)
{
	return (long long)a * b % Mod;
}

void prepare()
{
	int i, j, k, p;
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	for (i = 0; i <= 10000; ++i)
	{
		c[i][0] = 1;
		for (j = 1; j <= i && j <= 400; ++j)
		{
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
			if (c[i][j] >= Mod)
			{
				c[i][j] -= Mod;
			}
		}
	}
	for (i = 0; i <= 100; ++i)
	{
		f[i][0][0] = 1;
	}
	for (i = 1; i <= 100; ++i)
		for (j = 1; j <= 100; ++j)
			for (k = j; k <= 100; ++k)
			{
				f[i][j][k] = 0;
				for (p = j - 1; p < k; ++p)
				{
					f[i][j][k] = f[i][j][k] + mul(f[i][j - 1][p], c[i][k - p]);
					if (f[i][j][k] >= Mod)
					{
						f[i][j][k] -= Mod;
					}
				}
			}
}

int n, m, k, ans;
void debug()
{
	cout << ans << endl;
}

void work()
{
	int p;
	ans = 0;
	if (n > m)
	{
		swap(n, m);
	}
	if (n == 1)
	{
		printf("%d\n", c[m][k]);
		return;
	}
	else if (n * m < k)
	{
		puts("0");
		return;
	}
	else if (n == 2)
	{
		ans = add(add(c[2 * m][k], Mod - c[m][k]), Mod - c[m][k]);
		if (m == k)
		{
			ans = add(ans, 2);
		}
		printf("%d\n", ans);
		return;
	}
	// 4
	if (k >= 4)
	{
		ans = add(ans, c[n * m - 4][k - 4]);
	}
	if (k >= 3)
	{
		ans = add(ans, mul(4, c[n * m - 4][k - 3]));
	}
	if (k >= 2)
	{
		ans = add(ans, mul(2, c[n * m - 4][k - 2]));
	}
	if (k >= 2)
	{
		for (p = 1; p <= m - 2 && k - 2 - p >= 0; ++p)
		{
			ans = add(ans, mul(mul(2, c[m - 2][p]), c[n * m - 4 - (m - 2)][k - 2 - p]));
		}
		for (p = 0; p <= 2 * n - 4 && k - 2 - p >= m - 2; ++p)
		{
			ans = add(ans, mul(mul(2, c[n * 2 - 4][p]), f[n - 1][m - 2][k - 2 - p]));
		}
		for (p = 1; p <= n - 2 && k - 2 - p >= 0; ++p)
		{
			ans = add(ans, mul(mul(2, c[n - 2][p]), c[n * m - 4 - (n - 2)][k - 2 - p]));
		}
		for (p = 0; p <= 2 * m - 4 && k - 2 - p >= n - 2; ++p)
		{
			ans = add(ans, mul(mul(2, c[m * 2 - 4][p]), f[m - 1][n - 2][k - 2 - p]));
		}
	}
	if (k >= 1)
	{
		for (p = 1; p <= 2 * m - 4 && k - 1 - p >= n - 2; ++p)
		{
			ans = add(ans, mul(mul(4, add(c[2 * m - 4][p], Mod - c[m - 2][p])), f[m - 1][n - 2][k - 1 - p]));
		}
		for (p = 1; p <= 2 * n - 4 && k - 1 - p >= m - 2; ++p)
		{
			ans = add(ans, mul(mul(4, add(c[2 * n - 4][p], Mod - c[n - 2][p])), f[n - 1][m - 2][k - 1 - p]));
		}
		for (p = 2; p <= n - 2 + m - 2 && k - p - 1 >= 0; ++p)
		{
			ans = add(ans, mul(mul(4, add(add(c[n - 2 + m - 2][p], Mod - c[m - 2][p]), Mod - c[n - 2][p])), c[n * m - 4 - (n - 2) - (m - 2)][k - p - 1]));
		}
	}
	if (k >= 4)
	{
		for (p = 4; p <= (n - 2) * 2 + (m - 2) * 2 && k - p >= 0; ++p)
		{
			long long tmp = (long long)c[(n - 2) * 2 + (m - 2) * 2][p] - c[n - 2][p] * 2 - c[m - 2][p] * 2 + c[(n - 2) * 2][p] + c[(m - 2) * 2][p] + (long long)c[n - 2 + m - 2][p] * 4 - 2 * (c[(n - 2) * 2 + m - 2][p]) - 2 * (c[n - 2 + (m - 2) * 2][p]);
			tmp = tmp % Mod;
			if (tmp < 0)
			{
				tmp += Mod;
			}
			ans = add(ans, mul((int)tmp, c[n * m - 4 - (n - 2) * 2 - (m - 2) * 2][k - p]));
		}
	}
	for (p = 0; k - p >= 0; ++p)
	{
		if (p >= 2)
		{
			ans = add(ans, mul(add(mul(2, f[n - 1][m - 2][k - p]), Mod - f[n - 2][m - 2][k - p]), add(add(c[(n - 2) * 2][p], Mod - c[n - 2][p]), Mod - c[n - 2][p])));
		}
		if (p >= 2)
		{
			ans = add(ans, mul(add(mul(2, f[m - 1][n - 2][k - p]), Mod - f[m - 2][n - 2][k - p]), add(add(c[(m - 2) * 2][p], Mod - c[m - 2][p]), Mod - c[m - 2][p])));
		}
	}
	printf("%d\n", ans);
}

int main()
{
	int tt, i;
	prepare();
	scanf("%d", &tt);
	for (i = 1; i <= tt; ++i)
	{
		printf("Case %d: ", i);
		scanf("%d%d%d", &n, &m, &k);
		work();
	}
	return 0;
}
