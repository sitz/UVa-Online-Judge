#include <bits/stdc++.h>

using namespace std;

int N[128];
double P[128], C[128];
int main()
{
	int first = 1, n, i, j, f, tn, pr;
	double dist;
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf", C + i);
			pr = N[i] = -1;
			P[i] = C[i];
			for (j = 0; j < i; j++)
			{
				dist = 2.0 * sqrt(C[i] * C[j]) + P[j];
				if (dist > P[i])
				{
					pr = j;
					P[i] = dist;
				}
			}
			if (pr == -1)
			{
				f = i;
			}
			else
			{
				N[pr] = i;
			}
		}
		for (i = 0, dist = 0.0; i < n; i++)
		{
			if (P[i] + C[i] > dist)
			{
				dist = P[i] + C[i];
				pr = i;
			}
		}
		for (i = pr; i < n; i++)
		{
			N[i] = -1;
		}
		for (tn = 0, i = f; i != -1; i = N[i], tn++)
			;
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		printf("%.1lf\n%d\n", dist, tn);
		for (; f != -1; f = N[f])
		{
			printf("%d\n", f + 1);
		}
	}
	return 0;
}
