#include <bits/stdc++.h>
#define foreach(it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		vector<ll> gcd;
		ll ans = 0;
		vector<int> L;
		for (int i = 1; i <= n; i++)
		{
			ll x;
			scanf("%lld", &x);
			ans = max(ans, x);
			bool found = 0;
			for (int j = 0; j < gcd.size(); j++)
			{
				gcd[j] = __gcd(gcd[j], x);
				if (gcd[j] == x)
				{
					found = true;
				}
				ans = max(gcd[j] * (i - L[j] + 1), ans);
			}
			if (!found)
			{
				gcd.push_back(x);
				L.push_back(i);
			}
			vector<pair<ll, int>> t;
			for (int i = 0; i < gcd.size(); i++)
			{
				bool ok = false;
				for (int j = 0; j < t.size(); j++)
				{
					if (gcd[i] == t[j].first)
					{
						ok = true;
						t[j].second = min(t[j].second, L[i]);
						break;
					}
				}
				if (!ok)
				{
					t.push_back(make_pair(gcd[i], L[i]));
				}
			}
			gcd.resize(t.size());
			L.resize(t.size());
			for (int j = 0; j < t.size(); ++j)
			{
				gcd[j] = t[j].first;
				L[j] = t[j].second;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
