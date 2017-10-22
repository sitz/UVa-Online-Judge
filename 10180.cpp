#include <bits/stdc++.h>

using namespace std;

const double PI = 2 * acos(0.0);

int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		double x1, y1, x2, y2, r;
		scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &r);
		// ax + by + c = 0
		// a = (y2 - y1) / (x2 - x1)
		// b = -1
		// c = y1 - ax1
		double dx = x2 - x1, dy = y2 - y1;
		if (dx == 0.0) // can't get slope(infinity)
		{
			if (dy == 0.0)
			{
				printf("%.3lf\n", 0.0);
				continue;
			}
			double yg = y1, yl = y2;
			if (y1 < y2)
			{
				yg = y2;
				yl = y1;
			}
			if ((x1 < r && x1 > -r) && (yg > 0.0 && yl < 0.0))
			{
				double d1 = sqrt(x1 * x1 + y1 * y1), d2 = sqrt(x2 * x2 + y2 * y2), d3 = sqrt(dx * dx + dy * dy);
				double a;
				if (x1 == 0.0)
				{
					a = PI;
				}
				else
				{
					a = acos((d1 * d1 + d2 * d2 - d3 * d3) / (2.0 * d1 * d2));
				}
				double a1 = acos(r / d1), a2 = acos(r / d2);
				double theta = a - (a1 + a2);
				printf("%.3lf\n", r * theta + sqrt(d1 * d1 - r * r) + sqrt(d2 * d2 - r * r));
			}
			else
			{
				printf("%.3lf\n", yg - yl);
			}
		}
		else
		{
			// ax - y + c = 0, x^2 + y^2 = r^2
			// -> (a^2 + 1)x^2 + (2ac)x + (c^2 - r^2) = 0
			//
			// (a)x^2 + (b)x + (c) = 0
			// d = b^2 - 4ac
			// x = -b + sqrt(d) / 2a, -b - sqrt(d) / 2a
			double a = dy / dx, c = y1 - a * x1;
			double aSq = a * a, cSq = c * c, rSq = r * r;
			double d = 4.0 * (aSq * cSq - (aSq + 1.0) * (cSq - rSq));// discriminant
			if (d > 0.0)
			{
				double x = (-(2.0 * a * c) + sqrt(d)) / (2.0 * (aSq + 1.0));
				double xg = x1, xl = x2;
				if (x1 < x2)
				{
					xg = x2;
					xl = x1;
				}
				if (x >= xl && x <= xg)
				{
					double d1 = sqrt(x1 * x1 + y1 * y1), d2 = sqrt(x2 * x2 + y2 * y2), d3 = sqrt(dx * dx + dy * dy);
					double a;
					if (c == 0.0)
					{
						a = PI;
					}
					else
					{
						a = acos((d1 * d1 + d2 * d2 - d3 * d3) / (2.0 * d1 * d2));
					}
					double a1 = acos(r / d1), a2 = acos(r / d2);
					double theta = a - (a1 + a2);
					printf("%.3lf\n", r * theta + sqrt(d1 * d1 - rSq) + sqrt(d2 * d2 - rSq));
				}
				else
				{
					printf("%.3lf\n", sqrt(dx * dx + dy * dy));
				}
			}
			else
			{
				printf("%.3lf\n", sqrt(dx * dx + dy * dy));
			}
		}
	}
	return 0;
}
