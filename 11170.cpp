#include <bits/stdc++.h>

using namespace std;

long long int T[60][60] = {0};
int main()
{
	int i, j, n, f;
	T[0][0] = T[1][1] = 1;
	for (i = 2; i < 50; i++)
	{
		for (j = 0; j < i; j++)
		{
			T[i][j + 1] = 2 * T[i - 1][j];
		}
		for (j = 0; j < i; j++)
		{
			T[i][j] -= T[i - 2][j];
		}
	}
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		if (n == 1)
		{
			printf("Cos(A)\n");
			continue;
		}
		printf("%lldCos^%d(A)", T[n][n], n);
		for (i = n - 2; i > 1; i -= 2)
		{
			if (T[n][i] >= 0)
			{
				printf("+%lldCos^%d(A)", T[n][i], i);
			}
			else
			{
				printf("%lldCos^%d(A)", T[n][i], i);
			}
		}
		if (i)
		{
			if (T[n][1] > 0)
			{
				printf("+");
			}
			printf("%dCos(A)", T[n][1]);
		}
		else if (T[n][0] > 0)
		{
			printf("+1");
		}
		else
		{
			printf("-1");
		}
		printf("\n");
	}
	return 0;
}
