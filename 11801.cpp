#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SIZE(x) ((int)(x).size())

struct TOPIC
{
	long long x, a, b, c, d;
	int read()
	{
		scanf("%lld%lld%lld%lld%lld", &x, &a, &b, &c, &d);
		if (b * c < a * d)
		{
			swap(a, c);
			swap(b, d);
		}
		return 0;
	}
	long long work(int mid)
	{
		long long i, j, k, ans;
		ans = 1000000001LL;
		for (i = 0; i <= 100; ++i)
		{
			k = (x * mid - d * i - 1) / b + 1;
			ans = min(ans, i * c + k * a);
		}
		return ans;
	}
} tp[1003];
int main()
{
	long long i, j, m, n, T, TI, sum, now, ans;
	long long l, r, mid;
	scanf("%lld", &T);
	for (TI = 1; TI <= T; ++TI)
	{
		scanf("%lld%lld", &n, &m);
		for (i = 1; i <= n; ++i)
		{
			tp[i].read();
		}
		l = 0;
		r = m;
		ans = 0;
		while (l <= r)
		{
			mid = (l + r) >> 1;
			sum = 0;
			for (i = 1; i <= n; ++i)
			{
				sum += tp[i].work(mid);
			}
			if (sum <= m)
			{
				ans = max(ans, mid);
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		printf("Case %lld: ", TI);
		printf("%lld\n", ans);
	}
	return 0;
}
