#include <bits/stdc++.h>

using namespace std;

/**
 * Dynamic Programming, Subset sum
 */

enum
{
	MAX_COINS = 100,
	MAX_CENTS = 500,
	MAX_SUM = MAX_COINS * MAX_CENTS
};

bool possible[MAX_SUM + 1];

int main()
{
	int num_case;
	scanf("%d", &num_case);
	while (num_case--)
	{
		int num_coins;
		scanf("%d", &num_coins);
		int coin[MAX_COINS];
		for (int i = 0; i < num_coins; ++i)
			scanf("%d", &coin[i]);
		int sum = std::accumulate(coin, coin + num_coins, 0);
		memset(possible, 0, sizeof(possible));
		possible[0] = 1;
		for (int i = 0; i < num_coins; ++i)
			for (int j = sum - coin[i]; j >= 0; --j)
				if (possible[j])
					possible[j + coin[i]] = true;
		int min = INT_MAX;
		for (int i = 0; i <= sum; ++i)// sum=0 cent is valid
			if (possible[i] && abs(2 * i - sum) < min)
				min = abs(2 * i - sum);
		printf("%d\n", min);
	}
	return 0;
}
