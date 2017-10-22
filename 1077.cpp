#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const double eps = 1e-8;
const int inf = 0x3f3f3f3f;

#define maxx(a) memset(a, 0x3f, sizeof(a))
#define zero(a) memset(a, 0, sizeof(a))
#define FILL(a, b) memset(a, b, sizeof(a))
#define REP(i, a, b) for (i = a; i < b; i++)
#define rep(i, n) REP(i, 0, n)
#define srep(i, n) for (i = 1; i <= n; i++)
#define snuke(c, itr) for (__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); itr++)
#define MP make_pair
#define fi first
#define se second
typedef pair<int, int> PII;

const int N = 300 + 11;

struct Point
{
	double x, y;
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	Point()
	{
		x = 0;
		y = 0;
	}
	void show()
	{
		cout << "??" << x << ' ' << y << endl;
	}
};
typedef Point Vector;
Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(Point A, Point B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator*(Vector A, double p)
{
	return Vector(A.x * p, A.y * p);
}
Vector operator/(Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
}
Vector operator*(double p, Vector A)
{
	return Vector(A.x * p, A.y * p);
}
Vector operator/(double p, Vector A)
{
	return Vector(A.x / p, A.y / p);
}
bool operator<(const Point &a, const Point &b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x)
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
bool operator==(const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}
inline double Cross(Vector a, Vector b)
{
	return a.x * b.y - a.y * b.x;
}
inline double Cross(Point O, Point A, Point B)
{
	return Cross(A - O, B - O);
}
inline int sign(double x)
{
	return (x > eps) - (x < -eps);
}
double Length(Vector a)
{
	return sqrt(Dot(a, a));
}
double Angle(Vector A, Vector B)
{
	return acos(Dot(A, B) / Length(A) / Length(B));
}
double Area2(Point A, Point B, Point C)
{
	return Cross(B - A, C - A);
}
Vector Rotate(Vector a, double rad)
{
	return Vector(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad));
}
Vector Normal(Vector a)
{
	double l = Length(a);
	return Vector(-a.y / l, a.x / l);
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
	//å½ä¸ä»å½cross(v,w)!=0
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}
double DistanceToLine(Point p, Point a, Point b)
{
	Point v1 = b - a;
	Point v2 = p - a;
	return fabs(Cross(v1, v2)) / Length(v1);
}
double DistanceToSegment(Point p, Point a, Point b)
{
	if (a == b)
	{
		return Length(p - a);
	}
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(Dot(v1, v2)) < 0)
	{
		return Length(v2);
	}
	else if (dcmp(Dot(v1, v3)) > 0)
	{
		return Length(v3);
	}
	else
	{
		return fabs(Cross(v1, v2)) / Length(v1);
	}
}
Point GetLineProjection(Point p, Point a, Point b)
{
	Vector v = b - a;
	return a + v * (Dot(v, p - a) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1);
	double c2 = Cross(a2 - a1, b2 - a1);
	double c3 = Cross(b2 - b1, a1 - b1);
	double c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
double ConvexPolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
}
struct Line
{
	Vector v;
	Point p;
	Point pp;
	double ang;
	Line()
	{
	}
	Line(Point a, Vector vv)
	{
		p = a;
		v = vv;
		ang = atan2(v.y, v.x);
	}
	Line(Point a, Vector vv, Point b)
	{
		p = a;
		v = vv;
		ang = atan2(v.y, v.x);
		pp = b;
	}
	Point point(double a)
	{
		return v + a * (p - v);
	}
	bool operator<(const Line &L) const
	{
		return ang < L.ang;
	}
};
inline bool in_line(Point a, Line d)
{
	Point b = d.p, c = d.pp;
	return fabs((b.y - a.y) * (b.x - c.x) - (b.y - c.y) * (b.x - a.x)) < eps;
}
inline int across(Point a, Point b, Line line)
{
	int ans = sign(Cross(line.p, line.pp, a)) * sign(Cross(line.p, line.pp, b));
	return ans < 0;
}
bool OnLeft(Line l, Point pp)
{
	return Cross(l.v, pp - l.p) > 0;
}
Point GetLineIntersection(Line a, Line b)
{
	Vector u = a.p - b.p;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.p + a.v * t;
}
struct Polygon
{
	int n;
	Point p[400];
	Polygon()
	{
		n = 0;
	}
	Polygon(int nn, Point *pp)
	{
		n = nn;
		for (int q = 0; q < n; q++)
		{
			p[q] = pp[q];
		}
	}
	Point operator[](int a) const
	{
		return p[a];
	}
} o;
Polygon cut(Polygon &po, Point a, Point s)
{
	Point x, c;
	Polygon ans;
	int sum = 0;
	Vector tp = s - a;
	a = a - tp;
	s = s + tp;
	for (int q = 0; q < po.n; q++)
	{
		x = po[q];
		c = po[(q + 1) % po.n];
		if (OnLeft(Line(a, tp), x) || OnSegment(x, a, s))
		{
			ans.p[sum] = x;
			sum++;
		}
		if (across(x, c, Line(a, tp, s)))
		{
			ans.p[sum] = GetLineIntersection(x, c - x, a, s - a);
			sum++;
		}
	}
	ans.n = sum;
	return ans;
}

int n;
Point a1[N], a2[N];
int tot;
int stor[N];
int sum;
void work2()
{
	int i, j;
	tot = sum = 0;
	int a, b, c;
	rep(i, n)
	{
		cin >> a >> b >> c;
		a *= 2;
		b *= 2;
		c *= 2;
		Point b1(a - c / 2, 0), b2(a, b), b3(a + c / 2, 0);
		a1[tot] = b1;
		a2[tot] = b2;
		tot++;
		a1[tot] = b2;
		a2[tot] = b3;
		tot++;
		stor[sum++] = a - c / 2;
		stor[sum++] = a;
		stor[sum++] = a + c / 2;
	}
	sort(stor, stor + sum);
	sum = unique(stor, stor + sum) - stor;
	double ans = 0;
	for (i = 0; i < sum - 1; i++)
	{
		o.n = 4;
		o.p[0] = Point(stor[i], 0);
		o.p[1] = Point(stor[i + 1], 0);
		o.p[2] = Point(stor[i + 1], 1000000000);
		o.p[3] = Point(stor[i], 1000000000);
		rep(j, tot)
		{
			if (a2[j].x <= stor[i] + eps)
			{
				continue;
			}
			if (a1[j].x >= stor[i + 1] - eps)
			{
				continue;
			}
			o = cut(o, a1[j], a2[j]);
		}
		rep(j, o.n)
		{
			Point s = o[j];
			Point t = o[(j + 1) % (o.n)];
			if (s.x == stor[i] && t.x == stor[i])
			{
				continue;
			}
			if (s.x == stor[i + 1] && t.x == stor[i + 1])
			{
				continue;
			}
			if (s.y == 0 && t.y == 0)
			{
				continue;
			}
			if (s.y == 1000000000 && t.y == 1000000000)
			{
				continue;
			}
			ans += Length(s - t);
		}
	}
	printf("%.lf\n", ans / 2);
}

int main()
{
	int cas = 1;
	while (cin >> n && n)
	{
		printf("Case %d: ", cas++);
		work2();
		printf("\n");
	}
	return 0;
}
