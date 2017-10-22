#include <bits/stdc++.h>

using namespace std;

int max_, base;
unsigned int dp[1 << 10][11][102];

unsigned int solve(int last, int i, int state)
{
	if (dp[state][last][i] != -1)
	{
		return dp[state][last][i];
	}
	int res = ((state == (1 << base) - 1) && i >= base);
	if (i < max_)
	{
		int a = last + 1;
		int b = last - 1;
		if (a < base)
		{
			res = (res + (solve(a, i + 1, state | (1 << a)) % 1000000007)) % 1000000007;
		}
		if (b >= 0)
		{
			res = (res + (solve(b, i + 1, state | (1 << b)) % 1000000007)) % 1000000007;
		}
	}
	return dp[state][last][i] = res;
}
int main()
{
	int tc = 0, i, j, k, l;
	scanf("%d", &tc);
	while (tc--)
	{
		scanf("%d %d", &base, &max_);
		l = 1 << base;
		for (i = 0; i < l; i++)
			for (j = 0; j <= base; j++)
				for (k = 0; k <= max_ + 1; k++)
				{
					dp[i][j][k] = -1;
				}
		unsigned int res = 0;
		for (i = 1; i < base; i++)
		{
			res = (res + ((solve(i, 1, 1 << i)) % 1000000007)) % 1000000007;
		}
		printf("%u\n", res);
	}
	return 0;
}
