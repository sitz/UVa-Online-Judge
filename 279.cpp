#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 30;

int main()
{
	int cas, n;
	ll pos, dp[maxn + 5];
	char str[maxn + 5];
	dp[0] = 0;
	for (int i = 1; i <= maxn; i++)
	{
		dp[i] = (dp[i - 1] + i) * 2 - 1;
	}
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d%s%lld", &n, str, &pos);
		ll ans = 0, sign = 1;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'v')
			{
				ans += (sign * dp[n - i]);
				sign *= -1;
			}
		}
		printf("%lld\n", ans + pos + 1);
	}
	return 0;
}
