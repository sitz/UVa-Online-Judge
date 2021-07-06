#include <bits/stdc++.h>

using namespace std;

typedef long long xx;
xx Sum(xx n)
{
	xx m;
	m = n + 1;
	m = (n * m) / 2;
	return m;
}
int main()
{
	xx n, m, k, diff;
	while (scanf("%lld", &n) == 1)
	{
		m = sqrtl(n * 2);
		k = (m * (m + 1)) / 2;
		if (k < n)
		{
			m++;
			k += m;
		}
		printf("%lld/%lld\n", k - n + 1, m - (k - n));
	}
	return 0;
}
