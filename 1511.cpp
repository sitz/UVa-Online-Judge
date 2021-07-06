#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 200005;

int t, n, m, a1, a2, a3, a4;

struct Point
{
	int x, y, flag;
} p[N];

bool cmp(Point a, Point b)
{
	return a.y < b.y;
}

int solve()
{
	int ans = INF;
	sort(p, p + n + m, cmp);
	int tmp = INF;
	for (int i = 0; i < n + m; i++)
	{
		if (p[i].flag)
		{
			tmp = min(tmp, p[i].x - p[i].y);
		}
		else
		{
			ans = min(ans, p[i].y - p[i].x + tmp);
		}
	}
	tmp = INF;
	reverse(p, p + n + m);
	for (int i = 0; i < n + m; i++)
	{
		if (p[i].flag)
		{
			tmp = min(tmp, p[i].x + p[i].y);
		}
		else
		{
			ans = min(ans, -p[i].x - p[i].y + tmp);
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].flag = 0;
		}
		scanf("%d", &m);
		for (int i = n; i < n + m; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].flag = 1;
		}
		printf("%d\n", solve());
	}
	return 0;
}
