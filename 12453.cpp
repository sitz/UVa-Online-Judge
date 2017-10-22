#include <bits/stdc++.h>

using namespace std;

void ext_gcd(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return;
	}
	ext_gcd(b, a % b, x, y);
	long long t = x;
	x = y;
	y = t - a / b * y;
}
long long inv(long long a, long long b, long long n)
{
	a %= n;
	b %= n;
	long long x, y, e;
	ext_gcd(a, n, x, y);
	e = x * b % n;
	return (e + n) % n;
}
// ret min (x+y) for a*x-b*y=c (x>=0,y>=0)
long long cal(long long a, long long b, long long c)
{
	long long d = __gcd(a, b);
	if (c % d != 0)
	{
		return 1LL << 60;
	}
	a /= d;
	b /= d;
	c /= d;
	long long x = inv(a, c, b);
	long long y = (a * x - c) / b;
	long long k1 = -x / b;
	long long k2 = -y / a;
	if (y < 0)
	{
		if ((-y) % a != 0)
		{
			k2++;
		}
	}
	return x + y + max(k1, k2) * (a + b);
}

long long s, x1, y1_, x2, y2;

int main()
{
	int cas = 1;
	while (~scanf("%lld%lld%lld%lld%lld", &s, &x1, &y1_, &x2, &y2))
	{
		if (s == 0 && x1 == 0 && y1_ == 0 && x2 == 0 && y2 == 0)
		{
			break;
		}
		if (x1 == x2 || y1_ == y2)
		{
			printf("Case %d: 1\n", cas++);
			continue;
		}
		long long ans = (1LL << 60);
		long long ca1, ca2;
		if (x2 >= x1)
		{
			ca1 = (s - x1) * 2;
		}
		else
		{
			ca1 = x1 * 2;
		}
		if (y2 >= y1_)
		{
			ca2 = (s - y1_) * 2;
		}
		else
		{
			ca2 = y1_ * 2;
		}
		long long x3 = abs(x2 - x1);
		long long y3 = abs(y2 - y1_);
		//tepan
		long long cao = __gcd(y3, x3);
		cao = y3 * x3 / cao;
		ans = (cao / y3 + cao / x3) * 2;
		if (x3 * ca2 % (2 * s) == 0)
		{
			ans = min(ans, cal(y3, x3, x3 * ca2 / (2 * s)) * 2 + 1);
		}
		if (y3 * ca1 % (2 * s) == 0)
		{
			ans = min(ans, cal(y3, x3, -y3 * ca1 / (2 * s)) * 2 + 1);
		}
		if ((x3 * ca2 - y3 * ca1) % (2 * s) == 0)
		{
			ans = min(ans, cal(y3, x3, (x3 * ca2 - y3 * ca1) / (2 * s)) * 2 + 2);
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
