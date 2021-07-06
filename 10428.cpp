#include <bits/stdc++.h>

using namespace std;

double f[6], ff[6];
double ans[5], x, lastx;
int n, nn, ptr;
double calcf(double x)
{
	double sum = 0;
	for (int i = 0; i <= nn; i++)
	{
		sum = sum * x + f[i];
	}
	return sum;
}
double calcff(double x)
{
	double sum = 0;
	for (int i = 0; i <= nn - 1; i++)
	{
		sum = sum * x + ff[i];
	}
	return sum;
}
int main()
{
	int caseno = 1;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		nn = n;
		ptr = 0;
		for (int i = 0; i <= n; i++)
		{
			scanf("%lf", &f[i]);
		}
		for (int i = 0; i < n; i++)
		{
			ff[i] = f[i] * (n - i);
		}
		for (int i = 0; ptr < n; i++)
		{
			x = 100;
			lastx = x - 1;
			while (fabs(x - lastx) >= 1e-6)
			{
				lastx = x;
				if (calcff(x) == 0)//||fabs(calcff(x))<1e-4)
				{
					x = x * x + 1;
					lastx = x - 1;
				}
				else
				{
					x = x - calcf(x) / calcff(x);
				}
			}
			while (true)
			{
				if (fabs(calcf(x)) > 1e-6)
				{
					break;
				}
				ans[ptr++] = x;
				if (ptr == n)
				{
					break;
				}
				for (int j = 1; j < nn; j++)
				{
					f[j] += f[j - 1] * x;
				}
				nn--;
				for (int j = 0; j < nn; j++)
				{
					ff[j] = f[j] * (nn - j);
				}
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (ans[i] > ans[j])
				{
					double temp = ans[i];
					ans[i] = ans[j];
					ans[j] = temp;
				}
		printf("Equation %d:", caseno++);
		for (int i = 0; i < n; i++)
		{
			printf(" %.4lf", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
