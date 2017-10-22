#include <bits/stdc++.h>

using namespace std;

double x, y, x1, yy1, x2, y2, x3, y3, a, b, c, d, e, f, r;
double theta[3], pi = 3.1415926535897932384626433832795;
int t;
double GCD(double a, double b)
{
	if (fabs(b) < 6e-3)
	{
		return a;
	}
	else
	{
		return GCD(b, fmod(a, b));
	}
}
int main()
{
	scanf("%d", &t);
	for (; t; t--)
	{
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &yy1, &x2, &y2, &x3, &y3);
		a = 2 * (x1 - x2), b = 2 * (yy1 - y2), c = x1 * x1 + yy1 * yy1 - x2 * x2 - y2 * y2;
		d = 2 * (x2 - x3), e = 2 * (y2 - y3), f = x2 * x2 + y2 * y2 - x3 * x3 - y3 * y3;
		x = (c * e - b * f) / (a * e - b * d);
		y = (a * f - c * d) / (a * e - b * d);
		theta[0] = atan2(x1 - x, yy1 - y);
		theta[1] = atan2(x2 - x, y2 - y);
		theta[2] = atan2(x3 - x, y3 - y);
		double ans = GCD(fabs(theta[2] - theta[0]), 2 * pi);
		ans = GCD(ans, fabs(theta[1] - theta[0]));
		printf("%.lf\n", 2 * pi / ans);
	}
}
