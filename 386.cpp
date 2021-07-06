#include <bits/stdc++.h>

using namespace std;

void Cal(int n)
{
	int i, j, k, p, q, r;
	int N = n * n * n;
	for (i = 2; i <= n; i++)
	{
		p = i * i * i;
		for (j = i + 1; j < n; j++)
		{
			q = j * j * j;
			if (p + q >= N)
			{
				break;
			}
			for (k = j + 1; k < n; k++)
			{
				r = k * k * k;
				if (N == r + p + q)
				{
					printf("Cube = %d, Triple = (%d,%d,%d)\n", n, i, j, k);
				}
				if (r + p + q > N)
				{
					break;
				}
			}
		}
	}
}
int main()
{
	int i;
	for (i = 1; i <= 200; i++)
	{
		Cal(i);
	}
	return 0;
}
