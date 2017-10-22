#include <bits/stdc++.h>

using namespace std;

bool p[11000001];
int pr[804580];
int k = 0;

long long f(int r)
{
	int ll, rr, mm;
	long long ans = 0;
	ll = 0, rr = k;
	int j = pr[0];
	while (ll < rr)
	{
		mm = (ll + rr + 1) >> 1;
		if (j + pr[mm] <= r)
		{
			ll = mm;
		}
		else
		{
			rr = mm - 1;
		}
	}
	ans += ll + 0LL;
	for (int i = 1;; ++i)
	{
		while ((pr[i] + pr[ll] > r) && ll > i)
		{
			--ll;
		}
		if (ll <= i)
		{
			break;
		}
		ans += ll - i + 0LL;
	}
	return ans;
}

int main()
{
	int i, j;
	for (i = 2; i * i <= 11000000; ++i)
		if (!p[i])
			for (j = i * i; j <= 11000000; j += i)
			{
				p[j] = 1;
			}
	for (i = 3; i <= 11000000; i += 2)
		if (!p[i])
		{
			pr[k++] = i;
		}
	pr[k] = -1u >> 1;
	int l, r;
	long long s;
	while (scanf("%d%d", &l, &r) && l)
	{
		s = f(r) - f(l - 1);
		printf("%lld\n", s);
	}
	return 0;
}
