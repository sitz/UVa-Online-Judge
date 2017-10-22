#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define pb push_back
#define D distance_ls_p
#define NEXT(i, n) ((i + 1) % n)
typedef long long ll;
ll table[30][30];
ll dp(int i, int j, int n)
{
	if (i == 0)
	{
		return 0;
	}
	if (table[i][j] != -1)
	{
		return table[i][j];
	}
	ll ret = 0;
	if (i < j)
	{
		REP(k, i, j)
		ret = max(ret, dp(i, k, n) + dp(k + 1, j, n));
	}
	else if (i >= j)
	{
		ll ret2 = 0;
		if (i < n)
		{
			REP(k, i + 1, n + 1)
			{
				ret = max(ret, dp(k, 1, n) + dp(k, j, n));
			}
		}
		if (j > 0)
		{
			REP(k, 1, j)
			{
				ret2 = max(ret2, dp(i, k, n) + dp(n, k, n));
			}
		}
		ret += ret2;
	}
	return table[i][j] = ret;
}
main()
{
	int n, an;
	while (cin >> n >> an)
	{
		rep(i, 21) rep(j, 21) table[i][j] = -1;
		table[n][1] = an;
		ll ans = dp(1, n, n);
		cout << ans << endl;
	}
}
