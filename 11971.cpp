#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
int n, k;

LL pow2(int x)
{
	if (x == 0)
	{
		return 1;
	}
	LL tmp = pow2(x / 2);
	tmp *= tmp;
	if (x & 1)
	{
		tmp *= 2;
	}
	return tmp;
}

int main(void)
{
	int ncase, v = 0;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &k);
		if (k == 1)
		{
			printf("Case #%d: %lld/%lld\n", ++v, 0ll, 1ll);
			continue;
		}
		LL ans = pow2(k) - k - 1;
		while ((ans & 1) == 0 && ans)
		{
			ans /= 2;
			k--;
		}
		printf("Case #%d: %lld/%lld\n", ++v, ans, pow2(k));
	}
	return 0;
}
