#include <bits/stdc++.h>

using namespace std;

struct node
{
	int now, tom;
} cas[510];

int gcd(int a, int b)
{
	if (a > b)
	{
		swap(a, b);
	}
	while (a)
	{
		int m = a;
		a = b % a;
		b = m;
	}
	return b;
}

int vals1[51000], vals2[51000], n, p;
int dp[5100000], c, num[51000];

int main()
{
	bool yes = 0;
	while (scanf("%d", &c) != EOF)
	{
		scanf("%d%d", &n, &p);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &cas[i].now, &cas[i].tom);
		}
		int ans;
		for (int i = 1; i <= p; i++)
		{
			scanf("%d", &num[i]);
			int res1 = 0, res2 = 0, x, y;
			for (int j = 1; j <= num[i]; j++)
			{
				scanf("%d%d", &x, &y);
				res1 += cas[x].now * y;
				res2 += cas[x].tom * y;
			}
			if (res1 > c || res2 < res1)
			{
				p--;
				i--;
				continue;
			}
			if (i == 1)
			{
				ans = res1;
			}
			else
			{
				ans = gcd(ans, res1);
			}
			vals1[i] = res1;
			vals2[i] = res2;
		}
		memset(dp, 0, sizeof(dp));
		int t = 0;
		int px = c / ans;
		for (int i = 1; i <= p; i++)
		{
			t = px;
			int x = vals1[i] / ans;
			for (int j = px * ans; j >= ans * x; j -= ans)
			{
				dp[t] = max(dp[t], dp[t - x] + vals2[i] - vals1[i]);
				t--;
			}
		}
		if (yes)
		{
			printf("\n");
		}
		yes = 1;
		printf("%d\n", dp[px]);
	}
	return 0;
}
