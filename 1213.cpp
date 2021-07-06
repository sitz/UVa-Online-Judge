#include <bits/stdc++.h>

using namespace std;

#define N 1120

char primes[N];

int pnums[187];
unsigned int dp[N + 1][187][15];

unsigned int nWays(int n, int i, int k)
{
	if (!n && !k)
	{
		return 1;
	}
	else if (n < 0 || i >= 187 || k == 0)
	{
		return 0;
	}
	else if (dp[n][i][k] != -1)
	{
		return dp[n][i][k];
	}
	else
	{
		return dp[n][i][k] = nWays(n, i + 1, k) + nWays(n - pnums[i], i + 1, k - 1);
	}
}

int main()
{
	int i, j, k;

	memset(primes, 0, sizeof(primes));

	primes[0] = primes[1] = 1;
	for (i = 2; i * i < N; i++)
	{
		if (!primes[i])
		{
			for (j = i * i; j < N; j += i)
			{
				primes[j] = 1;
			}
		}
	}

	for (i = 0; i <= N; i++)
	{
		for (j = 0; j < 187; j++)
		{
			for (k = 0; k < 15; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	j = 0;
	for (i = 2; i < N; i++)
	{
		if (!primes[i])
		{
			pnums[j++] = i;
		}
	}

	scanf("%d%d", &i, &j);
	while (i || j)
	{
		printf("%u\n", nWays(i, 0, j));
		scanf("%d%d", &i, &j);
	}
	return 0;
}
