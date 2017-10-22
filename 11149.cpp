#include <bits/stdc++.h>

using namespace std;

int n, n2, B[80][80], C[80][80], T[80][80];
void ini()
{
	int i, j;
	for (i = 0; i < n2; i++)
	{
		for (j = 0; j < n2; j++)
		{
			B[i][j] = C[i][j] = 0;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &C[i][j]);
			C[i][j] %= 10;
		}
		j = i + n;
		B[i][i] = B[j][j] = C[i][j] = C[j][j] = 1;
	}
}
void mult(int M1[80][80], int M2[80][80])
{
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			T[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				T[i][j] += M1[i][k] * M2[k][j];
			}
		}
		for (; j < n2; j++)
		{
			T[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				T[i][j] += M1[i][k] * M2[k][j];
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			M1[i][j] = T[i][j] % 10;
		}
		for (; j < n2; j++)
		{
			M1[i][j] = (M1[i][j] + T[i][j]) % 10;
		}
	}
}
int main()
{
	int i, j, k;
	while (scanf("%d%d", &n, &k) == 2)
	{
		if (n == 0)
		{
			break;
		}
		n2 = n * 2;
		for (ini(); k; k >>= 1)
		{
			if (k & 1)
			{
				mult(B, C);
			}
			mult(C, C);
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				B[i][j] = B[i][j] + B[i][j + n];
			}
			B[i][i] += 9;
			printf("%d", B[i][0] % 10);
			for (j = 1; j < n; j++)
			{
				printf(" %d", B[i][j] % 10);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
