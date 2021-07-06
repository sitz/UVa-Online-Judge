#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)
#define FOREQ(i, a, b) for (int(i) = int(a); (i) <= int(b); (i)++)

bool is_prime(int n)
{
	if (n == 2)
	{
		return true;
	}
	if (n % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i * i <= n; i += 2)
		if (n % i == 0)
		{
			return false;
		}
	return true;
}

static vector<int> primes;

inline int survivor(int n)
{
	int i, s;
	for (s = 0, i = 1; i <= n; i++)
	{
		s = (s + primes[n - i]) % i;
	}
	return s + 1;
}

static int n;

int main()
{
	primes.push_back(2);
	for (int i = 3; i < 100000; i += 2)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
	}
	while (scanf("%d", &n))
	{
		if (!n)
		{
			break;
		}
		printf("%d\n", survivor(n));
	}
	return 0;
}
