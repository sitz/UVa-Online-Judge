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
#define root 1

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
//template< class T > inline T _gcd(T a,T b) {a=_abs(a);b=_abs(b); if(!b) return a; return _gcd(b,a%b);}
//template< class T > inline T _lcm(T a,T b) {a=_abs(a);b=_abs(b); return (a/_gcd(a,b))*b;}

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
#define MX (32767 + 10)
#define MOD 1000000007
#define inf 1000000000
#define lim 4000100
#define LOGMX 20
#define eps 1e-8
///===========================///

int n;

vector<string> s;
vi f;

bool isconst[300];

bool chk1()
{
	for (int i = 0; i + 6 - 1 < sz(s.back()); i++)
	{
		int cnt = 0;
		rep(j, 0, 5)
		{
			cnt += isconst[s.back()[i + j]];
		}
		if (cnt == 6)
		{
			return false;
		}
	}
	return true;
}
bool chk2()
{
	for (int i = 0; i + 5 - 1 < sz(s.back()); i++)
	{
		int cnt = 0;
		rep(j, 0, 4)
		{
			cnt += isconst[s.back()[i + j]];
		}
		if (cnt == 5)
		{
			f.pb(1);
			break;
		}
	}
	if (sz(f) != sz(s))
	{
		f.pb(0);
	}
	int cnt = 0;
	if (f.back())
	{
		for (int i = sz(f) - 2, j = 0; i >= 0 && j < 10; i--, j++)
		{
			cnt += f[i];
			if (cnt > 2)
			{
				break;
			}
		}
	}
	if (cnt > 2)
	{
		return false;
	}
	return true;
}

bool chk3()
{
	int cnt = 0;
	for (int i = sz(s) - 2, j = 0; i >= 0 && j < 10; i--, j++)
	{
		cnt += s.back() == s[i];
		if (cnt > 1)
		{
			break;
		}
	}
	if (cnt > 1)
	{
		return false;
	}
	return true;
}

int main()
{
	rep(x, 'a', 'z')
	{
		isconst[x - 'a' + 'A'] = isconst[x] = !(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y');
	}
	while (~scanf("%d", &n))
	{
		s.clear();
		f.clear();
		getchar();
		rep(i, 0, n - 1)
		{
			string r;
			getline(cin, r);
			s.pb(r);
			bool a = chk1(), b = chk2(), c = chk3();
			if (a && b && c)
			{
				puts("y");
			}
			else
			{
				puts("n");
			}
		}
	}
}
