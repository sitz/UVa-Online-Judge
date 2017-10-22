#include <bits/stdc++.h>

using namespace std;

// problem: Merchant Guild
// author : Bernhard Then
// method : dynamic programming, counting
// runtime: O(N^3), N = number of traders

const int MAXN = 300;

int locals[MAXN + 1];
// locals[i] is the number of local traders with favourite locations i (1 <= i <= n <= MAXN)

int cumulated_locals[MAXN + 1];
// cumulated_locals[0] = 0
// cumulated_locals[i] = locals[1] + locals[1] + ... + locals[i]

int M;
// calculate all results modulo M; 2 <= M

int dp[MAXN + 1][MAXN + 1];
// for doing memoization in function rec

int bin[MAXN + 1][MAXN + 1];
// binomial coefficients

int rec(int location, int additional)
{
	// 1 <= location; 0 <= additional
	// at most additional+1 traders can be assigned to location
	if (locals[location] > additional + 1)
	{
		return 0;
	}
	// recursion ends at location == 1
	if (location == 1)
	{
		return 1;
	}
	// memoization
	int &res = dp[location][additional];
	if (res != -1)
	{
		return res;
	}
	res = 0;
	int free = location + additional - cumulated_locals[location];
	for (int i = locals[location]; i <= additional + 1; ++i)
	{
		res = (res + (long long)bin[free][i - locals[location]] * rec(location - 1, additional + 1 - i)) % M;
	}
	return res;
}

int possible(int n_traders)
{
	// tests if it is possible to assign foreign traders to locations s.th. every trader (local+foreign)
	// finds a free spot
	int additional = 0;
	for (int i = n_traders; i >= 1; --i)
	{
		if (locals[i] > additional + 1)
		{
			return 0;
		}
		additional = additional + 1 - locals[i];
	}
	return 1;
}

int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 0; c < cases; ++c)
	{
		int n_traders;// number of all traders
		int n_locals; // number of local traders; 0 <= n_locals <= n_traders <= MAXN
		scanf("%d%d%d", &n_traders, &n_locals, &M);
		// initialize locals
		for (int i = 1; i <= n_traders; ++i)
		{
			locals[i] = 0;
		}
		// read in local traders
		for (int i = 0; i < n_locals; ++i)
		{
			int trader_no, favourite_pos;
			scanf("%d%d", &trader_no, &favourite_pos);// trader_no is not needed actually
			++locals[favourite_pos];
		}
		if (!possible(n_traders))
		{
			puts("NO");
			continue;
		}
		// calculate binomial coefficients modulo M
		for (int i = 0; i <= MAXN; ++i)
		{
			bin[i][0] = bin[i][i] = 1;
			for (int j = 1; j < i; ++j)
			{
				bin[i][j] = (bin[i - 1][j - 1] + bin[i - 1][j]) % M;
			}
		}
		// calculate cumulated_locals
		cumulated_locals[0] = 0;
		for (int i = 1; i <= n_traders; ++i)
		{
			cumulated_locals[i] = cumulated_locals[i - 1] + locals[i];
		}
		// init dp
		for (int i = 0; i <= n_traders; ++i)
		{
			for (int j = 0; j <= n_traders; ++j)
			{
				dp[i][j] = -1;
			}
		}
		printf("YES %d\n", rec(n_traders, 0));
	}
	return 0;
}
