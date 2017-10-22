#include <bits/stdc++.h>

using namespace std;

#define FRE(i, a, b) for (i = a; i <= b; i++)
#define FRL(i, a, b) for (i = a; i < b; i++)
#define mem(t, v) memset((t), v, sizeof(t))
#define sqr(x) (x) * (x)
#define all(x) x.begin(), x.end()
#define un(x) x.erase(unique(all(x)), x.end())
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d%d", &a, &b)
#define sfff(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define D(x) cout << #x " = " << (x) << endl
#define pf printf
#define VI vector<int>
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pb push_back
#define mp make_pair
#define pi acos(-1.00)
#define DBG pf("Hi\n")
#define sz size()
#define ins insert
#define fi first
#define se second
#define xx first
#define yy second
#define inf (1 << 29)
#define MOD 1000000007
#define eps 1e-9
#define MAX 100000

typedef long long int LL;
typedef double db;

unsigned long long int cnt[MAX + 10];

int main()
{
	int i, j, k, t, cs, v, f, p;
	unsigned long long res, F;
	LL w, mx;
	sf(t);
	FRE(cs, 1, t)
	{
		mem(cnt, 0);
		res = F = mx = 0;
		w = 1;
		sf(p);
		FRE(i, 1, p)
		{
			sff(v, f);
			cnt[v] = f;
			mx = max(mx, (LL)v);
		}
		FRE(i, 1, MAX)
		{
			F += cnt[i];
			res += F * cnt[i];
			if (i == mx)
			{
				break;
			}
			w = w * (cnt[i] + 1);
			if (w >= MOD)
			{
				w %= MOD;
			}
		}
		pf("Case %d: %llu %d\n", cs, res, w);
	}
	return 0;
}
