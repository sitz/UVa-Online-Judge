#include <bits/stdc++.h>

using namespace std;

#define MAXN 100

typedef long long LL;

int s[MAXN], t[MAXN];

LL fun(int *p, int i, int final)
{
	if (i == 0)
	{
		return 0;
	}
	if (p[i] == final)
	{
		return fun(p, i - 1, final);
	}
	return fun(p, i - 1, 6 - final - p[i]) + (1LL << (i - 1));
}

int main()
{
	int n;
	int cas = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &s[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &t[i]);
		}
		int k = n;
		while (s[k] == t[k] && k)
		{
			k--;
		}
		LL ans = 0;
		if (k != 0)
		{
			int other = 6 - s[k] - t[k];
			ans = fun(s, k - 1, other) + fun(t, k - 1, other) + 1;
		}
		printf("Case %d: %lld\n", cas++, ans);
	}
	return 0;
}
