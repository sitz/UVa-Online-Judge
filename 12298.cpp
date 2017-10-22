#include <bits/stdc++.h>

using namespace std;

bool is[50005], have[5][50005];
long long int dp[5][50005];

int main()
{
	int a, i, j, k, N, n, b;
	char ch;

	for (i = 2; i < 50005; i++)
		if (!is[i])
			for (j = i * 2; j < 50005; j += i)
				is[j] = true;

	while (scanf(" %d %d %d", &a, &b, &N) == 3 && (a + b + N))
	{
		for (i = 1; i <= b; i++)
			if (is[i])
				have[0][i] = have[1][i] = have[2][i] = have[3][i] = have[4][i] = 1;

		for (n = 0; n < N; n++)
		{
			scanf(" %d %c", &i, &ch);
			if (ch == 'S')
				j = 1;
			if (ch == 'H')
				j = 2;
			if (ch == 'C')
				j = 3;
			if (ch == 'D')
				j = 4;
			have[j][i] = 0;
		}

		memset(dp, 0, sizeof(dp));
		for (i = 1; i <= b; i++)
			if (is[i] && have[1][i] == 1)
				dp[1][i] = 1;

		for (i = 1; i <= b; i++)
			if (is[i] && have[2][i] == 1)
				for (j = b; j >= i; j--)
					dp[2][j] += dp[1][j - i];

		for (i = 1; i <= b; i++)
			if (is[i] && have[3][i] == 1)
				for (j = b; j >= i; j--)
					dp[3][j] += dp[2][j - i];

		for (i = 1; i <= b; i++)
			if (is[i] && have[4][i] == 1)
				for (j = b; j >= i; j--)
					dp[4][j] += dp[3][j - i];

		for (i = a; i <= b; i++)
			printf("%lld\n", dp[4][i]);
		printf("\n");
	}
	return 0;
}
