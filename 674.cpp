#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 7500;
const int coin[] = {1, 5, 10, 25, 50};

int dp[MAXSIZE];

void init()
{
	int i, j;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (i = 0; i < 5; i++)
		for (j = 1; j < MAXSIZE; j++)
			if (j >= coin[i])
			{
				dp[j] += dp[j - coin[i]];
			}
}

int main()
{
	init();
	int val;
	while (EOF != scanf("%d", &val))
	{
		printf("%d\n", dp[val]);
	}
	return 0;
}
