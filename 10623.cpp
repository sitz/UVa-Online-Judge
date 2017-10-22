#include <bits/stdc++.h>

using namespace std;

typedef long long int _int64;

_int64 sum;

// binary search
bool sqrt(_int64 n, _int64 &ans)
{
	_int64 left = 1, right = 65536, mid = (left + right) / 2;
	while (left <= right)
	{
		if (mid * mid == n)
		{
			ans = mid;
			return true;
		}
		else if (mid * mid > n)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
		mid = (left + right) / 2;
	}
	return false;
}

int main()
{
	int caseno = 1;
	while (scanf("%lld", &sum), sum != -1)
	{
		printf("Case %d:\n", caseno++);
		bool flag = false;
		if (sum == 1)
		{
			puts("0 0 0");
		}
		else if (sum == 2)
		{
			puts("0 0 1");
			puts("0 1 0");
			puts("1 0 0");
		}
		else
		{
			for (int m = 0; m < 100; m++)
				for (int p = 99; p >= 0; p--)
				{
					_int64 a = 1, b = (4 * m + 6 * p - 1), c = (2 + 2 * m * m - 2 * m + 6 * p * m + 3 * p * p - 3 * p - sum);
					_int64 d = b * b - 4 * c, e;
					if (sqrt(d, e))
					{
						if ((b - e) % 2 == 0)
						{
							_int64 x = (-b - e) / 2;
							if (x >= 0 && x < 20000)
							{
								printf("%d %lld %d\n", m, x, p);
								flag = true;
							}
							_int64 y = (-b + e) / 2;
							if (y >= 0 && y < 20000)
							{
								printf("%d %lld %d\n", m, y, p);
								flag = true;
							}
						}
					}
				}
			if (!flag)
			{
				puts("Impossible.");
			}
		}
	}
	return 0;
}
