#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int MAX_N = (int)1e7;
const int MAX_SIZE = MAX_N + 10;
const int MAX_PRIME = MAX_N + 10;
const int64 MOD = (int)(1e9) + 7;

bool isPrime[MAX_SIZE];
int primes[MAX_PRIME], P = 0, N = 0;

void sieve()
{
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < MAX_SIZE; i++)
		if (isPrime[i])
		{
			for (int j = i << 1; j < MAX_SIZE; j += i)
			{
				isPrime[j] = false;
			}
		}
	for (int i = 2; i < MAX_SIZE - 1; i++)
	{
		if (isPrime[i])
		{
			primes[P++] = i;
		}
	}
}
int64 pow_bin(int64 x, int n)
{
	int64 ret = 1;
	for (; n; n >>= 1)
	{
		if (n & 1)
		{
			ret = ret * x % MOD;
		}
		x = x * x % MOD;
	}
	return ret;
}
int solve()
{
	int64 ans = 1;
	for (int i = 0; i < P && N >= primes[i] * 2; i++)
	{
		int cnt = 0;
		for (int m = N; m;)
		{
			cnt += (m /= primes[i]);
		}
		ans = ans * pow_bin(primes[i], cnt & (~(1))) % MOD;
	}
	return (int)ans;
}

int main()
{
	sieve();
	while (scanf("%d", &N), N)
	{
		printf("%d\n", solve());
	}
	return 0;
}
