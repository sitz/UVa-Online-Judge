#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod 10000
ll Pow(ll k, ll m)
{
	ll h1, h, m1;
	if (m == 0)
	{
		return 1;
	}
	if (m == 1)
	{
		return k;
	}
	m1 = m / 2;
	h = Pow(k, m1);
	h1 = ((h % mod) * (h % mod)) % mod;
	if (m % 2 == 1)
	{
		h1 = ((h1 % mod) * (k % mod)) % mod;
	}
	return h1;
}
int main(void)
{
	ll a[15], h = 1, n, t = 1, n1, l1, ans, i;
	memset(a, 0, sizeof(a));
	for (i = 1; i < 15; i++)
	{
		a[i] = h * 9 * i;
		h *= 10;
		if (i != 1)
		{
			a[i] = (a[i] % mod + a[i - 1] % mod + mod) % mod;
		}
	}
	while (scanf("%lld", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		ans = 0;
		l1 = 0;
		n1 = n;
		while (n1)
		{
			n1 /= 10;
			l1++;
		}
		n1 = 1;
		for (i = 0; i < l1 - 1; i++)
		{
			n1 *= 10;
		}
		ans = (a[l1 - 1] % mod + (n - n1 + 1) % mod * l1 % mod + ans % mod + mod - 1) % mod;
		ans = (ans % mod + 4 * n % mod + mod - 2) % mod;
		ans = ((Pow(2, n) - n - 1 + mod) % mod + ans % mod + mod) % mod;
		ans = (ans % mod + Pow(2, n - 1) % mod * (a[l1 - 1] % mod + (n - n1 + 1) % mod * l1 % mod + n % mod) + mod) % mod;
		printf("Case %lld: %lld\n", t, ans);
		t++;
	}
	return 0;
}
