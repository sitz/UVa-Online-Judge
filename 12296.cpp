#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;

template <class T>
T sqr(T x)
{
	return x * x;
}
struct Point
{
	double x, y;
	Point()
	{
	}
	Point(double x, double y)
			: x(x), y(y)
	{
	}
};
typedef Point Vec;
Vec operator+(Vec a, Vec b)
{
	return Vec(a.x + b.x, a.y + b.y);
}
Vec operator-(Vec a, Vec b)
{
	return Vec(a.x - b.x, a.y - b.y);
}
Vec operator*(Vec a, double p)
{
	return Vec(a.x * p, a.y * p);
}
Vec operator/(Vec a, double p)
{
	return Vec(a.x / p, a.y / p);
}
inline int sgn(double x)
{
	return (x > EPS) - (x < -EPS);
}
bool operator<(Point a, Point b)
{
	return sgn(a.x - b.x) < 0 || sgn(a.x - b.x) == 0 && a.y < b.y;
}
bool operator==(Point a, Point b)
{
	return sgn(a.x - b.x) == 0 && sgn(a.y - b.y) == 0;
}

inline double dotDet(Vec a, Vec b)
{
	return a.x * b.x + a.y * b.y;
}
inline double crossDet(Vec a, Vec b)
{
	return a.x * b.y - a.y * b.x;
}
inline double dotDet(Point o, Point a, Point b)
{
	return dotDet(a - o, b - o);
}
inline double crossDet(Point o, Point a, Point b)
{
	return crossDet(a - o, b - o);
}
inline double vecLen(Vec x)
{
	return sqrt(dotDet(x, x));
}
inline Vec vecUnit(Vec x)
{
	return x / vecLen(x);
}
inline Vec normal(Vec x)
{
	return Vec(-x.y, x.x) / vecLen(x);
}
inline bool onSeg(Point x, Point a, Point b)
{
	return sgn(crossDet(x, a, b)) == 0 && sgn(dotDet(x, a, b)) < 0;
}

int segIntersect(Point a, Point c, Point b, Point d)
{
	Vec v1 = b - a, v2 = c - b, v3 = d - c, v4 = a - d;
	int a_bc = sgn(crossDet(v1, v2));
	int b_cd = sgn(crossDet(v2, v3));
	int c_da = sgn(crossDet(v3, v4));
	int d_ab = sgn(crossDet(v4, v1));
	if (a_bc * c_da > 0 && b_cd * d_ab > 0)
	{
		return 1;
	}
	if (onSeg(b, a, c) && c_da)
	{
		return 2;
	}
	if (onSeg(c, b, d) && d_ab)
	{
		return 2;
	}
	if (onSeg(d, c, a) && a_bc)
	{
		return 2;
	}
	if (onSeg(a, d, b) && b_cd)
	{
		return 2;
	}
	return 0;
}

Point lineIntersect(Point P, Vec v, Point Q, Vec w)
{
	Vec u = P - Q;
	double t = crossDet(w, u) / crossDet(v, w);
	return P + v * t;
}
struct Polygon
{
	int n;
	Point p[40];
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
};
struct Poly
{
	vector<Point> pt;
	Poly()
	{
		pt.clear();
	}
	~Poly()
	{
	}
	Poly(vector<Point> &pt)
			: pt(pt)
	{
	}
	Point operator[](int x) const
	{
		return pt[x];
	}
	int size()
	{
		return pt.size();
	}
	double area()
	{
		double ret = 0.0;
		for (int i = 0, sz = pt.size(); i < sz; i++)
		{
			ret += crossDet(pt[i], pt[(i + 1) % sz]);
		}
		return fabs(ret / 2.0);
	}
};

Poly cutPoly(Poly &poly, Point a, Point b)
{
	Poly ret = Poly();
	int n = poly.size();
	for (int i = 0; i < n; i++)
	{
		Point c = poly[i], d = poly[(i + 1) % n];
		if (sgn(crossDet(a, b, c)) >= 0)
		{
			ret.pt.push_back(c);
		}
		if (sgn(crossDet(b - a, c - d)) != 0)
		{
			Point ip = lineIntersect(a, b - a, c, d - c);
			if (onSeg(ip, c, d))
			{
				ret.pt.push_back(ip);
			}
		}
	}
	return ret;
}

bool isIntersect(Point a, Point b, Poly &poly)
{
	for (int i = 0, sz = poly.size(); i < sz; i++)
	{
		if (segIntersect(a, b, poly[i], poly[(i + 1) % sz]))
		{
			return true;
		}
	}
	return false;
}

struct Circle
{
	Point c;
	double r;
	Circle()
	{
	}
	Circle(Point c, double r)
			: c(c), r(r)
	{
	}
};

