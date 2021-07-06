#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

int mth(int y, int m, int d)
{
	int cnt = 0;
	if (y < 470)
	{
		while (true)
		{
			cnt++;
			m++;
			if (m == 13)
			{
				y++;
				m = 1;
			}
			if (y == 470 && m == 2)
			{
				break;
			}
		}
		return cnt;
	}
	if (m < 2)
	{
		return 2 - m + cnt;
	}
	else if (m == 2)
	{
		if (d < 14)
		{
			return 0 + cnt;
		}
		else
		{
			return 12 + cnt;
		}
	}
	else if (m > 2)
	{
		return 14 - m + cnt;
	}
	return -1;
}

int m[26][26], orig[26][26], cpy[26][26];
void mma(int n)
{
	rep(i, n) rep(j, n) cpy[i][j] = m[i][j], m[i][j] = 0;
	rep(i, n) rep(j, n) rep(k, n) m[i][j] += cpy[i][k] * orig[k][j];
}

double solve(int n, int y, int mon, int d, int *tar)
{
	int num = mth(y, mon, d);
	double dp[num + 1][26][2];
	rep(i, num + 1) rep(j, 26) rep(k, 2) dp[i][j][k] = 0;
	double prob[26];
	rep(i, n)
	{
		int sum = 0;
		rep(j, n) sum += orig[i][j];
		prob[i] = 1 / (double)sum;
	}
	dp[0][tar[0]][0] = 1;
	dp[0][tar[1]][1] = 1;
	rep(i, num)
	{
		rep(j, n)
		{
			rep(k, 2)
			{
				rep(l, n)
				{
					dp[i + 1][l][k] += prob[j] * orig[j][l] * dp[i][j][k];
				}
			}
		}
	}
	double ret = 0;
	rep(i, n)
	{
		ret += dp[num][i][0] * dp[num][i][1];
	}
	return ret;
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int y, mon, d;
		int r;
		cin >> y >> mon >> d;
		cin >> r;
		rep(i, 26)
		{
			rep(j, 26) m[i][j] = 0, orig[i][j] = 0;
			m[i][i] = 1;
			orig[i][i] = 1;
		}
		rep(i, r)
		{
			char a, b;
			cin >> a >> b;
			if (a != b)
			{
				orig[a - 'A'][b - 'A'] = orig[b - 'A'][a - 'A'] = 1;
			}
		}
		char a, b;
		cin >> a >> b;
		int tar[2];
		tar[0] = a - 'A';
		tar[1] = b - 'A';
		printf("%.5lf\n", solve(26, y, mon, d, tar));
	}
	return false;
}
