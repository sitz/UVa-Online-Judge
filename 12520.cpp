#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL l, n, ans, ans1;
	while (scanf("%lld%lld", &l, &n) && l)
	{
		if (n <= (l * l + 1) / 2)
		{
			ans = n * 4;
		}
		else
		{
			n = l * l - n;
			ans = 4 * l;
			LL a = ((l - 2) * (l - 2) + 1) / 2;
			LL b = (l - 2) * 2;
			if (l & 1)
			{
				b -= 2;
			}
			if (n <= a)
			{
				ans += n * 4;
			}
			else if (n <= a + b)
			{
				ans += a * 4 + (n - a) * 2;
			}
			else
			{
				ans += a * 4 + b * 2;
			}
			if (l & 1)
			{
				ans1 = 4 * l;
				LL a = ((l - 2) * (l - 2)) / 2;
				LL b = (l - 1) * 2;
				if (n <= a)
				{
					ans1 += n * 4;
				}
				else if (n <= a + b)
				{
					ans1 += a * 4 + (n - a) * 2;
				}
				else
				{
					ans1 += a * 4 + b * 2;
				}
				if (ans < ans1)
				{
					ans = ans1;
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
