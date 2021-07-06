#include <bits/stdc++.h>

using namespace std;

long long int mat[6][6];
int backup[7], sol[7];
unsigned long long int a[1500];
long long int det(int dim, long long int m[][6])
{
	if (dim == 1)
	{
		return m[0][0];
	}
	else
	{
		long long int result = 0;
		long long int temp[6][6];
		for (int i = 0; i < dim; i++)
		{
			for (int j = 1; j < dim; j++)
			{
				int loc = 0;
				for (int k = 0; k < dim; k++)
					if (k != i)
					{
						temp[j - 1][loc++] = m[j][k];
					}
			}
			long long int ret = m[0][i] * det(dim - 1, temp);
			if (i & 1)
			{
				result -= ret;
			}
			else
			{
				result += ret;
			}
		}
		return result;
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		for (int i = 0; i < 1500; i++)
		{
			scanf("%llu", &a[i]);
		}
		for (int i = 1; i <= 6; i++)
			for (int j = 0, product1 = i, product2 = i + 1; j < 6; j++, product1 *= i, product2 *= i + 1)
			{
				mat[i - 1][j] = product2 - product1;
			}
		long long int dorm = det(6, mat);
		bool ans = true;
		for (int i = 0; i < 6 && ans; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				backup[j] = mat[j][i];
			}
			for (int j = 0; j < 6; j++)
			{
				mat[j][i] = a[j + 1] - a[j];
			}
			long long int s = det(6, mat);
			if (s % dorm != 0)
			{
				ans = false;
			}
			else
			{
				s /= dorm;
				if (s < 0 || s > 1000)
				{
					ans = false;
				}
				else
				{
					sol[i + 1] = s;
				}
			}
			for (int j = 0; j < 6; j++)
			{
				mat[j][i] = backup[j];
			}
		}
		sol[0] = a[0] - sol[1] - sol[2] - sol[3] - sol[4] - sol[5] - sol[6];
		if (sol[0] < 0 || sol[0] > 1000)
		{
			ans = false;
		}
		for (int i = 0; i < 1500 && ans; i++)
		{
			long long int temp = a[i] - sol[0];
			for (int j = 0; j < 6 && ans; j++)
			{
				if (temp % (i + 1) != 0)
				{
					ans = false;
				}
				temp /= (i + 1);
				temp -= sol[j + 1];
			}
			if (temp != 0)
			{
				ans = false;
			}
		}
		if (ans)
		{
			for (int i = 0; i < 7; i++)
			{
				if (i)
				{
					putchar(' ');
				}
				printf("%d", sol[i]);
			}
			puts("");
		}
		else
		{
			puts("This is a smart sequence!");
		}
	}
	return 0;
}
