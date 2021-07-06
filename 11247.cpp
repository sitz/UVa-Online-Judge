#include <bits/stdc++.h>

using namespace std;

long long int m, x;

int main()
{
	while (scanf("%lld %lld", &m, &x), x || m)
	{
		if (x == 100 || x == 0 || m == 1)
		{
			puts("Not found");
		}
		else
		{
			long long a = (m - 1) * 100, b = (100 - x);
			long long int v = a / b;
			if (a % b == 0)
			{
				v--;
			}
			if (v >= m)
			{
				printf("%lld\n", v);
			}
			else
			{
				puts("Not found");
			}
		}
	}
	return 0;
}
