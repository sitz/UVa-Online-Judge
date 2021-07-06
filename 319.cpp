#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

inline int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	else
	{
		return x < 0 ? -1 : 1;
	}
}
inline double get_dist(double x, double y)
{
	return hypot(x, y);
}

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0)
			: x(x), y(y)
	{
	}
	void read()
	{
		scanf("%lf%lf", &x, &y);
	}
	void write()
	{
		printf("%lf %lf", x, y);
	}

	bool operator==(const Point &u) const
	{
		return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0;
	}
	bool operator!=(const Point &u) const
	{
		return !(*this == u);
	}
	bool operator<(const Point &u) const
	{
		return x < u.x || (x == u.x && y < u.y);
	}
	bool operator>(const Point &u) const
	{
		return u < *this;
	}
	bool operator<=(const Point &u) const
	{
		return *this < u || *this == u;
	}
	bool operator>=(const Point &u) const
	{
		return *this > u || *this == u;
	}
	Point operator+(const Point &u)
	{
		return Point(x + u.x, y + u.y);
	}
	Point operator-(const Point &u)
	{
		return Point(x - u.x, y - u.y);
	}
	Point operator*(const double u)
	{
		return Point(x * u, y * u);
	}
	Point operator/(const double u)
	{
		return Point(x / u, y / u);
	}
	double operator*(const Point &u)
	{
		return x * u.y - y * u.x;
	}
};
typedef Point Vector;

struct Line
{
	double a, b, c;
	Line(double a = 0, double b = 0, double c = 0)
			: a(a), b(b), c(c)
	{
	}
};

struct Circle
{
	Point o;
	double r;
	Circle()
	{
	}
	Circle(Point o, double r = 0)
			: o(o), r(r)
	{
	}
	void read()
	{
		o.read(), scanf("%lf", &r);
	}
	Point point(double rad)
	{
		return Point(o.x + cos(rad) * r, o.y + sin(rad) * r);
	}
	double get_area(double rad)
	{
		return rad * r * r / 2;
	}
};

namespace Punctual
{
	double get_dist(Point a, Point b)
	{
		double x = a.x - b.x, y = a.y - b.y;
		return sqrt(x * x + y * y);
	}
};

namespace Vectorial
{

double get_dot(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

double get_cross(Vector a, Vector b)
{
	return a.x * b.y - a.y * b.x;
}

double get_len(Vector a)
{
	return sqrt(get_dot(a, a));
}
double get_plength(Vector a)
{
	return get_dot(a, a);
}
double get_angle(Vector u)
{
	return atan2(u.y, u.x);
}
double get_angle(Vector a, Vector b)
{
	return acos(get_dot(a, b) / get_len(a) / get_len(b));
}
Vector rot(Vector a, double rad)
{
	return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}

Vector get_norm(Vector a)
{
	double l = get_len(a);
	return Vector(-a.y / l, a.x / l);
}
};

namespace Linear
{
	using namespace Vectorial;

	Line get_line(double x1, double y1, double x2, double y2)
	{
		return Line(y2 - y1, x1 - x2, y1 * (x2 - x1) - x1 * (y2 - y1));
	}
	Line get_line(double a, double b, Point u)
	{
		return Line(a, -b, u.y * b - u.x * a);
	}

	bool get_intersect(Line p, Line q, Point &o)
	{
		if (fabs(p.a * q.b - q.a * p.b) < eps)
		{
			return false;
		}
		o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
		o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
		return true;
	}

	bool get_intersect(Point p, Vector v, Point q, Vector w, Point &o)
	{
		if (dcmp(get_cross(v, w)) == 0)
		{
			return false;
		}
		Vector u = p - q;
		double k = get_cross(w, u) / get_cross(v, w);
		o = p + v * k;
		return true;
	}

	double get_dist_to_line(Point p, Point a, Point b)
	{
		return fabs(get_cross(b - a, p - a) / get_len(b - a));
	}
	double get_dist_to_seg(Point p, Point a, Point b)
	{
		if (a == b)
		{
			return get_len(p - a);
		}
		Vector v1 = b - a, v2 = p - a, v3 = p - b;
		if (dcmp(get_dot(v1, v2)) < 0)
		{
			return get_len(v2);
		}
		else if (dcmp(get_dot(v1, v3)) > 0)
		{
			return get_len(v3);
		}
		else
		{
			return fabs(get_cross(v1, v2) / get_len(v1));
		}
	}

