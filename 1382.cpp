#include <bits/stdc++.h>

using namespace std;

#define mem(name, value) memset(name, value, sizeof(name))
#define FOR(i, n) for (int i = 1; i <= n; i++)

const int MAXN = 100 + 10;

struct Point
{
	int x, y;
	bool operator<(const Point &rhs) const
	{
		return x < rhs.x;
	}
} p[MAXN];
int n, m, y[MAXN], left_[MAXN], on[MAXN], on2[MAXN];

int solve()
{
	sort(p, p + n);
	sort(y, y + n);
	m = unique(y, y + n) - y;
	if (m <= 2)
	{
		return n;
	}
	int ans = 0;
	for (int a = 0; a < m; a++)
		for (int b = a + 1; b < m; b++)
		{
			int ymin = y[a], ymax = y[b];
			int k = 0;
			for (int i = 0; i < n; i++)
			{
				if (i == 0 || p[i].x != p[i - 1].x)
				{
					k++;
					on[k] = on2[k] = 0;
					left_[k] = k == 0 ? 0 : left_[k - 1] + on2[k - 1] - on[k - 1];
				}
				if (p[i].y > ymin && p[i].y < ymax)
				{
					on[k]++;
				}
				if (p[i].y >= ymin && p[i].y <= ymax)
				{
					on2[k]++;
				}
			}
			if (k <= 2)
			{
				return n;
			}
			int M = 0;
			for (int j = 1; j <= k; j++)
			{
				ans = max(ans, left_[j] + on2[j] + M);
				M = max(on[j] - left_[j], M);
			}
		}
	return ans;
}

int main()
{
	int t = 0;
	while (~scanf("%d", &n) && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			y[i] = p[i].y;
		}
		printf("Case %d: %d\n", ++t, solve());
	}
	return 0;
}
