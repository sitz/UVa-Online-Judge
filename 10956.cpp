#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ULL;

static unsigned int base, min_, max_, max_2, r_non, r_fails, r_list[50001];

static unsigned int modexp(unsigned int b, unsigned int e, unsigned int m)
{
	unsigned int r;
	for (r = 1; e > 1; e >>= 1)
	{
		if (e & 1)
		{
			r = (unsigned int)(((ULL)r * (ULL)b) % m);
		}
		b = (unsigned int)(((ULL)b * (ULL)b) % m);
	}
	r = (unsigned int)(((ULL)r * (ULL)b) % m);
	return r;
}

static int check(unsigned int b, unsigned int n)
{
	unsigned int t, u, x;
	for (u = (n - 1) >> 1, t = 1; (u & 1) == 0; u >>= 1, t++)
		;
	x = modexp(b, u, n);
	if (x == 1 || x == (n - 1))
	{
		return 1;
	}
	while (t--)
	{
		u = ((ULL)x * (ULL)x) % n;
		if (u == 1)
		{
			return (x == (n - 1)) ? 1 : 0;
		}
		x = u;
	}
	return x == 1;
}

static void solve()
{
	unsigned int x;
	r_non = 0;
	r_fails = 0;
	max_2 = max_;
	if (max_2 > 0 && (max_2 & 1) == 0)
	{
		max_2--;
	}
	if (min_ > max_2)
	{
		return;
	}
	x = min_;
	if ((x & 1) == 0)
	{
		if (min_ == max_2)
		{
			return;
		}
		x++;
	}
	if (x < 3)
	{
		x = 3;
	}
	for (;;)
	{
		if (check(base, x))
		{
			if (check(2, x) && check(7, x) && check(61, x))
			{
				;
			}
			else
			{
				r_non++;
				r_list[r_fails++] = x;
			}
		}
		else
		{
			r_non++;
		}
		if (x == max_2)
		{
			break;
		}
		x += 2;
	}
}

int main()
{
	int i, t;
	for (t = 0; scanf("%u%u%u", &base, &min_, &max_) == 3 && base >= 2; t++)
	{
		if (t)
		{
			printf("\n");
		}
		solve();
		printf("There are %u odd non-prime numbers between %u and %u.\n",
					 r_non, min_, max_);
		if (r_fails == 0)
		{
			printf("There are no failures in base %u.\n", base);
		}
		else
		{
			printf("%u suspects fail in base %u:\n", r_fails, base);
			for (i = 0; i < r_fails; i++)
			{
				printf("%u\n", r_list[i]);
			}
		}
	}
	return 0;
}
