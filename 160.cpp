#include <bits/stdc++.h>

using namespace std;

enum
{
	PRIME_COUNT = 25
};

int primes[PRIME_COUNT] =
		{
				2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
				43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int count_factorial(int num, int fac)
{
	int counter = 0;
	while ((num % fac) == 0)
	{
		num = num / fac;
		counter++;
	}
	return counter;
}

int init(int fac_term[101][PRIME_COUNT])
{
	for (int i = 0; i < 101; ++i)
		for (int j = 0; j < PRIME_COUNT; ++j)
		{
			fac_term[i][j] = -1;
		}
}

void print_result(int n, int fac_term[PRIME_COUNT])
{
	printf("%3d! =", n);
	for (int i = 0; i < PRIME_COUNT; ++i)
	{
		if (fac_term[i] == -1)
		{
			break;
		}
		if (i == 15)
		{
			printf("\n      ");
		}
		printf("%3d", fac_term[i]);
	}
	putchar('\n');
}

int main()
{
	int fac_term[101][PRIME_COUNT];
	init(fac_term);
	// build factorial terms table
	for (int i = 2; i <= 100; ++i)
	{
		for (int j = 0; j < PRIME_COUNT; ++j)
		{
			if (primes[j] > i)
			{
				break;
			}
			fac_term[i][j] = count_factorial(i, primes[j]);
		}
		for (int j = 0; j < PRIME_COUNT; ++j)
		{
			if (fac_term[i - 1][j] >= 0)
			{
				fac_term[i][j] += fac_term[i - 1][j];
			}
		}
	}

	int n;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		print_result(n, fac_term[n]);
	}
	return 0;
}
