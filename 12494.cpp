#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

ll hash_(int n, const char *s)
{
	const ll P = 1000000007;
	ll Ppow = 1;
	rep(i, n) Ppow *= P;
	ll h = 0;
	rep(i, n) h = h * P + s[i];
	ll res = h;
	rep(i, n)
	{
		res = min(res, h);
		h *= P;
		h -= Ppow * s[i];
		h += s[i];
	}
	return res;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		char s[256];
		scanf("%s", s);
		int n = strlen(s);
		set<ll> S;
		rep(i, n) for (int j = i; j < n; j++)
		{
			int len = j - i + 1;
			S.insert(hash_(len, s + i));
		}
		printf("%d\n", S.size());
	}
	return 0;
}
