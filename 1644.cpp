#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
	for (int i = 3, sq = sqrt(n); i <= sq; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int k;
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= 1299709; i += 2)
	{
		if (is_prime(i))
		{
			primes.push_back(i);
		}
	}

	while (scanf("%d", &k) == 1, k)
	{
		for (int i=0; i<primes.size(); i++)
		{
			if (primes[i] == k)
			{
				printf("0\n");
				break;
			}
			if (primes[i] > k)
			{
				printf("%d\n", primes[i] - primes[i - 1]);
				break;
			}
		}
	}

	return 0;
}
