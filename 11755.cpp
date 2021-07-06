#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;

char s[105];
double dp[2][25][25];

int main()
{
	int T, cas = 0;
	scanf("%d", &T);
	while (T--)
	{
		double w[2];
		gets(s);
		gets(s);
		scanf("%lf%lf", &w[0], &w[1]);
		int n = strlen(s), ct1 = 0, ct2 = 0;
		bool ok = 1;
		for (int i = 0; i < n; i++)
		{
			if (ct1 >= 21 || ct2 >= 21)
			{
				ok = 0;
				break;
			}
			if (s[i] == 'W')
			{
				if (w[(i / 5) & 1] < eps)
				{
					ok = 0;
				}
				ct1++;
			}
			else
			{
				if (w[(i / 5) & 1] + eps > 1)
				{
					ok = 0;
				}
				ct2++;
			}
			if (ct1 == 20 && ct2 == 20)
			{
				ct1 = 15, ct2 = 15;
			}
		}
		printf("Case %d: ", ++cas);
		if (!ok)
		{
			printf("%.6f\n", -1.0);
			continue;
		}
		if (ct1 >= 21 || ct2 >= 21)
		{
			printf("%.6f\n", ct1 >= 21 ? 1.0 : 0.0);
			continue;
		}
		for (int i = 0; i <= 21; i++)
			for (int j = 0; j <= 21; j++)
			{
				dp[0][i][j] = 0;
			}
		dp[0][15][15] = 1;
		int c = 0, cur = 0, nk, nj;
		double ret = 0, tp = 0;
		for (int tt = 0; tt < 2; tt++)
		{
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j <= 21; j++)
					for (int k = 0; k <= 21; k++)
					{
						dp[1 - cur][j][k] = 0;
					}
				for (int j = 0; j <= 20; j++)
					for (int k = 0; k <= 20; k++)
					{
						nj = j + 1, nk = k;
						if (nj == 20 && nk == 20)
						{
							nj = 15, nk = 15;
						}
						dp[1 - cur][nj][nk] += dp[cur][j][k] * w[c];
						nj = j, nk = k + 1;
						if (nj == 20 && nk == 20)
						{
							nj = 15, nk = 15;
						}
						dp[1 - cur][nj][nk] += dp[cur][j][k] * (1 - w[c]);
					}
				for (int j = 0; j <= 20; j++)
				{
					ret += dp[1 - cur][21][j];
				}
				tp += dp[1 - cur][15][15];
				dp[1 - cur][15][15] = 0;
				cur = 1 - cur;
			}
			c = 1 - c;
		}
		if (fabs(tp - 1) < eps)
		{
			printf("%.6f\n", 0.0);
			continue;
		}
		ret /= (1 - tp);
		for (int i = 0; i <= 21; i++)
			for (int j = 0; j <= 21; j++)
			{
				dp[0][i][j] = 0;
			}
		bool first = 1;
		c = (n / 5) & 1, cur = 0;
		dp[0][ct1][ct2] = 1;
		double ans = 0, sum1 = 0, sum2 = 0;
		for (int tt = 0; tt < 10; tt++)
		{
			for (int i = first ? n % 5 : 0; i < 5; i++)
			{
				if (fabs(dp[cur][15][15]) > eps)
				{
					sum1 += dp[cur][15][15];
					dp[cur][15][15] = 0;
				}
				for (int j = 0; j <= 21; j++)
					for (int k = 0; k <= 21; k++)
					{
						dp[1 - cur][j][k] = 0;
					}
				for (int j = 0; j <= 20; j++)
					for (int k = 0; k <= 20; k++)
					{
						nj = j + 1, nk = k;
						if (nj == 20 && nk == 20)
						{
							nj = 15, nk = 15;
						}
						dp[1 - cur][nj][nk] += dp[cur][j][k] * w[c];
						nj = j, nk = k + 1;
						if (nj == 20 && nk == 20)
						{
							nj = 15, nk = 15;
						}
						dp[1 - cur][nj][nk] += dp[cur][j][k] * (1 - w[c]);
					}
				for (int j = 0; j <= 20; j++)
				{
					ans += dp[1 - cur][21][j];
					sum2 += dp[1 - cur][j][21];
				}
				cur = 1 - cur;
			}
			first = 0;
			c = 1 - c;
		}
		printf("%.6f\n", ans + sum1 * ret);
	}
	return 0;
}
