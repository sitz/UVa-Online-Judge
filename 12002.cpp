#include <bits/stdc++.h>

using namespace std;

#define maxn 510

int n, dp1[maxn], dp2[maxn], num[maxn];

void DP1()//increase
{
	int i, j;
	for (i = n; i >= 1; i--)
	{
		dp1[i] = 1;
		for (j = i + 1; j <= n; j++)
		{
			if (num[j] >= num[i])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}
}

void DP2()//
{
	int i, j;
	for (i = n; i >= 1; i--)
	{
		dp2[i] = 1;
		for (j = i + 1; j <= n; j++)
		{
			if (num[j] <= num[i])
			{
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
}

int main()
{
	int i, j;
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 1; i <= n; i++)
		{
			scanf("%d", &num[i]);
		}
		DP1();
		DP2();
		int ans = 0;
		for (i = 1; i <= n; i++)
		{
			ans = max(ans, max(dp1[i], dp2[i]));
			for (j = i + 1; j <= n; j++)
			{
				if (num[i] == num[j])
				{
					continue;
				}
				if (num[i] < num[j])
				{
					ans = max(ans, dp1[j] + dp2[i]);
				}
				else
				{
					ans = max(ans, dp1[i] + dp2[j]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
