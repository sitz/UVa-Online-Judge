#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int sz, p, q, x, y, l, mid;
	while (scanf("%lld%lld", &sz, &p) == 2)
	{
		if ((sz | p) == 0)
		{
			break;
		}
		mid = (sz + 1) / 2;
		if (p == 1)
		{
			printf("Line = %lld, column = %lld.\n", mid, mid);
			continue;
		}
		for (p--, x = 50000, y = 25000;; y = (y + 1) / 2)
		{
			if (x < 1)
			{
				x = 1;
			}
			else if (x > 100000)
			{
				x = 99999;
			}
			if (p >= x * x)
			{
				x += y;
			}
			else if (p < (x - 1) * (x - 1))
			{
				x -= y;
			}
			else
			{
				break;
			}
		}
		x |= 1;
		l = x / 2;
		p -= (x - 2) * (x - 2);
		q = p % (x - 1) + 1;
		switch (p / (x - 1))
		{
		case 0:
			printf("Line = %lld, column = %lld.\n", mid + l, mid + l - q);
			break;
		case 1:
			printf("Line = %lld, column = %lld.\n", mid + l - q, mid - l);
			break;
		case 2:
			printf("Line = %lld, column = %lld.\n", mid - l, mid - l + q);
			break;
		case 3:
			printf("Line = %lld, column = %lld.\n", mid - l + q, mid + l);
			break;
		}
	}
	return 0;
}
