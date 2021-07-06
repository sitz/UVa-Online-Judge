#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define two(i) (1 << (i))
int g[20][20];
int cnt[two(13)];
LL dp[two(13)][13], use[two(13)];

int main()
{
	for (int i = 0; i < two(13); i++)
	{
		cnt[i] = 0;
		for (int t = i; t > 0; t -= t & -t)
		{
			cnt[i]++;
		}
	}
	int T, cas = 0;
	scanf("%d", &T);
	while (T--)
	{
		int n, m, x, y;
		scanf("%d%d", &n, &m);
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &x, &y);
			g[x][y] = g[y][x] = 1;
		}
		LL ret = 0;
		for (int i = 0; i < n; i++)
		{
			for (int s = 0; s < two(n); s++)
				for (int j = 0; j < n; j++)
				{
					dp[s][j] = 0;
				}
			dp[two(i)][i] = 1;
			for (int s = 0; s < two(n); s++)
				for (int j = 0; j < n; j++)
					if (dp[s][j])
						for (int k = 0; k < n; k++)
							if (!(two(k) & s) && g[j][k])
							{
								dp[two(k) | s][k] += dp[s][j];
							}
			for (int s = 0; s < two(n); s++)
			{
				use[s] = 0;
				for (int j = 0; j < n; j++)
					if (dp[s][j] && g[j][i])
					{
						use[s] += dp[s][j];
					}
				use[s] /= 2;
				//		if(use[s])
				//			printf("==%d %d\n",i,s);
			}
			for (int s = 1; s < two(n); s++)
			{
				if (s & two(i))
				{
					continue;
				}
				LL t = 0;
				for (int ns = s; ns > 0; ns = (ns - 1) & s)
					if (cnt[s ^ ns] >= 2 && cnt[ns] >= 2)
					{
						t += use[s ^ ns ^ two(i)] * use[ns ^ two(i)];
					}
				ret += t;
			}
		}
		printf("Case %d: %lld\n", ++cas, ret / 2);
	}
	return 0;
}
