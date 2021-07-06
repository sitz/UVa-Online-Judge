#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define LL long long

int T, dp[1010][1010];
char s[1010];

void update(int &x, LL y)
{
	x = (x + y) % MOD;
}

int main()
{
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas)
	{
		memset(dp, 0, sizeof(dp));
		scanf("%s", s + 1);
		int n = 0;
		for (int i = 1; s[i]; ++i)
			if (s[i] != 'E')
			{
				s[++n] = s[i];
			}
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i)
		{
			if (s[i + 1] == 'D')
			{
				for (int j = 0; j <= i; ++j)
					if (dp[i][j])
					{
						if (j > 0)
						{
							update(dp[i + 1][j - 1], (LL)dp[i][j] * j * j);
						}
						update(dp[i + 1][j], (LL)dp[i][j] * j);
					}
			}
			else
			{
				for (int j = 0; j <= i; ++j)
					if (dp[i][j])
					{
						update(dp[i + 1][j], (LL)dp[i][j] * j);
						update(dp[i + 1][j + 1], dp[i][j]);
					}
			}
		}
		//		for (int i = 0; i <= n; ++i) printf("%d ", l[i]); puts("");
		//		for (int i = 0; i <= n; ++i) {
		//			for (int j = 0; j <= i; ++j)
		//				printf("%d ",dp[i][j]);
		//			puts("");
		//		}
		printf("Case %d: %d\n", cas, int(dp[n][0]));
	}
	return 0;
}
