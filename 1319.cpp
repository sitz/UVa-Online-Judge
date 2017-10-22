#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef vector<pii> vpi;
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const int hinf = 0x3f3f3f3f;
const ll mod = 1000000007;

#define out(x) cout << x << '\n';
#define fio                         \
	freopen("input.txt", "r", stdin); \
	freopen("output.txt", "w", stdout);
#define fino freopen("input.txt", "r", stdin);
#define sz(a) sizeof(a)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(a, i) memset((a), (i), sz(a))
#define clr(x) memset(x, 0, sz(x))
#define cdp(x) memset((x), -1, sizeof(x))
#define infi(x) memset(x, 0x3f, sz(x))
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)

int m, p, a, b;
double ans;

int main()
{
	while (scanf("%d%d%d%d", &m, &p, &a, &b) != EOF)
	{
		ans = 0;
		if (b >= 0)
		{
			ans += 1.0 * b * pow(a, p / 2.0);
			m -= b;
		}
		else
		{
			ans += 1.0 * a * (-b) * pow(1.0 / a, p / 2.0);
			m -= a * (-b);
		}
		while (m >= (1 + a))
		{
			ans += 1.0 * pow(a, p / 2.0);
			ans += 1.0 * a * pow(1.0 / a, p / 2.0);
			m -= (1 + a);
		}
		if (m > 1)
		{
			ans += 1.0 * pow((1.0 * m - 1.0) * (1.0 * m - 1.0) / a, p / 2.0);
			ans += 1.0 * (m - 1.0) * pow(1.0 / a, p / 2.0);
		}
		if (ans - floor(ans) > 0.5)
		{
			cout << floor(ans) + 1 << endl;
		}
		else
		{
			cout << floor(ans) << endl;
		}
	}
	return 0;
}
