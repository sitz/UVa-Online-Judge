#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, p;
	unsigned long long int n, b, c, m;
	for (t = 1; scanf("%llu%llu%d", &c, &n, &p) == 3; t++)
	{
		if (n == 0 && c == 0 && p == 0)
		{
			break;
		}
		for (m = 1LL; p; p--)
		{
			m *= 10LL;
		}
		for (b = 1LL, c %= m; n; n >>= 1)
		{
			if (n & 1LL)
			{
				b = (b * c) % m;
			}
			c = (c * c) % m;
		}
		printf("Case #%d: %llu\n", t, b);
	}
	return 0;
}
