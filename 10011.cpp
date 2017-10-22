#include <bits/stdc++.h>

using namespace std;

/**
1. test if the line through origin and house passes through the circle and has two
intersection points.
2. test if the segment connecting house and center of tree intersects with at least
one of the two tangent lines
3. test if the house is within the triangle formed by the origin and two tangent points

if all three tests pass, then pick the minimum among the distance from the house to
the tree and the distance from the house from two tangent lines
**/

class Point
{
public:
	double x, y;
	Point()
	{
		x = y = 0;
	}
	Point(double tx, double ty)
	{
		x = tx;
		y = ty;
	}
};

Point origin = Point(0, 0);

int fsig(double x)
{
	if (fabs(x) < 1e-6)
	{
		return 0;
	}
	else if (x > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int fcmp(double x, double y)
{
	return fsig(x - y);
}

double sqr(double x)
{
	return x * x;
}

double safe_sqrt(double x)
{
	if (fsig(x) == 0)
	{
		return 0;
	}
	else
	{
		return sqrt(x);
	}
}

double dis(double x1, double y1, double x2, double y2)
{
	return safe_sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

double cross(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

double dis_ptl(double x, double y, double a, double b, double c)
{
	return fabs(a * x + b * y + c) / sqrt(sqr(a) + sqr(b));
}

double line_circle_delta(double a, double b, Point center, double r)
{
	double offset_x = center.x, offset_y = center.y;
	double x1 = b, y1 = -a, x2 = b + b, y2 = -a - a;
	x1 -= offset_x;
	y1 -= offset_y;
	x2 -= offset_x;
	y2 -= offset_y;
	double dx = x2 - x1, dy = y2 - y1;
	double sqr_dr = sqr(dx) + sqr(dy);
	double D = x1 * y2 - x2 * y1;
	return sqr(r) * sqr_dr - sqr(D);
}

Point get_tangent(double a, double b, Point center, double r)
{
	double offset_x = center.x, offset_y = center.y;
	double x1 = b, y1 = -a, x2 = b + b, y2 = -a - a;
	x1 -= offset_x;
	y1 -= offset_y;
	x2 -= offset_x;
	y2 -= offset_y;
	double dx = x2 - x1, dy = y2 - y1;
	double sqr_dr = sqr(dx) + sqr(dy);
	double D = x1 * y2 - x2 * y1;
	double x = D * dy / sqr_dr;
	double y = -D * dx / sqr_dr;
	return Point(x + offset_x, y + offset_y);
}

int equal(Point a, Point b)
{
	return fcmp(a.x, b.x) == 0 && fcmp(a.y, b.y) == 0;
}

double area_triangle(Point a, Point b, Point c)
{
	return 0.5 * fabs(cross(c.x - a.x, c.y - a.y, c.x - b.x, c.y - b.y));
}

int point_in_triangle(Point p, Point a, Point b, Point c)
{
	if (equal(a, b) || equal(a, c) || equal(b, c))
	{
		return 0;
	}
	return fcmp(area_triangle(a, b, c), area_triangle(p, a, b) + area_triangle(p, b, c) + area_triangle(p, a, c)) == 0;
}

double calc(double cx, double cy, double r, double hx, double hy)
{
	Point center = Point(cx, cy);
	Point house = Point(hx, hy);
	double a1, b1, a2, b2;
	if (fcmp(fabs(cy), r) == 0)
	{
		a1 = 0;
		b1 = 1;
		a2 = 2 * cx * cy;
		b2 = sqr(r) - sqr(cx);
		if (b2 > 0)
		{
			a2 = -a2;
			b2 = -b2;
		}
	}
	else
	{
		a1 = 1;
		a2 = -1;
		b1 = (-cx * cy - r * safe_sqrt(sqr(cy) + sqr(cx) - sqr(r))) / (sqr(cy) - sqr(r));
		b2 = -(-cx * cy + r * safe_sqrt(sqr(cy) + sqr(cx) - sqr(r))) / (sqr(cy) - sqr(r));
	}
	double vx1 = b1, vy1 = -a1, vx2 = b2, vy2 = -a2;
	/* Intersection test */
	if (fsig(line_circle_delta(hy, -hx, center, r)) <= 0)
	{
		return 0;
	}
	/* cross test */
	if (fsig(cross(vx1, vy1, cx, cy) * cross(vx1, vy1, hx, hy)) <= 0 || fsig(cross(vx2, vy2, cx, cy) * cross(vx2, vy2, hx, hy)) <= 0)
	{
		return 0;
	}
	Point t1 = get_tangent(a1, b1, center, r);
	Point t2 = get_tangent(a2, b2, center, r);
	if (point_in_triangle(house, origin, t1, t2))
	{
		return 0;
	}
	double ans = dis(cx, cy, hx, hy) - r;
	ans = min(ans, dis_ptl(hx, hy, a1, b1, 0));
	ans = min(ans, dis_ptl(hx, hy, a2, b2, 0));
	return ans;
}

int main()
{
	int times;
	scanf("%d", &times);
	while (times--)
	{
		double cx, cy, r, hx, hy;
		scanf("%lf%lf%lf%lf%lf", &cx, &cy, &r, &hx, &hy);
		printf("%.3lf\n", calc(cx, cy, r, hx, hy));
	}
	return 0;
}
