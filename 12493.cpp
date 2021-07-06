#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const double esp = 1e-6;

LL Euler(LL n)
{
	LL ans = n;
	for (LL i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

int main()
{
	LL n;
	while (~scanf("%lld", &n))
	{
		printf("%lld\n", Euler(n) / 2);
	}
	return 0;
}
