#include <bits/stdc++.h>

using namespace std;

long long a, b, c, x, y;
long long E_GCD(long long aa, long long bb, long long &xx, long long &yy)
{
	if (bb == 0)
	{
		xx = 1;
		yy = 0;
		return aa;
	}
	else
	{
		long long tx, ty;
		long long d = E_GCD(bb, aa % bb, tx, ty);
		xx = ty;
		yy = tx - aa / bb * ty;
		return d;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		long long d = E_GCD(a, b, x, y);
		if (c % d)
		{
			puts("Impossible");
		}
		else if (a * b < 0)
		{
			puts("Infinitely many solutions");
		}
		else
		{
			c /= d;
			x *= c;
			y *= c;
			long long lower = (long long int)ceil((double)-x * d / b);
			long long upper = (long long int)floor((double)y * d / a);
			if (upper - lower + 1 > 0)
			{
				printf("%lld\n", upper - lower + 1);
			}
			else
			{
				puts("Impossible");
			}
		}
	}
	return 0;
}
