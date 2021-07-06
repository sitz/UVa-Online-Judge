#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()

#define double long double

const double eps = 1e-11;
const double low = atan(-3.66 / 11.), high = atan(3.66 / 11.);
const double g = 9.81;
const double pi = acos(-1);

bool isin(double a)
{
	double ta = a;
	if (ta < low || high < ta)
	{
		return false;
	}
	return true;
}

double dist(double a)
{
	return 11. / cos(a);
}

double height(double d, double b, double v0)
{
	double t = d / (v0 * cos(b));
	return -g * t * t / 2. + v0 * sin(b) * t + 0.11;
}

void solve(double a, double b, double v0)
{
	if (!isin(a))
	{
		cout << "out" << endl;
		return;
	}
	double d = dist(a);
	double h = height(d, b, v0);
	if (h < 0.11)
	{
		cout << "bounce" << endl;
	}
	else if (h - eps > 2.44)
	{
		cout << "out" << endl;
	}
	else
	{
		cout << "goal" << endl;
	}
}

main()
{
	double a, b, v0;
	while (cin >> a >> b >> v0)
	{
		if (a == 0 && b == 0 && v0 == 0)
		{
			break;
		}
		double aa = pi / 180 * a, bb = pi / 180 * b;
		solve(aa, bb, v0);
	}
}
