#include <bits/stdc++.h>

using namespace std;

#define MAXN 53

typedef long long ss;

ss C[MAXN], F[MAXN], CN;

void Print2(ss x, ss y)
{
	ss d = x + y, n = x * y;
	printf("x^2");
	if (d > 0)
		printf(" + %lldx", d);
	else if (d < 0)
	{
		d *= -1;
		printf(" - %lldx", d);
	}
	if (n >= 0)
	{
		printf(" + %lld", n);
	}
	else
	{
		n *= -1;
		printf(" - %lld", n);
	}
	printf(" = 0\n");
}

void Print1(ss n)
{
	printf("x");
	if (n < 0)
	{
		n *= -1;
		printf(" - %lld = 0\n", n);
	}
	else
		printf(" + %lld = 0\n", n);
}

void Print()
{
	ss i;
	printf("x^%lld", CN);
	for (i = CN - 1; i >= 1; i--)
	{
		if (F[i] < 0)
		{
			F[i] *= -1;
			if (F[i] > 1)
				printf(" - %lldx", F[i]);
			else
				printf(" - x");
			if (i > 1)
				printf("^%lld", i);
		}
		else if (F[i] > 0)
		{
			if (F[i] > 1)
				printf(" + %lldx", F[i]);
			else
				printf(" + x");
			if (i > 1)
				printf("^%lld", i);
		}
	}
	if (F[0] < 0)
	{
		F[0] *= -1;
		printf(" - %lld = 0", F[0]);
	}
	else
		printf(" + %lld = 0", F[0]);
}

void Set(ss n)
{
	ss i;
	F[n] = 1;
	for (i = n - 1; i > 0; i--)
		F[i] = F[i - 1] + F[i] * C[n];
	F[0] *= C[n];
}

void Cal()
{
	ss i;
	F[0] = C[1];
	F[1] = 1;
	for (i = 2; i <= CN; i++)
	{
		Set(i);
	}
	Print();
	printf("\n");
}

int main()
{
	ss i;
	while (scanf("%lld", &CN) == 1)
	{
		for (i = 1; i <= CN; i++)
		{
			scanf("%lld", &C[i]);
			C[i] *= -1;
		}
		if (CN == 2)
			Print2(C[1], C[2]);
		else if (CN == 1)
			Print1(C[1]);
		else
			Cal();
	}
	return 0;
}
