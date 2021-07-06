#include <bits/stdc++.h>

using namespace std;

// @ http://blog.csdn.net/u011345136/article/details/39082379

const int maxn = 2020;
const double eps = 1e-5;

double c[maxn], f[maxn], dp[maxn][maxn];

int main()
{
	int n, m, k;
	double p1, p2, p3, p4;
	while (scanf("%d%d%d%lf%lf%lf%lf", &n, &m, &k, &p1, &p2, &p3, &p4) != EOF)
	{
		if (p4 < eps)
		{
			printf("0.00000\n");
			continue;
		}
		double p = p2 / (1 - p1);
		double p41 = p4 / (1 - p1);
		double p31 = p3 / (1 - p1);
		f[0] = 1.0;
		for (int i = 1; i <= n; i++)
			f[i] = p * f[i - 1];

		dp[1][1] = p41 / (1 - p);
		c[1] = p41;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 2; j <= k; j++)
				c[j] = p31 * dp[i - 1][j - 1] + p41;
			for (int j = k + 1; j <= i; j++)
				c[j] = p31 * dp[i - 1][j - 1];

			double tmp = c[1] * f[i - 1];
			for (int j = 2; j <= i; j++)
				tmp += c[j] * f[i - j];

			dp[i][i] = tmp / (1 - f[i]);
			dp[i][1] = p * dp[i][i] + c[1];

			for (int j = 2; j < i; j++)
				dp[i][j] = p * dp[i][j - 1] + c[j];
		}

		printf("%.5lf\n", dp[n][m]);
	}
	return 0;
}
