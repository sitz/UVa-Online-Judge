#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int64 A1, A2, B1, B2, C1, C2;
		scanf("%lld%lld%lld%lld%lld%lld", &A1, &A2, &B1, &B2, &C1, &C2);
		int64 ans = (B2 - B1 + 1) * (A2 / 2 + 1 - (A1 ? (A1 - 1) / 2 + 1 : 0)) * (C2 / 2 + 1 - (C1 ? (C1 - 1) / 2 + 1 : 0));
		printf("Case %d: %lld\n", i + 1, ans);
	}
	return 0;
}
