#include <bits/stdc++.h>

using namespace std;

double pe[102][102][102];
int n, m, p, t;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int a[3][120];

void init(int id, int n)
{
	int i, j, k;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
				if (k >= min(i, j) && k <= max(i, j))
					a[id][k]++;
}

const int ml = 2;
double c[ml], cc[ml], ret[ml];

void mulrr(double *a, double *b)
{
	int i, j, k;
	cc[0] = a[0] * b[0] + a[1] * b[1];
	cc[1] = a[0] * b[1] + a[1] * b[0];
	a[0] = cc[0];
	a[1] = cc[1];
}

void power(double *a, int b)
{
	int i, j;
	--b;
	ret[0] = a[0];
	ret[1] = a[1];
	while (b)
	{
		if (b & 1)
			mulrr(ret, a);
		mulrr(a, a);
		b >>= 1;
	}
	a[0] = ret[0];
	a[1] = ret[1];
}

int main()
{
	int i, j, k, ca, ii, jj, kk, i2, j2, k2, cc = 1;
	scanf("%d", &ca);
	while (ca--)
	{
		memset(a, 0, sizeof(a));
		scanf("%d%d%d%d", &n, &m, &p, &t);
		init(0, n);
		init(1, m);
		init(2, p);
		if (t == 0)
		{
			printf("Case %d: %.10lf\n", cc++, 0.0);
			continue;
		}
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				for (k = 1; k <= p; k++)
				{
					pe[i][j][k] = 1;
					pe[i][j][k] *= a[0][i] * 1.0 / (n * n * 1.0);
					pe[i][j][k] *= a[1][j] * 1.0 / (m * m * 1.0);
					pe[i][j][k] *= a[2][k] * 1.0 / (p * p * 1.0);
				}
		double ans = 0;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				for (k = 1; k <= p; k++)
				{
					double pt = pe[i][j][k];
					c[0] = 1 - pt;
					c[1] = pt;
					power(c, t);
					ans += c[1];
				}
		printf("Case %d: %.10lf\n", cc++, ans);
	}
	return 0;
}
