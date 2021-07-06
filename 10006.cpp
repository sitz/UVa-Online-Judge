#include <bits/stdc++.h>

using namespace std;

#define MAXPRIME 65001

// mod exp, i.e. b^e mod m.
unsigned long long fast_mod_pow(unsigned long long b, unsigned long long e, unsigned long long m)
{
	unsigned long long r = 1;
	while (e > 0)
	{
		if ((e & 1) == 1)
		{
			r = (r * b) % m;
		}
		e >>= 1;
		b = (b * b) % m;
	}
	return r;
}

// gen all prime ≤MAXPRIME, via sieve
void gen_primes(bool p[])
{
	p[0] = p[1] = false;

	// starting at number 2 and going to the upper limit, mark
	// all numbers as potential primes
	for (int i = 2; i < MAXPRIME; i++)
	{
		p[i] = true;
	}
	int m = floor(sqrt(MAXPRIME));
	int n;

	// mark all multiples of a prime as non-primes. this has to be done for primes
	// only up to the square root, since every number in the array has at least
	// one factor smaller than the square root of the limit
	for (int i = 2; i < m; i++)
	{
		if (p[i])
		{
			n = MAXPRIME / i;
			for (int j = 2; j <= n; j++)
			{
				p[i * j] = false;
			}
		}
	}
}

// gen all carmichael numbers ≤given limit by performing fermat tst
void gen_carmi(bool c[], bool p[])
{
	// initialize carmichael numbers array with false
	memset(c, 0, MAXPRIME * sizeof(bool));

	// starting from the first non-prime, mark all
	// odd numbers as potential carmichael numbers
	for (int i = 9; i < MAXPRIME; i += 2)
	{
		c[i] = true;
	}

	// again, for all odd numbers, we exclude the primes and perform
	// the fermat test for 2 <= a <= n-1.
	for (int n = 9; n < MAXPRIME; n += 2)
	{
		// VERY IMPORTANT! check first if this number is prime, otherwise TLE
		if (p[n])
		{
			c[n] = false;
			continue;
		}
		for (int a = 2; a <= n - 1; a++)
		{
			if (fast_mod_pow(a, n, n) != a)
			{
				c[n] = false;
				break;
			}
		}
	}
}

int main()
{
	unsigned long long n; // #
	unsigned long long a; // a of fermat tst
	bool prime[MAXPRIME]; // prime[]
	bool carmi[MAXPRIME]; // carmichael[]
	gen_primes(prime);
	gen_carmi(carmi, prime);
	while (cin >> n && (n != 0))
	{
		if (carmi[n])
		{
			printf("The number %llu is a Carmichael number.\n", n);
		}
		else
		{
			printf("%llu is normal.\n", n);
		}
	}
	return 0;
}
