#include <bits/stdc++.h>

using namespace std;

/** 10973 - Triangle Counting
Each triangle can be uniquely identified with an ordered triple (x,y,z), in which x < y < z.

An algorithm with running time O(VE) (where V is the number of vertices, and E is the number of edges) for enumerating all triangles is presented below. The algorithm uses adjacency lists to represent the graph. As an optimization, it stores the graph as a set of directed edges (x,y), in which x < y.

for x=1..n, adj[x] is the set: { y: y>x and (x,y) is in E }.
flag[1..n] is a boolean array, with all elements initialized to 'false'
count = 0

for x = 1 to n:
    for each y in adj[x]:
        flag[y] = true
        for each y in adj[x]:
            for each z in adj[y]:
                if flag[z] then:
                    #yield (x,y,z)
                    count++
    for each y in adj[x]:
        flag[y] = false
*/

#define _USE_MATH_DEFINES// exposes constants M_PI
#define s(n) scanf("%d", &n)
#define sl(n) scanf("%lld", &n)
#define sf(n) scanf("%lf", &n)
#define ss(n) scanf("%s", n)
#define INF (1 << 30)
#define LINF (long long)1E18
#define EPS std::numeric_limits<double>::epsilon()
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = (a)-1, _b(b); i >= _b; --i)
#define REP(i, n) for ((i) = 0; (i) < (int)(n); ++(i))
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
#define FILL(a, v) memset(a, v, sizeof(a))
#define SQR(a) ((a) * (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ALL(x) x.begin(), x.end()
#define SZ(v) ((int)(v.size()))
#define LOG(a) (cerr << "line#" << __LINE__ << ": " #a " = " << (a) << endl)
#define DBG(...) (__VA_ARGS__)
#define debug(args...) \
	{                    \
		cerr << "case#";   \
		dbg, args;         \
		cerr << endl;      \
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
template <class T>
T gcd(T a, T b)
{
	return b ? gcd(b, a % b) : a;
}
typedef long long LL;
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
//typedef complex<double> pt;
//typedef complex<LL>     pti;
const double PI = 3.1415926535897932384626433832795 /*2*acos(0.0)*/;
const float PI_F = 3.14159265358979f;
double round(double x)
{
	const double sd = 100;//for accuracy to 2 decimal places
	return int(x * sd + (x < 0 ? -0.5 : 0.5)) / sd;
}
/////////////////////////////////////////////////////////////////////////////
#define MAXN 3001
vector<int> node[MAXN];
vector<int>::const_iterator p1, p2;
bool flag[MAXN];
int t, N, M, u, v, i, src, dst, the_count;

int main()
{
	scanf("%d\n", &t);// #testcases
	while (t--)
	{
		scanf("%d %d\n", &N, &M);// vertices,edges
		while (M--)
		{
			scanf("%d %d\n", &u, &v);// u->v
			src = min(u, v);
			dst = max(u, v);
			node[src].push_back(dst);
		}
		the_count = 0;
		for (i = 0; i < N; ++i)
		{
			for (p1 = node[i].begin(); p1 < node[i].end(); ++p1)
			{
				flag[*p1] = true;
			}
			for (p1 = node[i].begin(); p1 < node[i].end(); ++p1)
			{
				for (p2 = node[*p1].begin(); p2 < node[*p1].end(); ++p2)
				{
					if (flag[*p2])
					{
						the_count++;
					}
				}
			}
			for (p1 = node[i].begin(); p1 < node[i].end(); ++p1)
			{
				flag[*p1] = false;
			}
		}
		printf("%d\n", the_count);
		// reset state
		memset(flag, false, MAXN);
		for (i = 0; i < MAXN; ++i)
		{
			node[i].clear();
		}
	}
	return 0;
}
