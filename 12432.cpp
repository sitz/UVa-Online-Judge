#include <bits/stdc++.h>

using namespace std;

#define MaxN 1010
#define LL long long

struct Seg
{
	int l, r, c;
	LL p;
	bool operator<(const Seg &a) const
	{
		return r < a.r;
	}
} seg[MaxN];

LL dp[MaxN][4], cost[64];
;
int cg[MaxN][4];
bool cheap[64];

void update(int i, int j, LL x, int y)
{
	if (dp[i][j] == -1 || dp[i][j] > x || (dp[i][j] == x && cg[i][j] > y))
	{
		dp[i][j] = x, cg[i][j] = y;
	}
}

int main()
{
	int T, cas = 0, l, n, m;
	LL d;
	scanf("%d", &T);
	while (T--)
	{
		LL mv = -1;
		cin >> l >> n >> m >> d;
		for (int i = 1; i <= m; ++i)
		{
			cin >> cost[i];
			if (mv == -1 || cost[i] < mv)
			{
				mv = cost[i];
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			cheap[i] = mv == cost[i];
		}
		cheap[0] = cheap[m + 1] = 0;
		cost[0] = cost[m + 1] = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> seg[i].l >> seg[i].r >> seg[i].c >> seg[i].p;
		}
		sort(seg + 1, seg + n + 1);
		seg[0].p = seg[n + 1].p = seg[0].l = seg[0].r = seg[0].c = 0;
		seg[n + 1].l = seg[n + 1].r = l + 1;
		seg[n + 1].c = m + 1;
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 1; i <= n + 1; ++i)
		{
			for (int k = 0; k < i; ++k)
				if (seg[k].r < seg[i].l)
				{
					for (int j = 0; j < 3; ++j)
						if (dp[k][j] != -1)
						{
							if (cheap[seg[i].c] || cheap[seg[k].c])
							{
								update(i, 0, dp[k][j] + seg[i].p + (seg[i].l - seg[k].r - 1) * mv, cg[k][j] + (seg[k].c != seg[i].c));
							}
							else
							{
								update(i, 0, dp[k][j] + seg[i].p + (seg[i].l - seg[k].r - 1) * mv, cg[k][j] + (seg[i].l != seg[k].r + 1) + (seg[i].l != seg[k].r + 1 || seg[i].c != seg[k].c));
							}
						}
					if (seg[i].l == seg[k].r + 1 && seg[i].c == seg[k].c)
					{
						for (int j = 0; j < 2; ++j)
							if (dp[k][j] != -1)
							{
								update(i, j + 1, dp[k][j] + seg[i].p, cg[k][j]);
							}
						if (dp[k][1] != -1)
						{
							update(i, 2, dp[k][1] + seg[i].p - min(seg[i].p, d), cg[k][1]);
						}
						if (dp[k][2] != -1)
						{
							update(i, 2, dp[k][2] + seg[i].p - min(seg[i].p, d), cg[k][2]);
						}
					}
				}
		}
		//        for (int i = 1; i <= n+1; ++i) for (int j = 0; j < 3; ++j) printf("%d %d : %d %d\n", i, j, dp[i][j], cg[i][j]);
		cout << "Case " << ++cas << ": " << dp[n + 1][0] << " " << cg[n + 1][0] - 2 << endl;
	}
	return 0;
}
