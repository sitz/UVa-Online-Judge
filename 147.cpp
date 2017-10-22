#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 30000;
const int coin[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

long long dp[MAXSIZE + 10];

void init()
{
	int i, j;
	dp[0] = 1;
	for (i = 0; i < 11; i++)
	{
		for (j = 1; j <= MAXSIZE; j++)
		{
			if (j >= coin[i])
			{
				dp[j] += dp[j - coin[i]];
			}
		}
	}
}

int main()
{
	init();
	double f;
	while (EOF != scanf("%lf", &f))
	{
		int val = (int)(f * 100 + 1e-10);
		if (!val)
		{
			break;
		}
		printf("%6.2lf%17lld\n", f, dp[val]);
	}
	return 0;
}
