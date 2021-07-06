#include <bits/stdc++.h>

using namespace std;

int countBits(int n)
{
	int sum = 0;
	while (n > 0)
	{
		if ((n & 1) == 1)
		{
			sum++;
		}
		n = n >> 1;
	}
	return sum;
}
int main()
{
	int n, r, i, k, c, t;
	double sum;
	double cs;
	double *ppls;
	double *ppl;
	c = 1;
	scanf("%d %d", &n, &r);
	while (n != 0)
	{
		sum = 0;
		ppls = (double *)malloc(n * sizeof(double));
		ppl = (double *)malloc(n * sizeof(double));
		for (i = 0; i < n; i++)
		{
			scanf("%lf", &ppl[i]);
			ppls[i] = 0;
		}
		t = pow(2, n);
		for (i = 0; i < t; i++)
		{
			if (countBits(i) == r)
			{
				cs = 1;
				for (k = 0; k < n; k++)
				{
					if ((1 << k) & i)
					{
						cs *= ppl[k];
					}
					else
					{
						cs *= (1 - ppl[k]);
					}
				}
				for (k = 0; k < n; k++)
				{
					if ((1 << k) & i)
					{
						ppls[k] += cs;
					}
				}
				sum += cs;
			}
		}
		printf("Case %d:\n", c);
		for (k = 0; k < n; k++)
		{
			printf("%lf\n", ppls[k] / sum);
		}
		c++;
		scanf("%d %d", &n, &r);
	}
	return 0;
}
