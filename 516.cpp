#include <bits/stdc++.h>

using namespace std;

bool prime[1000010];

void compute_prime_table() /* with Sieve of Eratosthenes */
{
	int i, j;
	prime[0] = prime[1] = false;
	for (i = 2; i <= 1000000; i++)
	{
		prime[i] = true; /* initialization */
	}
	for (i = 2; i <= 1000;) /* for all primes up to 1000 */
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			prime[j] = false; /* delete all multiples of i */
		}
		for (i++; !prime[i]; i++)
			; /* find next prime */
	}
}

class PrimeLand
{
public:
	int ReadCase();
	void solve();
	//Data Information :
	int numCase;
	char buf[10000];
	int base[100], power[100];
	int resbase[100], respower[100], resnum;
	long x;
};

int PrimeLand::ReadCase()
{
	numCase = 0;
	if (cin.getline(buf, 10000))
	{
		if (strcmp(buf, "0") == 0)
		{
			return 0;
		}
		istringstream input(buf);
		int m, n;
		while (input >> m >> n)
		{
			base[numCase] = m;
			power[numCase] = n;
			numCase++;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

void PrimeLand::solve()
{
	int i;
	bool flag = false;
	x = 1;
	resnum = 0;
	for (i = 0; i < numCase; i++)
	{
		x *= (long)pow(base[i], power[i]);
	}
	x--;
	for (i = 2; i <= 100000; i++)
	{
		if (prime[i] == true)
		{
			if (x % i == 0)
			{
				resbase[resnum] = i;
				respower[resnum] = 0;
			}
			else if (x % i != 0)
			{
				continue;
			}
			while (1)
			{
				if (x == 1)
				{
					flag = true;
					break;
				}
				if (x % i == 0)
				{
					x /= i;
					respower[resnum]++;
				}
				else if (x % i != 0)
				{
					break;
				}
			}
			resnum++;
		}
		if (flag == true)
		{
			break;
		}
	}
	for (i = resnum - 1; i > 0; i--)
	{
		cout << resbase[i] << ' ' << respower[i] << ' ';
	}
	cout << resbase[i] << ' ' << respower[i] << endl;
}

int main()
{
	compute_prime_table();
	PrimeLand test;
	while (test.ReadCase())
	{
		test.solve();
	}
	return 0;
}
