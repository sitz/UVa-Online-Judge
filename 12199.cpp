#include <bits/stdc++.h>

using namespace std;

// preprocess: O(mod); after: O(log mod)

typedef long long ll;

const int mod = 10567201;

ll fact[mod];

// Compute a^n % 'mod' in O(log n), mod > 1
ll modexp(ll a, ll n, int mod)
{
	ll r = 1;
	while (n)
	{
		if (n & 1)
		{
			r = (r * a) % mod;
			--n;
		}
		else
		{
			a = (a * a) % mod;
			n >>= 1;
		}
	}
	return r;
}

// inverse of a in Z_p.
ll inverse(ll a)
{
	return modexp(a, mod - 2, mod);
}

// (m choose n) mod p, for n < p.
// for any m < p, (m choose n) mod p = ((m mod p) choose n) mod p,
// even if m mod p >= n.
ll ncr(ll m, ll n)
{
	if (m < n)
		return 0;
	return (fact[m] * inverse((fact[n] * fact[m - n]) % mod)) % mod;
}

ll calc(ll n, ll m, bool iszero)
{
	ll pow2n = modexp(2, n, mod),
		 invpow2n = inverse(pow2n);
	if (m & 1)
		return (ncr(pow2n, m) * invpow2n) % mod;
	else
	{
		static const ll inv2 = inverse(2);
		ll dif = ncr((pow2n * inv2) % mod, m / 2);
		if (m & 2)
			dif = (mod - dif) % mod;
		ll res1 = ((ncr(pow2n, m) + mod - dif) * invpow2n) % mod;
		return iszero ? (dif + res1) % mod : res1;
	}
}

int main()
{
	ll n, m, v;
	fact[0] = 1;
	for (n = 1; n < mod; ++n)
		fact[n] = (n * fact[n - 1]) % mod;
	while (scanf("%lli%lli%lli", &n, &m, &v) == 3 && n)
		printf("%lli\n", calc(n, m, v == 0));
	return 0;
}
