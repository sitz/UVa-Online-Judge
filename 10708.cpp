#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

const double pi = acos(-1);
const double eps = 1e-10;

#define RAD(a) (a * pi / 180)
#define ARG(a) (a * 180 / pi)

inline bool isp(P a, P b, P c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + eps;
}

inline bool can_catch(double X, double cx, double Y, double cy,
											double v, double l, double px, double py)
{
	double x = X - cx, y = Y - cy;
	//if (isp(P(X,Y),P(px,py),P(cx,cy)))return true;
	return !(sqrt(x * x + y * y) / v > l);
}

void solve(double cx, double cy, double px, double py,
					 double dpx, double dpy, double U, double V, double L)
{
	if (L < 1e-10)
	{
		if (abs(cx - px) < eps && abs(cy - py) < eps)
		{
			printf("%.2lf %.2lf %.2lf %.2lf\n",
						 0 + eps, 0 + eps, cx + eps, cy + eps);
		}
		else
		{
			puts("sorry, buddy");
		}
		return;
	}
	double t = 0;
	double l = 0, r = L;
	rep(i, 300)
	{
		t = (l + r) / 2;
		double X = px + U * t * dpx;
		double Y = py + U * t * dpy;
		if (can_catch(X, cx, Y, cy, V, t, px, py))
		{
			r = t - eps;
		}
		else
		{
			l = t + eps;
		}
	}
	if (abs(l - L) < 1e-9)
	{
		puts("sorry, buddy");
	}
	else
	{
		double X = px + U * t * dpx;
		double Y = py + U * t * dpy;
		double C = ARG(atan2(Y - cy, X - cx));
		if (C < -eps)
		{
			C += 360;
		}
		printf("%.2lf %.2lf %.2lf %.2lf\n",
					 C + eps, t + eps, X + eps, Y + eps);
	}
}

main()
{
	int te;
	cin >> te;
	while (te--)
	{
		double cx, cy, px, py, p, u, v, l;
		cin >> cx >> cy >> px >> py >> p >> u >> v >> l;
		solve(cx, cy, px, py, cos(RAD(p)), sin(RAD(p)),
					u, v, l);
	}
}
