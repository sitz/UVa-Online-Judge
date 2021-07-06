#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-5;

struct Point
{
	double x, y;
	Point(double a = 0, double b = 0) : x(a), y(b) {}
};

double angle(Point a, Point b, Point c)
{
	b.x -= a.x;
	b.y -= a.y;
	c.x -= a.x;
	c.y -= a.y;
	return acos((b.x * c.x + b.y * c.y) / (hypot(b.x, b.y) * hypot(c.x, c.y)));
}

bool fraction(double f, int n)
{
	return fabs(f * n - round(f * n)) < eps;
}

int main()
{
	const double pi = acos(-1);
	for (;;)
	{
		Point p[3];
		for (int i = 0; i < 3; ++i)
			if (scanf("%lf%lf", &p[i].x, &p[i].y) != 2)
			{
				return 0;
			}
		double a = angle(p[0], p[1], p[2]) / pi,
					 b = angle(p[1], p[2], p[0]) / pi;
		for (int n = 3; n <= 1000; ++n)
			if (fraction(a, n) && fraction(b, n))
			{
				printf("%i\n", n);
				break;
			}
	}
	return 0;
}
