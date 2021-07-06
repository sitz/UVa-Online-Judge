#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, first = 1, a, b, c, i, j, k, p, q;
	long long int max, unit, sum, tmp, X[25][25][25] = {0};
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &a, &b, &c);
		tmp = -(1LL << 33);
		for (i = 1; i <= a; i++)
		{
			for (j = 1; j <= b; j++)
			{
				for (k = 1; k <= c; k++)
				{
					scanf("%lld", &X[i][j][k]);
					if (X[i][j][k] > tmp)
					{
						tmp = X[i][j][k];
					}
					X[i][j][k] += X[i][j][k - 1];
				}
				for (k = 1; k <= c; k++)
				{
					X[i][j][k] += X[i][j - 1][k];
				}
			}
		}
		max = 0;
		for (p = 0; p < b; p++)
		{
			for (j = p + 1; j <= b; j++)
			{
				for (q = 0; q < c; q++)
				{
					for (k = q + 1; k <= c; k++)
					{
						for (i = 1, sum = 0; i <= a; i++)
						{
							unit = X[i][j][k] - X[i][p][k] - X[i][j][q] + X[i][p][q];
							if (sum < 0)
							{
								sum = unit;
							}
							else
							{
								sum += unit;
							}
							if (sum > max)
							{
								max = sum;
							}
						}
					}
				}
			}
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		if (max > 0)
		{
			printf("%lld\n", max);
		}
		else
		{
			printf("%lld\n", tmp);
		}
	}
	return 0;
}
