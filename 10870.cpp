#include <bits/stdc++.h>

using namespace std;

int n, m, d, a[15], f[15], b[15][15], ans;

void Cf(int a[15][15], int b[15][15], int n)
{
	int c[15][15] = {0};
	int i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			for (k = 0; k < n; k++)
			{
				c[i][j] += (a[i][k] * b[k][j]) % m;
				c[i][j] %= m;
			}
	memcpy(a, c, sizeof(c));
}

void Matrix_Pow(int a[15][15], int n, int b)
{
	int c[15][15] = {0}, d[15][15] = {0};
	int i;
	for (i = 0; i < n; i++)
	{
		c[i][i] = 1;
	}
	memcpy(d, a, sizeof(d));
	while (b > 0)
	{
		if (b & 1)
		{
			Cf(c, d, n);
		}
		b >>= 1;
		Cf(d, d, n);
	}
	memcpy(a, c, sizeof(c));
}

int main()
{
	int i;
	while (1)
	{
		scanf("%d%d%d", &d, &n, &m);
		if (d == 0)
		{
			break;
		}
		for (i = 0; i < d; i++)
		{
			scanf("%d", &a[i]);
			a[i] %= m;
		}
		for (i = 0; i < d; i++)
		{
			scanf("%d", &f[i]);
			f[i] %= m;
		}
		memset(b, 0, sizeof(b));
		for (i = 0; i < d; i++)
		{
			b[i][0] = a[i];
		}
		for (i = 1; i < d; i++)
		{
			b[i - 1][i] = 1;
		}
		Matrix_Pow(b, d, n - d);
		ans = 0;
		for (i = d - 1; i >= 0; i--)
		{
			ans += (f[i] * b[d - i - 1][0]) % m;
			ans %= m;
		}
		printf("%d\n", ans);
	}
	return 0;
}
