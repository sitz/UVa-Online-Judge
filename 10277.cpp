#include <bits/stdc++.h>

using namespace std;

long long int P, Q;

long long int gcd(long long int x, long long int y)
{
	return y == 0 ? x : gcd(y, x % y);
}

void solve()
{
	long long int min, mid, max, ans, total, temp;
	if (P == 0)
	{
		printf("0 2\n");
	}
	else if (P == Q)
	{
		printf("2 0\n");
	}
	else
	{
		ans = gcd(Q, P);
		P /= ans, Q /= ans;
		for (total = 3; total <= 50000; total++)
		{
			temp = P * total * (total - 1);
			if (temp % Q)
			{
				continue;
			}
			else
			{
				temp /= Q;
			}
			min = 1, max = total;
			for (;;)
			{
				mid = (min + max) / 2;// binary search
				if (mid == min)
				{
					break;
				}
				if (mid * mid - mid - temp > 0)
				{
					max = mid;
				}
				else
				{
					min = mid;
				}
			}
			if (mid * mid - mid - temp == 0)
			{
				printf("%lld %lld\n", mid, total - mid);
				return;
			}
		}
		printf("impossible\n");
	}
}

int main()
{
	for (;;)
	{
		scanf("%lld%lld", &P, &Q);
		if (!P && !Q)
		{
			break;
		}
		solve();
	}
	return 0;
}
