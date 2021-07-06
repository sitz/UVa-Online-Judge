#include <bits/stdc++.h>

using namespace std;

#define LL long long
LL f[65];
LL solve(LL x)
{
	int i, j;
	for (i = 61; i >= 0; i--)
		if (x % f[i] == f[i] - 1)
			return x / f[i + 1];
}
int main()
{
	int i, j, k;
	f[0] = 1;
	for (i = 1; i <= 62; i++)
		f[i] = f[i - 1] << 1;
	int t, n;
	LL x, ans;
	scanf("%d", &t);
	while (t--)
	{
		ans = 0;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%lld", &x);
			ans ^= solve(x);
		}
		if (ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
