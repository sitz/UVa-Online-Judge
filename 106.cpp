#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline T gcd(T a, T b)
{
	T c;
	while (b)
	{
		c = b, b = a % b, a = c;
	}
	return a;
}

int X[1000005] = {0}, Y[1000005] = {0}, M[1000005];

int main()
{
	int i, j, k, sum = 0, a, b, c, n;
	for (i = 0; i < 1000005; i++)
	{
		M[i] = 2000000;
	}
	for (i = 1; i < 1001; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (i * i + j * j > 1000000)
			{
				break;
			}
			a = i * i - j * j;
			b = 2 * i * j;
			c = i * i + j * j;
			if (gcd(a, gcd(b, c)) == 1)
			{
				X[c]++;
				for (k = 1; c * k <= 1000000; k++)
				{
					if (c * k < M[a * k])
					{
						M[a * k] = c * k;
					}
					if (c * k < M[b * k])
					{
						M[b * k] = c * k;
					}
					if (c * k < M[c * k])
					{
						M[c * k] = c * k;
					}
				}
			}
		}
	}
	for (i = 0; i < 1000005; i++)
	{
		if (M[i] != 2000000)
		{
			Y[M[i]]++;
		}
	}
	for (i = 1; i < 1000005; i++)
	{
		X[i] += X[i - 1];
		Y[i] += Y[i - 1];
	}
	while (scanf("%d", &n) == 1)
	{
		printf("%d %d\n", X[n], n - Y[n]);
	}
	return 0;
}
