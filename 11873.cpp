#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, test = 1;
	while (scanf("%lld", &n) != EOF && n)
	{
		printf("Case %lld: %lld", test++, n * 6);
		n *= n;
		printf(" %lld %lld %lld", 6 * n, 8 * n, 2 * n);
		n *= n;
		printf(" %lld\n", 32 * n);
	}
	return 0;
}
