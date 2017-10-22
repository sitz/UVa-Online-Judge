#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long m, minn, maxx;
	int cas = 1;
	long long s1, s2;
	double ans;
	while (~scanf("%lld%lld%lld", &m, &minn, &maxx) && (m || minn || maxx))
	{
		ans = 0;
		if (m <= minn)
		{
			printf("Case %d: %.2lf\n", cas++, ans);
			continue;
		}
		if (m <= maxx)
		{
			ans += 0.1 * (maxx - m + 1) * (m * (m - minn + 1) - (minn + m) * (m - minn + 1) / 2);
			ans += 0.05 * (1 + m - minn) * (m - minn) / 2 + 0.15 * (m - minn) * (m - minn + 1) * (2 * (m - minn) + 1) / 6;
		}
		else
		{
			ans += (maxx + 1) * (0.2 * m - 0.05 * maxx) * (maxx - minn + 1) - (0.2 * m + 0.1 * maxx + 0.15) * (maxx + minn) * (maxx - minn + 1) / 2 + 0.15 / 6 * (maxx * (maxx + 1) * (2 * maxx + 1) - (minn - 1) * minn * (2 * minn - 1));
		}
		long long k = (maxx - minn + 1) * (maxx - minn + 2) / 2;
		ans = ans / k;
		printf("Case %d: %.2lf\n", cas++, ans);
	}
	return 0;
}
