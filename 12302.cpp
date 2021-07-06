#include <bits/stdc++.h>

using namespace std;

#define sqr(a) ((a) * (a))
#define trarea(p) fabs((vdet(p[0], p[1], p[2]) / 2.0))
#define EPS 1e-12
#define MAXN 20

struct Point
{
	double x, y;
	Point(){};
	Point(double _x, double _y) : x(_x), y(_y){};
} p[MAXN];
struct Seg
{
	Point a, b;
	Seg(){};
	Seg(Point _a, Point _b) : a(_a), b(_b){};
};
struct Circle
{
	Point c;
	double r;
};
Point must_on[3];
Circle mc;

double dot(Point p, Point p1, Point p2)
{
	return (p1.x - p.x) * (p2.x - p.x) + (p1.y - p.y) * (p2.y - p.y);
}
inline double vdet(Point op, Point p1, Point p2)
{
	return (p1.x - op.x) * (p2.y - op.y) - (p2.x - op.x) * (p1.y - op.y);
}
inline double dis(Point a, Point b)
{
	return sqr(a.x - b.x) + sqr(a.y - b.y);
}
Point get_out_Circle(Point p[])
{
	double c1, c2, xa, xb, xc, ya, yb, yc;
	Point o;
	xa = p[0].x, xb = p[1].x, xc = p[2].x;
	ya = p[0].y, yb = p[1].y, yc = p[2].y;
	c1 = (sqr(xa) + sqr(ya) - sqr(xb) - sqr(yb)) / 2.0;
	c2 = (sqr(xa) + sqr(ya) - sqr(xc) - sqr(yc)) / 2.0;
	o.x = (c1 * (ya - yc) - c2 * (ya - yb)) / ((xa - xb) * (ya - yc) - (xa - xc) * (ya - yb));
	o.y = (c1 * (xa - xc) - c2 * (xa - xb)) / ((ya - yb) * (xa - xc) - (ya - yc) * (xa - xb));
	return o;
}
inline double get_out_r(Point p[])
{
	double a = dis(p[0], p[1]), b = dis(p[1], p[2]), c = dis(p[2], p[0]), s = trarea(p);
	return a * b * c / sqr(4 * s);
}
void get_Circle(int tm)
{
	switch (tm)
	{
	case 0:
		mc.r = -1;
		break;
	case 1:
		mc.r = 0, mc.c = must_on[0];
		break;
	case 2:
		mc.r = dis(must_on[0], must_on[1]) / 4.0;
		mc.c.x = (must_on[0].x + must_on[1].x) / 2.0;
		mc.c.y = (must_on[0].y + must_on[1].y) / 2.0;
		break;
	case 3:
		mc.r = get_out_r(must_on);
		mc.c = get_out_Circle(must_on);
		break;
	}
}
void min_Circle(int t, int ton)
{
	get_Circle(ton);
	if (ton >= 3)
	{
		return;
	}
	for (int i = 0; i < t; i++)
		if (dis(mc.c, p[i]) > mc.r + EPS)
		{
			must_on[ton] = p[i];
			min_Circle(i, ton + 1);
		}
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
Point intersection(Seg u, Seg v)
{
	Point ret = u.a;
	double t = ((u.a.x - v.a.x) * (v.a.y - v.b.y) - (u.a.y - v.a.y) * (v.a.x - v.b.x)) / ((u.a.x - u.b.x) * (v.a.y - v.b.y) - (u.a.y - u.b.y) * (v.a.x - v.b.x));
	ret.x += (u.b.x - u.a.x) * t;
	ret.y += (u.b.y - u.a.y) * t;
	return ret;
}

int main()
{
	int n;
	double x1, x2, x3, y1, y2, y3;
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3))
	{
		n = 0;
		if (x1 < 0.0 && x2 < 0.0 && x3 < 0.0 && y1 < 0.0 && y2 < 0.0 && y3 < 0.0)
		{
			break;
		}
		p[n++] = Point((x1 + x2) * 0.5, (y1 + y2) * 0.5);
		p[n++] = Point((x1 + x3) * 0.5, (y1 + y3) * 0.5);
		p[n++] = Point((x2 + x3) * 0.5, (y2 + y3) * 0.5);
		Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
		Seg s;
		s = Seg(p1, p2);
		p[n++] = perpendicular(p3, s);
		s = Seg(p1, p3);
		p[n++] = perpendicular(p2, s);
		s = Seg(p2, p3);
		p[n++] = perpendicular(p1, s);
		Seg s1(p1, p[5]), s2(p2, p[4]);
		Point o = intersection(s1, s2);
		p[n++] = Point((o.x + x1) * 0.5, (o.y + y1) * 0.5);
		p[n++] = Point((o.x + x2) * 0.5, (o.y + y2) * 0.5);
		p[n++] = Point((o.x + x3) * 0.5, (o.y + y3) * 0.5);
		random_shuffle(p, p + n);
		min_Circle(n, 0);
		printf("%.6lf %.6lf %.6lf\n", mc.c.x, mc.c.y, sqrt(mc.r));
	}
	return 0;
}
