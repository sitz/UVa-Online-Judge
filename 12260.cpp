#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000

typedef pair<int, int> PII;
PII dp[MAXN + 1][MAXN + 1], val[MAXN];
int t, n;
char name[21];

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		scanf("%s", name);
		int jan_start;
		if (!strcmp(name, "Jan"))
		{
			jan_start = 1;
		}
		else
		{
			jan_start = 0;
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d %d", &val[i].first, &val[i].second);
			val[i].first *= -1;
		}
		sort(val, val + n);
		for (int i = 1; i <= n; ++i)
		{
			dp[i][0].second = dp[i - 1][0].second - val[i - 1].first;
			dp[i][(i + jan_start) / 2 + 1] = PII(0, 0);
			for (int j = 1; j <= (i + jan_start) / 2; ++j)
				dp[i][j] = max(PII(dp[i - 1][j].first, dp[i - 1][j].second - val[i - 1].first), PII(dp[i - 1][j - 1].first + val[i - 1].second, dp[i - 1][j - 1].second));
		}
		printf("%d %d\n", dp[n][(n + jan_start) / 2].second, dp[n][(n + jan_start) / 2].first);
	}
	return 0;
}
