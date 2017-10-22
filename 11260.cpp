#include <bits/stdc++.h>

using namespace std;

typedef long long llong;
llong mod = 100000000;

llong fx(llong n)
{
	llong product = 1;
	int res = n % 3;
	if (res == 0)
	{
		product *= (n / 3);
		product %= mod;
		product *= (n + 1);
		product %= mod;
		product *= (4 * n - 1);
		product %= mod;
	}
	else if (res == 2)
	{
		product *= (n + 1) / 3;
		product %= mod;
		product *= n;
		product %= mod;
		product *= (4 * n - 1);
		product %= mod;
	}
	else
	{
		product = (4 * n - 1) / 3;
		product %= mod;
		product *= n;
		product %= mod;
		product *= (n + 1);
		product %= mod;
	}
	return product;
}

llong fy(llong n)
{
	llong product = 1;
	int res = n % 3;
	if (res == 0)
	{
		product *= (n / 3);
		product %= mod;
		product *= (n + 1);
		product %= mod;
		product *= (2 * n + 1);
		product %= mod;
	}
	else if (res == 2)
	{
		product *= (n + 1) / 3;
		product %= mod;
		product *= n;
		product %= mod;
		product *= (2 * n + 1);
		product %= mod;
	}
	else
	{
		product = (2 * n + 1) / 3;
		product %= mod;
		product *= n;
		product %= mod;
		product *= (n + 1);
		product %= mod;
	}
	return (2 * product) % mod;
}

int main()
{
	llong n, n1, n2, x, y, z, m;
	while (scanf("%lld", &n) != EOF && n)
	{
		if (n > 0)
		{
			n -= !(n % 2);
			m = sqrt(n);
			n2 = (m - 1) >> 1, n1 = (m) >> 1;
			x = fx(n1);
			y = fy(n2);
			z = ((n - m * m + 2 * (m % 2) + (m % 2 == 0)) / 2) % mod;
			z *= m;
			z %= mod;
			printf("%lld\n", (x + y + z) % mod);
		}
		else
		{
			printf("0\n");
		}
	}
	return 0;
}
