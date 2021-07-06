#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : Nero
Created Time: 2013-8-31 21:55:28
Problem id  : UVA 12235
Problem Name: Help Bubu
*********************************************** */

#define REP(i, a, b) for (int i = (a); i < (int)(b); i++)
#define clr(a, b) memset(a, b, sizeof(a))

const int INF = 0x3f3f3f3f;
int dp[2][102][(1 << 8)][8];// åiæ¬ä¹¦,åèµ°jæ¬,çä¸çä¹¦çéåä¸ºs,çä¸çä¹¦æåä¸æ¬ä¸ºkçæå°æ··ä¹±åº¦
int n, K;
int all;

int main()
{
	int ca = 0;
	while (~scanf("%d%d", &n, &K), n || K)
	{
		all = 0;
		int a;
		clr(dp[0], INF);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a);
			a -= 25;
			int now = i & 1;
			int nes = !now;
			clr(dp[nes], INF);
			dp[nes][i][(1 << a)][a] = 1;
			int MM = min(i, K);
			for (int j = 0; j <= min(i, K); j++)
			{
				for (int s = all; s; s = (s - 1) & all)
				{
					for (int k = 0; (1 << k) <= s; k++)
						if (dp[now][j][s][k] != INF)
						{
							if (k == a)
								dp[nes][j][s][a] = min(dp[nes][j][s][a], dp[now][j][s][k]);
							else
							{
								dp[nes][j][s | (1 << a)][a] = min(dp[nes][j][s | (1 << a)][a], dp[now][j][s][k] + 1);
								dp[nes][j + 1][s][k] = min(dp[nes][j + 1][s][k], dp[now][j][s][k]);
							}
						}
				}
			}
			all |= (1 << a);
		}

		int minx = INF;
		for (int j = 0; j <= K; j++)
		{
			for (int s = all; s; s = (s - 1) & all)
			{
				for (int k = 0; (1 << k) <= s; k++)
					if (dp[n & 1][j][s][k] != INF)
					{
						int cnt = 0;
						for (int ss = s ^ all; ss; ss >>= 1)
							if (ss & 1)
								cnt++;
						minx = min(minx, cnt + dp[n & 1][j][s][k]);
					}
			}
		}
		printf("Case %d: %d\n\n", ++ca, minx);
	}
	return 0;
}
