#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;

ll mypow(ll n, ll mod)
{
	if (n == 1)
	{
		return 2;
	}
	if (n == 0)
	{
		return 1;
	}
	ll ret = mypow(n / 2, mod);
	ret = ret * ret;
	ret %= mod;
	if (n % 2 == 1)
	{
		ret *= 2;
	}
	return ret % mod;
}

bool solve(ll n)
{
	if (mypow(n - 1, n) != 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

main()
{
	ll n;
	while (cin >> n && n != -1)
	{
		if (solve(n))
		{
			cout << n << " is a Jimmy-number" << endl;
		}
		else
		{
			cout << n << " is not a Jimmy-number" << endl;
		}
	}
}
