#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000

int prev_[MAXN + 1] = {0}, nxt[MAXN + 1] = {0};
double log10factorial[MAXN + 1] = {0};

inline void init()
{
	prev_[2] = -1;
	nxt[2] = 3;
	prev_[3] = 2;
	nxt[3] = 5;
	for (long long i = 3; i <= MAXN; i += 2)
	{
		prev_[i] = i - 2;
		nxt[i] = i + 2;
	}
	for (long long prime = 3; prime * prime <= MAXN; prime = nxt[prime])
	{
		for (long long fact = prime; prime * fact <= MAXN; fact = nxt[fact])
		{
			for (long long mult = prime * fact; mult <= MAXN; mult *= prime)
			{
				// remove
				nxt[prev_[mult]] = nxt[mult];
				prev_[nxt[mult]] = prev_[mult];
				prev_[mult] = 0;
				nxt[mult] = 0;
			}
		}
	}

	log10factorial[1] = 0.0f;
	for (int i = 2; i <= MAXN; i++)
		log10factorial[i] = log10factorial[i - 1] + log10(i);
}

int main()
{
	init();
	int cases = 0;
	long double gcd = 0, lcm = 0;
	long long n = 0, prime = 0, power = 0;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		cases++;
		gcd = 0;
		for (prime = 2; prime * 2 <= n; prime = nxt[prime])
		{
			power = prime;
			while (n >= power)
			{
				gcd += (n / (int)power) * (n / (int)power - 1) / 2 * log10(prime);
				power *= prime;
			}
		}
		lcm = log10factorial[n] * (n - 1) - gcd;
		printf("Case %d: %lld %lld\n", cases, (long long)(gcd / 100) + 1, (long long)(lcm / 100) + 1);
	}
	return 0;
}
