#include <bits/stdc++.h>

using namespace std;

#define MAXN 10000000

char p[MAXN + 3];

int prime_table()
{
	int i, j;
	p[1] = 0;
	for (i = 2; i <= MAXN; i++)
	{
		p[i] = 1;
	}
	for (i = 2; i < sqrt(MAXN);)
	{
		for (j = i + i; j <= MAXN; j += i)
		{
			p[j] = 0;
		}
		for (i++; !p[i]; i++)
			;
	}
	return 0;
}

int even(int n)
{
	int i, j;
	if (n == 4)
	{
		printf("2 2\n");
		return 1;
	}
	for (i = 3, j = n - 3; i <= j; i++, j--)
	{
		if (p[i] && p[j])
		{
			printf("%d %d\n", i, j);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, a, b, k;
	prime_table();
	while (scanf("%d", &n) == 1)
	{
		if (n < 8)
		{
			printf("Impossible.\n");
			continue;
		}
		if (n % 2 == 0)
		{
			printf("2 2 ");
			even(n - 4);
		}
		else
		{
			printf("2 3 ");
			even(n - 5);
		}
	}
	return 0;
}
