#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-9;
const double pi = acos(-1.0);
const int maxn = 300 + 10;
int dblcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	return x > 0 ? 1 : -1;
}
inline double sqr(double x)
{
	return x * x;
}
struct Point2D
{
	double x, y;
	Point2D() {}
	Point2D(double a, double b) : x(a), y(b) {}
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
	void output()
	{
		printf("%.3lf %.3lf\n", x, y);
	}
	Point2D operator+(const Point2D &a) const
	{
		return Point2D(x + a.x, y + a.y);
	}
	Point2D operator-(const Point2D &a) const
	{
		return Point2D(x - a.x, y - a.y);
	}
	Point2D operator*(const double &a) const
	{
		return Point2D(x * a, y * a);
	}
	Point2D operator/(const double &a) const
	{
		return Point2D(x / a, y / a);
	}
	bool operator==(const Point2D &a) const
	{
		return dblcmp(x - a.x) == 0 && dblcmp(y - a.y) == 0;
	}
	bool operator<(const Point2D &a) const
	{
		return dblcmp(x - a.x) < 0 || (dblcmp(x - a.x) == 0 && dblcmp(y - a.y) < 0);
	}
	double len()
	{
		return hypot(x, y);
	}
};
double det(const Point2D &a, const Point2D &b)
{
	return a.x * b.y - a.y * b.x;
}
double dot(const Point2D &a, const Point2D &b)
{
	return a.x * b.x + a.y * b.y;
}
double dist(const Point2D &a, const Point2D &b)
{
	return (a - b).len();
}
Point2D rotate(const Point2D &p, double a)
{
	return Point2D(p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a));
}
bool judgeinter(Point2D a, Point2D b, Point2D c, Point2D d)
{
	double d1, d2, d3, d4;
	d1 = det(c - a, b - a);
	d2 = det(d - a, b - a);
	d3 = det(a - c, d - c);
	d4 = det(b - a, d - c);
	return dblcmp(d1 * d2) < 0 && dblcmp(d3 * d4) < 0;
}
Point2D getinter(Point2D p, Point2D v, Point2D q, Point2D w)
{
	Point2D u = p - q;
	double t = det(w, u) / det(v, w);
	return p + v * t;
}
bool onSeg(const Point2D &p, const Point2D &a1, const Point2D &a2)
{
	return dblcmp(det(a1 - p, a2 - p)) == 0 && dblcmp(dot(a1 - p, a2 - p)) < 0;
}
int n, kase = 0;
Point2D p[maxn], v[maxn * maxn];
void solve()
{
	for (int i = 0; i < n; i++)
	{
		p[i].input();
		v[i] = p[i];
	}
	n -= 1;
	int c = n, e = n;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (judgeinter(p[i], p[i + 1], p[j], p[j + 1]))
			{
				v[c++] = getinter(p[i], p[i + 1] - p[i], p[j], p[j + 1] - p[j]);
			}
	sort(v, v + c);
	c = unique(v, v + c) - v;
	for (int i = 0; i < c; i++)
		for (int j = 0; j < n; j++)
			if (onSeg(v[i], p[j], p[j + 1]))
			{
				e++;
			}
	printf("Case %d: There are %d pieces.\n", ++kase, e + 2 - c);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	while (scanf("%d", &n) == 1 && n)
	{
		solve();
	}
	return 0;
}
