#include <bits/stdc++.h>

using namespace std;

int C[1024], T[460000];
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	int i, j, c, n = 0, r, p = 0;
	for (i = 1; i < 1024; i++)
	{
		C[i] = i * i * i;
	}
	for (i = 1; i < 1001; i++)
	{
		c = C[i];
		for (j = i; C[j] + c <= 1000100000; j++)
		{
			T[n++] = C[j] + c;
		}
	}
	qsort(T, n, sizeof(int), cmp);
	for (i = 1; i < n; i++)
	{
		if (T[i] == T[i - 1])
		{
			c = T[p++] = T[i];
			while (T[++i] == c)
				;
		}
	}
	T[p] = T[p - 1] + 1000000;
	while (scanf("%d%d", &n, &r) == 2)
	{
		if (n > T[p - 1])
		{
			printf("None\n");
			continue;
		}
		if (n <= 1729)
		{
			i = 0;
		}
		else
		{
			for (i = p >> 1, j = p >> 2;; j = (j + 1) / 2)
			{
				if (i < 1)
				{
					i = 1;
				}
				else if (i >= p)
				{
					i = p - 1;
				}
				/*T[i-1]<n<=T[i]*/
				if (n <= T[i - 1])
				{
					i -= j;
				}
				else if (n > T[i])
				{
					i += j;
				}
				else
				{
					break;
				}
			}
		}
		for (c = 0; T[i] <= n + r; i++, c++)
		{
			printf("%d\n", T[i]);
		}
		if (!c)
		{
			printf("None\n");
		}
	}
	return 0;
}
