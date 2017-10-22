#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : Nero
Created Time: 2013/9/7 13:56:38
Problem id  : UVA 1347
Problem Name: Tour
*********************************************** */

#define REP(i, a, b) for (int i = (a); i < (int)(b); i++)
#define clr(a, b) memset(a, b, sizeof(a))

const double Inf = 1e15;
double dp[55][55];
int n;
double x[55], y[55];

double sqr(double x) { return x * x; }
double dis(int a, int b)
{
	return sqrt(sqr(x[a] - x[b]) + sqr(y[a] - y[b]));
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf", &x[i], &y[i]);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				dp[i][j] = Inf;
		dp[1][1] = 0.0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + dis(i, i + 1));
				dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + dis(j, i + 1));
			}
		}
		double ans = Inf;
		for (int j = 1; j <= n; j++)
		{
			ans = min(ans, dp[n][j] + dis(n, j));
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}
