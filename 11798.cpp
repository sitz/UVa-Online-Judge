#include <bits/stdc++.h>

using namespace std;

const int MOD = (int)1e9 + 7;
const int MAXK = 51;
const int MAXN = 211;

int dp[MAXK][MAXN], choose[MAXN][MAXN], odd[MAXK][MAXN], even[MAXK][MAXN];

int add_mod(int a, int b)
{
	return a + b >= MOD ? a + b - MOD : a + b;
}

int multiply_mod(int a, int b)
{
	return (long long)(a)*b % MOD;
}

int main()
{
	choose[0][0] = 1;
	for (int i = 1; i < MAXN; ++i)
	{
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j)
		{
			choose[i][j] = add_mod(choose[i - 1][j - 1], choose[i - 1][j]);
		}
	}
	dp[0][0] = 1;
	for (int index = 1; index < MAXN; ++index)
	{
		dp[1][index] = 1;
	}
	for (int i = 2; i < MAXK; ++i)
	{
		for (int j = i; j < MAXN; ++j)
		{
			for (int k = 1; j - k >= i - 1; ++k)
			{
				dp[i][j] = add_mod(dp[i][j], multiply_mod(dp[i - 1][j - k], choose[j][k]));
			}
		}
	}
	odd[1][0] = 1;
	for (int i = 2; i < MAXK; ++i)
	{
		for (int j = 1; j < MAXN - 1; ++j)
		{
			int w = j, b = j + 1;
			for (int k = 1; k < i; ++k)
			{
				int w_color = k, b_color = i - k;
				int ways = choose[i][k];
				ways = multiply_mod(ways, dp[b_color][b]);
				ways = multiply_mod(ways, dp[w_color][w]);
				odd[i][j] = add_mod(odd[i][j], ways);
			}
		}
	}
	for (int i = 2; i < MAXK; ++i)
	{
		for (int j = 1; j < MAXN; ++j)
		{
			int w = j, b = j;
			for (int k = 1; k < i; ++k)
			{
				int w_color = k, b_color = i - k;
				int ways = choose[i][k];
				ways = multiply_mod(ways, dp[b_color][b]);
				ways = multiply_mod(ways, dp[w_color][w]);
				even[i][j] = add_mod(even[i][j], ways);
			}
		}
	}
	int task;
	scanf("%d", &task);
	for (int task_index = 1; task_index <= task; ++task_index)
	{
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		int w = (n + 1) * (m + 1) / 2;
		bool bit = ((n + 1) * (m + 1) & 1) == 1;
		int ret = 0;
		for (int empty = 0; empty <= k; ++empty)
		{
			int ways = multiply_mod(choose[k][empty], bit ? odd[k - empty][w] : even[k - empty][w]);
			ret = add_mod(ret, ways);
		}
		printf("Case %d: %d\n", task_index, ret);
	}
	return 0;
}
