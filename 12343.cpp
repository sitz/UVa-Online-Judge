#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int callen(ll x)
{
	if (x <= 1)
	{
		return 0;
	}
	int i;
	ll p = 1LL;
	i = 0;
	while ((p << i) <= x)
	{
		i++;
	}
	return i - 1;
}

//统计X到Y得某一位的1的个数，很容易发现规律的。
//就是循环节为Z，一半是0，一半是1
ll cal(ll x, ll y, ll z)
{
	ll tmp = (y - x + 1) / z;
	ll mod = (y - x + 1) % z;
	if (mod >= z / 2)
	{
		y = mod - z / 2;
	}
	else
	{
		y = 0;
	}
	return ((y + z / 2 * tmp) & (1LL));
}
ll doit(ll x, int len)
{
	if (x < 1)
	{
		return 0;
	}
	ll p = 1LL;
	ll ans = 0LL;
	ans = (p << len);
	for (int i = 1; i <= len; i++)
	{
		ll l, r;
		l = (p << i);
		r = min((p << (i + 1)) - 1, x);
		ll sum = 0LL;
		for (int j = 0; j < i; j++)
		{
			ll tmp = cal(l, r, 1LL << (j + 1));
			sum |= (tmp << j);
		}
		sum |= (((r - l + 1) & (1LL)) << i);
		//printf("%I64d\n",sum);
		ans ^= (sum << (len - i));
	}
	return ans;
}
int main()
{
	int T, t, i;
	int len1, len2;
	ll l, r;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		scanf("%llu%llu", &l, &r);
		//printf("%I64d %I64d\n",l,r);
		len1 = callen(l - 1);
		len2 = callen(r);
		//printf("%d %d\n",len1,len2);
		l = doit(l - 1, len1);
		r = doit(r, len2);
		ll ans = (l << (len2 - len1)) ^ r;
		printf("Case %d: %llu\n", t, ans);
	}
	return 0;
}
