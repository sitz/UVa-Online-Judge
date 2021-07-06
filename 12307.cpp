#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-12
#define MAXN 100005

struct Point
{
	double x, y;
} pt[MAXN], cpt[MAXN];
struct Seg
{
	Point a, b;
};
int n, cn;

inline bool cmp(const Point &a, const Point &b)
{
	return (a.y < b.y) || (a.y == b.y && a.x < b.x);
}
inline double cross(Point a, Point b, Point c)
{
	return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
inline double dot(Point a, Point b, Point c)
{
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}
inline double sqrdis(Point a, Point b)
{
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double relation(Point p, Seg s)
{
	return dot(s.a, p, s.b) / ((s.b.x - s.a.x) * (s.b.x - s.a.x) + (s.b.y - s.a.y) * (s.b.y - s.a.y));
}
Point perpendicular(Point p, Seg s)
{
	Point t;
	double r = relation(p, s);
	t.x = s.a.x + r * (s.b.x - s.a.x);
	t.y = s.a.y + r * (s.b.y - s.a.y);
	return t;
}
void convexHull()
{
	sort(pt, pt + n, cmp);
	int top = 0, i, j, s;
	memset(cpt, 0, sizeof(cpt));
	pt[n] = pt[0];
	for (i = 0; i < n; i++)
	{
		while ((top >= 2) && (cross(cpt[top - 2], cpt[top - 1], pt[i]) <= 0))
		{
			top--;
		}
		cpt[top++] = pt[i];
	}
	j = top - 1;
	for (i = n - 2; i >= 0; i--)
	{
		while ((top > j + 1) && (cross(cpt[top - 2], cpt[top - 1], pt[i]) <= 0))
		{
			top--;
		}
		cpt[top++] = pt[i];
	}
	cn = top - 1;
}
void areaSBR()
{
	int p, q, r;
	double res = 1e99;
	p = q = 1;
	for (int i = 0; i < cn; i++)
	{
		while (cross(cpt[i], cpt[i + 1], cpt[p + 1]) - cross(cpt[i], cpt[i + 1], cpt[p]) > 0)
		{
			p = (p + 1) % cn;
		}
		while (dot(cpt[i], cpt[i + 1], cpt[q + 1]) - dot(cpt[i], cpt[i + 1], cpt[q]) > 0)
		{
			q = (q + 1) % cn;
		}
		if (i == 0)
		{
			r = q;
		}
		while (dot(cpt[i], cpt[i + 1], cpt[r + 1]) - dot(cpt[i], cpt[i + 1], cpt[r]) <= 0)
		{
			r = (r + 1) % cn;
		}
		double d = sqrdis(cpt[i], cpt[i + 1]);
		res = min(res, cross(cpt[i], cpt[i + 1], cpt[p]) * (dot(cpt[i], cpt[i + 1], cpt[q]) - dot(cpt[i], cpt[i + 1], cpt[r])) / d);
	}
	printf("%.2lf", res);
}
void perimeterSBR()
{
	int p, q, r;
	double res = 1e99;
	p = q = 1;
	for (int i = 0; i < cn; i++)
	{
		while (cross(cpt[i], cpt[i + 1], cpt[p + 1]) - cross(cpt[i], cpt[i + 1], cpt[p]) > 0)
		{
			p = (p + 1) % cn;
		}
		while (dot(cpt[i], cpt[i + 1], cpt[q + 1]) - dot(cpt[i], cpt[i + 1], cpt[q]) > 0)
		{
			q = (q + 1) % cn;
		}
		if (i == 0)
		{
			r = q;
		}
		while (dot(cpt[i], cpt[i + 1], cpt[r + 1]) - dot(cpt[i], cpt[i + 1], cpt[r]) <= 0)
		{
			r = (r + 1) % cn;
		}
		Seg s;
		s.a = cpt[i];
		s.b = cpt[i + 1];
		Point p1 = perpendicular(cpt[p], s);
		Point p2 = perpendicular(cpt[q], s);
		Point p3 = perpendicular(cpt[r], s);
		double d = 2.0 * (sqrt(sqrdis(p1, cpt[p])) + sqrt(sqrdis(p2, p3)));
		res = min(res, d);
	}
	printf("%.2lf", res);
}

int main()
{
	while (scanf("%d", &n) && (n))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &pt[i].x, &pt[i].y);
		}
		convexHull();
		if (cn < 3)
		{
			printf("0.00 0.00\n");
			continue;
		}
		areaSBR();
		printf(" ");
		perimeterSBR();
		printf("\n");
	}
	return 0;
}
