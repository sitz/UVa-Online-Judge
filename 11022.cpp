#include <bits/stdc++.h>

using namespace std;

char str[100];
int dp[100][100];
int run(int left, int right)
{
	if (left == right)
	{
		return 1;
	}
	if (dp[left][right])
	{
		return dp[left][right];
	}
	int length = right - left + 1;
	for (int len = 1; len < length; len++)
	{
		if (length % len != 0)
		{
			continue;
		}
		int t = length / len;
		bool flag = true;
		for (int j = 1, base = left + len; j < t && flag; j++, base += len)
			for (int l = 0; l < len && flag; l++)
				if (str[left + l] != str[base + l])
				{
					flag = false;
				}
		if (flag)
		{
			int s = run(left, left + len - 1);
			if (!dp[left][right])
			{
				dp[left][right] = s;
				return s;
			}
		}
	}
	if (dp[left][right])
	{
		return dp[left][right];
	}
	for (int k = left; k < right; k++)
	{
		int s = run(left, k) + run(k + 1, right);
		if (!dp[left][right] || dp[left][right] > s)
		{
			dp[left][right] = s;
			if (s == 1)
			{
				return s;
			}
		}
	}
	return dp[left][right];
}
int main()
{
	while (scanf("%s", str) == 1)
	{
		if (strcmp(str, "*") == 0)
		{
			break;
		}
		memset(dp, 0, sizeof(dp));
		int ans = run(0, strlen(str) - 1);
		printf("%d\n", ans);
	}
}
