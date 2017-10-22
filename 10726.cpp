#include <bits/stdc++.h>

using namespace std;

long c, m;
bool find(long n)//找最小的coconut數
{
	long i;
	for (i = 0; i < c; i++)
	{
		if ((n - m) % c)
		{
			return false;
		}
		n = n - (n - m) / c - m;
	}
	if (n % c == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	long low, high;
	long i, count, d, sum;
	int cases;
	scanf("%d", &cases);
	for (int x = 1; x <= cases; x++)
	{
		scanf("%ld %ld %ld %ld", &c, &m, &low, &high);
		if (c > 8)
		{
			printf("Case %d: %ld\n", x, 0);
			continue;
		}
		else
		{
			for (i = low; i <= high; i++)
				if (find(i))
				{
					break;
				}
			if (i > high)
			{
				printf("Case %d: 0\n", x);
				continue;
			}
			sum = i;
			for (i = 0, d = 1; i < c + 1; i++)
			{
				d *= c;
			}
			count = 0;
			while (sum <= high)
			{
				sum += d;
				count++;
			}
			printf("Case %d: %ld\n", x, count);
		}
	}
	return 0;
}