#include <bits/stdc++.h>

using namespace std;

typedef long long Big;
Big K;

int GETI()
{
	Big L, U, sum, M;
	L = 1;
	U = K / 2 + 1;
	M = (L + U) / 2;
	sum = (M * (M + 1)) / 2;
	while (L != U && sum != K && L != U - 1)
	{
		if (sum > K)
		{
			U = M - 1;
		}
		else
		{
			L = M + 1;
		}
		M = (U + L) / 2;
		sum = (M * (M + 1)) / 2;
	}
	return M;
}
void CAL()
{
	Big I, i, sum;
	I = GETI();
	sum = (I * (I + 1)) / 2;
	if (sum == K)
	{
		printf("%lld\n", I);
		return;
	}
	for (i = I;; i++)
	{
		sum = ((i * (i + 1)) / 2) - K;
		if (sum % 2 == 0)
		{
			printf("%lld\n", i);
			return;
		}
	}
}

int main()
{
	int kase;
	scanf("%d", &kase);
	while (kase--)
	{
		scanf("%lld", &K);
		if (K < 0)
		{
			K = -K;
		}
		if (K == 0 || K == 2)
		{
			printf("3\n");
			if (kase)
			{
				printf("\n");
			}
			continue;
		}
		else if (K == 1)
		{
			printf("1\n");
			if (kase)
			{
				printf("\n");
			}
			continue;
		}
		CAL();
		if (kase)
		{
			putchar('\n');
		}
	}
	return 0;
}
