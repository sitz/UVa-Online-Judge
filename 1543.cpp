#include <bits/stdc++.h>

using namespace std;

#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
const int N = 45;
int n, m, i, j, k, x;
double p[N], dp[N][N][N];
const double pi = acos(-1.0);

inline double cal(double p1, double p2)
{
	double d = pi * (p1 - p2);
	return 2 * sin(d);
}

inline double area(double p1, double p2, double p3)
{
	double a = cal(p1, p2);
	double b = cal(p2, p3);
	double c = cal(p3, p1);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

int main()
{
	while (~scanf("%d%d", &n, &m) && n || m)
	{
		double ans = 0;
		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= n; i++)
		{
			scanf("%lf", &p[i]);
		}
		for (x = 1; x <= n; x++)
		{
			int t = min(x, m);
			for (i = 3; i <= t; i++)
			{
				for (j = 1; j < x; j++)
				{
					for (k = j + 1; k < x; k++)
					{
						double s = area(p[x], p[k], p[j]);
						dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j][k] + s);
						if (i == m)
						{
							ans = max(ans, dp[i][j][x]);
						}
					}
				}
			}
		}
		printf("%.6lf\n", ans);
	}
	return 0;
}
