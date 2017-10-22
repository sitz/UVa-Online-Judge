#include <bits/stdc++.h>

using namespace std;

#define dou double
#define mem(a) memset(a, 0, sizeof(a))
#define memm(a) memset(a, -1, sizeof(a))
#define LL long long
#define PB push_back
#define MP make_pair
#define PII pair<int, string>
#define FI first
#define SE second
#define SZ(a) ((int)a.size())
#define ALL(a) a.begin(), a.end()
#define RI(a) scanf("%d", &(a))
#define RII(a, b) scanf("%d%d", &(a), &(b))
#define RIII(a, b, c) scanf("%d%d%d", &(a), &(b), &(c))
#define RL(a) scanf("%lld", &(a))
#define RLL(a, b) scanf("%lld%lld", &(a), &(b))
#define RLLL(a, b, c) scanf("%lld%lld%lld", &(a), &(b), &(c))
#define PI(r) printf("%d\n", (r))
#define PL(r) printf("%lld\n", (r))
#define RS(s) scanf("%s", (s))
#define SL(a) strlen(a)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REPP(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define FOR(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define MID ((l + r) >> 1)
#define L (x << 1)
#define R ((x << 1) | 1)
#define LC L, l, MID
#define RC R, MID + 1, r
#define LB(x) ((x) & (-(x)))
#pragma warning(disable : 4996)
//#pragma comment(linker, "/STACK:102400000,102400000")
#define EPS 1e-8
#define INF 0x3f3f3f3f
#define LIM (1ll << 60)
#define MOD 1000000007
#define N 111111

int n, m;
const int ha = 1313131;
int len, tot;
vector<int> e[111];
char s[1111];

int build(int &x)
{
	int now = ++tot;
	if (s[x] == '[')
	{
		x++;
	}
	while (x < len)
	{
		if (s[x] == '[')
		{
			e[now].push_back(build(x));
		}
		else if (s[x] == ']')
		{
			return now;
		}
		x++;
	}
	return 0;
}

bool match(int x, int n, vector<string> &tmp)
{
	REP(i, n / x)
	{
		REP(j, x)
		{
			if (tmp[i * x + j] != tmp[j])
			{
				return 0;
			}
		}
	}
	return 1;
}

int qp(int x, int y)
{
	int re = 1;
	while (y)
	{
		if (y & 1)
		{
			re = 1ll * re * x % MOD;
		}
		y >>= 1;
		x = 1ll * x * x % MOD;
	}
	return re;
}

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : x;
}

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
	{
		x -= MOD;
	}
}

int cal(int n, int col)
{
	int re = 0;
	REPP(i, 1, n)
	add(re, qp(col, gcd(n, i)));
	re = 1ll * re * qp(n, MOD - 2) % MOD;
	return re;
}

PII dfs(int x)
{
	if (SZ(e[x]) == 0)
	{
		return MP(m, (string) "()");
	}
	else
	{
		vector<string> tmp;
		vector<int> dp;
		string ss;
		int n = SZ(e[x]);
		REP(i, n)
		{
			PII tt = dfs(e[x][i]);
			tmp.push_back(tt.second);
			dp.push_back(tt.first);
		}
		int tt = 0;
		for (int i = 1; i < n; ++i)
		{
			if (n % i == 0)
			{
				if (match(i, n, tmp))
				{
					tt = i;
					break;
				}
			}
		}
		sort(ALL(tmp));
		REP(i, SZ(tmp))
		ss += tmp[i];
		ss = '(' + ss + ')';
		if (tt == 0)
		{
			tt = n;
		}
		int cnt = n / tt, col = 1;
		REP(i, tt)
		col = 1ll * col * dp[i] % MOD;
		return MP(1ll * m * cal(cnt, col) % MOD, ss);
	}
}

int main()
{
	//freopen("D:/Contest/1.in", "r", stdin);
	//freopen("1.ans", "w", stdout);
	//ios :: sync_with_stdio(false);
	int t, x, y, z, ca = 1;
	RI(t);
	while (t--)
	{
		scanf("%s %d", s, &m);
		len = SL(s), tot = 0;
		int now = 0;
		build(now);
		printf("Case #%d: %d\n", ca++, dfs(1).first);
		REPP(i, 1, tot)
		e[i].clear();
	}
	return 0;
}
