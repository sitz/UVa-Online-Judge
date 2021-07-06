#include <bits/stdc++.h>

using namespace std;

const int MAXSIZE = 10010;

int cntPrime[MAXSIZE];

bool isPrime(int n)
{
	for (int i = 2; i <= (int)sqrt(n); i++)
		if (n % i == 0)
		{
			return false;
		}
	return true;
}

void init()
{
	int i;
	cntPrime[0] = 1;
	for (i = 1; i < 40; i++)
	{
		cntPrime[i] = cntPrime[i - 1] + 1;
	}
	for (; i <= 10000; i++)
		if (isPrime(i * i + i + 41))
		{
			cntPrime[i] = cntPrime[i - 1] + 1;
		}
		else
		{
			cntPrime[i] = cntPrime[i - 1];
		}
}

int main()
{
	init();
	int a, b;
	while (scanf("%d%d", &a, &b) == 2)
	{
		int cnt;
		if (a == 0)
		{
			cnt = cntPrime[b];
		}
		else
		{
			cnt = cntPrime[b] - cntPrime[a - 1];
		}
		printf("%.2lf\n", cnt * 100.0 / (b - a + 1) + 1e-6);
	}
	return 0;
}
