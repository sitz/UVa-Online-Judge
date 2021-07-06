#include <bits/stdc++.h>

using namespace std;

int p[1000010];
int digit[1000010];
void compute_prime_table() /* with Sieve of Eratosthenes */
{
	int i, j;
	p[0] = p[1] = 0;
	for (i = 2; i <= 1000000; i++)
	{
		p[i] = 1; /* initialization */
	}
	for (i = 2; i <= 1000;) /* for all primes up to 1000 */
	{
		for (j = i + i; j <= 1000000; j += i)
		{
			p[j] = 0; /* delete all multiples of i */
		}
		for (i++; !p[i]; i++)
			; /* find next prime */
	}
}

int digit_sum(int n)
{
	int sum = 0;
	while (n)
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void get_digit_prime_table()
{
	compute_prime_table();
	int i;
	digit[0] = 0;
	for (i = 1; i <= 1000000; i++)
	{
		if (p[i] && p[digit_sum(i)])
		{
			digit[i] = digit[i - 1] + 1;
		}
		else
		{
			digit[i] = digit[i - 1];
		}
	}
}

int main()
{
	get_digit_prime_table();
	int N, t, t1, t2;
	scanf("%d", &N);
	for (t = 0; t < N; t++)
	{
		scanf("%d %d", &t1, &t2);
		printf("%d\n", digit[t2] - digit[t1 - 1]);
	}
	return 0;
}