	Point get_pt_to_line(Point p, Point a, Point b)
	{
		Vector v = b - a;
		return a + v * (get_dot(v, p - a) / get_dot(v, v));
	}

	bool have_intersect(Point a1, Point a2, Point b1, Point b2)
	{
		double c1 = get_cross(a2 - a1, b1 - a1), c2 = get_cross(a2 - a1, b2 - a1), c3 = get_cross(b2 - b1, a1 - b1), c4 = get_cross(b2 - b1, a2 - b1);
		return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
	}

	bool on_seg(Point p, Point a, Point b)
	{
		return dcmp(get_cross(a - p, b - p)) == 0 && dcmp(get_dot(a - p, b - p)) < 0;
	}
}

namespace Triangular
{
	using namespace Vectorial;

	double get_angle(double a, double b, double c)
	{
		return acos((a * a + b * b - c * c) / (2 * a * b));
	}
	double get_area(double a, double b, double c)
	{
		double s = (a + b + c) / 2;
		return sqrt(s * (s - a) * (s - b) * (s - c));
	}
	double get_area(double a, double h)
	{
		return a * h / 2;
	}
	double get_area(Point a, Point b, Point c)
	{
		return fabs(get_cross(b - a, c - a)) / 2;
	}
	double get_dir_area(Point a, Point b, Point c)
	{
		return get_cross(b - a, c - a) / 2;
	}
};

namespace Polygonal
{
	using namespace Vectorial;
	using namespace Linear;

	double get_area(Point *p, int n)
	{
		double ret = 0;
		for (int i = 1; i < n - 1; i++)
		{
			ret += get_cross(p[i] - p[0], p[i + 1] - p[0]);
		}
		return fabs(ret) / 2;
	}

	int get_convex_hull(Point *p, int n, Point *ch)
	{
		sort(p, p + n);
		int m = 0;
		for (int i = 0; i < n; i++)
		{
			while (m > 1 && dcmp(get_cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 1])) <= 0)
			{
				m--;
			}
			ch[m++] = p[i];
		}
		int k = m;
		for (int i = n - 2; i >= 0; i--)
		{
			while (m > k && dcmp(get_cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2])) <= 0)
			{
				m--;
			}
			ch[m++] = p[i];
		}
		if (n > 1)
		{
			m--;
		}
		return m;
	}

	int isPointInPolygon(Point o, Point *p, int n)
	{
		int wn = 0;
		for (int i = 0; i < n; i++)
		{
			int j = (i + 1) % n;
			if (on_seg(o, p[i], p[j]))
			{
				return 0;
			}
			int k = dcmp(get_cross(p[j] - p[i], o - p[i]));
			int d1 = dcmp(p[i].y - o.y);
			int d2 = dcmp(p[j].y - o.y);
			if (k > 0 && d1 <= 0 && d2 > 0)
			{
				wn++;
			}
			if (k < 0 && d2 <= 0 && d1 > 0)
			{
				wn--;
			}
		}
		return wn ? -1 : 1;
	}
};

namespace Circular
{
	using namespace Linear;
	using namespace Vectorial;
	using namespace Triangular;

	int get_line_circle_intersect(Point p, Point q, Circle O, double &t1, double &t2, vector<Point> &sol)
	{
		Vector v = q - p;

		double a = v.x, b = p.x - O.o.x, c = v.y, d = p.y - O.o.y;
		double e = a * a + c * c, f = 2 * (a * b + c * d), g = b * b + d * d - O.r * O.r;
		double delta = f * f - 4 * e * g;
		if (dcmp(delta) < 0)
		{
			return 0;
		}
		if (dcmp(delta) == 0)
		{
			t1 = t2 = -f / (2 * e);
			sol.push_back(p + v * t1);
			return 1;
		}

		t1 = (-f - sqrt(delta)) / (2 * e);
		sol.push_back(p + v * t1);
		t2 = (-f + sqrt(delta)) / (2 * e);
		sol.push_back(p + v * t2);
		return 2;
	}

