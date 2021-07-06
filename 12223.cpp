#include <bits/stdc++.h>

using namespace std;

#define esp 1e-6
#define pi acos(-1.0)
#define inf 0x0f0f0f0f
#define pb push_back
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a, b) make_pair((a), (b))
#define bit(k) (1 << (k))
#define in freopen("solve_in.txt", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);

#define bug puts("********))))))");
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
#define Rep(i, base, n) for (int i = base; i < n; i++)
#define REPS(s, i) for (int i = 0; s[i]; i++)
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

const int maxn = 50000 + 100;
VII g[maxn];
LL dp[maxn], cnt[maxn], num[maxn], Max;
int n, m;

void dfs(int u, int fa)
{
	dp[u] = 0;
	cnt[u] = num[u];
	REP(i, g[u].size())
	{
		int v = g[u][i].first;
		int d = g[u][i].second;
		if (v == fa)
		{
			continue;
		}
		dfs(v, u);
		cnt[u] += cnt[v];
		dp[u] += dp[v] + (LL)cnt[v] * d;
	}
}

void dfs1(int u, int fa)
{
	REP(i, g[u].size())
	{
		int v = g[u][i].first;
		int d = g[u][i].second;
		if (v == fa)
		{
			continue;
		}
		dp[v] += (dp[u] - dp[v] - (LL)d * cnt[v]) + (LL)d * (cnt[1] - cnt[v]);
		Max = min(Max, dp[v]);
		dfs1(v, u);
	}
}

int main()
{
	for (int T, t = scanf("%d", &T); t <= T; t++)
	{
		REP(i, maxn)
		g[i].clear(),
				cnt[i] = num[i] = 0;
		scanf("%d", &n);
		REP(i, n - 1)
		{
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			g[u].pb(mp(v, d));
			g[v].pb(mp(u, d));
		}
		scanf("%d", &m);
		REP(i, m)
		{
			int u;
			scanf("%d", &u);
			scanf("%d", &num[u]);
		}
		dfs(1, 1);
		Max = dp[1];
		dfs1(1, 1);
		int ok = 0;
		printf("%lld\n", Max * 2);
		Rep(i, 1, n + 1)
		{
			if (Max == dp[i])
			{
				if (ok)
				{
					putchar(' ');
				}
				printf("%d", i);
				ok = 1;
			}
		}
		puts("");
	}
	return 0;
}
