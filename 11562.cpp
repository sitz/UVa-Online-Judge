#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1);
int sgn(double x)
{
	return (x < -eps) ? -1 : (x > eps);
}

//2D PT
struct PT
{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator-(const PT o)
	{
		return PT(x - o.x, y - o.y);
	}
	PT operator+(const PT o)
	{
		return PT(x + o.x, y + o.y);
	}
	PT operator*(double s)
	{
		return PT(x * s, y * s);
	}
	PT operator/(double s)
	{
		return PT(x / s, y / s);
	}
	bool operator<(const PT &o) const
	{
		return y < o.y - eps || (y < o.y + eps && x < o.x - eps);
	}
	bool operator==(const PT &o) const
	{
		return !sgn(y - o.y) && !sgn(x - o.x);
	}
	bool operator!=(const PT &o) const
	{
		return sgn(y - o.y) || sgn(x - o.x);
	}
	void rd()
	{
		scanf("%lf %lf", &x, &y);
	}
	double ang()
	{
		return atan2(y, x);
	}
};

PT pp[205];
double kk[205];

double work(PT p[], int n, double th, double r)
{
	PT oo(sin(th), cos(th));
	oo = oo * r;
	for (int i = 0; i < n; i++)
	{
		kk[i] = (p[i] - oo).ang();
	}
	sort(kk, kk + n);
	if (kk[n - 1] - kk[0] < PI)
	{
		return kk[n - 1] - kk[0];
	}
	for (int i = 1; i < n; i++)
		if (kk[i] - kk[i - 1] > PI)
		{
			return PI * 2 - kk[i] + kk[i - 1];
		}
	return 0;
}

int main()
{
	//freopen("1.txt", "r", stdin);
	srand(330597937);
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 0; i < n; i++)
		{
			pp[i].rd();
		}
		double best = 0;
		double ans = work(pp, n, best, m);
		for (double step = 1; step > 1e-4; step /= 2)
		{
			for (int i = 1; i <= 100; i++)
			{
				double th = rand();
				double tmp = best + step * atan2(sin(th), cos(th));
				double now = work(pp, n, tmp, m);
				if (now > ans)
				{
					ans = now, best = tmp;
				}
			}
		}
		printf("%.8f\n", ans);
	}
	return 0;
}
