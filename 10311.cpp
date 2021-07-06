#include <bits/stdc++.h>

using namespace std;

#define MAXBITS 100000000
#define USIZE (8 * sizeof(unsigned))
unsigned bitarray[MAXBITS / USIZE];
#define SETBIT(X) (bitarray[X / USIZE] |= 1 << (X % USIZE))
#define RESETBIT(X) (bitarray[X / USIZE] &= ~(1 << (X % USIZE)))
#define GETBIT(X) ((bitarray[X / USIZE] & (1 << (X % USIZE))) ? 1 : 0)

int P[5900000], tp;

void sieve()
{
	int i, j;
	for (i = 1; i <= MAXBITS; i++)
	{
		SETBIT(i);
	}
	for (i = 2; i < sqrt(MAXBITS);)
	{
		for (j = i + i; j < MAXBITS; j += i)
		{
			RESETBIT(j);
		}
		for (i++; !GETBIT(i); i++)
			;
	}
}

// binary search
int BinLo(int key)
{
	int lo = 1, up = tp - 1;
	int mid = (lo + up) / 2;
	while (lo < up)
	{
		if (P[mid] >= key)
		{
			if (P[mid - 1] < key)
			{
				return mid - 1;
			}
			up = mid - 1;
		}
		else if (P[mid] < key)
		{
			if (P[mid + 1] >= key)
			{
				return mid;
			}
			lo = mid + 1;
		}
		mid = (lo + up) / 2;
	}
	return 0;
}

void Cal(int n)
{
	int res1, res2, s1 = 1, s2 = tp - 1, dif, f = 1;
	if (n <= 4)
	{
		printf("%d is not the sum of two primes!\n", n);
		return;
	}
	if (n % 2)
	{
		dif = n - 2;
		if (GETBIT(dif))
		{
			printf("%d is the sum of 2 and %d.\n", n, dif);
		}
		else
		{
			printf("%d is not the sum of two primes!\n", n);
		}
		return;
	}
	s1 = BinLo(n / 2);
	while (s1 > 0)
	{
		dif = n - P[s1];
		if (GETBIT(dif))
		{
			res1 = P[s1];
			res2 = dif;
			f = 0;
			break;
		}
		s1--;
	}
	if (f)
	{
		printf("%d is not the sum of two primes!\n", n);
		return;
	}
	printf("%d is the sum of %d and %d.\n", n, res1, res2);
}

int main()
{
	int n;
	P[0] = 2;
	sieve();
	tp = 1;
	for (int i = 3; i + 1 < MAXBITS; i += 2)
	{
		if (GETBIT(i))
		{
			P[tp++] = i;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		Cal(n);
	}
	return 0;
}
