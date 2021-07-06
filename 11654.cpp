#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES// exposes constants, eg. M_PI
#define S(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SD(n) scanf("%lf", &n)
#define SS(n) scanf("%s", n)
#define INF INT_MAX
#define LINF LLONG_MAX
#define EPS std::numeric_limits<double>::epsilon()
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = (a)-1, _b(b); i >= _b; --i)
#define REP(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define RREP(i, n) for (int(i) = n; (i) >= (int)0; --(i))
#define DREP(a) \
	sort(all(a)); \
	a.erase(unique(all(a)), a.end())
#define INDEX(arr, ind) (lower_bound(all(arr), ind) - arr.begin())
#define FOREACH(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
#define mp make_pair
#define pb push_back
#define tri(a, b, c) mp(a, mp(b, c))
#define fst first
#define snd second
//#define FILL(a,v)           memset(a,v,sizeof(a))
#define SQT(a) ((a) * (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALL(x) x.begin(), x.end()
#define SZ(v) ((int)(v.size()))
#define LOG(a) (cerr << "\tline#" << __LINE__ << ": " #a " = " << (a) << endl)
#define DBG(args...)                       \
	{                                        \
		cerr << "\tcase#" << (cc + 1) << ": "; \
		dbg, args;                             \
		cerr << endl;                          \
	}
struct debugger
{
	template <typename T>
	debugger &operator,(const T &v)
	{
		cerr << v << " ";
		return *this;
	}
} dbg;
typedef long long LL;
typedef long long ll;
typedef unsigned long long ULL;
typedef unsigned int uint;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<PLL> VLL;
typedef vector<TRI> VT;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VII> VVII;
typedef vector<VLL> VVLL;
typedef vector<VT> VVT;
typedef complex<double> pt;
typedef complex<LL> pti;
const double PI = M_PI;
template <class T>
inline T gcd(T a, T b)
{
	return b ? gcd(b, a % b) : a;
}
inline double round(double x)
{
	const double sd = 100;// accuracy = 2 dp
	return int(x * sd + (x < 0 ? -0.5 : 0.5)) / sd;
}
inline int cmp(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
template <typename T>
inline void print(T *array, int size)
{
	printf("\tarray[] = [");
	for (int i = 0; i < size; ++i)
	{
		printf("%lld", (LL)array[i]);
		if (i < size - 1)
		{
			printf(" ");
		}
	}
	printf("]\n");
}
template <typename T>
inline void print(T **array, int size1, int size2)
{
	printf("\tarray[][] = [");
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			printf("%lld", (LL)array[i][j]);
			if (j < size2 - 1)
			{
				printf(" ");
			}
		}
		printf("]\n");
	}
}
/////////////////////////////////////////////////////////////////////////////
const int MOD = 10000007;
const int MAXN = 252;
int T, n;
LL v[MAXN];

int main()
{
	//clock_t start = clock();
	scanf("%d", &T);
	REP(cc, T)
	{
		scanf("%d", &n);
		memset(v, 0, MAXN);
		REP(i, n)
		{
			scanf("%lld", &v[i]);
		}
		map<pair<ll, ll>, ll> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				ll diff = v[i] - v[j];
				pair<ll, ll> ii1 = make_pair(j, diff);
				pair<ll, ll> ii = make_pair(i, diff);
				if (m.count(ii1))
				{
					m[ii] += 1 + m[ii1], m[ii] %= MOD;
				}
				else
				{
					m[ii]++;
				}
			}
		}
		ll ans = n;
		map<pair<ll, ll>, ll>::iterator it;
		for (it = m.begin(); it != m.end(); it++)
		{
			ans += it->second;
			ans %= MOD;
		}
		printf("Case %d: %lld\n", cc + 1, ans);
	}
	//fprintf(stderr, "*** Total time: %.3lf seconds ***\n",
	//        ((clock() - start) / (double) CLOCKS_PER_SEC));
	return 0;
}
