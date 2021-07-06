#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	LL n, t;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		if (n & 1)
		{
			printf("%lld\n", (n * n - 2 * n + 1) / 4);
		}
		else
		{
			printf("%lld\n", (n * n - 2 * n) / 4);
		}
	}
	return 0;
}
