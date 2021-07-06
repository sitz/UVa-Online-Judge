#include <bits/stdc++.h>

using namespace std;

int M[50005];
int main()
{
	int n, q, i, j, x;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", M + i);
	}
	M[0] = -1;
	M[n + 1] = 2147483647;
	scanf("%d", &q);
	while (q--)
	{
		scanf("%d", &x);
		if (x > M[1])
		{
			for (i = n / 2, j = n / 4;; j = (j + 1) / 2)
			{
				if (i < 0)
				{
					i = 0;
				}
				else if (i > n)
				{
					i = n;
				}
				if (M[i] >= x)
				{
					i -= j;
				}
				else if (M[i + 1] < x)
				{
					i += j;
				}
				else
				{
					break;
				}
			}
			printf("%d ", M[i]);
		}
		else
		{
			printf("X ");
		}
		if (x < M[n])
		{
			for (i = n / 2, j = n / 4;; j = (j + 1) / 2)
			{
				if (i <= 0)
				{
					i = 1;
				}
				else if (i > n + 1)
				{
					i = n + 1;
				}
				if (M[i - 1] > x)
				{
					i -= j;
				}
				else if (M[i] <= x)
				{
					i += j;
				}
				else
				{
					break;
				}
			}
			printf("%d\n", M[i]);
		}
		else
		{
			printf("X\n");
		}
	}
	return 0;
}
