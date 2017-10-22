#include <bits/stdc++.h>

using namespace std;

double x, y, c;

double f(double t)
{
	if (t == 0.)
	{
		return (min(x, y) - c);
	}
	double A = acos(t / y);
	double B = acos(t / x);
	double x1, x2, x3, x4;
	double y1, y2, y3, y4;
	double a1, b1, c1;
	double a2, b2, c2;
	x1 = 0;
	y1 = 0;
	x2 = t;
	y2 = y * sin(A);
	x3 = t;
	y3 = 0;
	x4 = 0;
	y4 = x * sin(B);
	a1 = y1 - y2;
	b1 = x2 - x1;
	c1 = (x2 * y1 - x1 * y2);
	a2 = y3 - y4;
	b2 = x4 - x3;
	c2 = (x4 * y3 - x3 * y4);
	double cy = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);
	//printf("huh %0.3lf %0.3lf%\n",cy,c);
	return (cy - c);
}

double min(double a, double b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	double a, b, t;
	while (scanf("%lf %lf %lf", &x, &y, &c) == 3)
	{
		a = 0.;
		b = min(x, y);
		t = (a + b) / 2.;
		double v1 = f(a);
		double v2 = f(b);
		//printf("%0.3lf %0.3lf\n",a,b);
		//printf("%0.3lf %0.3lf\n",v1,v2);
		while (true)
		{
			double m = f(t);
			if (v1 * m < 0.)
			{
				b = t;
				v2 = m;
				t = (a + b) / 2.;
			}
			else
			{
				a = t;
				v1 = m;
				t = (a + b) / 2.;
			}
			if (fabs(a - b) <= 1e-6)
			{
				break;
			}
		}
		printf("%0.3lf\n", a);
	}
	return 0;
}
