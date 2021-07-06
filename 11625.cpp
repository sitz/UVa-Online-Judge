#include <bits/stdc++.h>

using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long ll;

const ll MOD = 1000000007;

int K;

struct mat
{
	ll m[101][101];
	mat()
	{
		REP(a, 0, K + 1)
		REP(b, 0, K + 1)
				m[a][b] = 0;
	}
};

mat operator*(const mat &p, const mat &q)
{
	mat r;
	REP(a, 0, K + 1)
	REP(b, 0, K + 1) REP(c, 0, K + 1)
	{
		r.m[a][c] += p.m[a][b] * q.m[b][c];
		r.m[a][c] %= MOD;
	}
	return r;
}

mat matexp(const mat &a, ll n)
{
	mat r;
	REP(i, 0, K + 1)
	r.m[i][i] = 1;
	mat e = a;
	for (int i = 0; (1ll << i) <= n; i++)
	{
		if ((n >> i) & 1)
			r = r * e;
		e = e * e;
	}
	return r;
}

ll dp[101][101];

mat gen(int s)
{
	mat r;
	REP(a0, 0, K + 1)
	{
		REP(i, 0, K + 1)
		dp[0][i] = 0;
		dp[0][a0] = 1;
		REP(n, 0, s)
		{
			REP(a, 0, K + 1)
			dp[n + 1][a] = 0;
			REP(a, 0, K + 1)
			{
				int b = ((-n - 2 * a) % K + K) % K;
				if (b >= 1)
				{
					dp[n + 1][a] += b * dp[n][a];
					dp[n + 1][a] %= MOD;
				}
				if (a >= 1)
				{
					dp[n + 1][a == 1 ? b + 1 : a - 1] += a * dp[n][a];
					dp[n + 1][a == 1 ? b + 1 : a - 1] %= MOD;
				}
			}
		}
		REP(a, 0, K + 1)
		r.m[a0][a] = dp[s][a];
	}
	return r;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (; T; T--)
	{
		ll L;
		scanf("%lld%d", &L, &K);

		mat r = matexp(gen(K), L / K) * gen(L % K);

		ll res = 0;
		REP(a, 0, K + 1)
		{
			res += r.m[K][a];
			res %= MOD;
		}
		printf("%lld\n", res);
	}
	return 0;
}
