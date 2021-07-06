#include <bits/stdc++.h>

using namespace std;

#define maxn 31627

typedef long long Int;

char sv[maxn + 3];
Int ip, res, Z, P[3500], Res[100000];

int Com(const void *a, const void *b)
{
	return *(Int *)a - *(Int *)b;
}

void Table()
{
	Int i, j;
	for (i = 2; i * i < maxn;)
	{
		for (j = i + i; j < maxn; j += i)
			sv[j] = 1;
		for (++i; sv[i]; i++)
			;
	}
	ip = 1;
	P[0] = 2;
	for (i = 3; i < maxn; i += 2)
		if (!sv[i])
			P[ip++] = i;
}

Int isPrime(Int n)
{
	Int i;
	if (n < maxn)
	{
		if (!sv[n])
			return 1;
		return 0;
	}
	for (i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 0;
	return 1;
}

void Recur(Int ind, Int rem, Int val)
{
	Int i, d, j, k, p, v, x;
	if (rem == 1)
	{
		Res[res++] = val;
		return;
	}
	for (i = ind; i < ip; i++)
	{
		k = P[i] - 1;
		if (k * k > rem)
			break;
		d = 1;
		for (j = 1; j < 32; j++)
		{
			p = k * d;
			if (p > rem || rem % p)
				break;
			v = val * d * P[i];
			Recur(i + 1, rem / p, v);
			x = rem / p;
			if (x > P[i] && isPrime(x + 1))
				Res[res++] = (v) * (x + 1);
			d *= P[i];
		}
	}
}

void Cal()
{
	Int i, j, k, d, p, x;
	res = 0;
	for (i = 0; i < ip; i++)
	{
		k = P[i] - 1;
		if (k * k > Z)
			break;
		d = 1;
		for (j = 1; j < 32; j++)
		{
			p = k * d;
			if (p > Z || Z % p)
				break;
			Recur(i + 1, Z / p, (d * P[i]));
			x = Z / p;
			if (isPrime(x + 1) && x >= P[i])
				Res[res++] = (d * P[i]) * (x + 1);
			d *= P[i];
		}
	}
	if (isPrime(Z + 1))
		Res[res++] = Z + 1;
	if (!res)
	{
		printf("No solution.\n");
		return;
	}
	qsort(Res, res, sizeof(Int), Com);
	printf("%lld", Res[0]);
	for (i = 1; i < res; i++)
		printf(" %lld", Res[i]);
	printf("\n");
}

int main()
{
	Table();
	while (scanf("%lld", &Z) == 1)
	{
		if (Z % 2 && Z > 1)
		{
			printf("No solution.\n");
			continue;
		}
		if (Z == 1)
		{
			printf("1 2\n");
			continue;
		}
		Cal();
	}
	return 0;
}
