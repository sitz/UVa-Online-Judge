#include <bits/stdc++.h>

using namespace std;

const long long P = 1000000007;
long long dp[1000010];
long long re[1000010];
long long re42[1000010];
int main()
{
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 9;
	dp[3] = 32;
	re[0] = 1;
	re[1] = 3;
	re[2] = 12;
	re[3] = 44;
	for (int i = 4; i < 1000004; i++)
	{
		dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 5 + re[i - 3] * 4) % P;
		re[i] = (re[i - 1] + dp[i]) % P;
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		scanf("%d", &n);
		cout << dp[n] << "\n";
		//printf("%I64d\n",dp[n]);
	}
	return 0;
}
