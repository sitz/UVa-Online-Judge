#include <bits/stdc++.h>

using namespace std;

unsigned long long int base[64], n;
int temp[9] = {0, 0, 1, 0, 2, 1, 0, 0, 3};
int main()
{
	base[0] = 1ull;
	for (int i = 1; i <= 63; i++)
	{
		base[i] = base[i - 1] * 2ull;
	}
	while (scanf("%llu", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		if (n < 9)
		{
			printf("%d\n", temp[n]);
		}
		else
		{
			while (true)
			{
				if (n < 9)
				{
					printf("%d\n", temp[n]);
					break;
				}
				int i, j, k, p;
				for (i = 1; i <= 63; i++)
					if (base[i - 1] <= n && base[i] > n)
					{
						break;
					}
				i--;
				if (base[i] == n)
				{
					printf("%d\n", i);
					break;
				}
				unsigned long long int b = base[i], temp = base[i + 1];
				p = i;
				for (i--, j = 1; i >= 1; i--, j++)
					for (k = 0; k < j; k++)
						if (b + base[i] / 2 < n)
						{
							b += base[i] / 2;
						}
						else
						{
							goto end;
						}
			end:
				if (n < temp && n >= temp - p)
				{
					printf("0\n");
					break;
				}
				n -= b;
				n += base[i - 1];
			}
		}
	}
	return 0;
}
