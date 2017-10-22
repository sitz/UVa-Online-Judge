#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long L, R;
	while (scanf("%lld%lld", &L, &R) == 2 && L)
	{
		printf("%lld\n", R / 5 - L / 5 + 1);
	}
	return 0;
}
