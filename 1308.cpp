#include <bits/stdc++.h>

using namespace std;

const double eps = 5 * (1e-13);
const double pi = acos(-1.0);

int n;

struct Point
{
	double x, y;
	Point() {}
	Point(double _x, double _y) : x(_x), y(_y) {}
};

struct Circle
{
	Point c;
	double r;
	Circle() {}
	Circle(Point _c, double _r) : c(_c), r(_r) {}
	Point point(double x)
	{
		return Point(c.x + cos(x) * r, c.y + sin(x) * r);
	}
};

double normal(double x)
{
	return x - floor(x / (2 * pi)) * 2 * pi;
}

double dcmp(double x)
{
	if (fabs(x) <= eps)
	{
		return 0;
	}
	return (x < 0) ? -1 : 1;
}

double DIST(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Circle C[200];
double a[1000];
int tot = 0;
bool flag[110];

void check(Point x)
{
	for (int i = n - 1; i >= 0; i--)
	{
		double d = DIST(x, C[i].c);
		if (dcmp(d - C[i].r) < 0)
		{
			flag[i] = true;
			break;
		}
	}
}

int main()
{
	while (scanf("%d", &n) != EOF && n)
	{
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; i++)
		{
			double x, y, z;
			scanf("%lf%lf%lf", &x, &y, &z);
			C[i] = Circle(Point(x, y), z);
		}
		for (int i = 0; i < n; i++)
		{
			tot = 0;
			for (int j = 0; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				double dist = DIST(C[i].c, C[j].c);
				double ri = C[i].r, rj = C[j].r;
				if (dcmp(dist - ri - rj) >= 0 || dcmp(dist - fabs(ri - rj)) <= 0)
				{
					continue;
				}
				double t = atan2(C[j].c.y - C[i].c.y, C[j].c.x - C[i].c.x);
				double dt = acos((ri * ri + dist * dist - rj * rj) / (2. * ri * dist));
				a[tot++] = normal(t + dt);
				a[tot++] = normal(t - dt);
			}
			a[tot++] = 0;
			a[tot++] = 2 * pi;
			sort(a, a + tot);
			tot = unique(a, a + tot) - a;
			for (int j = 0; j < tot - 1; j++)
			{
				double u = (a[j] + a[j + 1]) / 2;
				double r1 = C[i].r + eps, r2 = C[i].r - eps;
				Point p1 = Point(C[i].c.x + r1 * cos(u), C[i].c.y + r1 * sin(u));
				Point p2 = Point(C[i].c.x + r2 * cos(u), C[i].c.y + r2 * sin(u));
				check(p1);
				check(p2);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			if (flag[i])
			{
				ans++;
			}
		printf("%d\n", ans);
	}
	return 0;
}
