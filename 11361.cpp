#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
const int K = 100;
int dp[10][K][K][2];

int solve(int keta, int modall, int modnow, int isbound,
					string &in, int mod)
{
	if (keta == in.size())
	{
		return modall == 0 && modnow == 0;
	}
	int &ret = dp[keta][modall][modnow][isbound];
	if (ret == -1)
	{
		ret = 0;
		rep(i, 10)
		{
			int allnext = (modall + i) % mod, nownext = (modnow * 10 + i) % mod;
			if (isbound)
			{
				if (i > in[keta] - '0')
				{
					continue;
				}
				else
					ret += solve(keta + 1, allnext, nownext, i == in[keta] - '0' ? 1 : 0,
											 in, mod);
			}
			else
			{
				ret += solve(keta + 1, allnext, nownext, isbound, in, mod);
			}
		}
	}
	return ret;
}

void init()
{
	rep(i, 10) rep(j, K) rep(k, K) rep(l, 2) dp[i][j][k][l] = -1;
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int a, b, k;
		cin >> a >> b >> k;
		a--;
		int ans;
		if (k > 100)
		{
			//ans=b/k-a/k;
			ans = 0;
		}
		else
		{
			//all value is zero is counted.
			stringstream sin;
			int ta, tb;
			string t;
			sin << a;
			sin >> t;
			init();
			ta = solve(0, 0, 0, 1, t, k);
			stringstream sin2;
			sin2 << b;
			sin2 >> t;
			init();
			tb = solve(0, 0, 0, 1, t, k);
			ans = tb - ta;
		}
		cout << ans << endl;
	}
	return false;
}
