#include <bits/stdc++.h>

using namespace std;

void swap(double &a, double &b)
{
	double t = a;
	a = b;
	b = t;
}
double ax, ay, bx, by;
inline double func(double x, double y)
{
	return sqrt(ax * ax + (ay - y) * (ay - y)) +
				 sqrt((bx - x) * (bx - x) + by * by) +
				 sqrt(x * x + y * y) +
				 sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
		if (ax > bx)
		{
			swap(ax, bx);
			swap(ay, by);
		}
		double m = (by - ay) / (bx - ax);
		double b = by - m * bx;
		double t = -b / m;
		double minx = 0, maxx = t;
		while (maxx - minx > 1e-3)
		{
			double x1 = (minx * 2 + maxx) / 3;
			double x2 = (minx + maxx * 2) / 3;
			double miny = 0, maxy = b;
			while (maxy - miny > 1e-3)
			{
				double y1 = (miny * 2 + maxy) / 3;
				double y2 = (miny + maxy * 2) / 3;
				double v1 = func(x1, y1);
				double v2 = func(x1, y2);
				if (v1 < v2)
				{
					maxy = y2;
				}
				else
				{
					miny = y1;
				}
			}
			double s1 = func(x1, (maxy + miny) * 0.5);
			miny = 0, maxy = b;
			while (maxy - miny > 1e-3)
			{
				double y1 = (miny * 2 + maxy) / 3;
				double y2 = (miny + maxy * 2) / 3;
				double v1 = func(x2, y1);
				double v2 = func(x2, y2);
				if (v1 < v2)
				{
					maxy = y2;
				}
				else
				{
					miny = y1;
				}
			}
			double s2 = func(x2, (maxy + miny) * 0.5);
			if (s1 < s2)
			{
				maxx = x2;
			}
			else
			{
				minx = x1;
			}
		}
		double x = (maxx + minx) * 0.5;
		double miny = 0, maxy = b;
		while (maxy - miny > 1e-3)
		{
			double y1 = (miny * 2 + maxy) / 3;
			double y2 = (miny + maxy * 2) / 3;
			double v1 = func(x, y1);
			double v2 = func(x, y2);
			if (v1 < v2)
			{
				maxy = y2;
			}
			else
			{
				miny = y1;
			}
		}
		printf("%.3lf\n", func(x, (maxy + miny) * 0.5));
	}
}
