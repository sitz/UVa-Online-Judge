#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

int check(int n, double h[], double d[], double theta, double v)
{
	double vx = v * cos(theta), vy = v * sin(theta);
	double t, x = 0, hh;
	int i;
	for (i = 0; i < n; i++)
	{
		t = x / vx;
		hh = vy * t - 0.5 * 9.8 * t * t;
		if (hh < h[i] - eps)
			return 0;
		t = (x + d[i]) / vx;
		hh = vy * t - 0.5 * 9.8 * t * t;
		if (hh < h[i] - eps)
			return 0;
		x += d[i];
	}
	return 1;
}

int main()
{
	int n, i;
	double h[105], d[105];
	while (scanf("%d", &n) == 1)
	{
		for (i = 0; i < n; i++)
			scanf("%lf %lf", &h[i], &d[i]);
		double X = 0;
		for (i = 0; i < n; i++)
			X += d[i];
		double l = 0, r = acos(-1) / 2, mid;// bin srch
		double theta, v;
		while (fabs(l - r) > 1e-5)
		{
			mid = (l + r) / 2;
			theta = mid, v = sqrt(X * 9.8 / sin(2 * theta));
			if (check(n, h, d, theta, v))
				r = mid;
			else
				l = mid;
		}
		printf("%.2lf %.2lf\n", theta / acos(-1) * 180, v);
	}
	return 0;
}
