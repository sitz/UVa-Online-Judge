#include <bits/stdc++.h>

using namespace std;

#define nMax 9000

int p[nMax];
long long k, a[nMax];

void init()
{
	for (int i = 2; i < nMax; i++)
		if (!a[i])
		{
			p[k++] = i;
			for (int j = i * i; j < nMax; j += i)
				a[j] = 1;
		}
}

#define LL long long
#define mod 1000000007
#define bug printf("Before Here!");

int i;
LL f(LL s)
{
	LL ret = 1LL;
	for (int j = 0; j < i; j++)
	{
		ret *= (a[j] / s + 1);
		ret %= mod;
	}
	return ret;
}

LL n;
int main()
{
	int t, cas = 1;
	init();
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld", &n, &k);
		for (i = 0; i < 1000; i++)
		{
			LL m = n;
			a[i] = 0LL;
			while (m)
			{
				m /= p[i];
				a[i] += m;
			}
			if (a[i] < k)
				break;
		}

		printf("Case %d: %lld\n", cas++, ((f(k) - f(k + 1)) % mod + mod) % mod);
	}
	return 0;
}
