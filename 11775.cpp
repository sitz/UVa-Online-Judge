#include <bits/stdc++.h>

using namespace std;

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)

typedef long long ll;
const int maxn = 3000 + 100;
const int mod = 10000007;
char str[maxn];
int p[maxn], valA[maxn], valB[maxn], dp[maxn][maxn];
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	p[0] = 1;
	for (int i = 1; i < maxn; ++i)
	{
		p[i] = (p[i - 1] * 2) % mod;
	}
	int t, tcase = 0;
	scanf("%d", &t);
	map<string, int> mp;
	while (t--)
	{
		tcase++;
		mp.clear();
		scanf("%s", str);
		int n = strlen(str);
		int i = 0, cnt = 0, totA = 0, totB = 0;
		string s = "";
		while (i < n)
		{
			s = "";
			s += str[i++];
			while (str[i] >= '0' && str[i] <= '9')
			{
				s += str[i++];
			}
			if (mp[s])
			{
				valA[totA++] = mp[s];
			}
			else
			{
				mp[s] = valA[totA++] = ++cnt;
			}
		}
		scanf("%s", str);
		n = strlen(str);
		i = 0;
		while (i < n)
		{
			s = "";
			s += str[i++];
			while (str[i] >= '0' && str[i] <= '9')
			{
				s += str[i++];
			}
			if (mp[s])
			{
				valB[totB++] = mp[s];
			}
			else
			{
				mp[s] = valB[totB++] = ++cnt;
			}
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= totA; ++i)
			for (int j = 1; j <= totB; ++j)
				if (valA[i - 1] == valB[j - 1])
				{
					dp[i][j] = (dp[i - 1][j - 1] * 2 + 1) % mod;
				}
				else
				{
					dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1]) % mod;
				}
		int ans = (p[totA] + p[totB] - 2) % mod;
		ans = (ans - dp[totA][totB] * 2) % mod;
		ans = (ans + mod) % mod;
		printf("Case %d: %d\n", tcase, ans);
	}
	return 0;
}
