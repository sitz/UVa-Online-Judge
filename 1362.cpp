#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000000;

long long dp[330][330];
char s[330];

long long solve(int pos1, int pos2)
{
	if (pos1 > pos2)
	{
		return 0;
	}
	if (pos1 == pos2)
	{
		return 1;
	}
	if (dp[pos1][pos2] != -1)
	{
		return dp[pos1][pos2];
	}
	long long ans = 0;
	for (int i = pos1 + 2; i <= pos2; i++)
	{
		if (s[pos1] == s[i] && s[i] == s[pos2])
		{
			ans = (ans + solve(pos1 + 1, i - 1) * solve(i, pos2)) % MOD;
		}
	}
	return dp[pos1][pos2] = ans;
}

int main()
{
	while (scanf("%s", s) != EOF)
	{
		memset(dp, -1, sizeof(dp));
		cout << solve(0, strlen(s) - 1) << endl;
	}
	return 0;
}
