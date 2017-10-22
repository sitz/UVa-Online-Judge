#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, j;
	long long n, t, res;
	while (scanf("%lld", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 1, j = 0;; i++)
		{
			t = (long long)i * i * 6;
			if (t >= n)
			{
				break;
			}
			res = (n - t);
			if (res % (i * 7) == 0)
			{
				res /= (i * 7);
				if (res >= 100000007)
				{
					res %= 100000007;
				}
				if (res > 0)
				{
					printf("Possible Missing Soldiers = %d\n", (int)(((res * res) << 1) % 100000007));
					j++;
				}
			}
		}
		if (j == 0)
		{
			printf("No Solution Possible\n");
		}
		printf("\n");
	}
	return 0;
}
