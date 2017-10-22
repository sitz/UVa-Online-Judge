#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

double dp[50][11];

double solve(int n, int r, int m, int *d, double *p, string &in)
{
	rep(i, n)
	{
		rep(j, 11) dp[i][j] = 0;
	}
	if (in[0] != '*')
	{
		dp[0][in[0] - '0'] = 1;
	}
	else
	{
		rep(k, m)
		{
			dp[0][d[k]] += p[k];
		}
	}
	rep(i, (int)in.size() - 1)
	{
		rep(j, 11)
		{
			if (in[i + 1] != '*')
			{
				dp[i + 1][((j * 10) + in[i + 1] - '0') % 11] += dp[i][j];
				continue;
			}
			rep(k, m)
			{
				dp[i + 1][((j * 10) + d[k]) % 11] += p[k] * dp[i][j];
			}
		}
	}
	return dp[n - 1][r];
}

main()
{
	int n, q;
	int tc = 1;
	while (cin >> n && n)
	{
		printf("Case %d:\n", tc++);
		int d[n];
		double p[n];
		rep(i, n)
		{
			cin >> d[i] >> p[i];
		}
		cin >> q;
		rep(i, q)
		{
			string in;
			int r;
			cin >> in >> r;
			printf("%.8lf\n", solve(in.size(), r, n, d, p, in));
		}
	}
}
