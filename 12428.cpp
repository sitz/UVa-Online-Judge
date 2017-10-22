#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
int64 N, M;
void init()
{
	scanf("%lld%lld", &N, &M);
}
int solve()
{
	if (M < N)
	{
		return M;
	}
	int ans = N - 2;
	M -= N - 1;
	for (int cur = 1; M > 0; cur++)
	{
		ans--;
		M -= cur;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d", &T);
	for (; T--;)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
