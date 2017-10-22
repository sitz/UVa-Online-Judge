#include <bits/stdc++.h>

using namespace std;

struct Beat
{
	int p, id;
	bool operator<(const Beat &tt) const
	{
		return p > tt.p;
	}
} team[555][555];

int n, m, k, tm_, day[555], dp[2][5][5][5][5], vis[555];

void tomax(int &a, int b)
{
	if (a < b)
	{
		a = b;
	}
}
int get(int i, int j)
{
	if (i <= 0 || day[i] == 0)
	{
		return 111111;
	}
	return team[day[i]][j].id;
}

bool check(int i, int j, int r, int e, int w, int f)
{
	tm_++;
	int tt;
	tt = get(i, f);
	if (tt < 110)
	{
		vis[tt] = tm_;
	}
	tt = get(i - 1, w);
	if (tt < 110 && vis[tt] == tm_)
	{
		return 0;
	}
	if (tt < 110)
	{
		vis[tt] = tm_;
	}
	tt = get(i - 2, e);
	if (tt < 110 && vis[tt] == tm_)
	{
		return 0;
	}
	if (tt < 110)
	{
		vis[tt] = tm_;
	}
	tt = get(i - 3, r);
	if (tt < 110 && vis[tt] == tm_)
	{
		return 0;
	}
	if (tt < 110)
	{
		vis[tt] = tm_;
	}
	tt = get(i - 4, j);
	if (tt < 110 && vis[tt] == tm_)
	{
		return 0;
	}
	if (tt < 110)
	{
		vis[tt] = tm_;
	}
	return 1;
}

int work()
{
	int ret = 0;
	memset(dp, 0, sizeof(dp));
	memset(vis, 0, sizeof(vis));
	tm_ = 0;
	int now = 0, nex = 1;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int r = 0; r < 5; r++)
			{
				for (int e = 0; e < 5; e++)
				{
					for (int w = 0; w < 5; w++)
					{
						for (int f = 0; f < 5; f++)
						{
							if (check(i, j, r, e, w, f))
							{
								tomax(dp[nex][r][e][w][f], dp[now][j][r][e][w] + team[day[i]][f].p);
								if (i == k)
								{
									tomax(ret, dp[nex][r][e][w][f]);
								}
							}
						}
					}
				}
			}
		}
		swap(now, nex);
		memset(dp[nex], 0, sizeof(dp[nex]));
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		k += 10;
		for (int i = 1; i <= m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &team[i][j].p);
				team[i][j].id = j;
			}
			sort(team[i], team[i] + n);
		}
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &day[i]);
		}
		printf("%.2f\n", work() / 100.0);
	}
	return 0;
}
