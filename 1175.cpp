#include <bits/stdc++.h>

using namespace std;

//Template updates date: 20140718
#define esp 1e-6
#define inf 0x3f3f3f3f
#define pi acos(-1.0)
#define pb push_back
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a, b) make_pair((a), (b))
#define bit(k) (1 << (k))
#define iin freopen("pow.in", "r", stdin);
#define oout freopen("pow.out", "w", stdout);
#define in freopen("solve_in.txt", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);
#define bug puts("********))))))");
#define Inout iin oout
#define inout in out

#define SET(a, v) memset(a, (v), sizeof(a))
#define SORT(a) sort((a).begin(), (a).end())
#define REV(a) reverse((a).begin(), (a).end())
#define READ(a, n)     \
	{                    \
		REP(i, n)          \
				cin >> (a)[i]; \
	}
#define REP(i, n) for (int i = 0; i < (n); i++)
#define VREP(i, n, base) for (int i = (n); i >= (base); i--)
#define Rep(i, base, n) for (int i = (base); i < (n); i++)
#define REPS(s, i) for (int i = 0; (s)[i]; i++)
#define pf(x) ((x) * (x))
#define mod(n) ((n))
#define Log(a, b) (log((double)b) / log((double)a))
#define Srand() srand((int)time(0))
#define random(number) (rand() % number)
#define random_range(a, b) (int)(((double)rand() / RAND_MAX) * (b - a) + a)

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;
typedef vector<PII, int> VIII;
typedef VI::iterator IT;
typedef map<string, int> Mps;
typedef map<int, int> Mpi;
typedef map<int, PII> Mpii;
typedef map<PII, int> Mpiii;

const int maxn = 1100;
int n;
int mav[maxn][maxn], wa[maxn][maxn], ma[maxn][maxn];
int ii, link[maxn], st[maxn], vv[maxn], r[maxn], wife[maxn];
struct cmp
{
	bool operator()(const int &a, const int &b)
	{
		return vv[a] > vv[b];
	}
};
void solve()
{
	int inq[maxn];
	queue<int> q;
	VREP(i, n, 1)
	q.push(i), inq[i] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		inq[u] = 0;
		for (st[u]++; st[u] <= n; st[u]++)
		{
			int v = ma[u][st[u]];
			if (link[v] == 0 || wa[v][link[v]] > wa[v][u])
			{
				if (link[v] && !inq[link[v]])
				{
					q.push(link[v]), inq[link[v]] = 1;
				}
				link[v] = u;
				wife[u] = v;
				break;
			}
		}
	}
}
int main()
{
	int T;
	Rep(t, scanf("%d", &T), T + 1)
	{
		if (t != 1)
		{
			puts("");
		}
		int tmp;
		SET(st, 0);
		SET(link, 0);
		Rep(i, scanf("%d", &n), n + 1)
				Rep(j, 1, n + 1) scanf("%d", &ma[i][j]);
		for (int i = 1; i <= n; i++)
			Rep(j, 1, n + 1)
					scanf("%d", &tmp),
					wa[i][tmp] = j;
		solve();
		Rep(i, 1, n + 1)
				printf("%d\n", wife[i]);
	}
	return 0;
}
