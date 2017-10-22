#include <bits/stdc++.h>

using namespace std;

int p[1000010];
void compute_prime_table() /* with Sieve of Eratosthenes */
{
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i <= 1000000; i++)
	{
		p[i] = 1; /* initialization */
	}
	for (i = 2; i <= 1000;) /* for all primes up to 1000 */
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			p[j] = 0; /* delete all multiples of i */
		}
		for (i++; !p[i]; i++)
			; /* find next prime */
	}
}

int reversed(int n)
{
	int res = 0;
	while (n)
	{
		res *= 10;
		res += (n % 10);
		n /= 10;
	}
	return res;
}

int main()
{
	compute_prime_table();
	int N, rev;
	while (cin >> N)
	{
		if (!p[N])
		{
			cout << N << " is not prime." << endl;
		}
		else
		{
			rev = reversed(N);
			if (p[rev] && rev != N)
			{
				cout << N << " is emirp." << endl;
			}
			else
			{
				cout << N << " is prime." << endl;
			}
		}
	}
	return 0;
}
