#include <bits/stdc++.h>

using namespace std;

void pri();
bool is[10000005];
long long int prime[664580];

int main()
{
	long long int P, p, Q, q, i, j, n, ans, num, tmp, ker, count;
	pri();
	while (scanf(" %lld", &Q) == 1 && Q)
	{
		tmp = 2;
		ker = (sqrt(Q) + 0.000001);
		while (Q % 2 == 0)
		{
			Q /= 2;
		}
		for (i = 1; prime[i] <= ker && i < 664579; i++)
		{
			if (prime[i] > Q)
			{
				break;
			}
			count = 0;
			while (Q % prime[i] == 0)
			{
				Q /= prime[i];
				count++;
			}
			tmp *= (count * 2 + 1);
		}
		if (Q != 1)
		{
			tmp *= 3;
		}
		printf("%lld\n", tmp);
	}
	return 0;
}

void pri()
{
	long long int i, j, k = 0;
	for (i = 0; i < 10000005; i++)
	{
		is[i] = true;
	}
	for (i = 2; i < 10000005; i++)
		if (is[i])
		{
			for (j = i * i; j < 10000005; j += i)
			{
				is[j] = false;
			}
			prime[k++] = i;
		}
}
