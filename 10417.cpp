#include <bits/stdc++.h>

using namespace std;

#define MAXN 13
#define MAXB 6
#define MAXD 350000

double f[MAXN][MAXD], g[MAXN][MAXB];
int vis[MAXN][MAXD], a[MAXB], b[MAXB], N, M, gift[MAXB];

double dfs(int cur, int st)
{
	int i, j, k;
	double ans = 0;
	if (vis[cur][st])
	{
		return f[cur][st];
	}
	k = st;
	for (i = 5; i > 0; i--)
	{
		a[i] = k % 13;
		k /= 13;
	}
	for (i = 1; i <= 5; i++)
	{
		if (a[i])
		{
			--a[i];
			for (j = 1, k = 0; j <= 5; j++)
				k = k * 13 + a[j];
			ans += dfs(cur + 1, k) * g[cur][i];
			++a[i];
		}
	}
	vis[cur][st] = 1;
	return f[cur][st] = ans;
}

void solve()
{
	int i, j, k, box;
	double max, ans, res;
	scanf("%d", &N);
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &gift[i]);
	}
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			scanf("%lf", &g[i][j]);
		}
	}
	for (i = 1, k = 0; i <= 5; i++)
	{
		k = k * 13 + gift[i];
	}
	memset(vis, 0, sizeof(vis));
	vis[N + 1][0] = 1;
	f[N + 1][0] = 1;
	res = dfs(1, k);
	max = -1;
	for (i = 1; i <= 5; i++)
	{
		if (gift[i])
		{
			--gift[i];
			for (j = 1, k = 0; j <= 5; j++)
				k = k * 13 + gift[j];
			++gift[i];
			ans = f[2][k] * g[1][i] / gift[i];
			if (ans / res > max + 1e-9)
			{
				max = ans / res;
				box = i;
			}
		}
	}
	printf("%d %.3lf\n", box, max);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
	return 0;
}
