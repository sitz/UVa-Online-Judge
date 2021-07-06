#include <bits/stdc++.h>

using namespace std;

inline int readint()
{
	char c = getchar();
	while (!isdigit(c))
	{
		c = getchar();
	}
	int x = 0;
	while (isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

inline long long readlong()
{
	char c = getchar();
	while (!isdigit(c))
	{
		c = getchar();
	}
	long long x = 0;
	while (isdigit(c))
	{
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

#define FOR(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define CIR(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define ADJ(i, u) for (int i = hd[u]; i != -1; i = edge[i].nxt)
#define ECH(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++i)
#define PII pair<int, int>
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(v) v.size()
#define ALL(v) v.begin(), v.end()
#define CLR(v, a) memset(v, a, sizeof(v))
#define IT iterator
#define LL long long
#define DB double
#define PI 3.1415926

//#pragma comment(linker,"/STACK:102400000,102400000")
#define INF 1000000000
#define N 10005
#define M N * 100
#define C 26

char ss[M];
int maxv[M << 2];
int upv[M << 2];
int Map[256];
int dp[N], idx[N], len[N], pos[N];
int tot;

void init()
{
	FOR(i, 26)
	{
		Map[i + 'a'] = i;
	}
}

#define lch rt << 1, L, mid
#define rch rt << 1 | 1, mid + 1, R

void build(int rt, int L, int R)
{
	upv[rt] = -INF;
	maxv[rt] = -INF;
	if (L == R)
	{
		return;
	}
	int mid = L + R >> 1;
	build(lch);
	build(rch);
}

void push_down(int rt, int L, int R)
{
	if (upv[rt] != -INF)
	{
		int v = upv[rt];
		upv[rt] = -INF;
		upv[rt << 1] = max(upv[rt << 1], v);
		upv[rt << 1 | 1] = max(upv[rt << 1 | 1], v);
		maxv[rt << 1] = max(maxv[rt << 1], v);
		maxv[rt << 1 | 1] = max(maxv[rt << 1 | 1], v);
	}
}

void update(int rt, int L, int R, int l, int r, int v)
{
	if (l <= L && R <= r)
	{
		maxv[rt] = max(maxv[rt], v);
		upv[rt] = max(upv[rt], v);
		return;
	}
	int mid = L + R >> 1;
	push_down(rt, L, R);
	if (l <= mid)
	{
		update(lch, l, r, v);
	}
	if (r > mid)
	{
		update(rch, l, r, v);
	}
}

int query(int rt, int L, int R, int p)
{
	if (L == p && R == p)
	{
		return maxv[rt];
	}
	int mid = L + R >> 1;
	push_down(rt, L, R);
	if (p <= mid)
	{
		return query(lch, p);
	}
	else
	{
		return query(rch, p);
	}
}

struct AC
{
	int ch[M][C];
	int ff[M];
	int it;
	queue<int> Q;
	vector<int> G[M];
	int tdfn, st[M], ed[M];

	void init()
	{
		CLR(ch[0], 0);
		FOR(i, it)
		G[i].clear();
		it = 1;
		tdfn = 1;
	}

	void insert(char *ss, int len)
	{
		int cur = 0;
		FOR(i, len)
		{
			int c = Map[ss[i]];
			if (!ch[cur][c])
			{
				ch[cur][c] = it;
				CLR(ch[it], 0);
				ff[it] = 0;
				it++;
			}
			cur = ch[cur][c];
		}
	}

	void set_fail()
	{
		ff[0] = 0;
		FOR(i, C)
		{
			int u = ch[0][i];
			if (u)
			{
				ff[u] = 0;
				Q.push(u);
				G[0].PB(u);
			}
		}
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			FOR(i, C)
			{
				int v = ch[u][i];
				if (!v)
				{
					ch[u][i] = ch[ff[u]][i];
				}
				else
				{
					Q.push(v);
					int fa = ff[u];
					while (fa && !ch[fa][i])
					{
						fa = ff[fa];
					}
					ff[v] = ch[fa][i];
					G[ff[v]].PB(v);
				}
			}
		}
	}

	void dfs(int u)
	{
		st[u] = tdfn++;
		for (int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];
			dfs(v);
		}
		ed[u] = tdfn - 1;
	}

	void solve(int id)
	{
		int key = -INF, cur = 0;
		for (int i = 0; i < len[id]; i++)
		{
			int j = i + pos[id];
			int c = Map[ss[j]];
			cur = ch[cur][c];
			key = max(key, query(1, 1, tot, st[cur]));
		}
		dp[id] = 1;
		if (key > 0)
		{
			dp[id] += key;
		}
		update(1, 1, tot, st[cur], ed[cur], dp[id]);
	}

} ac;

bool cmp(const int &a, const int &b)
{
	return len[a] < len[b];
}

int main()
{
	init();
	int n;
	while (scanf("%d", &n))
	{
		if (n == 0)
		{
			break;
		}
		int rt = 0;
		ac.init();
		REP(i, 1, n)
		{
			scanf("%s", ss + rt);
			pos[i] = rt;
			len[i] = strlen(ss + rt);
			ac.insert(ss + rt, len[i]);
			rt += len[i];
		}
		ac.set_fail();
		ac.dfs(0);
		REP(i, 1, n)
		idx[i] = i;
		sort(idx + 1, idx + n + 1, cmp);
		tot = ac.tdfn - 1;
		build(1, 1, tot);
		REP(i, 1, n)
		{
			ac.solve(idx[i]);
		}
		int res = 0;
		REP(i, 1, n)
		{
			res = max(res, dp[i]);
		}
		printf("%d\n", res);
	}
	return 0;
}
