#include <bits/stdc++.h>

using namespace std;

#define eps 1e-6

int compare(const void *a, const void *b)
{
	double *x, *y;
	x = (double *)a;
	y = (double *)b;
	if (x - y >= eps)
		return -1;
	if (y - x >= eps)
		return 1;
	return 0;
}

bool valid(double a, double b, double c, double d)
{
	double theta, alpha, eta, xx;
	if (a - d > eps)
		return false;
	theta = acos((a * a + b * b - c * c) / (2 * a * b));
	alpha = acos(a / d);// since D[j] = 2*r
	eta = theta - alpha;
	xx = d * cos(eta);
	return (xx - b > -eps);
}

int main()
{
	double D[120], ara[10], theta, alpha, eta, xx, a, b, c;
	int i, j, m, n, count, res[120];
	while (scanf("%d", &n) == 1)
	{
		for (i = 1; i <= n; i++)
			scanf("%lf", &D[i]);
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%lf%lf%lf", &ara[0], &ara[1], &ara[2]);
			qsort(ara, 3, sizeof(double), compare);
			a = ara[0];
			b = ara[1];
			c = ara[2];
			for (j = 1, count = 0; j <= n; j++)
			{
				if (valid(a, b, c, D[j]) || valid(b, c, a, D[j]) || valid(c, a, b, D[j]))
					res[count++] = j;
			}
			if (count == 0)
				printf("Peg %c will not fit into any holes\n", i + 65);
			else
			{
				printf("Peg %c will fit into hole(s):", i + 65);
				for (j = 0; j < count; j++)
					printf(" %d", res[j]);
				printf("\n");
			}
		}
	}
	return 0;
}
