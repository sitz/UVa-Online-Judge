#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
LL ans[10002], v[1002];
set<LL> s;
int maxd;
LL gcd(LL a, LL b)
{
	return b ? gcd(b, a % b) : a;
}
typedef long long LL;
LL get_first(LL a, LL b)
{
	return b / a + 1;
}
bool better(int d)
{
	for (int i = d; i >= 0; i--)
		if (v[i] != ans[i])
		{
			return ans[i] == -1 || v[i] < ans[i];
		}
	return false;
}
bool dfs(int d, LL from, LL aa, LL bb)
{
	if (d == maxd)
	{
		if (bb % aa)
		{
			return false;
		}
		v[d] = bb / aa;
		if (s.count(bb / aa))
		{
			return false;
		}
		if (better(d))
		{
			memcpy(ans, v, sizeof(LL) * (d + 1));
		}
		return true;
	}
	bool ok = false;
	for (LL i = max(from, get_first(aa, bb));; i++)
	{
		if (bb * (maxd + 1 - d) <= i * aa)
		{
			break;
		}
		if (s.count(i))
		{
			continue;
		}
		v[d] = i;
		LL b2 = bb * i;
		LL a2 = aa * i - bb;
		LL g = gcd(a2, b2);
		if (dfs(d + 1, i + 1, a2 / g, b2 / g))
		{
			ok = true;
		}
	}
	return ok;
}
int main()
{
	int t, k;
	LL a, b, num;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++)
	{
		s.clear();
		scanf("%lld%lld%d", &a, &b, &k);
		for (int i = 0; i < k; i++)
		{
			scanf("%lld", &num);
			s.insert(num);
		}
		int ok = 0;
		for (maxd = 1;; maxd++)
		{
			memset(ans, -1, sizeof(ans));
			if (dfs(0, get_first(a, b), a, b))
			{
				ok = 1;
				break;
			}
		}
		printf("Case %d: %lld/%lld=", ii, a, b);
		for (int i = 0; i <= maxd; ++i)
		{
			if (i)
			{
				printf("+");
			}
			printf("1/%lld", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
