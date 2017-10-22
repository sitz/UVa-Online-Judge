#include <bits/stdc++.h>

using namespace std;

struct T
{
	int s, e;
	int v;
} t[133];

bool cmp(T a, T b)
{
	if (a.s == b.s)
	{
		return a.e < b.e;
	}
	return a.s < b.s;
}

int main()
{
	int n, i, k, j, ca = 0;
	char ch[1024];
	while (scanf("%d", &n) == 1 && n)
	{
		int ans = 0;
		t[0].s = 6 * 60;
		t[0].e = 6 * 60;
		t[0].v = 0;
		for (i = 1; i <= n; i++)
		{
			int h, m, hh, mm;
			scanf("%d:%d-%d:%d %d", &h, &m, &hh, &mm, &t[i].v);
			gets(ch);
			t[i].s = h * 60 + m;
			if (t[i].s < 6 * 60)
			{
				t[i].s += 24 * 60;
			}
			t[i].e = hh * 60 + mm;
			if (t[i].e < t[i].s)
			{
				t[i].e += 24 * 60;
			}
			ans = max(ans, t[i].v);
		}
		sort(t, t + n + 1, cmp);
		int dp[122][122];
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (i = 0; i <= n; i++)
			for (j = i; j <= n; j++)
				if (dp[i][j] != -1)
				{
					ans = max(ans, dp[i][j]);
					for (k = 1; k <= n; k++)
					{
						if (t[k].s >= t[i].e && t[k].e <= t[j].s && i)
						{
							continue;
						}
						if (k == j || k == i)
						{
							continue;
						}
						if (t[k].s >= max(t[j].e, t[i].e))
						{
							dp[i][k] = max(dp[i][k], dp[i][j] + t[k].v);
							dp[j][k] = max(dp[j][k], dp[i][j] + t[k].v);
						}
						else if (t[k].s >= min(t[j].e, t[i].e))
						{
							if (t[j].e >= t[i].e)
							{
								dp[j][k] = max(dp[j][k], dp[i][j] + t[k].v);
							}
							else
							{
								dp[i][k] = max(dp[i][k], dp[i][j] + t[k].v);
							}
						}
					}
				}
		printf("Case %d: %d\n", ++ca, ans);
	}
	return 0;
}
