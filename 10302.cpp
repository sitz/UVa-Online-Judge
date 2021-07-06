#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long int x, ans;
	while (scanf("%lld", &x) == 1)
	{
		printf("%lld\n", (x * x * (x + 1) * (x + 1)) / 4LL);
	}
	return 0;
}
