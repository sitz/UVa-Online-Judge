#include <bits/stdc++.h>

using namespace std;

int a[8], n;
int c[8] = {1, 2, 5, 10, 20, 50, 100, 200};
int t[8], g[8];

int judge()
{
	int i, j, k;
	for (i = 0; i < n; i++)
		if (t[i] < 0)
		{
			return 0;
		}
	for (i = 0; i < 8; i++)
		if (g[i] < 0)
		{
			return 0;
		}
	if (g[2] % 2 == 1 || g[5] % 2 == 1)
	{
		return 0;
	}
	g[3] += g[2] / 2;
	g[2] = 0;
	g[6] += g[5] / 2;
	g[5] = 0;
	for (i = 0; i < n; i++)
	{
		int tv = t[i];
		for (j = 7; j >= 0; j--)
		{
			if (tv >= g[j] * c[j])
			{
				tv -= g[j] * c[j];
				g[j] = 0;
			}
			else
			{
				g[j] -= tv / c[j];
				tv %= c[j];
			}
		}
		if (tv != 0)
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	while (1)
	{
		int i, j, k;
		scanf("%d", &n);
		if (n == -1)
		{
			break;
		}
		for (i = 0; i < 8; i++)
		{
			scanf("%d", &a[i]);
		}
		int sum = 0;
		for (i = 0; i < 8; i++)
		{
			sum += c[i] * a[i];
		}
		if (sum % n != 0)
		{
			printf("no\n");
		}
		else
		{
			int flag = 0;
			sum /= n;
			for (i = 0; i < (1 << n); i++)
				for (j = 0; j < (1 << n); j++)
				{
					for (k = 0; k < n; k++)
					{
						t[k] = sum;
					}
					for (k = 0; k < 8; k++)
					{
						g[k] = a[k];
					}
					for (k = 0; k < n; k++)
						if (((1 << k) & i) > 0)
						{
							g[2]--;
							t[k] -= 5;
						}
					for (k = 0; k < n; k++)
						if (((1 << k) & j) > 0)
						{
							g[5]--;
							t[k] -= 50;
						}
					if (judge())
					{
						flag = 1;
					}
				}
			if (flag == 1)
			{
				printf("yes\n");
			}
			else
			{
				printf("no\n");
			}
		}
	}
	return 0;
}
