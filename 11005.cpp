#include <bits/stdc++.h>

using namespace std;

int C[40], P[40], min_;

int main()
{
	int i, first = 1, t, tt, q, x, r, sum;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		for (i = 0; i < 36; i++)
		{
			scanf("%d", &C[i]);
		}
		if (first)
		{
			first = 0;
		}
		else
		{
			printf("\n");
		}
		scanf("%d", &q);
		printf("Case %d:\n", t);
		while (q--)
		{
			scanf("%d", &x);
			printf("Cheapest base(s) for number %d:", x);
			min_ = 0x7fffffff;
			for (i = 2; i < 37; i++)
			{
				for (r = x, sum = 0; r; r /= i)
				{
					sum += C[r % i];
				}
				P[i] = sum;
				if (sum < min_)
				{
					min_ = sum;
				}
			}
			for (i = 2; i < 37; i++)
			{
				if (P[i] == min_)
				{
					printf(" %d", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
