#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
	if (b > a)
		swap(a, b);
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}

int main()
{
	LL i, j, s, m, n, kase = 1, x, y, z, d;
	while (scanf("%lld%lld", &m, &n) && m + n)
	{
		printf("Case %lld: ", kase++);
		s = m * n + m + n + 1;
		s = s * (s - 1) * (s - 2) / 6;
		x = (n + 1) * n * (n - 1) / 6 * (m + 1);
		y = (m + 1) * m * (m - 1) / 6 * (n + 1);
		d = min(m, n);
		z = 0;
		for (i = 2; i <= m; i++)
			for (j = 2; j <= n; j++)
				z += (gcd(i, j) - 1) * (m - i + 1) * (n - j + 1);
		printf("%lld\n", s - x - y - 2 * z);
	}
	return 0;
}
