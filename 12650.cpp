#include <bits/stdc++.h>

using namespace std;

long int num[10001];

int main()
{
	long int i, n, r, t, sum;
	while (scanf("%ld %ld", &n, &r) == 2)
	{
		for (i = 0; i < n; i++)
		{
			num[i + 1] = 1;
		}
		sum = 0;
		while (r--)
		{
			scanf("%ld", &t);
			num[t] = 0;
			sum += t;
		}
		if (sum == (n * (n + 1)) / 2)
		{
			printf("*");
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				if (num[i + 1])
				{
					printf("%ld ", i + 1);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
