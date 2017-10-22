#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (__typeof(b) i = (a); i <= (b); i++)
#define FORD(i, a, b) for (__typeof(a) i = (a); i >= (b); i--)
#define FORIT(i, m) for (__typeof((m).begin()) i = (m).begin(); i != (m).end(); ++i)
#define SET(t, v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define REV(x) reverse(ALL(x))
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())

#define sz size()
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define i64 long long
#define LL i64
#define LD long double

#define D(x) \
	if (1)     \
	cerr << __LINE__ << " " << #x " = " << x << endl
#define D2(x, y) \
	if (1)         \
	cerr << __LINE__ << " " << #x " = " << x << ", " << #y " = " << y << endl

typedef pair<int, i64> pii;
#define M 100005

pii m[M];
int n, k;
i64 p[M], w[M], sum[M];

pii f(int x)
{
	if (x == n + 1)
	{
		return pii(0, 0);
	}
	pii &ret = m[x];
	if (ret.first != -1)
	{
		return ret;
	}
	ret.first = 1 << 20;
	int lim = min(x + k - 1, n);
	int st = x;
	i64 cost = 0;
	FOR(i, x, lim)
	{
		// updating the current cost
		cost += (p[i] - p[st]) * w[i];
		// move the position of least cost
		while (st < i)
		{
			i64 newcost = cost + (sum[st] - sum[x - 1]) * (p[st + 1] - p[st]) - (sum[i] - sum[st]) * (p[st + 1] - p[st]);
			if (newcost < cost)
			{
				cost = newcost, st++;
			}
			else
			{
				break;
			}
		}
		// try to recurse and get a better solution
		pii t = f(i + 1);
		t.first++, t.second += cost;
		if (t < ret)
		{
			ret = t;
		}
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &n, &k);
		FOR(i, 1, n)
		scanf("%lld %lld", &p[i], &w[i]);
		REP(i, n + 1)
		m[i].first = -1;
		sum[0] = 0;
		FOR(i, 1, n)
		sum[i] = sum[i - 1] + w[i];
		FORD(i, n, 1)
		f(i);
		pii ans = f(1);
		printf("%d %lld\n", ans.first, ans.second);
	}
	return 0;
}
