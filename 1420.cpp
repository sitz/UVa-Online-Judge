#include <bits/stdc++.h>

using namespace std;

//BISMILLAHIRRAHMANIRRAHIM
/*
 manus tar shopner soman boro
 Author :: Shakil Ahmed
.............AUST_CSE27.........
 prob   ::
 Type   ::
 verdict::
 */

#define pf(a) printf("%d\n", a)
#define pf2(a, b) printf("%d %d\n", a, b)
#define pfcs(cs, a) printf("Case %d: %d\n", cs, a)
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define pb push_back
#define mp make_pair
#define pi acos(-1.0)
#define ff first
#define LL long long
#define ss second
#define rep(i, n) for (i = 0; i < n; i++)
#define REP(i, n) for (i = n; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define ROF(i, a, b) for (int i = a; i >= b; i--)
#define re return
#define QI queue<int>
#define SI stack<int>
#define pii pair<int, int>
#define MAX
#define MOD
#define INF 1 << 30
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define memo(a, b) memset((a), (b), sizeof(a))
#define G() getchar()
#define MAX3(a, b, c) max(a, max(b, c))

double const EPS = 3e-8;

template <class T>
T gcd(T a, T b)
{
	return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b)
{
	return (a / gcd<T>(a, b) * b);
}

const int N = 100005;
struct abc
{
	LL s, t, time;
} inp[2 * N];
bool cmp(abc a, abc b)
{
	return a.time < b.time;
}
int main()
{
	int n, i;
	while (scanf("%d", &n) && n)
	{
		int idx = 0;
		LL s, t;
		rep(idx, n)
		{
			scanf("%lld %lld", &inp[idx].s, &inp[idx].t);
			inp[idx].time = inp[idx].s + (inp[idx].t - inp[idx].s) / 2 + 1;
		}
		int cnt = 0, mx = -1;
		sort(inp, inp + n, cmp);
		LL tmp = -1;
		rep(i, idx)
		{
			tmp = max(tmp, inp[i].s) + (inp[i].t - inp[i].s) / 2 + 1;
			if (tmp > inp[i].t)
			{
				break;
			}
		}
		if (i < idx)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}
