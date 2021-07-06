#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
typedef long long ll;
const int N = 1000001;

int table[61];
void init_P(int n, ll *in)
{
	int i, j;
	table[0] = -1;
	for (i = 0, j = -1; i < n; i++, j++, table[i] = j)
	{
		while (j >= 0 && in[i] != in[j])
		{
			j = table[j];
		}
	}
	//table[i]=j;
}

int solve(ll *in, int pat, int n, ll *p, ll *q)
{
	int ans = 0;
	int i = 0, j = 0;
	while (i < n && j < pat)
	{
		while (j >= 0 && !(p[i] <= in[j] && in[j] <= q[i]))
		{
			j = table[j];
		}
		i++;
		j++;
		if (j == pat)
		{
			ans++;
			j = table[j];
			j = pat - 1;
		}
	}
	return ans;
}

void generate(ll p0, ll q0, ll A, ll B, ll C, ll D, ll E, ll F, ll M,
							ll *p, ll *q, int n)
{
	ll pprev = p0, qprev = q0;
	rep(i, n)
	{
		p[i] = (A * pprev + B * qprev + C) % M;
		q[i] = (D * pprev + E * qprev + F) % M;
		if (q[i] < p[i])
		{
			swap(p[i], q[i]);
		}
		pprev = p[i];
		qprev = q[i];
	}
}

ll p[N], q[N];
main()
{
	int te, tc = 1;
	cin >> te;
	while (te--)
	{
		int pnum;
		cin >> pnum;
		ll pat[pnum];
		rep(i, pnum) cin >> pat[i];
		int n;
		ll p0, q0, a, b, c, d, e, f, m;
		cin >> n >> p0 >> q0 >> a >> b >> c >> d >> e >> f >> m;
		generate(p0, q0, a, b, c, d, e, f, m, p, q, n);
		init_P(pnum, pat);
		printf("Case %d: %d\n", tc++, solve(pat, pnum, n, p, q));
	}
}
