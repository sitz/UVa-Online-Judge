#include <bits/stdc++.h>

using namespace std;

int main()
{
	// finding the divisors of |a-b|
	int a, b;
	while (true)
	{
		scanf("%d %d", &a, &b);
		if (a == 0)
		{
			break;
		}
		a -= b;
		if (a < 0)
		{
			a = -a;
		}
		int ans = 1;
		for (int i = 2; i <= a / i; ++i)
		{
			if (a % i == 0)
			{
				int cont = 1;
				while (a % i == 0)
				{
					a /= i;
					++cont;
				}
				ans *= cont;
			}
		}
		if (a > 1)
		{
			ans <<= 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}
