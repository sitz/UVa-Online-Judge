#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int M = 10010;
const long long oo = 4557430888798830399;

bool lab[N];
int u[M], v[M], w[M], n, p, s, t;
long long dp[N][N][2];

struct Re
{
	int x, y, z;
	Re() {}
	Re(int x, int y, int z) : x(x), y(y), z(z) {}
};

void spfa()
{
	memset(dp, 63, sizeof(dp));
	if (lab[s])
	{
		dp[s][0][0] = 0;
	}
	else
	{
		dp[s][0][1] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p; j++)
		{
			for (int k = 0; k < 2; k++)
			{
				if (lab[v[j]] && 0 == k)
				{
					dp[v[j]][i + 1][0] = min(dp[v[j]][i + 1][0], dp[u[j]][i][0] + w[j]);
				}
				else
				{
					dp[v[j]][i + 1][1] = min(dp[v[j]][i + 1][1], dp[u[j]][i][k] + w[j]);
				}
				if (lab[u[j]] && 0 == k)
				{
					dp[u[j]][i + 1][0] = min(dp[u[j]][i + 1][0], dp[v[j]][i][0] + w[j]);
				}
				else
				{
					dp[u[j]][i + 1][1] = min(dp[u[j]][i + 1][1], dp[v[j]][i][k] + w[j]);
				}
			}
		}
	}
}

void solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (dp[t][i][0] < dp[t][i][1])
		{
			puts("Infinity");
			return;
		}
		if (dp[t][i][1] != oo)
		{
			break;
		}
	}
	long long ret = -1;
	for (int i = 1; i <= n; i++)
	{
		if (dp[t][i][0] != oo && dp[t][i][0] < dp[t][i][1])
		{
			long long mx = oo;
			for (int j = 1; j < i; j++)
			{
				if (dp[t][j][1] <= dp[t][i][0])
				{
					mx = -1;
					break;
				}
				long long tmp = (dp[t][j][1] - dp[t][i][0]) / (i - j);
				if (0 == (dp[t][j][1] - dp[t][i][0]) % (i - j))
				{
					tmp--;
				}
				mx = min(mx, tmp);
			}
			if (mx < 0)
			{
				continue;
			}
			for (int j = i + 1; j <= n; j++)
			{
				if (dp[t][i][0] < dp[t][j][1])
				{
					continue;
				}
				long long tmp = (dp[t][i][0] - dp[t][j][1]) / (j - i);
				if (0 == (dp[t][i][0] - dp[t][j][1]) % (j - i))
				{
					tmp++;
				}
				if (mx < tmp)
				{
					mx = -1;
					break;
				}
			}
			ret = max(ret, mx);
		}
	}
	if (ret < 0)
	{
		puts("Impossible");
		return;
	}
	else
	{
		cout << ret << endl;
	}
}

int main()
{
	while (scanf("%d%d%d%d", &n, &p, &s, &t) != EOF)
	{
		for (int i = 0; i < p; i++)
		{
			scanf("%d%d%d", &u[i], &v[i], &w[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			lab[i] = false;
		}
		int m;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x);
			lab[x] = true;
		}
		spfa();
		solve();
	}
	return 0;
}
