#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/120/12046.html
// Runtime: 0.556s
// Tag: Dp

// @BEGIN_OF_SOURCE_CODE

#define LL long long
#define MOD 1000007

int memo[40 + 2][2 + 1][3 + 1][4 + 1][5 + 1][6 + 1][64 + 2];
int n;

int dp(int at, int m2, int m3, int m4, int m5, int m6, int mask)
{
	if (at == n)
	{
		if (mask & (1 << 1) && m2)
		{
			return 0;
		}
		if (mask & (1 << 2) && m3)
		{
			return 0;
		}
		if (mask & (1 << 3) && m4)
		{
			return 0;
		}
		if (mask & (1 << 4) && m5)
		{
			return 0;
		}
		if (mask & (1 << 5) && m6)
		{
			return 0;
		}
		return 1;
	}
	if (memo[at][m2][m3][m4][m5][m6][mask] != -1)
	{
		return memo[at][m2][m3][m4][m5][m6][mask];
	}
	int sum = 0;
	int t2, t3, t4, t5, t6;
	if (at == 0)
	{
		for (int i = 1; i <= 6; i++)
		{
			sum += dp(at + 1, i % 2, i % 3, i % 4, i % 5, i % 6, mask | (1 << (i - 1)));
			sum %= MOD;
		}
		return memo[at][m2][m3][m4][m5][m6][mask] = sum;
	}
	for (int i = 1; i <= 6; i++)
	{
		t2 = (m2 * 10 + i) % 2;
		t3 = (m3 * 10 + i) % 3;
		t4 = (m4 * 10 + i) % 4;
		t5 = (m5 * 10 + i) % 5;
		t6 = (m6 * 10 + i) % 6;
		sum += dp(at + 1, t2, t3, t4, t5, t6, mask | (1 << (i - 1)));
		sum %= MOD;
	}
	return memo[at][m2][m3][m4][m5][m6][mask] = sum;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	while (testCase--)
	{
		scanf("%d", &n);
		memset(memo, -1, sizeof(memo));
		printf("%d\n", dp(0, 0, 0, 0, 0, 0, 0));
	}
	return 0;
}

// @END_OF_SOURCE_CODE
