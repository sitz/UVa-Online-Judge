#include <bits/stdc++.h>

using namespace std;

#define M 1005
#define inf 0x3fffffff

struct point
{
	int x, y;
} pw[M];

struct polygon
{
	polygon() : u(-inf), d(inf), l(inf), r(-inf) {}
	int n, u, d, l, r;
	point p[M];
	bool inRectBox(point &pt)
	{
		return l <= pt.x && pt.x <= r && d <= pt.y && pt.y <= u;
	}
};

int multi(point a, point b, point c)
{
	return (b.x - a.x) * (c.y - b.y) - (c.x - b.x) * (b.y - a.y);
}

bool ptInPg(point &pt, polygon &pg)
{
	int cnt = 0, i, j, cp;
	for (i = 0, j = pg.n - 1; i < pg.n; j = i++)
	{
		if (pt.y > pg.p[i].y && pt.y > pg.p[j].y ||
				pt.y < pg.p[i].y && pt.y < pg.p[j].y)
		{
			continue;
		}
		cp = multi(pt, pg.p[i], pg.p[j]);
		if (cp == 0 &&
				(pg.p[i].x <= pt.x && pt.x <= pg.p[j].x ||
				 pg.p[j].x <= pt.x && pt.x <= pg.p[i].x))
		{
			return true;
		}
		if (cp < 0 && pg.p[i].y > pg.p[j].y && pt.y != pg.p[i].y ||
				cp > 0 && pg.p[i].y < pg.p[j].y && pt.y != pg.p[j].y)
		{
			++cnt;
		}
	}
	return (cnt & 1);
}

int has[M];

int main()
{
	int t, m, cc = 0, i, n, id;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &pw[i].x, &pw[i].y);
		}
		scanf("%d", &m);
		printf("Case #%d:\n", ++cc);
		while (m--)
		{
			polygon pg;
			scanf("%d", &pg.n);
			for (i = 0; i < n; i++)
			{
				has[i] = 0;
			}
			for (i = 0; i < pg.n; i++)
			{
				scanf("%d", &id);
				--id;
				has[id] = 1;
				pg.p[i] = pw[id];
				if (pg.u < pg.p[i].y)
				{
					pg.u = pg.p[i].y;
				}
				if (pg.d > pg.p[i].y)
				{
					pg.d = pg.p[i].y;
				}
				if (pg.l > pg.p[i].x)
				{
					pg.l = pg.p[i].x;
				}
				if (pg.r < pg.p[i].x)
				{
					pg.r = pg.p[i].x;
				}
			}
			int ans = pg.n;
			for (i = 0; i < n; i++)
			{
				if (has[i])
				{
					continue;
				}
				if (pg.inRectBox(pw[i]) && ptInPg(pw[i], pg))
				{
					++ans;
				}
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
