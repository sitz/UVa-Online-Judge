#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1.0), eps = 1e-6;

int main()
{
	double w, h, s, d;
	while (scanf("%lf %lf", &w, &h) == 2)
	{
		if (fabs(w) < eps && fabs(h) < eps)
		{
			break;
		}
		if (h < w)
		{
			swap(w, h);
		}
		d = h / (pi + 1);
		d = min(d, w);
		s = pi * d * d * 0.25 * w;
		d = 2.0 * h / 3.0;
		if (pi * d <= w)
		{
			d = min(d, w);
			s = max(s, pi * h * h * h / 27.0);
		}
		s = max(s, w * w * (pi * h - w) / (4 * pi * pi));
		printf("%.3lf\n", s);
	}
	return 0;
}
