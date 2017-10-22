#include <bits/stdc++.h>

using namespace std;

const int maxn = 110;
const double eps = 1e-6;

inline double sqr(double a)
{
	return a * a;
}
inline double dis(double x1, double y1, double x2, double y2)
{
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double x[maxn], y[maxn];
int n;
double f(double x0, double y0)
{
	int i;
	double tot = 0;
	for (i = 0; i < n; i++)
	{
		tot += dis(x0, y0, x[i], y[i]);
	}
	return tot;
}
double countdfx(double x0, double y0)
{
	int i;
	double tot = 0;
	for (i = 0; i < n; i++)
	{
		tot += (x0 - x[i]) / dis(x0, y0, x[i], y[i]);
	}
	return tot;
}
double countdfy(double x0, double y0)
{
	int i;
	double tot = 0;
	for (i = 0; i < n; i++)
	{
		tot += (y0 - y[i]) / dis(x0, y0, x[i], y[i]);
	}
	return tot;
}
double countdfxx(double x0, double y0)
{
	int i;
	double tot = 0;
	for (i = 0; i < n; i++)
	{
		tot += sqr(y0 - y[i]) / pow(dis(x0, y0, x[i], y[i]), 3);
	}
	return tot;
}
double countdfyy(double x0, double y0)
{
	int i;
	double tot = 0;
	for (i = 0; i < n; i++)
	{
		tot += sqr(x0 - x[i]) / pow(dis(x0, y0, x[i], y[i]), 3);
	}
	return tot;
}
double work()
{
	const double maxl = 1e5;
	double x0 = maxl, y0 = maxl;
	int i;
	for (i = x0 = y0 = 0.0; i < n; i++)
	{
		x0 += x[i], y0 += y[i];
	}
	x0 /= n;
	y0 /= n;
	while (1)
	{
		double xp = x0, yp = y0;
		for (i = 0; i < n; i++)
			if (dis(x0, y0, x[i], y[i]) < eps)
			{
				x0 += eps;
				y0 += eps;
			}
		double xd = countdfx(xp, yp), yd = countdfy(xp, yp);
		double xdd = countdfxx(xp, yp), ydd = countdfyy(xp, yp);
		x0 -= xd / xdd;
		y0 -= yd / ydd;
		if (f(x0, y0) > f(xp, yp))
		{
			x0 = xp;
			y0 = yp;
			break;
		}
		if (dis(x0, y0, xp, yp) < eps)
		{
			break;
		}
	}
	return f(x0, y0);
}

int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int i;
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}
		printf("%.0lf\n", work());
		if (T > 0)
		{
			printf("\n");
		}
	}
	return 0;
}
