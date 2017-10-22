#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
const int N = 7;
double dp[N][N][N][N][N][N];

double solve(int c, int *in)
{
	int r = *max_element(in, in + c);
	if (r == 0)
	{
		return 0;
	}
	double &ret = dp[in[0]][in[1]][in[2]][in[3]][in[4]][in[5]];
	if (ret == -1)
	{
		REP(i, 1, r + 1)
		{
			int cnt = 0;
			rep(j, c) if (in[j] >= i)
			{
				cnt++;
			}
			if (cnt == 0)
			{
				continue;
			}
			rep(j, 2)//left or right
			{
				double sum = 0;
				rep(k, 3)//power
				{
					int next[6] = {0};
					rep(l, c) next[l] = in[l];
					int tmp = 0;
					rep(l, c && tmp < k + 1)
					{
						if (next[l] < i)
						{
							continue;
						}
						else
						{
							next[l]--, tmp++;
						}
					}
					if (j)
					{
						reverse(next, next + c);
					}
					sum += 1 / 3. * (1 - solve(c, next));
				}
				ret = max(ret, sum);
				reverse(in, in + c);
			}
		}
	}
	return ret;
}

main()
{
	int c;
	while (cin >> c && c)
	{
		int in[6] = {0};
		rep(i, N) rep(j, N) rep(k, N) rep(l, N) rep(m, N) rep(n, N)
				dp[i][j][k][l][m][n] = -1;
		rep(i, c) cin >> in[i];
		double ans = solve(c, in);
		printf("%.6lf\n", solve(c, in));
	}
}
