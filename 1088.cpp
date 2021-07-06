#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N = 105;
const int M = 6005;
const int INF = 1000000005;
typedef pair<int, int> per;
vector<per> E[N];
bool u[N];
int dp[N][M], m1[M], m2[M], ld, tmp[M];
void dfs(int x)
{
	u[x] = true;
	dp[x][0] = 0;
	for (int i = E[x].size() - 1; i >= 0; i--)
	{
		int j = E[x][i].first, t = E[x][i].second;
		if (!u[j])
		{
			dfs(j);
			for (int k = 0; k <= ld; k++)
			{
				tmp[k] = dp[x][k];
				dp[x][k] = INF;
			}
			m1[0] = tmp[0];
			m2[0] = dp[j][0];
			for (int k = 1; k <= ld; k++)
			{
				m1[k] = min(m1[k - 1], tmp[k]);
				m2[k] = min(m2[k - 1], dp[j][k]);
			}
			for (int k = t; k <= ld; k++)
			{
				int h = tmp[k];
				if (h > ld || k + t > ld)
				{
					continue;
				}
				int xd = ld - t - k;
				if (xd > k - t)
				{
					xd = k - t;
				}
				if (xd < 0)
				{
					continue;
				}
				int hh = m2[xd];
				if (hh + h - t > ld)
				{
					continue;
				}
				int nh = max(h, hh - t);
				if (dp[x][k] > nh)
				{
					dp[x][k] = nh;
				}
			}
			for (int k = 0; k + t <= ld; k++)
			{
				int h = dp[j][k];
				if (h > ld || k + t > ld)
				{
					continue;
				}
				int xd = ld - t - k;
				if (xd > k + t)
				{
					xd = k + t;
				}
				int hh = m1[xd];
				if (hh + h - t > ld)
				{
					continue;
				}
				int nh = max(hh, h - t);
				if (dp[x][k + t] > nh)
				{
					dp[x][k + t] = nh;
				}
			}
			if (!t)
			{
				continue;
			}
			//---------
			t = 60 - t;
			for (int k = 0; k <= ld; k++)
			{
				int h = tmp[k];
				if (h + t > ld)
				{
					continue;
				}
				int xd = ld + t - k;//k+xd-t<=ld
				if (xd > k + t)
				{
					xd = k + t;
				}
				if (xd > ld)
				{
					xd = ld;
				}
				int hh = m2[xd];
				if (hh + h + t > ld)
				{
					continue;
				}
				int nh = max(h, hh + t);
				if (dp[x][k] > nh)
				{
					dp[x][k] = nh;
				}
			}
			for (int k = t; k <= ld; k++)
			{
				int h = dp[j][k];
				if (h + t > ld)
				{
					continue;
				}
				int xd = ld + t - k;//k+xd-t<=ld
				if (xd > k - t)
				{
					xd = k - t;
				}
				if (xd > ld)
				{
					xd = ld;
				}
				int hh = m1[xd];
				if (hh + h + t > ld)
				{
					continue;
				}
				int nh = max(h + t, hh);
				if (dp[x][k - t] > nh)
				{
					dp[x][k - t] = nh;
				}
			}
		}
	}
}
bool check(int x)
{
	ld = x;
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j <= ld; j++)
		{
			dp[i][j] = INF;
		}
	}
	memset(u, 0, sizeof(u));
	dfs(1);
	for (i = 0; i <= ld; i++)
	{
		if (dp[1][i] <= ld)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n, i, ca = 1;
	while (~scanf("%d", &n))
	{
		if (!n)
		{
			break;
		}
		for (i = 1; i < n; i++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			c %= 60;
			E[a].push_back(mp(b, c));
			E[b].push_back(mp(a, c));
		}
		int low = -1, high = 10000, mid;
		while (low < high - 1)
		{
			int mid = (low + high) / 2;
			if (check(mid))
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		printf("Case %d: %d\n", ca++, high);
		for (i = 1; i <= n; i++)
		{
			E[i].clear();
		}
	}
	return 0;
}
/*
5
2 1 51
2 3 27
3 4 0
5 1 40

5
1 2 59
1 3 42
2 4 40
4 5 24
r1:37 r2:39
i:0 A:2 B:1 C:59
i:1 A:3 B:1 C:42
i:2 A:4 B:2 C:40
i:3 A:5 B:4 C:24
0
 */
