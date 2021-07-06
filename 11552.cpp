#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

const int N = 1000;
const int A = 26;

int dp[N][A];
int chunk[N][26];
int ckind[N];

int solve(int n)
{
	rep(i, n) rep(j, 26) dp[i][j] = (1 << 21);
	rep(i, 26)
	{
		if (chunk[0][i] > 0)
		{
			dp[0][i] = ckind[0];
		}
	}
	REP(i, 1, n)
	{
		rep(j, 26)//last
		{
			if (chunk[i][j] == 0)
			{
				continue;
			}
			rep(k, 26)//prev
			{
				if (ckind[i] == 1)
				{
					if (j == k)
					{
						dp[i][j] = min(dp[i][j], dp[i - 1][k]);
					}
					else
					{
						dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
					}
				}
				else if (j != k && chunk[i][k] > 0)
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + ckind[i] - 1);
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i - 1][k] + ckind[i]);
				}
			}
		}
	}
	int ret = (1 << 21);
	rep(i, A)
	{
		ret = min(ret, dp[n - 1][i]);
	}
	return ret;
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int k;
		string in;
		cin >> k >> in;
		int n = in.size() / k;
		for (int i = 0; i < in.size(); i += k)
		{
			int now = i / k;
			rep(j, 26) chunk[now][j] = 0;
			ckind[now] = 0;
			for (int j = i; j < i + k; j++)
			{
				if (chunk[now][in[j] - 'a'] == 0)
				{
					ckind[now]++;
				}
				chunk[now][in[j] - 'a']++;
			}
		}
		cout << solve(n) << endl;
	}
}
