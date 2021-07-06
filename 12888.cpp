#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define ins insert
#define ff first
#define ss second
#define ll long long int
#define llu long long unsigned
#define sss stringstream
#define oss ostringstream
#define iss istringstream
#define pii pair<int, int>
#define _sq(x) ((x) * (x))
#define lcm(a, b) ((a) * ((b) / gcd(a, b)))
#define mem(a) memset(a, 0, sizeof(a))
#define _set(a) memset(a, -1, sizeof(a))
#define popcount(n) __builtin_popcount(n)
#define popcountl(n) __builtin_popcountll(n)
#define ctz(x) __builtin_ctz(x)// # trailing 0s
#define ctzl(x) __builtin_ctzll(x)
#define clz(x) __builtin_clz(x)
#define clzl(x) __builtin_clzll(x)// # leading 0s
#define check(mask, k) (mask & (1 << k))
#define set1(mask, k) (mask | (1 << k))
#define set0(mask, k) (mask & (~(1 << k)))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pi acos(-1.0)
#define inf (1 << 30)
#define eps 1e-9
#define MAX 1000005
#define MAXL 15

int fr[MAX], mul[MAX];

void gen()
{
	int i, j;
	for (i = 2; i < MAX; i++)
	{
		mul[i] = 1;
	}
	for (i = 2; i < MAX; i++)
	{
		if (fr[i] == 0)
		{
			for (j = i; j < MAX; j += i)
			{
				fr[j]++;
				mul[j] *= i;
			}
		}
	}
}

int main()
{
	int tcase;
	ll n, m, i;
	gen();
	scanf("%d", &tcase);
	while (tcase--)
	{
		scanf("%lld %lld", &n, &m);
		if (n > m)
		{
			swap(n, m);
		}
		ll ans = n * m;
		for (i = 2; i <= n; i++)
		{
			if (mul[i] == i)
			{
				ll tmp = (m / i);
				ll tmp1 = (n / i);
				if (fr[i] & 1)
				{
					ans -= (tmp * tmp1);
				}
				else
				{
					ans += (tmp * tmp1);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
