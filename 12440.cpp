#include <bits/stdc++.h>

using namespace std;

#define REP(a, b) for (int a = 0; a < b; a++)
#define FOR(a, b, c) for (int a = b; a <= c; a++)
#define RESET(a, b) memset(a, b, sizeof a)

#define MP make_pair
#define F first
#define S second
#define PII pair<int, int>

#define MAXN 131072

int INF = 2123123123;

struct node
{
	int val, prop;
};

int nkasus;
int n, h[MAXN], col[MAXN];
int dp[MAXN];
int pre[MAXN];
int stek[MAXN], p;
node stri[2 * MAXN];
set<int> him;

void isiPre()
{
	him.clear();
	int di = 1;
	FOR(i, 1, n)
	{
		while (him.count(col[i]))
		{
			him.erase(col[di++]);
		}
		him.insert(col[i]);
		pre[i] = di;
	}
}

void build(int nod, int ki, int ka)
{
	stri[nod].val = 0;
	stri[nod].prop = 0;
	if (ki < ka)
	{
		int tgh = (ki + ka) >> 1;
		build(2 * nod + 1, ki, tgh);
		build(2 * nod + 2, tgh + 1, ka);
	}
}

void push(int x)
{
	stri[2 * x + 1].prop += stri[x].prop;
	stri[2 * x + 2].prop += stri[x].prop;
	stri[x].prop = 0;
}

int GET(int x)
{
	return stri[x].val + stri[x].prop;
}

void update(int nod, int ki, int ka, int a, int b, int val)
{
	if ((a <= ki) && (ka <= b))
	{
		stri[nod].prop += val;
	}
	else
	{
		int tgh = (ki + ka) >> 1;
		push(nod);
		if (a <= tgh)
		{
			update(2 * nod + 1, ki, tgh, a, b, val);
		}
		if (b > tgh)
		{
			update(2 * nod + 2, tgh + 1, ka, a, b, val);
		}
		stri[nod].val = min(GET(2 * nod + 1), GET(2 * nod + 2));
	}
}

int query(int nod, int ki, int ka, int a, int b)
{
	if ((a <= ki) && (ka <= b))
	{
		return GET(nod);
	}
	else
	{
		int tgh = (ki + ka) >> 1;
		int ret = INF;
		push(nod);
		if (a <= tgh)
		{
			ret = min(ret, query(2 * nod + 1, ki, tgh, a, b));
		}
		if (b > tgh)
		{
			ret = min(ret, query(2 * nod + 2, tgh + 1, ka, a, b));
		}
		stri[nod].val = min(GET(2 * nod + 1), GET(2 * nod + 2));
		return ret;
	}
}

int main()
{
	scanf("%d", &nkasus);
	REP(jt, nkasus)
	{
		scanf("%d", &n);
		FOR(i, 1, n)
		{
			scanf("%d %d", &col[i], &h[i]);
		}
		h[0] = MAXN;
		isiPre();
		stek[0] = 0;
		p = 1;
		build(0, 1, n);
		FOR(i, 1, n)
		{
			while (h[stek[p - 1]] <= h[i])
			{
				update(0, 1, n, stek[p - 2] + 1, stek[p - 1], -h[stek[p - 1]]);
				p--;
			}
			stek[p++] = i;
			update(0, 1, n, stek[p - 2] + 1, stek[p - 1], h[i]);
			dp[i] = query(0, 1, n, pre[i], i);
			update(0, 1, n, i + 1, i + 1, dp[i]);
		}
		printf("Case %d: %d\n", jt + 1, dp[n]);
	}
	return 0;
}
