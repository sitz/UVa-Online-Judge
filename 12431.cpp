#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

//typedef  long LL;
LL mmod(LL a, LL b, LL n)
{
	a = a % n;
	LL res = 0;
	while (b)
	{
		if (b & 1)
		{
			res = res + a;
			if (res >= n)
			{
				res = res - n;
			}
		}
		a = a << 1;
		if (a >= n)
		{
			a = a - n;
		}
		b = b >> 1;
	}
	return res;
}

LL exmod(LL a, LL b, LL n)
{
	a = a % n;
	LL res = 1;
	while (b >= 1)
	{
		if (b & 1)
		{
			res = mmod(res, a, n);
		}
		a = mmod(a, a, n);
		b = b >> 1;
	}
	return res;
}

LL same(LL n, LL b, LL d, LL m)
{
	LL res = exmod(b, n, (b - 1) * m);
	//printf("%lld %lld %lld %lld %lld\n", n, b, d, m, res);
	if (res == 0)
	{
		res += (b - 1) * m - 1;
	}
	else
	{
		res -= 1;
	}
	res /= (b - 1);
	res = (res * d) % m;
	return res;
}

int main()
{
	int T, cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		LL n, b, d, m;
		scanf("%lld%ld%ld%ld", &n, &b, &d, &m);
		printf("Case %d: %lld\n", cas++, same(n, b, d, m));
	}
	return 0;
}
