#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
char FLAG[MAXN + 3];
int PR[MAXN];
int STORE[MAXN + 2];
long long K, N, D;
void PRIME_TABLE()
{
	int i, j;
	K = 0;
	for (i = 2; i <= MAXN; i++)
	{
		FLAG[i] = 1;
	}
	for (i = 2; i <= 10;)
	{
		for (j = i + i; j <= MAXN; j += i)
		{
			FLAG[j] = 0;
		}
		for (++i; !FLAG[i]; i++)
			;
	}
	for (i = 2; i <= MAXN; i++)
		if (FLAG[i])
		{
			PR[K++] = i;
		}
}
long long FACT(int j)
{
	long long d = 1, n;
	long long m = 0;
	n = pow(j, d++);
	while (N >= n)
	{
		m += N / n;
		n = pow(j, d++);
	}
	return m;
}
void FACTOR1()
{
	int i, j;
	for (i = 0; i < K && PR[i] <= N; i++)
	{
		j = PR[i];
		STORE[j] = FACT(j);
	}
}
int FACTOR2()
{
	int i, j, m = 0;
	long long k = D;
	for (i = 0; i < K && PR[i] <= D; i++)
	{
		m = 0;
		j = PR[i];
		if (D % PR[i] == 0)
		{
			while (D % j == 0 && D > 1)
			{
				m++;
				D /= j;
			}
		}
		STORE[j] -= m;
		if (STORE[j] < 0)
		{
			return 0;
		}
		if (D == 1)
		{
			return 1;
		}
	}
	if (D != 1)
	{
		return 0;
	}
	return 1;
}
void CALCULATE()
{
	int i;
	long long n = 1;
	for (i = 0; i <= 100; i++)
	{
		n *= STORE[i] + 1;
	}
	printf("%lld\n", n);
}
int main()
{
	int j, i;
	PRIME_TABLE();
	while (1)
	{
		scanf("%lld%lld", &N, &D);
		if (D < 0)
		{
			D = -D;
		}
		if (!N)
			if (!D)
			{
				break;
			}
		if (D == 0)
		{
			printf("0\n");
			continue;
		}
		if (N == 0 && D == 1)
		{
			printf("1\n");
			continue;
		}
		FACTOR1();
		if (D == 1)
		{
			CALCULATE();
			goto done;
		}
		j = FACTOR2();
		if (j)
		{
			CALCULATE();
		}
		else
		{
			printf("0\n");
		}
	done:;
		for (i = 0; i < MAXN; i++)
		{
			STORE[i] = 0;
		}
	}
	return 0;
}
