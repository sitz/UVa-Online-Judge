#include <bits/stdc++.h>

using namespace std;

#define MX 100005
#define REP(i, n) for (int i = 0; i < (n); i++)
#define OREP(i, n) for (int i = 1; i <= (n); i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;

int n, m, k, t;

char input[MX];

int dp[205][205];
int nums[205];

bool check(int i, int j, int L)
{
	for (int k = 0; k < L; k++)
	{
		for (int l = i + k + L; l <= j; l += L)
		{
			if (input[l] != input[l - L])
			{
				return false;
			}
		}
	}
	return true;
}
void go(int i, int j)
{
	int len = j - i + 1;
	int ret = len;
	for (int L = i; L < j; L++)
	{
		ret = min(ret, dp[i][L] + dp[L + 1][j]);
	}
	for (int L = 1; L <= len / 2; L++)
	{
		if (len % L == 0)
		{
			if (check(i, j, L))
			{
				ret = min(ret, nums[len / L] + 2 + dp[i][i + L - 1]);
			}
		}
	}
	dp[i][j] = ret;
}
int main()
{
	for (int i = 0; i < 10; i++)
	{
		nums[i] = 1;
	}
	for (int i = 10; i < 100; i++)
	{
		nums[i] = 2;
	}
	for (int i = 100; i < 201; i++)
	{
		nums[i] = 3;
	}
	scanf("%d", &t);
	REP(i, t)
	{
		scanf("%s", input);
		int len = strlen(input);
		memset(dp, 0x7f, sizeof dp);
		REP(i, n)
		dp[i][i] = 1;
		for (int L = 1; L <= len; L++)
		{
			for (int i = 0; i < len; i++)
			{
				int j = i + L - 1;
				if (j >= len)
				{
					break;
				}
				go(i, j);
			}
		}
		printf("%d\n", dp[0][len - 1]);
	}
	return 0;
}