	int get_circle_circle_intersect(Circle o1, Circle o2, vector<Point> &sol)
	{
		double d = get_len(o1.o - o2.o);

		if (dcmp(d) == 0)
		{
			if (dcmp(o1.r - o2.r) == 0)
			{
				return -1;
			}
			return 0;
		}

		if (dcmp(o1.r + o2.r - d) < 0)
		{
			return 0;
		}
		if (dcmp(fabs(o1.r - o2.r) - d) > 0)
		{
			return 0;
		}

		double a = get_angle(o2.o - o1.o);
		double da = acos((o1.r * o1.r + d * d - o2.r * o2.r) / (2 * o1.r * d));
		Point p1 = o1.point(a - da), p2 = o1.point(a + da);
		sol.push_back(p1);
		if (p1 == p2)
		{
			return 1;
		}
		sol.push_back(p2);
		return 2;
	}

	int get_tan(Point p, Circle o, Vector *v)
	{
		Vector u = o.o - p;
		double d = get_len(u);
		if (d < o.r)
		{
			return 0;
		}
		else if (dcmp(d - o.r) == 0)
		{
			v[0] = rot(u, M_PI / 2);
			return 1;
		}
		else
		{
			double ang = asin(o.r / d);
			v[0] = rot(u, -ang);
			v[1] = rot(u, ang);
			return 2;
		}
	}

	int get_tan(Circle o1, Circle o2, Point *a, Point *b)
	{
		int cnt = 0;
		if (o1.r < o2.r)
		{
			swap(o1, o2);
			swap(a, b);
		}
		double d2 = get_len(o1.o - o2.o);
		d2 = d2 * d2;
		double rdif = o1.r - o2.r, rsum = o1.r + o2.r;
		if (d2 < rdif * rdif)
		{
			return 0;
		}
		if (dcmp(d2) == 0 && dcmp(o1.r - o2.r) == 0)
		{
			return -1;
		}

		double base = get_angle(o2.o - o1.o);
		if (dcmp(d2 - rdif * rdif) == 0)
		{
			a[cnt] = o1.point(base);
			b[cnt] = o2.point(base);
			cnt++;
			return cnt;
		}

		double ang = acos((o1.r - o2.r) / sqrt(d2));
		a[cnt] = o1.point(base + ang);
		b[cnt] = o2.point(base + ang);
		cnt++;
		a[cnt] = o1.point(base - ang);
		b[cnt] = o2.point(base - ang);
		cnt++;

		if (dcmp(d2 - rsum * rsum) == 0)
		{
			a[cnt] = o1.point(base);
			b[cnt] = o2.point(base);
			cnt++;
		}
		else if (d2 > rsum * rsum)
		{
			double ang = acos((o1.r + o2.r) / sqrt(d2));
			a[cnt] = o1.point(base + ang);
			b[cnt] = o2.point(base + ang);
			cnt++;
			a[cnt] = o1.point(base - ang);
			b[cnt] = o2.point(base - ang);
			cnt++;
		}
		return cnt;
	}

	Circle circumscribed_circle(Point p1, Point p2, Point p3)
	{
		double Bx = p2.x - p1.x, By = p2.y - p1.y;
		double Cx = p3.x - p1.x, Cy = p3.y - p1.y;
		double D = 2 * (Bx * Cy - By * Cx);
		double cx = (Cy * (Bx * Bx + By * By) - By * (Cx * Cx + Cy * Cy)) / D + p1.x;
		double cy = (Bx * (Cx * Cx + Cy * Cy) - Cx * (Bx * Bx + By * By)) / D + p1.y;
		Point p = Point(cx, cy);
		return Circle(p, get_len(p1 - p));
	}

	Circle inscribed_circle(Point p1, Point p2, Point p3)
	{
		double a = get_len(p2 - p3);
		double b = get_len(p3 - p1);
		double c = get_len(p1 - p2);
		Point p = (p1 * a + p2 * b + p3 * c) / (a + b + c);
		return Circle(p, get_dist_to_line(p, p1, p2));
	}

