#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-7

double a1, b1, t1, a2, b2, t2, t2_;

int main()
{
	int t = 1;
	while (scanf("%lf%lf%lf%lf%lf%lf", &a1,&b1,&t1,&a2,&b2,&t2_), a1 + b1 + t1)
	{
		t2 = sqrt(t1 * t1 * a2 * a2 * a2 / a1 / a1 / a1);
		t2_ = fmod(t2_, t2);
		double c2 = sqrt(a2 * a2 - b2 * b2);
		double area_ellipse = M_PI * a2 * b2;
		double area_run = area_ellipse * (t2_ / t2);
		double lo = 0.0f, hi = 2 * M_PI, mid = (lo + hi) / 2;
		while (hi - lo > EPS)
		{
			double area = (mid * a2 * b2) / 2. - (c2 * b2 * sin(mid)) / 2.;
			if (area < area_run)
			{
				lo = mid;
				mid = (lo + hi) / 2;
			}
			else
			{
				hi = mid;
				mid = (lo + hi) / 2;
			}
		}
		printf("Solar System %d: %.3lf %.3lf\n", t++,a2*cos(lo),b2*sin(lo));
	}
	return 0;
}
