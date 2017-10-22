#include <bits/stdc++.h>

using namespace std;

#define ROUND 0
int cad[10000];
int usd[10000];

double rate[10000];

int initcad = 100000;
int initusd = 0;
double commission = .03;

double max(double a, double b, double c)
{
	if (a >= b && a >= c)
	{
		return a;
	}
	if (b >= c)
	{
		return b;
	}
	return c;
}

int main()
{
	int n, i;
	while (1)
	{
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%lf", rate + i);
		}
		for (i = 0; i < n; i++)
		{
			cad[i + 1] = max(initcad + initusd * rate[i] * (1 - commission) + ROUND,
											 cad[i], usd[i] * rate[i] * (1 - commission) + ROUND);
			usd[i + 1] = max(initusd + initcad / rate[i] * (1 - commission) + ROUND,
											 usd[i], cad[i] / rate[i] * (1 - commission) + ROUND);
			//printf("%d %d\n", usd[i+1], cad[i+1]);
		}
		printf("%01d.%02d\n", cad[n] / 100, cad[n] % 100);
	}
}
