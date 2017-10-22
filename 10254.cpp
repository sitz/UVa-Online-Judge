#include <bits/stdc++.h>

using namespace std;

#define limit 1000000000

int T[10005][6] = {0}, len[10005] = {0}, A[6] = {0}, la;

int main()
{
	int i, j, k, c, s;
	la = len[0] = A[0] = 1;
	for (i = c = s = 1; i < 10005; i++, c++)
	{
		len[i] = ((len[i - 1] > la) ? len[i - 1] : la);
		for (j = 0; j < len[i]; j++)
		{
			T[i][j] = T[i - 1][j] + A[j];
		}
		for (j = 0; j < len[i]; j++)
		{
			if (T[i][j] >= limit)
			{
				T[i][j + 1]++;
				T[i][j] -= limit;
			}
		}
		if (T[i][len[i]])
		{
			len[i]++;
		}
		if (c == s)
		{
			c = 0, s++;
			for (j = 0; j < la; j++)
			{
				A[j] <<= 1;
			}
			for (j = 0; j < la; j++)
			{
				if (A[j] >= limit)
				{
					A[j + 1]++;
					A[j] -= limit;
				}
			}
			if (A[la])
			{
				la++;
			}
		}
	}
	while (scanf("%d", &c) == 1)
	{
		printf("%d", T[c][len[c] - 1]);
		for (i = len[c] - 2; i >= 0; i--)
		{
			printf("%09d", T[c][i]);
		}
		printf("\n");
	}
	return 0;
}
