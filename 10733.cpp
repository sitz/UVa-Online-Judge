#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int n1, n2;
	while (scanf("%lld", &n1) == 1)
	{
		if (n1 == 0LL)
		{
			break;
		}
		n1 += (n2 = n1 * (n1 - 1) / 2LL);
		printf("%lld\n", n1 * (n1 + 1LL) / 2LL * (n1 + 2LL) / 3LL + (n2 - 2LL) * (n2 - 1LL) / 2LL * n2 / 3LL);
	}
	return 0;
}
