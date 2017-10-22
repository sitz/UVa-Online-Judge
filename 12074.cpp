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

#define INF 1000000000
#define N 100015

int cx[N], cy[N], key[N], d[N];
int dp[N], root[N << 2];

int ch[N * 70][2], maxv[N * 70];
int it;
int maX, maY, miX, miY;

void build()
{
	maxv[0] = 0;
	it = 1;
	CLR(root, 0);
}

#define lch ch[rt][0], L, mid
#define rch ch[rt][1], mid + 1, R

void push_up(int rt)
{
	maxv[rt] = max(maxv[ch[rt][0]], maxv[ch[rt][1]]);
}

void insert2(int &rt, int L, int R, int y, int v)
{
	if (!rt)
	{
		rt = it++;
		ch[rt][0] = 0;
		ch[rt][1] = 0;
		maxv[rt] = 0;
	}
	if (L == R)
	{
		maxv[rt] = max(maxv[rt], v);
		return;
	}
	int mid = L + R >> 1;
	if (y <= mid)
	{
		insert2(lch, y, v);
	}
	else
	{
		insert2(rch, y, v);
	}
	push_up(rt);
}

void insert(int rt, int L, int R, int x, int y, int val)
{
	insert2(root[rt], miY, maY, y, val);
	if (L == R)
	{
		return;
	}
	int mid = L + R >> 1;
	if (x <= mid)
	{
		insert(rt << 1, L, mid, x, y, val);
	}
	else
	{
		insert(rt << 1 | 1, mid + 1, R, x, y, val);
	}
}

int query2(int &rt, int L, int R, int y1, int y2)
{
	if (!rt)
	{
		return 0;
	}
	if (y1 <= L && R <= y2)
	{
		return maxv[rt];
	}
	int mid = L + R >> 1;
	int res = 0;
	if (y1 <= mid)
	{
		res = max(res, query2(lch, y1, y2));
	}
	if (y2 > mid)
	{
		res = max(query2(rch, y1, y2), res);
	}
	return res;
}

int query(int rt, int L, int R, int x1, int x2, int y1, int y2)
{
	if (x1 <= L && R <= x2)
	{
		return query2(root[rt], miY, maY, y1, y2);
	}
	int mid = L + R >> 1;
	int res = 0;
	if (x1 <= mid)
	{
		res = max(res, query(rt << 1, L, mid, x1, x2, y1, y2));
	}
	if (x2 > mid)
	{
		res = max(res, query(rt << 1 | 1, mid + 1, R, x1, x2, y1, y2));
	}
	return res;
}

bool cmp(const int &a, const int &b)
{
	return key[a] < key[b];
}

int idx[N];

int main()
{
	int test, n;
	scanf("%d", &test);
	FOR(cas, test)
	{
		scanf("%d", &n);
		build();
		maX = maY = -INF;
		miX = miY = INF;
		FOR(i, n)
		{
			scanf("%d%d%d%d", cx + i, cy + i, key + i, d + i);
			idx[i] = i;
			int tx = cx[i], ty = cy[i];
			cx[i] = tx - ty, cy[i] = tx + ty;
			maX = max(maX, cx[i]);
			miX = min(miX, cx[i]);
			maY = max(maY, cy[i]);
			miY = min(miY, cy[i]);
		}
		sort(idx, idx + n, cmp);
		FOR(i, n)
		{
			int id = idx[i];
			int res = query(1, miX, maX, cx[id] - d[id], cx[id] + d[id], cy[id] - d[id], cy[id] + d[id]) + 1;
			dp[id] = res;
			insert(1, miX, maX, cx[id], cy[id], dp[id]);
		}
		int res = 1;
		FOR(i, n)
		res = max(res, dp[i]);
		printf("Case %d: %d\n", cas + 1, res);
	}
	return 0;
}
