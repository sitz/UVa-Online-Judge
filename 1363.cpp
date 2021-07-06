#include <bits/stdc++.h>

using namespace std;

/* **********************************************
Author      : JayYe
Created Time: 2013-9-13 15:24:23
File Name   : JayYe.cpp
*********************************************** */

#define LL long long

LL cal(int l, int r)
{
	return (LL)(r - l + 1) * (l + r) / 2;
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != -1)
	{
		LL ans = 0;
		for (int i = 1; i <= n && i <= k; i++)
		{
			int tmp = k / i;
			int then = k / tmp;
			if (then >= n)
			{
				int num = n - i + 1;
				ans += (LL)num * k - tmp * cal(i, n);
				break;
			}
			int num = then - i + 1;
			ans += (LL)num * k - tmp * cal(i, then);
			i = then;
		}
		if (n > k)
			ans += (LL)k * (n - k);
		printf("%lld\n", ans);
	}
	return 0;
}
