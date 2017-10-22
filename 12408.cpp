#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	ll r, t, n, ans;
	while (scanf("%lld%lld%lld", &r, &t, &n), r)
	{
		if (t < r || t > n * r)
		{
			puts("0");
		}
		else
		{
			ll x1 = (t - r) / (n - 1);
			ll x2 = (n * r - t) / (n - 1);
			printf("%lld\n", ((n - 1) * x1 + 2) * (x1 + 1) / 2 + ((n - 1) * (r - x2 - 1) + 2) * (r - x2) / 2 + (x2 - x1) * (t - r + 1) - 2);
		}
	}
	return 0;
}
