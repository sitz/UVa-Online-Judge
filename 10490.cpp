#include <bits/stdc++.h>

using namespace std;

/*104902*/
char pr[50];
int perfect[] = {2, 3, 5, 7, 13, 17, 19, 31};
int N;
long long PER;
void prime_table()
{
	int i, j;
	for (i = 2; i <= 32; i++)
	{
		pr[i] = 1;
	}
	for (i = 2; i <= sqrt(32);)
	{
		for (j = i + i; j <= 31; j += i)
		{
			pr[j] = 0;
		}
		for (++i; !pr[i]; i++)
			;
	}
}
int PERFECT()
{
	int i;
	for (i = 0; i < 8; i++)
		if (perfect[i] == N)
		{
			PER = pow(2.0, (double)N - 1.0) * (pow(2.0, (double)N) - 1);
			return 1;
		}
	return 0;
}
int main()
{
	int p;
	prime_table();
	while (scanf("%d", &N) && N)
	{
		p = PERFECT();
		if (p)
		{
			printf("Perfect: %lld!\n", PER);
		}
		else if (pr[N] && !p)
		{
			printf("Given number is prime. But, NO perfect number is available.\n");
		}
		else if (!pr[N] && !p)
		{
			printf("Given number is NOT prime! NO perfect number is available.\n");
		}
	}
	return 0;
}
