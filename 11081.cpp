#include <bits/stdc++.h>

using namespace std;

const int MAXL = 60 + 5;

int T, len1, len2, len3, dp1[MAXL][MAXL][MAXL], dp2[MAXL][MAXL][MAXL], dp[MAXL][MAXL][MAXL];
char str1[MAXL], str2[MAXL], str3[MAXL];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s%s%s", str1 + 1, str2 + 1, str3 + 1);
		len1 = strlen(str1 + 1), len2 = strlen(str2 + 1), len3 = strlen(str3 + 1);
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		memset(dp, 0, sizeof(dp));
		for (int j = 0; j <= len1; j++)
			for (int k = 0; k <= len2; k++)
				dp1[j][k][0] = dp2[j][k][0] = dp[j][k][0] = 1;
		for (int i = 1; i <= len3; i++)
			for (int j = 0; j <= len1; j++)
				for (int k = 0; k <= len2; k++)
				{
					if (j)
					{
						dp1[j][k][i] = dp1[j - 1][k][i];
						if (str3[i] == str1[j])
							dp1[j][k][i] = (dp1[j][k][i] + dp[j - 1][k][i - 1]) % 10007;
					}

					if (k)
					{
						dp2[j][k][i] = dp2[j][k - 1][i];
						if (str3[i] == str2[k])
							dp2[j][k][i] = (dp2[j][k][i] + dp[j][k - 1][i - 1]) % 10007;
					}
					dp[j][k][i] = (dp1[j][k][i] + dp2[j][k][i]) % 10007;
				}
		printf("%d\n", dp[len1][len2][len3]);
	}
	return 0;
}
