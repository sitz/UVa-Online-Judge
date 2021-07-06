#include <bits/stdc++.h>

using namespace std;

double matrix[100][200];
int n;
bool solve()
{
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i] == 0.0)
		{
			return false;
		}
		double base = matrix[i][i];
		for (int j = i; j < 2 * n; j++)
		{
			matrix[i][j] /= base;
		}
		for (int j = 0; j < n; j++)
		{
			if (i != j && matrix[j][i])
			{
				double p = matrix[j][i] / matrix[i][i];
				for (int k = i; k < 2 * n; k++)
				{
					matrix[j][k] -= p * matrix[i][k];
				}
			}
		}
	}
	return true;
}
int main()
{
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 2 * n; j++)
			{
				matrix[i][j] = 0;
			}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				scanf("%lf", &matrix[i][j]);
			}
		for (int i = 0; i < n; i++)
		{
			matrix[i][n + i] = 1.0;
		}
		if (!solve())
		{
			puts("Not possible");
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = n; j < 2 * n; j++)
				{
					if (j != n)
					{
						printf(" ");
					}
					printf("%.6lf", matrix[i][j]);
				}
				printf("\n");
			}
		}
		puts("");
	}
	return 0;
}