	double get_pub_area_to_triangle(Circle O, Point a, Point b)
	{
		if (dcmp((a - O.o) * (b - O.o)) == 0)
			return 0;
		int sig = 1;
		double da = get_plength(O.o - a), db = get_plength(O.o - b);
		if (dcmp(da - db) > 0)
		{
			swap(da, db);
			swap(a, b);
			sig = -1;
		}

		double t1, t2;
		vector<Point> sol;
		int n = get_line_circle_intersect(a, b, O, t1, t2, sol);

		if (dcmp(da - O.r * O.r) <= 0)
		{
			if (dcmp(db - O.r * O.r) <= 0)
				return get_dir_area(O.o, a, b) * sig;

			int k = 0;
			if (get_plength(sol[0] - b) > get_plength(sol[1] - b))
				k = 1;

			double ret = get_area(O.o, a, sol[k]) + O.get_area(get_angle(sol[k] - O.o, b - O.o));
			double tmp = (a - O.o) * (b - O.o);
			return ret * sig * dcmp(tmp);
		}

		double d = get_dist_to_seg(O.o, a, b);
		if (dcmp(d - O.r) >= 0)
		{
			double ret = O.get_area(get_angle(a - O.o, b - O.o));
			double tmp = (a - O.o) * (b - O.o);
			return ret * sig * dcmp(tmp);
		}

		double k1 = O.r / get_len(a - O.o), k2 = O.r / get_len(b - O.o);
		Point p = O.o + (a - O.o) * k1, q = O.o + (b - O.o) * k2;
		double ret1 = O.get_area(get_angle(p - O.o, q - O.o));
		double ret2 = O.get_area(get_angle(sol[0] - O.o, sol[1] - O.o)) - get_area(O.o, sol[0], sol[1]);
		double ret = (ret1 - ret2), tmp = (a - O.o) * (b - O.o);
		return ret * sig * dcmp(tmp);
	}

	double get_pub_area_to_polygon(Circle O, Point *p, int n)
	{
		if (dcmp(O.r) == 0)
			return 0;
		double area = 0;
		for (int i = 0; i < n; i++)
		{
			int u = (i + 1) % n;
			area += get_pub_area_to_triangle(O, p[i], p[u]);
		}
		return fabs(area);
	}
};

using namespace Linear;
using namespace Polygonal;

const int MAXN = 505;

double ans;
int N, E;
Point P[MAXN];

void solve(Point o, Point s, double r)
{
	double rad = 2 * M_PI;
	int idx = -1;

	for (int i = 0; i < N; i++)
	{
		double d = get_len(P[i] - o);
		if (dcmp(d - r) > 0)
		{
			continue;
		}
		double k = get_angle(s - o, P[i] - o);
		if (dcmp((s - o) * (P[i] - o)) < 0)
		{
			k = 2 * M_PI - k;
		}
		if (dcmp(k - rad) == 0 && (idx == -1 || dcmp(get_len(P[idx] - o) - get_len(P[i] - o)) < 0))
		{
			idx = i;
		}
		if (dcmp(k - rad) < 0)
		{
			rad = k;
			idx = i;
		}
	}

	if (dcmp(o.y + r) <= 0)
	{
		if (idx == -1)
		{
			E = 1, ans = rad * r;
			return;
		}
	}
	else
	{
		Point t = Point(o.x + sqrt(r * r - o.y * o.y), 0);
		double k = get_angle(s - o, t - o);
		if (dcmp((s - o) * (t - o)) < 0)
		{
			k = 2 * M_PI - k;
		}

		if (idx == -1 || dcmp(k - rad) <= 0)
		{
			rad = k;
			idx = -1;
		}
	}

	if (idx != -1)
	{
		rad = get_angle(s - o, P[idx] - o);
		solve(P[idx], o + rot(s - o, rad), r - get_len(P[idx] - o));
		if (E == 0)
		{
			ans += 2 * rad * r;
		}
	}
	else
	{
		ans = 2 * rad * r;
	}
}

int main()
{
	int t = 1;
	double r;
	while (scanf("%d%lf", &N, &r) == 2 && r != 0)
	{
		for (int i = 0; i < N; i++)
		{
			P[i].read();
		}
		ans = E = 0;
		solve(Point(0, 0), Point(-r, 0), r);
		printf("Pendulum #%d\nLength of periodic orbit = %.2lf\n\n", t++, ans);
	}
	return 0;
}
