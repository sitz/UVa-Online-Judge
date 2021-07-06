#include <bits/stdc++.h>

using namespace std;

bool prime[1000010];
int realPrime[100000], pIndex, numOfPrime;
long long alPrimeNum[90000];

void sieve()
{
	int i, j;
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	for (i = 2; i <= 1000;)
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			prime[j] = 0;
		}
		for (i++; !prime[i]; i++)
			;
	}
	numOfPrime = 0;
	for (i = 2; i < 1000000; i++)
		if (prime[i])
		{
			realPrime[numOfPrime++] = i;
		}
}

int cmp(const void *a, const void *b)
{
	long long *aa = (long long *)a;
	long long *bb = (long long *)b;
	if (*aa > *bb)
	{
		return 1;
	}
	else if (*aa == *bb)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void preCal()
{
	pIndex = 0;
	int pri;
	for (pri = 0; pri < numOfPrime; pri++)
	{
		long long value;
		value = realPrime[pri];
		while ((value *= realPrime[pri]) < 1e12)
		{
			alPrimeNum[pIndex++] = value;
		}
	}
	qsort(alPrimeNum, pIndex, sizeof(long long), cmp);
}

// binary search
int bin_search(long long range)
{
	int low, mid, high;
	low = 0;
	high = 80069;
	while (1)
	{
		mid = (int)(low + high) / 2;
		if (range < alPrimeNum[mid] && range < alPrimeNum[mid - 1])
		{
			high = mid - 1;
			continue;
		}
		if (range > alPrimeNum[mid] && range > alPrimeNum[mid + 1])
		{
			low = mid + 1;
			continue;
		}
		if (range >= alPrimeNum[mid - 1] && range < alPrimeNum[mid])
		{
			return mid;
		}
		if (range >= alPrimeNum[mid] && range < alPrimeNum[mid + 1])
		{
			return mid + 1;
		}
		if (range == alPrimeNum[mid + 1])
		{
			return mid + 2;
		}
	}
}

int main()
{
	sieve();
	preCal();
	int numOfCase, k;
	cin >> numOfCase;
	for (k = 0; k < numOfCase; k++)
	{
		long long low, high;
		cin >> low >> high;
		cout << bin_search(high) - bin_search(low - 1) << endl;
	}
	return 0;
}
