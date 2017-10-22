#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

struct Pt
{
	double x, y;
	bool operator<(const Pt &a) const
	{
		if (fabs(x - a.x) > eps)
		{
			return x < a.x;
		}
		return y < a.y;
	}
};

struct Seg
{
	Pt s, e;
};

int inInterval(Seg a, Pt p)
{
	return min(a.s.x, a.e.x) <= p.x &&
				 p.x <= max(a.s.x, a.e.x) &&
				 min(a.s.y, a.e.y) <= p.y &&
				 p.y <= max(a.s.y, a.e.y);
}

int calcIntersection(Seg a, Seg b, Pt &p)
{
	double a1, b1, c1, a2, b2, c2;
	double D, Dx, Dy;
	a1 = a.s.y - a.e.y, b1 = -a.s.x + a.e.x;
	a2 = b.s.y - b.e.y, b2 = -b.s.x + b.e.x;
	c1 = a1 * a.s.x + b1 * a.s.y;
	c2 = a2 * b.s.x + b2 * b.s.y;
	D = a1 * b2 - a2 * b1;
	Dx = c1 * b2 - c2 * b1;
	Dy = a1 * c2 - a2 * c1;
	if (fabs(D) < eps)// NONE or LINE
	{
		return 0;
	}
	p.x = Dx / D, p.y = Dy / D;
	return inInterval(a, p) == 1 && inInterval(b, p) == 1;
}

int inPolygon(Pt p[], int n, Pt q)
{
	int i, j, cnt = 0;
	for (i = 0, j = n - 1; i < n; j = i++)
	{
		if (p[i].y > q.y != p[j].y > q.y &&
				q.x < (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y) + p[i].x)
		{
			cnt++;
		}
	}
	return cnt & 1;
}

int main()
{
	int n, m;
	int i, j, p, q;
	Pt a[105], b[105];
	while (scanf("%d", &n) == 1 && n)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%lf %lf", &a[i].x, &a[i].y);
		}
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%lf %lf", &b[i].x, &b[i].y);
		}
		Seg s1, s2;
		Pt ret[10005];
		int retN = 0;
		for (i = 0, j = n - 1; i < n; j = i++)
		{
			s1.s = a[i], s1.e = a[j];
			for (p = 0, q = m - 1; p < m; q = p++)
			{
				s2.s = b[p], s2.e = b[q];
				if (calcIntersection(s1, s2, ret[retN]))
				{
					retN++;
				}
			}
		}
		for (i = 0; i < n; i++)
			if (inPolygon(b, m, a[i]))
			{
				ret[retN++] = a[i];
			}
		for (i = 0; i < m; i++)
			if (inPolygon(a, n, b[i]))
			{
				ret[retN++] = b[i];
			}
		if (retN == 0)
		{
			puts("0");
			continue;
		}
		sort(ret, ret + retN);
		for (i = 1, j = 0; i < retN; i++)
		{
			if (fabs(ret[i].x - ret[j].x) > eps ||
					fabs(ret[i].y - ret[j].y) > eps)
			{
				ret[++j] = ret[i];
			}
		}
		retN = j + 1;
		printf("%d\n", retN);
		for (i = 0; i < retN; i++)
		{
			printf("%.2lf %.2lf\n", ret[i].x, ret[i].y);
		}
	}
	return 0;
}
