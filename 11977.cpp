#include <bits/stdc++.h>

using namespace std;

// http://uva.onlinejudge.org/external/119/11977.html
// Runtime: 1.644s
// Tag: Math

#define N 1000000
#define MOD 10000019
#define Square(p) p *p

bool mark[N];
vector<int> primeList;

struct primeFreq
{
	int primeNum;
	int freq;
} primeFrequency[N];

void sieve()
{
	memset(mark, true, sizeof(mark));
	mark[0] = mark[1] = false;
	for (int i = 4; i < N; i += 2)
	{
		mark[i] = false;
	}
	int len = sqrt(N);
	for (int i = 3; i <= len; i += 2)
	{
		if (mark[i])
		{
			for (int j = i * i; j < N; j += 2 * i)
			{
				mark[j] = false;
			}
		}
	}
	primeList.push_back(2);
	for (int i = 3; i < N; i += 2)
	{
		if (mark[i])
		{
			primeList.push_back(i);
		}
	}
	// printf ("%d\n", primeList.size ());
}

void calcPrimeFactorFrequencyFactorialN(int n)
{
	int tmp;
	for (size_t i = 0; i < primeList.size(); i++)
	{
		tmp = n;
		int total = 0;
		while (tmp)
		{
			total += (tmp / primeList[i]);
			tmp /= primeList[i];
		}
		primeFrequency[i].primeNum = primeList[i];
		primeFrequency[i].freq = total;
	}
}

long long bigMod(long long b, long long p)
{
	if (p == 0)
	{
		return 1;
	}
	if (p % 2 == 0)
	{
		return Square(bigMod(b, p / 2)) % MOD;
	}
	return ((b % MOD) * bigMod(b, p - 1)) % MOD;
}

int main()
{
	sieve();
	int testCase;
	scanf("%d", &testCase);
	int cases = 0;
	while (testCase--)
	{
		int n, t;
		scanf("%d %d", &n, &t);
		calcPrimeFactorFrequencyFactorialN(n);
		int primeLen = (int)primeList.size();
		long long res = 1;
		bool resFound = false;
		for (int i = 0; i < primeLen; i++)
		{
			if (primeFrequency[i].freq >= t)
			{
				resFound = true;
				res *= bigMod(primeFrequency[i].primeNum, primeFrequency[i].freq / t);
				res %= MOD;
			}
		}
		if (resFound)
		{
			printf("Case %d: %lld\n", ++cases, res);
		}
		else
		{
			printf("Case %d: -1\n", ++cases);
		}
	}
	return 0;
}
