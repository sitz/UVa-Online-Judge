#include <bits/stdc++.h>

using namespace std;

//Template updates date: 20140316
#define esp 1e-6
#define pi acos(-1.0)
#define inf 0x0f0f0f0f
#define pb push_back
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a, b) make_pair((a), (b))
#define bit(k) (1 << (k))
#define in freopen("in.txt", "r", stdin);
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

const int maxn = 110;
const int maxm = 50000 + 100;
long dp[maxn][maxm];
Mpi M;

struct NODE
{
	char s[10];
	int cap;
	long pri[maxn];
} name[10];

struct Transition
{
	int from;
	int to;
	int buy;
	int sell;
	Transition() {}
	Transition(int from, int to, int buy, int sell) : from(from), to(to), buy(buy), sell(sell) {}
	long cost(int days)
	{
		return (buy >= 0 ? name[buy].pri[days] : 0) +
					 (sell >= 0 ? -name[sell].pri[days] : 0);
	}
	void toString()
	{
		if (buy >= 0)
		{
			printf("BUY %s\n", name[buy].s);
		}
		else if (sell >= 0)
		{
			printf("SELL %s\n", name[sell].s);
		}
		else
		{
			puts("HOLD");
		}
	}
} by[maxn][maxm];

vector<Transition> transition;
long c;
int n, m, kk, lastcode;

int encode(int Count[])
{
	int code = 0;
	REP(i, n)
	code = code * (kk + 1) + Count[i];
	if (!M.count(code))
	{
		M[code] = lastcode++;
	}
	return M[code];
}

int Generate(int Count[], int c)
{
	int code = encode(Count);
	if (code == lastcode - 1)
	{
		transition.pb(Transition(code, code, -1, -1));
		REP(i, n)
		{
			if (Count[i] < name[i].cap && c < kk)
			{
				Count[i]++;
				int tcode = Generate(Count, c + 1);
				Count[i]--;
				transition.pb(Transition(code, tcode, i, -1));
			}
			if (Count[i] > 0)
			{
				Count[i]--;
				int tcode = Generate(Count, c - 1);
				transition.pb(Transition(code, tcode, -1, i));
				Count[i]++;
			}
		}
	}
	return code;
}
void print_ans(int s, int st)
{
	if (s > 1)
	{
		print_ans(s - 1, by[s][st].from);
	}
	by[s][st].toString();
}
void solve()
{
	int Count[10];
	SET(Count, 0);
	int root = Generate(Count, 0);
	SET(dp, -1);
	dp[0][root] = c;
	for (int i = 0; i < m; i++)
	{
		REP(j, (int)transition.size())
		{
			int from = transition[j].from;
			int to = transition[j].to;
			if (dp[i][from] >= 0)
			{
				long Cost = dp[i][from] - transition[j].cost(i);
				if (Cost > dp[i + 1][to])
				{
					dp[i + 1][to] = Cost;
					by[i + 1][to] = transition[j];
				}
			}
		}
	}
	printf("%.2f\n", (double)dp[m][root] / 10000);
	print_ans(m, root);
}

int main()
{
	int kase = 1;
	double tmp;
	while (scanf("%lf%d%d%d", &tmp, &m, &n, &kk) != EOF)
	{
		if (kase != 1)
		{
			puts("");
		}
		kase++;
		transition.clear();
		M.clear();
		lastcode = 0;
		c = (long)(tmp * 10000);
		REP(i, n)
		{
			int size;
			scanf("%s%d%d", name[i].s, &size, &name[i].cap);
			REP(j, m)
			{
				scanf("%lf", &tmp);
				name[i].pri[j] = (long)(tmp * 10000 * size);
			}
		}
		solve();
	}
	return 0;
}
