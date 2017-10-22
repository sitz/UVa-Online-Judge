#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f
#define Max 110
int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}
double dp[60][60];
char s[10];
int t, m, T;
int to[60];
int main()
{
	int i, j;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &m, &T);
		to[0] = 0;
		to[m + 1] = 0;
		to[m + 2] = -1;
		for (i = 1; i <= m; i++)
		{
			if (scanf("%d", &to[i]) == 0)
			{
				scanf("%s", s);
				to[i] = inf;
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[0][0] = 1.0;
		for (j = 0; j <= T; j++)
			for (i = 0; i <= m; i++)
			{
				// printf("i %d j %d dp %lf\n",i,j,dp[i][j]);
				if (to[i + 1] == inf)
				{
					dp[i + 1][j + 2] += dp[i][j] * 0.5;
				}
				else
				{
					dp[i + 1 + to[i + 1]][j + 1] += dp[i][j] * 0.5;
				}
				if (to[i + 2] == inf)
				{
					dp[i + 2][j + 2] += dp[i][j] * 0.5;
				}
				else
				{
					dp[i + 2 + to[i + 2]][j + 1] += dp[i][j] * 0.5;
				}
			}
		for (i = 0; i < T; i++)
		{
			dp[m + 1][T] += dp[m + 1][i];
		}
		if (dp[m + 1][T] == 0.5)
		{
			printf("Push. 0.5000\n");
		}
		else if (dp[m + 1][T] < 0.5)
		{
			printf("Bet against. %.4lf\n", dp[m + 1][T]);
		}
		else
		{
			printf("Bet for. %.4lf\n", dp[m + 1][T]);
		}
	}
}
