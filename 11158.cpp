#include <bits/stdc++.h>

using namespace std;

int X[60];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int t, tt, n, i, j, sum, a, b;
	scanf("%d", &tt);
	for (t = 1; t <= tt; t++)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", X + i);
		}
		qsort(X, n, sizeof(int), cmp);
		sum = abs(X[0] - X[n - 1]);
		for (i = 1, j = n - 2; i <= j; i++, j--)
		{
			a = abs(X[i] - X[j + 1]);
			b = abs(X[i - 1] - X[j]);
			sum += a + b;
		}
		if (n & 1)
		{
			i = n >> 1;
			a = abs(X[i] - X[i - 1]);
			b = abs(X[i] - X[i + 1]);
			if (a < b)
			{
				sum -= a;
			}
			else
			{
				sum -= b;
			}
		}
		printf("Case %d: %d\n", t, sum);
	}
	return 0;
}
