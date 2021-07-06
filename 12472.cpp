#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

const ll INF = 1LL << 61;

int to_binary(ll a, char *s)
{
	int i;
	for (i = 0; a > 0; i++)
	{
		s[i] = a % 2 + '0';
		a /= 2;
	}
	return i;
}

ll dfs(const char *s, char *t, int i = 54, bool b = false)
{
	if (i == -1)
	{
		ll res = 0;
		rep(j, 55) res |= (ll)(t[j] - '0') << j;
		return res;
	}
	if (t[i] == '?')
	{
		if (b)
		{
			t[i] = '0';
			ll res = dfs(s, t, i - 1, true);
			t[i] = '?';
			return res;
		}
		else
		{
			t[i] = '1';
			ll res = dfs(s, t, i - 1, s[i] < t[i]);
			if (s[i] == '0')
			{
				t[i] = '0';
				res = min(res, dfs(s, t, i - 1, false));
			}
			t[i] = '?';
			return res;
		}
	}
	else
	{
		if (b)
		{
			return dfs(s, t, i - 1, true);
		}
		else
		{
			if (s[i] <= t[i])
			{
				return dfs(s, t, i - 1, s[i] < t[i]);
			}
			else
			{
				return INF;
			}
		}
	}
}

void solve()
{
	ll a, b, p;
	scanf("%lld%lld%lld", &a, &b, &p);
	char sa[64], sp[64];
	int na = to_binary(a, sa);
	int np = to_binary(p, sp);
	for (; na < 55; na++)
	{
		sa[na] = '0';
	}
	ll ans = INF;
	rep(i, 56 - np)
	{
		char s[64] = "???????????????????????????????????????????????????????";
		rep(j, np) s[i + j] = sp[j];
		ans = min(ans, dfs(sa, s));
	}
	if (ans <= b)
	{
		printf("%lld\n", ans);
	}
	else
	{
		puts("NONE");
	}
}

int main()
{
	int T, t;
	scanf("%d", &T);
	for (t = 1; t <= T; t++)
	{
		printf("Case %d: ", t), solve();
	}
	return 0;
}
