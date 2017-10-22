#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL MOD = 1000000007LL;

LL modpow(int base, int power)
{
	if (power == 0)
	{
		return 1LL;
	}
	LL tmp = modpow(base, power >> 1);
	tmp = (tmp * tmp) % MOD;
	if (power & 1)
	{
		tmp = (tmp * base) % MOD;
	}
	return tmp;
}

int main()
{
	char pp[10005];
	int T, t = 0;
	scanf("%d", &T);
	getchar();
	while (T--)
	{
		gets(pp);
		int l = strlen(pp);
		LL mod = 0LL;
		for (int i = 0; i < l; i++)
		{
			mod = (mod * 10 + (pp[i] - '0')) % (MOD - 1);
		}
		LL ans = modpow(3, mod);
		ans = (ans + 1) % MOD;
		ans = (ans * modpow(2, MOD - 2)) % MOD;
		ans = (ans + MOD) % MOD;
		printf("Case %d: %lld\n", ++t, ans);
	}
	return 0;
}
