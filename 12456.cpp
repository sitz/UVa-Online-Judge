#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main()
{
	for (int n; scanf("%d", &n), n;)
	{
		vector<int> base(n);
		rep(i, n) scanf("%d", &base[i]);
		ll ans1 = 1, ans2 = 1;
		rep(i, n)
		{
			ans1 *= base[i];
			if (i < (n + 1) / 2)
			{
				ans2 *= min(base[i], base[n - i - 1]);
			}
		}
		printf("%lld\n", ans1 - ans2);
	}
	return 0;
}
