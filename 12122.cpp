#include <bits/stdc++.h>

using namespace std;

#define REP(i, s, t) for (int i = (s); i < (t); i++)
#define FOREACH(i, v) for (typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)

typedef long long ll;

const int MAXZ = 2100;

int V[300];
int M[300][300];
ll R[MAXZ][300];
ll Rc[MAXZ][300];

const int MOD = 1000000007;

ll powmod(ll a, int b)
{
	ll r = 1, e = a;
	for (int i = 0; (1 << i) <= b; i++)
	{
		if (b & (1 << i))
			r = r * e % MOD;
		e = e * e % MOD;
	}
	return r;
}

const int Z = MAXZ;
ll pol[MAXZ];
ll smallinvs[2 * MAXZ + 10];
ll hmult[MAXZ];

ll evpol(ll x)
{
	x %= MOD;
	if (x < Z)
		return pol[x];
	ll pr = 1;
	REP(i, 0, Z)
	pr = pr * (x - i) % MOD;
	ll res = 0;
	REP(j, 0, Z)
	{
		ll h = pol[j];
		h = h * hmult[j] % MOD;
		h = h * pr % MOD;
		h = h * powmod(x - j, MOD - 2) % MOD;
		res = (res + h) % MOD;
	}
	return res;
}

ll powt[MAXZ + 5][10];

int main()
{
	int T;
	scanf("%d", &T);
	REP(i, 0, 2 * MAXZ + 10)
	smallinvs[i] = powmod(i - MAXZ - 5, MOD - 2);
	REP(i, 0, MAXZ + 5)
	REP(k, 0, 10)
	powt[i][k] = powmod(i, k);
	for (; T; T--)
	{
		int N;
		scanf("%d", &N);
		REP(i, 0, N)
		{
			scanf("%d", V + i);
			REP(j, 0, i)
			scanf("%d", &M[i][j]);
		}
		REP(i, 0, Z)
		{
			Rc[i][0] = 0;
			REP(j, 0, N)
			{
				if (i == 0)
					R[i][j] = V[j];
				else
				{
					R[i][j] = R[i - 1][j];
					REP(k, 0, j)
					R[i][j] = (R[i][j] + powt[i + 1][M[j][k]] * R[i][k]) % MOD;
				}
				Rc[i][j + 1] = (Rc[i][j] + R[i][j]) % MOD;
			}
		}
		REP(j, 0, Z)
		{
			hmult[j] = 1;
			REP(i, 0, Z)
			if (i != j)
				hmult[j] = (ll)hmult[j] * smallinvs[j - i + MAXZ + 5] % MOD;
		}
		int Q;
		scanf("%d", &Q);
		REP(qu, 0, Q)
		{
			int p, b, d;
			ll a, c;
			scanf("%d%lld%d%lld%d", &p, &a, &b, &c, &d);
			a--;
			b--;
			a %= MOD;
			c %= MOD;
			pol[0] = 0;
			REP(i, 0, Z - 1)
			pol[i + 1] = (pol[i] + powmod(i - a + 1, p) * (Rc[i][b + d + 1] - Rc[i][b])) % MOD;
			ll res = ((evpol(a + c + 1) - evpol(a)) % MOD + MOD) % MOD;
			printf("%d\n", (int)res);
		}
		printf("\n");
	}
	return 0;
}
