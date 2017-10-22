#include <bits/stdc++.h>

using namespace std;

double gettheta(double a, double b, double c)
{
	double t = (a * a + b * b - c * c) / 2 / a / b;
	return acos(t);
}

double l, w, R, r1, r2;

int main()
{
	const double pi = 3.1415926535897932384626433832795;
	while (scanf("%lf %lf %lf", &l, &w, &R) == 3)
	{
		double area = 0.75 * pi * R * R;
		if (l < w)
		{
			double t = l;
			l = w;
			w = t;
		}
		r1 = R - l;
		r2 = R - w;
		if (r1 < 0)
		{
			r1 = 0;
		}
		if (r2 < 0)
		{
			r2 = 0;
		}
		if (r1 <= w && r2 <= l)
		{
			area += pi * r1 * r1 / 4 + pi * r2 * r2 / 4;
		}
		else
		{
			double diag = sqrt(l * l + w * w);
			double theta = pi - gettheta(diag, l, w) - gettheta(diag, r1, r2);
			area += 0.5 * r1 * r1 * theta;
			theta = pi - gettheta(diag, w, l) - gettheta(diag, r2, r1);
			area += 0.5 * r2 * r2 * theta;
			theta = gettheta(r1, r2, diag);
			area += 0.5 * r1 * r2 * sin(theta);
			area -= 0.5 * l * w;
		}
		printf("%.10lf\n", area);
	}
	return 0;
}
