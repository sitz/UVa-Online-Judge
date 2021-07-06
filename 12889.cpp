#include <bits/stdc++.h>

using namespace std;

#define sc scanf
#define pf printf
#define pb push_back
#define pob pop_back
#define PI 2 * acos(0.0)
#define NL printf("\n")
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)
#define fr0(i, n) for (i = 0; i < n; i++)
#define frp(i, a, b) for (i = a; i <= b; i++)
#define frn(i, a, b) for (i = a; i >= b; i--)
#define CLR(a) memset(a, 0, sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))

template <class T>
T bigmod(T b, T p, T m)
{
	if (!p)
	{
		return 1;
	}
	T res = (bigmod(b, p / 2, m)) % m;
	res = (res * res) % m;
	if (p & 1)
	{
		res = (res * b) % m;
	}
	return res % m;
}

template <class T>
T modinv(T b, T m)
{
	return bigmod(b, m - 2, m);
}

typedef long long LL;
typedef unsigned long long ULL;

const LL INF = 1000000007LL;
const LL MOD = 1000000007LL;
const int MAX = 1000005;
const int sz = 100005;

int main()
{
	int n, k, i, f, ff, fff, t, on;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		f = 0, ff = 0, fff = 0, on = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &k);
			if (!k)
			{
				f = 1;
			}
			if (k)
			{
				ff = 1;
			}
			if (k > 1)
			{
				fff = 1;
			}
			if (k == 1)
			{
				on = 1;
			}
		}
		if (n == 1 || (f && !ff) || (!f && !on && fff) || (!f && !fff))
		{
			puts("Better luck next time!");
		}
		else
		{
			puts("Happy Birthday Tutu!");
		}
	}
	return 0;
}
