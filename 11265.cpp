#include <bits/stdc++.h>

using namespace std;

typedef complex<double> Point;
typedef pair<Point, Point> Segment;

const double eps = 1E-8;
const int MaxN = 20000 + 10;

Segment s[MaxN];
Point p[2][MaxN];
int pn[2], cur, nxt;

void init_half_plane()
{
	cur = 0;
	nxt = 1;
	pn[cur] = 4;
	p[cur][0] = Point(0.0, 0.0);
	p[cur][1] = Point(1000000.0, 0.0);
	p[cur][2] = Point(1000000.0, 1000000.0);
	p[cur][3] = Point(0, 1000000.0);
}
double cross(const Point &a, const Point &b)
{
	return (conj(a) * b).imag();
}
int sgn(double x)
{
	return x > eps ? 1 : (x < -eps ? -1 : 0);
}
bool line_intersect(const Point &a, const Point &b, const Point &p, const Point &q, Point &ans)
{
	double d1 = cross(p - a, b - a), d2 = cross(q - a, b - a);
	if (fabs(d1 - d2) < eps)
	{
		return false;
	}
	ans = (d1 * q - d2 * p) / (d1 - d2);
	return true;
}
void add_half_plane(const Point &a, const Point &b)// direction is the left to the a->b vector
{
	nxt = 1 - cur;
	pn[nxt] = 0;
	int n = pn[cur], &m = pn[nxt];
	p[cur][n] = p[cur][0];
	Point t1 = p[cur][0];
	int o1 = sgn(cross(a - t1, b - t1));
	for (int i = 1; i <= n; ++i)
	{
		Point t2 = p[cur][i];
		int o2 = sgn(cross(a - t2, b - t2));
		if (o1 >= 0)
		{
			p[nxt][m++] = t1;
		}
		if ((o1 ^ o2) == -2)
		{
			line_intersect(a, b, t1, t2, p[nxt][m++]);
		}
		t1 = t2;
		o1 = o2;
	}
	cur = nxt;
}

int main()
{
	int n, cc = 0;
	double w, h, x, y, x1, y1, x2, y2;
	for (; scanf("%d%lf%lf%lf%lf", &n, &w, &h, &x, &y) != EOF;)
	{
		init_half_plane();
		Point ori(x, y), p1(0.0, 0.0), p2(w, 0.0), p3(w, h), p4(0.0, h);
		add_half_plane(p1, p2);
		add_half_plane(p2, p3);
		add_half_plane(p3, p4);
		add_half_plane(p4, p1);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
			Point t1(x1, y1), t2(x2, y2);
			if (sgn(cross(t2 - t1, ori - t1)) < 0)
			{
				swap(t1, t2);
			}
			add_half_plane(t1, t2);
		}
		double ans = 0.0;
		p[cur][pn[cur]] = p[cur][0];
		for (int i = 0; i < pn[cur]; ++i)
		{
			ans += cross(p[cur][i], p[cur][i + 1]);
		}
		printf("Case #%d: %.3f\n", ++cc, (ans / 2.0));
	}
	return 0;
}
