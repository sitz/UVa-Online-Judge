#include <bits/stdc++.h>

using namespace std;

#define see(x) cout << #x << ":" << x << endl;

const int maxn = 105;
const int mod = 1234;
int dp[maxn][maxn][maxn], cntt[maxn], c[maxn][maxn], way[maxn][5];
int exp22[maxn], exp3[maxn], f[maxn];
string str, tmp;
map<string, int> cha;
int main()
{
	int t, i, j, p, l, m, cas = 1, n, k, cnt, ti, tj, tp;
	int x, y, z;
	c[0][0] = 1;
	for (i = 1; i < maxn; i++)
	{
		c[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	exp22[0] = exp3[0] = f[0] = 1;
	for (i = 1; i < maxn; i++)
	{
		exp22[i] = (exp22[i - 1] * 2) % mod;
		exp3[i] = (exp3[i - 1] * 3) % mod;
		f[i] = (f[i - 1] * i) % mod;
	}
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		m = 0;
		for (i = 0; i <= k; i++)
		{
			for (j = 0; j <= k; j++)
			{
				for (p = 0; p <= k; p++)
				{
					if ((i + j + p) == k)
					{
						way[m][1] = i;
						way[m][2] = j;
						way[m][3] = p;
						m++;
					}
				}
			}
		}
		cha.clear();
		cnt = 0;
		memset(cntt, 0, sizeof(cntt));
		x = y = z = 0;
		for (i = 0; i < n; i++)
		{
			cin >> str;
			p = str.find('-');
			tmp = str.substr(p + 1, str.size() - p - 1);
			if (!cha[tmp])
			{
				cha[tmp] = ++cnt;
				cntt[cnt]++;
			}
			else
			{
				cntt[cha[tmp]]++;
				if (cntt[cha[tmp]] == 3)
				{
					z++;
				}
			}
			y = n - z * 2 - cnt;
			x = cnt - z - y;
		}
		memset(dp, 0, sizeof(dp));
		dp[z][y][x] = 1;
		for (i = n; i >= 0; i--)
		{
			for (j = n; j >= 0; j--)
			{
				for (p = n; p >= 0; p--)
				{
					if (dp[i][j][p])
					{
						for (l = 0; l < m; l++)
						{
							ti = way[l][1];
							tj = way[l][2];
							tp = way[l][3];
							if (i >= ti && j >= tj && p >= tp)
							{
								dp[i - ti][j + ti - tj][p + tj - tp] += dp[i][j][p] * c[i][ti] % mod * exp3[ti] % mod * c[j][tj] % mod * exp22[tj] % mod * c[p][tp] % mod * f[k] % mod;
								dp[i - ti][j + ti - tj][p + tj - tp] %= mod;
							}
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", cas++, dp[0][0][0]);
	}
	return 0;
}
