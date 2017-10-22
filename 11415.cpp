#include <bits/stdc++.h>

using namespace std;

#define N 2750000
static int *factors;
static int *counts;
int main()
{
	register int i, j, k;
	int n, c;
	factors = (int *)malloc((N) * sizeof(int));
	counts = (int *)malloc(10000001 * sizeof(int));
	factors[0] = 0;
	factors[1] = 0;
	for (i = 2; i < N; i++)
	{
		factors[i] = 0;
	}
	for (i = 2; i < N; i++)
	{
		if (!factors[i])
		{
			factors[i] = 1;
		}
		for (j = 2; j <= i && (k = j * i) < N; j++)
		{
			if (!factors[k] && factors[j] == 1)
			{
				factors[k] = factors[i] + 1;
			}
		}
	}
	for (i = 2; i < N; i++)
	{
		factors[i] += factors[i - 1];
	}
	j = 0;
	for (i = 1; i < 10000001; i++)
	{
		for (; factors[j] <= i; j++)
			;
		counts[i] = j;
	}
	scanf("%d", &c);
	while (c > 0)
	{
		scanf("%d", &n);
		printf("%d\n", counts[n]);
		c--;
	}
	return 0;
}
