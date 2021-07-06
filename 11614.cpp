#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	unsigned long long n;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%llu", &n);
		printf("%llu\n", (-1 + sqrt(1 + 4 * n * 2)) / 2);
	}
	return 0;
}
