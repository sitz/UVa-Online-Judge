#include <bits/stdc++.h>

using namespace std;

#define GET(x) (mark[(x) >> 5] >> ((x)&31) & 1)
#define SET(x) (mark[(x) >> 5] |= 1 << ((x)&31))

int mark[(2000000 >> 5) + 1], phi[2000005], dep_phi[2000005], dp[2000005];

void sieve()
{
	SET(1);
	int n = 2000000;
	for (int i = 2; i <= n; i++)
	{
		if (!GET(i))
		{
			for (int j = i; j <= n; j += i)
			{
				phi[j] = phi[j] / i * (i - 1);
				SET(j);
			}
		}
	}
}

int main()
{
	for (int i = 2; i <= 2000000; i++)
	{
		phi[i] = i;
	}
	sieve();
	for (int i = 2; i <= 2000000; i++)
	{
		dep_phi[i] = 1 + dep_phi[phi[i]];
		dp[i] = dp[i - 1] + dep_phi[i];
	}
	scanf("%*d");
	int i, j;
	while (scanf("%d%d", &i, &j) == 2)
	{
		printf("%d\n", dp[j] - dp[i - 1]);
	}
	return 0;
}
