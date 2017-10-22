#include <bits/stdc++.h>

using namespace std;

long long a[60];

long long get(long long n, int K)
{
	long long ans = 0, i;
	for (i = 30; i >= 0; i--)
		if (n & (1 << i))
		{
			n -= (1 << i);
			ans += a[i] * (1 << (K - i));
			K--;
		}
	return ans;
}

int main()
{
	int A, B, K, i;
	a[0] = 1;
	for (i = 1; i <= 30; i++)
		a[i] = a[i - 1] * 3;
	int T, tc;
	scanf("%d", &T);
	for (tc = 1; tc <= T; tc++)
	{
		scanf("%d%d%d", &K, &A, &B);
		printf("Case %d: %lld\n", tc, get(B, K) - get(A - 1, K));
	}
	return 0;
}
