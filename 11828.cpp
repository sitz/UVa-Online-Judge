#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef long long ll;
const ll mod = 1000000000;
const int N = 1010;
ll p2[N], p24[N], p25[N];
ll comb[N][N] = {0}, sum[N][N] = {0};

void computepow(int a, ll *b)
{
	b[0] = 1;
	REP(i, 1, N)
	b[i] = (b[i - 1] * a) % mod;
}

void precalc()
{
	computepow(2, p2);
	computepow(24, p24);
	computepow(25, p25);
	comb[0][0] = 1;
	REP(i, 1, N)
	{
		comb[i][0] = 1;
		REP(j, 1, i)
		comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
		comb[i][i] = 1;
	}
	sum[0][0] = 1;
	REP(i, 1, N)
	{
		sum[i][0] = 1;
		REP(j, 1, i + 1)
		{
			sum[i][j] = (sum[i][j - 1] + comb[i][j] * p25[j]) % mod;
		}
	}
}

ll solve(int n, int m, int k)
{
	ll ret = 0;
	for (int i = 0; i <= m; i++)
	{
		if (i + 2 * (m - i) <= k)
		{
			int can = min(n, (k - (i + 2 * (m - i))) / 2);
			//cout << n <<" " << can << " "
			//<< sum[n][can] <<" " << comb[m][i] <<" " << p2[i] <<
			//" " << p24[m-i] << endl;
			//ret+=sum[n][can]*comb[m][i]*p2[i]*p24[m-i];
			ll tmp = (sum[n][can] * comb[m][i]) % mod;
			tmp = (tmp * p2[i]) % mod;
			tmp = (tmp * p24[m - i]) % mod;
			ret = (ret + tmp) % mod;
		}
	}
	return ret;
}

main()
{
	precalc();
	int te, len, k;
	cin >> te;
	rep(tc, te)
	{
		cin >> len >> k;
		string a;
		cin >> a;
		int n = 0, m = 0;
		for (int i = 0; i < a.size() / 2; i++)
		{
			//cout << a[i] <<" " << a[a.size()-i-1] << endl;
			if (a[i] == a[a.size() - i - 1])
			{
				n++;
			}
			else
			{
				m++;
			}
		}
		ll ans = solve(n, m, k);
		if (a.size() % 2 == 1)
		{
			ans = (ans + 25 * solve(n, m, k - 1)) % mod;
		}
		cout << "Case " << tc + 1 << ": " << ans << endl;
	}
	return 0;
}
