#include <bits/stdc++.h>

using namespace std;

int matrix[3][3000], n;
void put(int loc, int start, int len)
{
	int s;
	int temp[1000];
	memset(temp, 0, sizeof(temp));
	if (loc == 1 || loc == 6 || loc == 8)
	{
		for (int i = 0; i < len; i++)
		{
			temp[i] = start + i;
		}
	}
	else if (loc == 5 || loc == 7 || loc == 3)
	{
		temp[len / 2] = start + len - 1;
		int op = len - 1, ep = len / 2 - 1;
		for (int i = 0; i < len - 1; i++)
			if ((start + i) & 1)
			{
				temp[op--] = start + i;
			}
			else
			{
				temp[ep--] = start + i;
			}
	}
	else
	{
		for (int i = 0, j = len / 2; i < len; i++, j = (j + 1) % len)
		{
			temp[j] = start + i;
		}
	}
	if (loc == 1 || loc == 6 || loc == 8)
	{
		if (loc == 1)
		{
			s = 0;
		}
		else if (loc == 6)
		{
			s = len;
		}
		else
		{
			s = 2 * len;
		}
		for (int i = 0; i < len; i++)
		{
			matrix[0][s + i] = temp[i];
		}
	}
	else if (loc == 5 || loc == 7 || loc == 3)
	{
		if (loc == 5)
		{
			s = 0;
		}
		else if (loc == 7)
		{
			s = len;
		}
		else
		{
			s = 2 * len;
		}
		for (int i = 0; i < len; i++)
		{
			matrix[1][s + i] = temp[i];
		}
	}
	else
	{
		if (loc == 9)
		{
			s = 0;
		}
		else if (loc == 2)
		{
			s = len;
		}
		else
		{
			s = 2 * len;
		}
		for (int i = 0; i < len; i++)
		{
			matrix[2][s + i] = temp[i];
		}
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		int sum = 3 * (1 + 3 * n) * n / 2;
		if (sum % n)
		{
			puts("IMPOSSIBLE");
		}
		else
		{
			sum /= n;
			int k = n / 3;
			for (int i = 0; i < 9; i++)
			{
				put(i + 1, i * k + 1, k);
			}
			//  printf("%d\n",n);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (j)
					{
						putchar(' ');
					}
					printf("%d", matrix[i][j]);
				}
				printf("\n");
			}
		}
	}
}