inline bool inCircle(Point a, Circle c)
{
	return vecLen(c.c - a) < c.r;
}
bool lineCircleIntersect(Point s, Point t, Circle C, vector<Point> &sol)
{
	Vec dir = t - s, nor = normal(dir);
	Point mid = lineIntersect(C.c, nor, s, dir);
	double len = sqr(C.r) - dotDet(C.c - mid, C.c - mid);
	if (sgn(len) < 0)
	{
		return 0;
	}
	if (sgn(len) == 0)
	{
		sol.push_back(mid);
		return 1;
	}
	Vec dis = vecUnit(dir);
	len = sqrt(len);
	sol.push_back(mid + dis * len);
	sol.push_back(mid - dis * len);
	return 2;
}
double Cross(Point a, Point b)
{
	return a.x * b.y - a.y * b.x;
}
int dcmp(double x)
{
	if (fabs(x) < EPS)
	{
		return 0;
	}
	else
	{
		return x < 0 ? -1 : 1;
	}
}
double Length(Point a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
double Dot(Point a, Point b)
{
	return a.x * b.x + a.y * b.y;
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
	Point v1 = b - a, v2 = p - a, v3 = p - b;
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
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
bool segCircleIntersect(Point s, Point t, Circle C)
{
	vector<Point> tmp;
	tmp.clear();
	if (lineCircleIntersect(s, t, C, tmp))
	{
		if (tmp.size() < 2)
		{
			return false;
		}
		for (int i = 0, sz = tmp.size(); i < sz; i++)
		{
			if (onSeg(tmp[i], s, t))
			{
				return true;
			}
		}
	}
	return false;
}
vector<Poly> cutPolies(Point s, Point t, vector<Poly> polies)
{
	vector<Poly> ret;
	ret.clear();
	for (int i = 0, sz = polies.size(); i < sz; i++)
	{
		Poly tmp;
		tmp = cutPoly(polies[i], s, t);
		if (tmp.size() >= 3 && tmp.area() > EPS)
		{
			ret.push_back(tmp);
		}
		tmp = cutPoly(polies[i], t, s);
		if (tmp.size() >= 3 && tmp.area() > EPS)
		{
			ret.push_back(tmp);
		}
	}
	return ret;
}

int ptInPoly(Point p, Poly &poly)
{
	int wn = 0, sz = poly.size();
	for (int i = 0; i < sz; i++)
	{
		if (onSeg(p, poly[i], poly[(i + 1) % sz]))
		{
			return -1;
		}
		int k = sgn(crossDet(poly[(i + 1) % sz] - poly[i], p - poly[i]));
		int d1 = sgn(poly[i].y - p.y);
		int d2 = sgn(poly[(i + 1) % sz].y - p.y);
		if (k > 0 && d1 <= 0 && d2 > 0)
		{
			wn++;
		}
		if (k < 0 && d2 <= 0 && d1 > 0)
		{
			wn--;
		}
	}
	if (wn != 0)
	{
		return 1;
	}
	return 0;
}
double ConvexPolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		area += crossDet(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
}
bool circlePoly(Circle C, Poly &poly)
{
	int sz = poly.size();
	if (ptInPoly(C.c, poly))
	{
		return true;
	}
	for (int i = 0; i < sz; i++)
	{
		if (inCircle(poly[i], C))
		{
			return true;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		if (segCircleIntersect(poly[i], poly[(i + 1) % sz], C))
		{
			return true;
		}
	}
	return false;
}
int isPointInPolygon(Point p, Polygon po)
{
	int wn = 0;
	int n = po.n;
	for (int i = 0; i < n; i++)
	{
		if (OnSegment(p, po[i], po[(i + 1) % n]))
		{
			return -1;
		}
		int k = dcmp(Cross(po[(i + 1) % n] - po[i], p - po[i]));
		int d1 = dcmp(po[i].y - p.y);
		int d2 = dcmp(po[(i + 1) % n].y - p.y);
		if (k > 0 && d1 <= 0 && d2 > 0)
		{
			wn++;
		}
		if (k < 0 && d2 <= 0 && d1 > 0)
		{
			wn--;
		}
	}
	if (wn != 0)
	{
		return 1;
	}
	return 0;
}
vector<double> circlePolies(Circle C, vector<Poly> &polies)
{
	vector<double> ret;
	ret.clear();
	for (int i = 0, sz = polies.size(); i < sz; i++)
	{
		if (circlePoly(C, polies[i]))
		{
			ret.push_back(polies[i].area());
		}
	}
	return ret;
}

const double dir[4][2] = {{0.0, 0.0}, {1.0, 0.0}, {1.0, 1.0}, {0.0, 1.0}};

Polygon pl[10000];
int main()
{
	double L, W;
	int n, m;
	while (cin >> n >> m >> L >> W && (n + m + L + W > EPS))
	{
		vector<Poly> cur;
		cur.push_back(Poly());
		for (int i = 0; i < 4; i++)
		{
			cur[0].pt.push_back(Point(L * dir[i][0], W * dir[i][1]));
		}
		Point p[2];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> p[j].x >> p[j].y;
			}
			cur = cutPolies(p[0], p[1], cur);
		}
		double ar[10000];
		double u;
		double ans[10000];
		int num = cur.size();
		for (int q = 0; q < num; q++)
		{
			pl[q].n = cur[q].size();
			for (int e = 0; e < pl[q].n; e++)
			{
				pl[q].p[e].x = cur[q][e].x;
				pl[q].p[e].y = cur[q][e].y;
			}
			ar[q] = ConvexPolygonArea(pl[q].p, pl[q].n);
		}
		Point x;
		for (int q = 0; q < m; q++)
		{
			scanf("%lf%lf%lf", &x.x, &x.y, &u);
			int s = 0;
			for (int e = 0; e < num; e++)
			{
				bool i = false;
				for (int r = 0; r < pl[e].n; r++)
					if (DistanceToSegment(x, pl[e][r], pl[e][(r + 1) % pl[e].n]) < u - EPS)
					{
						i = true;
					}
				if (isPointInPolygon(x, pl[e]))
				{
					i = true;
				}
				if (i)
				{
					ans[s++] = ar[e];
				}
			}
			sort(ans, ans + s);
			printf("%d", s);
			for (int e = 0; e < s; e++)
			{
				printf(" %.2f", ans[e]);
			}
			printf("\n");
		}
		cout << endl;
	}
}
