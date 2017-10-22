#include <bits/stdc++.h>
using namespace std;

int main()
{
	int T, all, small, p, q, r, x, y, z;
	long long n[100000];

	scanf("%d", &T);
	for (int t = 1; t <= T; ++t)
	{
		bool exclude[100000] = {false};
		scanf("%d %d", &all, &small);
		scanf("%d %d %d %d %d %d", &p, &q, &r, &x, &y, &z);
		for (long long i = 1; i <= all; ++i)
			n[i - 1] = (p * i * i + q * i + r) % 1000007;
		for (long long i = 1; i <= small; ++i)
			++exclude[(x * i * i + y * i + z) % all];
		long long root = INT_MAX, s = accumulate(n, n + all, 0ll);
		for (int i = 0; i < all; ++i)
			if (!exclude[i] && n[i] < root)
				root = n[i];
		printf("Case %d: %lld\n", t, (s - root) * root);
	}
}
