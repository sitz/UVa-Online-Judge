#include <bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;

int64 josephus(int64 n, int64 k)
{
	if (n == 1)
	{
		return 0;
	}
	return (josephus(n - 1, k) + k) % n;
}
int main()
{
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++)
	{
		int64 n, k;
		scanf("%lld%lld", &n, &k);
		int64 val = josephus(n, k) + 1;
		printf("Case %d: %lld\n", t, val);
	}
	return 0;
}
