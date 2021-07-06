#include <bits/stdc++.h>

using namespace std;

#define MAX 50000

typedef long long LL;
typedef unsigned long long ULL;

LL calc(double N, double K)
{
	double root1 = (-3 * K + sqrt(12 * N / K - 3 * K * K)) / 6;
	double root2 = (-3 * K - sqrt(12 * N / K - 3 * K * K)) / 6;
	if (root1 >= 0)
	{
		return (LL)root1;
	}
	return (LL)root2;
}

int main()
{
	while (1)
	{
		LL N, K, k;
		scanf("%lld", &N);
		if (N == 0)
		{
			break;
		}
		K = (LL)ceil(pow(N, 1 / 3.0)) + 1;
		bool stat = false;
		for (k = 1; k <= K; k++)
		{
			LL Y = calc((double)N, (double)k);
			LL X = k + Y;
			if (X >= 0 && Y >= 0 && X * X * X - Y * Y * Y == N)
			{
				printf("%lld %lld\n", X,Y);
				stat = true;
				break;
			}
		}
		if (!stat)
		{
			printf("No solution\n");
		}
	}
	return 0;
}
