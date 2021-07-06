#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/120/12030.html
// Runtime: 0.508s
// Tag: Dp, bitmask, backtrack

// @BEGIN_OF_SOURCE_CODE

#define LL long long

int matrix[15 + 3][15 + 3];
long long memo[32768 + 5][2][2];
int n;

// at = dress position
// bitmask = which pair of shoes already matched
// one = 1, if all the matches upto have value 1, otherwise 0
// two = 1, if at least one match upto have value 2, otherwise 0
long long dp(int at, int bitmask, int one, int two)
{
	if (at == n)
	{
		return (one || two) == 1 ? 1 : 0;
	}
	if (memo[bitmask][one][two] != -1)
	{
		return memo[bitmask][one][two];
	}
	long long sum = 0;
	int tmp_one;
	int tmp_two;
	for (int i = 0; i < n; i++)
	{
		if ((bitmask & (1 << i)) == 0)
		{
			tmp_one = matrix[at][i] == 1 && one ? 1 : 0;
			tmp_two = matrix[at][i] == 2 || two ? 1 : 0;
			sum += dp(at + 1, bitmask | (1 << i), tmp_one, tmp_two);
		}
	}
	return memo[bitmask][one][two] = sum;
}

int main()
{
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		memset(memo, -1, sizeof(memo));
		printf("Case %d: %lld\n", ++cases, dp(0, 0, 1, 0));
	}
	return 0;
}

// @END_OF_SOURCE_CODE
