#include <bits/stdc++.h>

using namespace std;

int coin[25];
long long dp[10010];

int main()
{
	int i, j, n;
	for (i = 0; i < 21; i++)
	{
		coin[i] = (i + 1) * (i + 1) * (i + 1);
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < 21; i++)
		for (j = 0; j + coin[i] <= 10000; j++)
		{
			dp[j + coin[i]] += dp[j];
		}
	while (cin >> n)
	{
		cout << dp[n] << endl;
	}
	return 0;
}
