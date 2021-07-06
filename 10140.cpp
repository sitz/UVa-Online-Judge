#include <bits/stdc++.h>

using namespace std;

long long low, upper;
bool flag[1000010];
int prime[1000000];

void sieve()
{
	int d, i, j;
	d = upper - low + 1;
	for (i = 0; i < d; i++)
	{
		flag[i] = true;
	}
	if (low % 2 == 0)
	{
		i = 0;
	}
	else
	{
		i = 1;
	}
	for (; i < d; i += 2)
	{
		flag[i] = false;
	}
	for (i = 3; i <= sqrt(upper); i += 2)
	{
		if (i > low && !flag[i - low])
		{
			continue;
		}
		j = low / i * i;
		if (j < low)
		{
			j += i;
		}
		if (j == i)
		{
			j += i;
		}
		j -= low;
		for (; j < d; j += i)
		{
			flag[j] = false;
		}
	}
	if (low == 1)
	{
		flag[1 - low] = false;
	}
	if (low <= 2)
	{
		flag[2 - low] = true;
	}
}

bool isPrime(int n)
{
	if (n == 0 || n == 1)
	{
		return 0;
	}
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void solve()
{
	int max, min, maxFir, maxSec, minFir, minSec;
	bool exist = false;
	max = -1;
	min = 0x7fffffff;
	long long index, numOfPrime = 0;
	for (index = low; index <= upper; index++)
	{
		if (flag[index - low])
		{
			prime[numOfPrime++] = index;
		}
	}
	for (index = 0; index < numOfPrime - 1; index++)
	{
		if ((prime[index + 1] - prime[index]) > max)
		{
			max = prime[index + 1] - prime[index];
			maxFir = prime[index];
			maxSec = prime[index + 1];
			exist = true;
		}
		if ((prime[index + 1] - prime[index]) < min)
		{
			min = prime[index + 1] - prime[index];
			minFir = prime[index];
			minSec = prime[index + 1];
			exist = true;
		}
	}
	if (exist)
	{
		cout << minFir << "," << minSec << " are closest, " << maxFir << "," << maxSec << " are most distant." << endl;
	}
	else
	{
		cout << "There are no adjacent primes." << endl;
	}
}

int main()
{
	while (cin >> low >> upper)
	{
		sieve();
		solve();
	}
	return 0;
}
