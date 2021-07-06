#include <bits/stdc++.h>

using namespace std;

int d, n, m;
int base[3][3];
int sol[10] = {0, 1, 2, 6, 19, 61, 196, 629, 2017, 6466};
void run(int n, int m, int matrix[3][3])
{
	if (n == 1)
	{
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				matrix[i][j] = base[i][j];
			}
	}
	else
	{
		int temp[3][3];
		if (n & 1)
		{
			run(n - 1, m, temp);
			memset(matrix, 0, sizeof(temp));
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
					{
						matrix[i][j] = (matrix[i][j] + (temp[i][k] * base[k][j])) % m;
					}
		}
		else
		{
			run(n / 2, m, temp);
			memset(matrix, 0, sizeof(temp));
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					for (int k = 0; k < 3; k++)
					{
						matrix[i][j] = (matrix[i][j] + (temp[i][k] * temp[k][j])) % m;
					}
		}
	}
}
int main()
{
	base[0][0] = 5;
	base[0][1] = -7;
	base[0][2] = 4;
	base[1][0] = 1;
	base[1][1] = 0;
	base[1][2] = 0;
	base[2][0] = 0;
	base[2][1] = 1;
	base[2][2] = 0;
	int t, sum;
	m = 10000;
	scanf("%d", &t);
	for (int caseno = 1; caseno <= t; caseno++)
	{
		scanf("%d", &n);
		int matrix[3][3];
		sum = 0;
		if (n <= 9)
		{
			sum = sol[n];
			printf("Case %d: %d\n", caseno, sum);
		}
		else
		{
			run(n - 4, 10000, matrix);
			for (int i = 0; i < 3; i++)
			{
				sum = (sum + matrix[0][i] * (sol[4 - i] % m)) % m;
			}
			while (sum < 0)
			{
				sum += m;
			}
			printf("Case %d: %04d\n", caseno, sum);
		}
	}
}
