#include <bits/stdc++.h>

using namespace std;

#define INFINITO 0x3f3f3f3f
#define MAX 1024

int fa, fb;
int n;
int f[MAX];

int mdc(int a, int b)
{
	return (b == 0 ? a : mdc(b, a % b));
}

int calcula(const int &num, const int &den)
{
	int i;
	int pa = 0, pb = 0;
	for (i = 0; i < n; ++i)
	{
		int idas = int(ceil(
				double(f[i]) / (double(num) / double(den))));
		if (idas > 3)
		{
			return INFINITO;
		}
		pa += idas * num - f[i] * den;
		pb += idas;
	}
	return fa * pa + fb * pb * den;
}

int main()
{
	int i, j;
	int a, b;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		scanf("%d %d", &a, &b);
		fa = a;
		fb = b;
		for (i = 0; i < n; ++i)
		{
			scanf("%d", &f[i]);
		}
		double menor = INFINITO;
		int den, num;
		for (i = 1; i <= 100; ++i)
		{
			for (j = 1; j <= 3; ++j)
			{
				int x = calcula(i, j);
				double p = double(x) / double(j);
				if (p < menor)
				{
					menor = p;
					num = x;
					den = j;
				}
			}
		}
		a = num;
		b = den;
		int x = mdc(a, b);
		a /= x;
		b /= x;
		if (b > 1)
		{
			printf("%d / %d\n", a, b);
		}
		else
		{
			printf("%d\n", a);
		}
	}
	return 0;
}
