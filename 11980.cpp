#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1LL << 30;

LL n, m;

int main()
{
	int t, cas = 0;
	scanf("%d", &t);
	while (t--)
	{
		LL res1 = 0, res2 = 0;
		scanf("%lld %lld", &n, &m);
		for (int i = 60; i >= 0; --i)
		{
			LL test = 1LL << i;
			if ((n & test) == 0)
			{
				res1 |= m & test;
			}
			else if ((m & test) == 0)
			{
				res1 |= test;
			}
			else
			{
				while (test)
				{
					res1 |= test, test >>= 1;
				}
				break;
			}
		}
		LL tmp = 0;
		LL all = 1LL << 61;
		--all;
		for (int i = 60; i >= 0; --i)
		{
			LL test = 1LL << i;
			if (res1 & test)
			{
				LL low = 0, upper = 0;
				low = n ^ tmp;
				upper = n ^ tmp;
				LL range = test;
				upper |= range - 1;
				low &= all - (range - 1);
				tmp |= test;
				//                printf("upper = %lld low = %lld\n", upper, low);
				if (upper <= m)
				{
					continue;
				}
				if (low <= m)
				{
					low = m + 1;
				}
				LL a = upper + low;
				LL b = upper - low + 1;
				if (a & 1)
				{
					b >>= 1;
				}
				else
				{
					a >>= 1;
				}
				res2 = (res2 + (a % MOD) * (b % MOD)) % MOD;
			}
		}
		printf("Case %d: %lld %lld\n", ++cas, res1, res2);
	}
	return 0;
}
