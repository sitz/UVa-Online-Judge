#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

int n;
double xa, ya, xb, yb, xc, yc;

struct Point
{
	double x, y;
};

Point rotate(Point A, Point B, double delta)
{
	Point C;
	Point vec;
	vec.x = B.x - A.x;
	vec.y = B.y - A.y;
	double r = sqrt(vec.x * vec.x + vec.y * vec.y);
	double sita = asin(fabs(vec.y) / r);
	if (vec.x >= 0 && vec.y >= 0)
	{
		sita = sita;
	}
	if (vec.x <= 0 && vec.y >= 0)
	{
		sita = PI - sita;
	}
	if (vec.x <= 0 && vec.y <= 0)
	{
		sita = PI + sita;
	}
	if (vec.x >= 0 && vec.y <= 0)
	{
		sita = -sita;
	}
	sita += delta;
	vec.x = r * cos(sita);
	vec.y = r * sin(sita);
	C.x = A.x + vec.x;
	C.y = A.y + vec.y;
	return C;
}

int main()
{
	int kase = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		scanf("%lf%lf", &xa, &ya);
		scanf("%lf%lf", &xb, &yb);
		scanf("%lf%lf", &xc, &yc);
		double A = xa * xa + ya * ya;
		double B = xb * xb + yb * yb;
		double C = xc * xc + yc * yc;
		double Xbc = xb - xc;
		double Xab = xa - xb;
		double Xac = xa - xc;
		double Ybc = yb - yc;
		double Yab = ya - yb;
		double Yac = ya - yc;
		double x, y;
		y = ((A - B) * Xbc - (B - C) * Xab) / (2 * Yab * Xbc - 2 * Ybc * Xab);
		if (fabs(xa - xb) > 0.0000001)
		{
			x = ((A - B) - 2 * Yab * y) / (2 * Xab);
		}
		else
		{
			x = ((B - C) - 2 * Ybc * y) / (2 * Xbc);
		}
		Point O, P;
		O.x = x;
		O.y = y;
		P.x = xa;
		P.y = ya;
		double delta = 2 * acos(-1.0) / n;
		double xmax = -100000000;
		double xmin = 100000000;
		double ymax = -100000000;
		double ymin = 100000000;
		for (int i = 0; i < n; i++)
		{
			//          printf( "Poly %.3lf  %.3lf\n",P.x,P.y );
			if (P.x > xmax)
			{
				xmax = P.x;
			}
			if (P.x < xmin)
			{
				xmin = P.x;
			}
			if (P.y > ymax)
			{
				ymax = P.y;
			}
			if (P.y < ymin)
			{
				ymin = P.y;
			}
			P = rotate(O, P, delta);
		}
		printf("Polygon %d: %.3lf\n", kase++, (xmax - xmin) * (ymax - ymin));
	}
	return 0;
}
