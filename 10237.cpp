#include <bits/stdc++.h>

using namespace std;

long long int O[35][905] = {0}, E[35][905] = {0}, B[35][905] = {0};

int main()
{
	int i, j, k;
	for (i = 0; i <= 30; i++)
	{
		O[i][0] = E[i][0] = 1;
	}
	for (i = 1; i <= 30; i++)
	{
		for (j = 1; j <= i; j++)
		{
			O[i][j] = O[i - 1][j] + O[i - 1][j - 1] * (i + (i & 1) - j);
		}
	}
	for (i = 1; i <= 30; i++)
	{
		for (j = 1; j <= i; j++)
		{
			E[i][j] = E[i - 1][j] + E[i - 1][j - 1] * ((i | 1) - j);
		}
	}
	for (i = 1; i <= 30; i++)
	{
		for (j = 0; j < 2 * i; j++)
		{
			for (k = 0; k <= j; k++)
			{
				B[i][j] += O[i][k] * E[i][j - k];
			}
		}
	}
	while (scanf("%d%d", &i, &j) == 2)
	{
		if ((i | j) == 0)
		{
			break;
		}
		printf("%lld\n", B[i][j]);
	}
	return 0;
}
