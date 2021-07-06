#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b, c, i, j = 1;
	while (scanf("%lld%lld", &b, &c) == 2)
	{
		if (b < 0 && c < 0)
		{
			break;
		}
		a = b;
		for (i = 1; i != 0; i++)
		{
			if (a == 1)
			{
				break;
			}
			if (a % 2 == 0)
			{
				a = a / 2;
			}
			else
			{
				a = a * 3 + 1;
			}
			if (a > c)
			{
				break;
			}
		}
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", j, b, c, i);
		j++;
	}
	return 0;
}
