#include <bits/stdc++.h>

using namespace std;

#define limit 10000000
int T[16][160][30] = {0}, len[16][160] = {0};
int main()
{
	int i, j, k;
	/* process i^j */
	for (i = 0; i < 16; i++)
	{
		T[i][0][0] = len[i][0] = 1;
		for (j = 1; j < 151; j++)
		{
			len[i][j] = len[i][j - 1];
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k] = T[i][j - 1][k] * i;
			}
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k + 1] += T[i][j][k] / limit;
				T[i][j][k] %= limit;
			}
			if (T[i][j][len[i][j]])
			{
				len[i][j]++;
			}
		}
	}
	/* process j*i^j */
	for (i = 0; i < 16; i++)
	{
		for (j = 0; j < 151; j++)
		{
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k] *= j;
			}
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k + 1] += T[i][j][k] / limit;
				T[i][j][k] %= limit;
			}
			if (T[i][j][len[i][j]])
			{
				len[i][j]++;
			}
		}
	}
	/* process sigma */
	for (i = 0; i < 16; i++)
	{
		for (j = 1; j < 151; j++)
		{
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k] += T[i][j - 1][k];
			}
			for (k = 0; k < len[i][j]; k++)
			{
				T[i][j][k + 1] += T[i][j][k] / limit;
				T[i][j][k] %= limit;
			}
			if (T[i][j][len[i][j]])
			{
				len[i][j]++;
			}
		}
	}
	while (scanf("%d%d", &j, &i) == 2)
	{
		printf("%d", T[i][j][len[i][j] - 1]);
		for (k = len[i][j] - 2; k >= 0; k--)
		{
			printf("%07d", T[i][j][k]);
		}
		printf("\n");
	}
	return 0;
}
