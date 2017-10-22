#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

typedef pair<int, int> pi;

int t, n, en, vi[N], num;
map<int, pi> vis;

struct Point
{
	int x, y, id, v, h;
} p[N];

struct Edge
{
	int x, y1, y2;
} e[N];

bool cmp1(Point a, Point b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

bool cmp2(Point a, Point b)
{
	if (a.y != b.y)
	{
		return a.y < b.y;
	}
	return a.x < b.x;
}

bool cmp3(Point a, Point b)
{
	return a.id < b.id;
}

void init()
{
	en = 0;
	vis.clear();
	memset(vi, 0, sizeof(vi));
	num = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].id = i;
	}
}

void dfs(int id, int bo)
{
	if (vi[id])
	{
		return;
	}
	vi[id] = 1;
	num++;
	if (bo)
	{
		dfs(p[id].v, 0);
	}
	else
	{
		dfs(p[id].h, 1);
	}
}

int solve()
{
	if (n % 2)
	{
		return -1;
	}
	int ans = 0;
	sort(p, p + n, cmp1);
	int i, save = -1;
	for (i = 0; i < n; i += 2)
	{
		if (p[i].x != p[i + 1].x)
		{
			return -1;
		}
		if (save != p[i].x)
		{
			vis[p[i].x].first = en;
			if (i != 0)
			{
				vis[p[i - 1].x].second = en;
			}
			save = p[i].x;
		}
		e[en].x = p[i].x;
		e[en].y1 = p[i + 1].y;
		e[en++].y2 = p[i].y;
		p[i].h = p[i + 1].id;
		p[i + 1].h = p[i].id;
		ans += (p[i + 1].y - p[i].y);
	}
	vis[p[n - 1].x].second = en;
	sort(p, p + n, cmp2);
	for (i = 0; i < n; i += 2)
	{
		if (p[i].y != p[i + 1].y)
		{
			return -1;
		}
		for (int j = vis[p[i].x].second; j < vis[p[i + 1].x].first; j++)
		{
			if (e[j].y1 >= p[i].y && e[j].y2 <= p[i].y)
			{
				return -1;
			}
		}
		p[i].v = p[i + 1].id;
		p[i + 1].v = p[i].id;
		ans += (p[i + 1].x - p[i].x);
	}
	sort(p, p + n, cmp3);
	dfs(0, 0);
	if (num != n)
	{
		return -1;
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
