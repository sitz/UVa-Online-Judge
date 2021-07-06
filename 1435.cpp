#include <bits/stdc++.h>

using namespace std;

#define maxn 3000009
#define ll long long

void gcd(ll a, ll b, ll &d, ll &x, ll &y)
{
	if (!b)
	{
		d = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

bool check(ll a, ll b, ll n)
{
	ll d, x, y;
	gcd(a, b, d, x, y);
	if (n % d)
	{
		return 0;
	}
	a /= d;
	b /= d;
	n /= d;
	x *= n;
	y *= n;
	if (x < 0)
	{
		swap(x, y);
		swap(a, b);
	}
	return y + a * (x / b) >= 0;
}

bool yes(ll a, ll b, ll x, ll y)
{
	if ((x % a == 0 && y % b == 0) || (x % b == 0 && y % a == 0))
	{
		return 1;
	}
	return 0;
}

int main()
{
	int t;
	ll a, b, x, y;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
		if ((x % a == 0 && x % b == 0 && check(a, b, y) || (y % a == 0 && y % b == 0 && check(a, b, x)) || yes(a, b, x, y)))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
