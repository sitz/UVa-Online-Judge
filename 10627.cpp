#include <bits/stdc++.h>

using namespace std;

#define LL long long
const double eps = 1e-8;

LL gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}

LL lcm(LL a, LL b)
{
	return a / gcd(a, b) * b;
}

LL L, u, v, t;

void solve()
{
	if (u == 0 && v == 0)
	{
		puts("0");
		return;
	}
	if (u < v)
	{
		u = v;
	}
	LL mx = u * t;
	LL ans = 0;
	if (mx >= L)
	{
		ans++;
		ans += (mx - L) / (L * 2);
	}
	printf("%lld\n", ans);
}

int main()
{
	while (scanf("%lld%lld%lld%lld", &L, &u, &v, &t) != -1 && L)
	{
		if (u == 0 || v == 0)
		{
			solve();
			continue;
		}
		if (u < v)
		{
			swap(u, v);
		}
		LL mx = t * (u + v);
		LL ans = 0;
		if (mx >= L)
		{
			ans++;
			ans += (mx - L) / (L * 2);
		}
		if (t * (u - v) >= L)
		{
			ans++;
			ans += (t * (u - v) - L) / (L * 2);
		}
		LL tmp = gcd(u, v);
		if (((u - v) / tmp) % 2 == 1 && L <= t * tmp)
		{
			ans--;
			ans -= (LL)(t * tmp - L) / (L * 2);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
