#include <bits/stdc++.h>

using namespace std;

int X[10005];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int n, i, j, max, len, f;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 0; i < n; i++)
		{
			scanf("%d", X + i);
		}
		qsort(X, n, sizeof(int), cmp);
		for (i = len = max = 1; i < n; i++)
		{
			if (X[i] == X[i - 1])
			{
				len++;
			}
			else
			{
				if (len > max)
				{
					max = len;
				}
				len = 1;
			}
		}
		if (len > max)
		{
			max = len;
		}
		printf("%d\n", max);
		for (i = 0; i < max; i++)
		{
			for (j = 0, f = 1; j * max + i < n; j++)
			{
				if (f)
				{
					f = 0;
				}
				else
				{
					printf(" ");
				}
				printf("%d", X[j * max + i]);
			}
			printf("\n");
		}
	}
	return 0;
}
