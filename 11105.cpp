#include <bits/stdc++.h>

using namespace std;

int P[90000] = {5}, L[1000005] = {0};
int main()
{
	int ptr, i, j, sq, ok;
	long long int tmp;
	for (ptr = 1; P[ptr - 1] < 1000000; ptr++)
	{
		for (i = P[ptr - 1] + 4;; i += 4)
		{
			sq = sqrt(i);
			for (j = 0, ok = 1; P[j] <= sq; j++)
			{
				if (i % P[j])
				{
					continue;
				}
				ok = 0;
				break;
			}
			if (ok)
			{
				break;
			}
		}
		P[ptr] = i;
	}
	for (i = 0; i < ptr; i++)
	{
		for (j = i; j < ptr; j++)
		{
			tmp = (long long int)P[i] * P[j];
			if (tmp > 1000001)
			{
				break;
			}
			L[tmp] = 1;
		}
	}
	for (i = 5; i <= 1000001; i += 4)
	{
		L[i] += L[i - 4];
	}
	while (scanf("%d", &i) == 1)
	{
		if (i == 0)
		{
			break;
		}
		printf("%d %d\n", i, L[i]);
	}
	return 0;
}
