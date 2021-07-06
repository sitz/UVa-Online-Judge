#include <bits/stdc++.h>

using namespace std;

#define S(a) scanf("%d", &a)
#define P(a) printf("%d", a)
#define PS(a) printf("%s", a)

#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define SLL(a) scanf("%lld", &a)
#define PLL(a) printf("%lld", a)
#define SLL2(a, b) scanf("%lld%lld", &a, &b)
#define SLL3(a, b, c) scanf("%lld%lld%lld", &a, &b, &c)

#define PCASE printf("Case %d: ", kk++)
#define PCASENL printf("Case %d:\n", kk++)
#define NL puts("")

#define sz(a) ((int)a.size())
#define repv(i, a) for (int i = 0; i < sz(a); i++)
#define revv(i, a) for (int i = sz(a) - 1; i >= 0; i--)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rev(i, a, b) for (int i = a; i >= b; i--)
#define reps(i, s) for (int i = 0; s[i]; i++)
#define FOR(I, A, B) for (int I = (A); I < (B); ++I)
#define REP(I, N) FOR(I, 0, N)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define countbit(x) __builtin_popcount(x)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define pi (2.0 * acos(0.0))
#define PI (2.0 * acos(0.0))
#define SET(a) memset(a, -1, sizeof a)
#define CLR(a) memset(a, 0, sizeof a)
#define set0(ar) memset(ar, 0, sizeof ar)
#define setinf(ar) memset(ar, 126, sizeof ar)
#define in(a, x, y) (a >= x && a <= y)
#define out(a, x, y) (!in(a, x, y))
#define eq(a, b) (fabs(a - b) < eps)
#define less(a, b) (a + eps < b)
#define great(a, b) (a > b + eps)
#define xx first
#define yy second

#define MAX(a) (*max_element(all(a)))
#define MIN(a) (*min_element(all(a)))

#define LB(a, x) (lower_bound(all(a), x) - a.begin())
#define UB(a, x) (upper_bound(all(a), x) - a.begin())

int ts, kk = 1;

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;

template <class T>
inline T _sq(T a)
{
	return a * a;
}
template <class T, class X>
inline T _pow(T a, X y)
{
	T z = 1;
	rep(i, 1, y)
	{
		z *= a;
	}
	return z;
}

template <class T>
inline T _extended(T a, T b, T &x, T &y)
{
	a = _abs(a);
	b = _abs(b);
	T g, x1, y1;
	if (!b)
	{
		x = 1;
		y = 0;
		g = a;
		return g;
	}
	g = _extended(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

template <class T, class X>
inline T ithroot(T x, X i)
{
	return (T)(pow((double)x, 1.0 / (double)i) + (1e-9));
}

template <class T, class X>
inline bool getbit(T a, X i)
{
	T t = 1;
	return ((a & (t << i)) > 0);
}
template <class T, class X>
inline T setbit(T a, X i)
{
	T t = 1;
	return (a | (t << i));
}
template <class T, class X>
inline T resetbit(T a, X i)
{
	T t = 1;
	return (a & (~(t << i)));
}
template <class T, class X>
inline T togglebit(T a, X i)
{
	T t = 1;
	return (a ^ (t << i));
}

template <class T, class X, class Y>
inline T bigmod(T n, X m, Y mod)
{
	ull ret = 1, a = n % mod;
	while (m)
	{
		if (m & 1)
		{
			ret = (ret * a) % mod;
		}
		m >>= 1;
		a = (a * a) % mod;
	}
	ret %= mod;
	return (T)ret;
}
template <class T, class Y>
inline T modinv(T n, Y mod)
{
	return bigmod(n, mod - 2, mod);
}

template <class T>
inline void unify(vector<T> &a)
{
	sort(all(a));
	a.erase(unique(all(a)), a.end());
}

///       //CONSTANT//        ///
///  power     01234567890123456789     ///
#define MX (200 + 5)
#define MOD 1000000007
#define inf 1000000000
#define lim 1000000000
#define LOGMX 20
#define eps 1e-9
///===========================///

int in[MX], cost[MX], sum[MX], dp[MX][MX];

string s, r;

map<string, int> mp;

vi adj[MX];

int dfs(int u)
{
	int &ret = sum[u];
	ret = 1;
	repv(i, adj[u])
	{
		ret += dfs(adj[u][i]);
	}
	return ret;
}

int go(int p, int u, int r)
{
	if (r <= 0)
	{
		return 0;
	}
	if (u >= sz(adj[p]))
	{
		return inf;
	}
	int &ret = dp[adj[p][u]][r];
	if (ret != -1)
	{
		return ret;
	}
	ret = inf;
	ret = min(ret, cost[adj[p][u]] + go(p, u + 1, r - sum[adj[p][u]]));
	rep(i, 0, r)
	{
		ret = min(ret, go(adj[p][u], 0, i) + go(p, u + 1, r - i));
	}
	return ret;
}

int main()
{
	int n, m;
	while (getline(cin, s) && s[0] != '#')
	{
		CLR(in);
		CLR(cost);
		rep(i, 0, MX - 1) adj[i].clear();
		mp.clear();
		istringstream is(s);
		is >> n >> m;
		rep(i, 1, n)
		{
			getline(cin, s);
			is.clear();
			is.str(s);
			string r;
			int y;
			ll x;
			is >> r >> x;
			if (!mp.count(r))
			{
				mp[r] = sz(mp);
			}
			y = mp[r];
			cost[y] = x;
			while (is >> r)
			{
				if (!mp.count(r))
				{
					mp[r] = sz(mp);
				}
				adj[y].pb(mp[r]);
				in[mp[r]]++;
			}
		}
		rep(i, 1, n)
		{
			if (!in[i])
			{
				dfs(i);
				adj[0].pb(i);
			}
		}
		SET(dp);
		cout << go(0, 0, m) << endl;
	}
	return 0;
}
