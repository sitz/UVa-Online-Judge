#include <bits/stdc++.h>

using namespace std;

#define maxim 100
#define LLD long long unsigned
#define LLU long long unsigned
#define HD short int
#define HU short unsigned
#define pi acos(-1.0)
#define inf (1 << 29)
#define CLR(a) memset(a, 0, sizeof(a))
#define SET(a) memset(a, -1, sizeof(a))
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define eps 1e-9
#define rep(i, init, n) for (i = init; i < n; i++)
#define rem(i, init, n) for (i = init; i > n; i--)
#define foreach(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define _abs(a) ((a) < 0 ? (-(a)) : (a))
#define area(x1, y1, x2, y2, x3, y3) (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2))
#define sqr(x) ((x) * (x))
#define distSqr(x1, y1, x2, y2) (sqr(x1 - x2) + sqr(y1 - y2))
#define spDist(lat1, long1, lat2, long2, r) (r * acos(sin(lat1) * sin(lat2) + cos(lat1) * cos(lat2) * cos(long1 - long2)))
#define isEq(a, b) (fabs(a - b) < eps)
#define STR string
#define LF double
#define IT iterator
#define VI vector<int>
#define VLLD vector<LLD>
#define VS vector<STR>
#define VLF vector<LF>
#define MII map<int, int>
#define MIB map<int, bool>
#define MSI map<STR, int>
#define MSB map<STR, bool>
#define MSS map<STR, STR>
#define M2dII map<int, map<int, int>>
#define QI queue<int>
#define SI stack<int>
#define PII pair<int, int>
#define PPI pair<PII, int>
#define ff first
#define ss second
#define VPII vector<PII>
#define MP make_pair
#define chk(a, k) ((bool)(a & (1 << (k))))
#define set0(a, k) (a & (~(1 << (k))))
#define set1(a, k) (a | (1 << (k)))
#define chkA(a, k) (bool)(a[(k) >> 5] & (1 << ((k)&31)))
#define setA0(a, k) (a[(k) >> 5] &= ~(1 << ((k)&31)))
#define setA1(a, k) (a[(k) >> 5] |= (1 << ((k)&31)))
#define SD(a) scanf("%d", &a)
#define SU(a) scanf("%u", &a)
#define SHD(a) scanf("%hd", &a)
#define SHU(a) scanf("%hu", &a)
#define SF(a) scanf("%f", &a)
#define SLF(a) scanf("%lf", &a)
#define SC(a) scanf("%c", &a)
#define SS(a) scanf("%s", a)
int diru[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dirv[] = {-1, 0, 1, -1, 1, -1, 0, 1};
using namespace std;
#define DEB(args...) \
	{                  \
		dbg, args;       \
		cerr << endl;    \
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
T sq(T n) { return n * n; }
template <class T>
T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a % b) : a); }
template <class T>
T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template <class T>
bool inside(T a, T b, T c) { return a <= b && b <= c; }
template <class T>
void setmax(T &a, T b)
{
	if (a < b)
		a = b;
}
template <class T>
void setmin(T &a, T b)
{
	if (b < a)
		a = b;
}
template <class T>
T power(T N, T P) { return (P == 0) ? 1 : N * power(N, P - 1); }
vector<PII> G[20][20];
char clr[20][20];
char in[20][20];
int freq[30];
int cnt;
void dfs(int i, int j)
{
	cnt++;
	freq[in[i][j] - '0']++;
	clr[i][j] = 1;
	int k, a, b;
	rep(k, 0, sz(G[i][j]))
	{
		a = G[i][j][k].ff;
		b = G[i][j][k].ss;
		if (clr[a][b])
			continue;
		dfs(a, b);
	}
}

int main()
{
	int r, c, n, T, t = 1, m, i, j, k, l, val, x, y, a, b;
	SD(T);
	rep(t, 1, T + 1)
	{
		SD(r);
		SD(c);
		rep(i, 0, r)
				SS(in[i]);
		rep(i, 0, r)
				rep(j, 0, c)
						G[i][j]
								.clear();
		rep(i, 0, r)
				rep(j, 0, c)
		{
			SD(m);
			if (m & 1)
				G[i][j].pb(PII(i - 1, j));
			if (m & 2)
				G[i][j].pb(PII(i, j + 1));
			if (m & 4)
				G[i][j].pb(PII(i + 1, j));
			if (m & 8)
				G[i][j].pb(PII(i, j - 1));
		}
		CLR(clr);
		bool ans = 1;
		rep(i, 0, r)
				rep(j, 0, c)
		{
			if (clr[i][j])
				continue;
			cnt = 0;
			CLR(freq);
			dfs(i, j);
			rep(k, 1, cnt + 1) if (freq[k] != 1)
					ans = 0;
		}
		rep(i, 0, r)
		{
			SET(freq);
			rep(j, 0, c)
			{
				if (freq[in[i][j] - '0'] != -1 && j - freq[in[i][j] - '0'] - 1 < in[i][j] - '0')
					ans = 0;
				freq[in[i][j] - '0'] = j;
			}
		}
		rep(j, 0, c)
		{
			SET(freq);
			rep(i, 0, r)
			{
				if (freq[in[i][j] - '0'] != -1 && i - freq[in[i][j] - '0'] - 1 < in[i][j] - '0')
					ans = 0;
				freq[in[i][j] - '0'] = i;
			}
		}
		if (ans)
			puts("valid");
		else
			puts("invalid");
	}
	return 0;
}
