#include <bits/stdc++.h>

using namespace std;

#define mod 10000000000000007LL
long long int times(long long int a, long long int b)
{
	long long int rt = 0LL;
	int i;
	for (i = 63; i >= 0; i--)
	{
		if (a & ((1LL) << i))
		{
			rt = (2 * rt + b) % mod;
		}
		else
		{
			rt = (2 * rt) % mod;
		}
	}
	return rt;
}
int main()
{
	long long int r, c, a, b, ans, p;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &r, &c);
		a = (r * c) / 2;
		b = (r * c + 1) / 2;
		ans = 1LL;
		for (p = b - 1LL, c = a; p; p /= 2)
		{
			if (p & 1)
			{
				ans = times(ans, c);
			}
			c = times(c, c);
		}
		for (p = a - 1LL, c = b; p; p /= 2)
		{
			if (p & 1)
			{
				ans = times(ans, c);
			}
			c = times(c, c);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
