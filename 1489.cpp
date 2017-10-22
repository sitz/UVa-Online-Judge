#include <bits/stdc++.h>

using namespace std;

#define CLR(a) memset(a, 0, sizeof(a))
#define REP(i, a, b) for (int i = a; i < b; i++)
#define REP_D(i, a, b) for (int i = a; i <= b; i++)

typedef long long ll;

const ll maxn = 55;
const ll key = 30;
const ll MOD = 1000000003L;
ll n, a[maxn], k;
ll bit[40];
ll dp[maxn][maxn];

void getBit()
{
	bit[0] = 1;
	REP_D(i, 1, 31)
	{
		bit[i] = bit[i - 1] * 2;
	}
}

ll getLeft(int i, int have)
{
	if (have < 0)
	{
		return 0;
	}
	return (a[i] & (bit[have + 1] - 1));
}

ll getDp(int pos, int key, int need, int num)
{
	CLR(dp);
	dp[0][0] = 1;
	REP_D(i, 1, n)
	{
		REP_D(j, 0, num)
		{
			if (a[i] & bit[pos])
			{
				if (i < key || i > key)
				{
					if (j >= 1)
					{
						dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] * (getLeft(i, pos - 1) + 1)) % MOD;
					}
				}
			}
			if (a[i] & bit[pos])
			{
				if (i > key)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][j] * (bit[pos])) % MOD;
				}
				else if (i == key)
				{
					dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
				}
			}
			else
			{
				dp[i][j] = (dp[i][j] + dp[i - 1][j] * (getLeft(i, pos - 1) + 1)) % MOD;
			}
		}
	}
	ll res = 0;
	REP_D(i, 0, num)
	{
		if ((i & 1) == need)
		{
			res += dp[n][i];
		}
	}
	return res;
}

ll dfs(int pos)
{
	if (pos < 0)
	{
		return 1;
	}
	ll ans = 0;
	ll num = 0;
	REP_D(i, 1, n)
	{
		if (bit[pos] & a[i])
		{
			num++;
		}
	}
	ll need = ((k & bit[pos]) >> pos);
	if ((num & 1) == need)
	{
		ans = (ans + dfs(pos - 1)) % MOD;
	}
	CLR(dp);
	//dp[0][0] = 1;
	REP_D(i, 1, n)
	{
		if (a[i] & bit[pos])
		{
			ans = (ans + getDp(pos, i, need, num)) % MOD;
		}
	}
	return ans;
}

int main()
{
	//freopen("1Ain.txt", "r", stdin);
	//freopen("1Aout.txt", "w", stdout);
	getBit();
	while (scanf("%lld%lld", &n, &k) != EOF)
	{
		if (!n && !k)
		{
			break;
		}
		REP_D(i, 1, n)
		{
			scanf("%lld", &a[i]);
		}
		printf("%lld\n", dfs(key));
	}
	return 0;
}
