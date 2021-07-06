#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3000;
const double pi = acos(-1.0);

struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;
struct Line
{
	Point P;
	Vector v;
	double ang;
	Line(){};
	Line(Point P, Vector v) : P(P), v(v) { ang = atan2(v.y, v.x); }
	bool operator<(const Line &L) const
	{
		return ang < L.ang;
	}
};

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
bool operator<(Point a, Point b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const double eps = 1e-8;
int dcmp(double x)
{
	if (fabs(x) < eps)
		return 0;
	else
		return x < 0 ? -1 : 1;
}
bool operator==(Point a, Point b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

//å¹³æ¹
double sqr(double x)
{
	return x * x;
}
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C)
{
	return Cross(B - A, C - A);
}

//ç¹ç§¯
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
//é¿åº¦
double Length(Vector A) { return sqrt(Dot(A, A)); }
//å¤¹è§
double Angle(Vector A, Vector B)
{
	return acos(Dot(A, B) / Length(A) / Length(B));
}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}
Vector Normal(const Vector &A)
{//è®¡ç®åä½æ³åé
	double L = Length(A);
	return Vector(-A.y / L, A.x / L);
}
double DistanceToline(Point P, Point A, Point B)
{
	Vector v1 = B - A, v2 = P - A;
	return fabs(Cross(v1, v2)) / Length(v1);
}

double DistanceToSegment(Point P, Point A, Point B)
{
	if (A == B)
		return Length(P - A);
	Vector v1 = B - A, v2 = P - A, v3 = P - B;
	if (dcmp(Dot(v1, v2)) > 0)
		return Length(v2);
	else if (dcmp(Dot(v1, v3)) > 0)
		return Length(v3);
	else
		return fabs(Cross(v1, v2)) / Length(v1);
}

//çº¿æ®µç¸äº¤å¤å®
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
				 c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
	return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//çº¿æ®µç¸äº¤æ¯å¦å¨ç«¯ç¹ä¸
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}

double PolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
}

int ConvexHull(Point *p, int n, Point *ch)//æ±å¸å
{
	sort(p, p + n);
	n = unique(p, p + n) - p;
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	int k = m;
	for (int i = n - 2; i >= 0; i--)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}
	if (n > 1)
		m--;
	return m;
}
double RotatingCalipers(Point *ch, int n)//æè½¬å¡å£³
{
	int q = 1;
	double ans = 0;
	for (int i = 0; i < n; i++)
	{
		while (Cross(ch[i + 1] - ch[i], ch[q + 1] - ch[i]) > Cross(ch[i + 1] - ch[i], ch[q] - ch[i]))
			q = (q + 1) % n;
		ans = max(ans, max(Length(ch[i] - ch[q]), Length(ch[i + 1] - ch[q + 1])));
	}
	return ans;
}

bool OnLeft(Line L, Point p)
{
	return Cross(L.v, p - L.P) > 0;
}
Point GetIntersection(Line a, Line b)
{
	Vector u = a.P - b.P;
	double t = Cross(b.v, u) / Cross(a.v, b.v);
	return a.P + a.v * t;
}

//å·ænä¸ªé¡¶ç¹(0-n-1)çå¤è¾¹å½¢çé¢ç§¯
double ConvexPolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 1; i < n - 1; i++)
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	return area / 2;
}
int HalfplaneIntersection(Line *L, int n, Point *poly)
{
	sort(L, L + n);
	int first, last;
	Point *p = new Point[n];
	Line *q = new Line[n];
	q[first = last = 0] = L[0];
	for (int i = 1; i < n; ++i)
	{
		while (first < last && !OnLeft(L[i], p[last - 1]))
			last--;
		while (first < last && !OnLeft(L[i], p[first]))
			first++;
		q[++last] = L[i];
		if (fabs(Cross(q[last].v, q[last - 1].v)) < eps)
		{
			last--;
			if (OnLeft(q[last], L[i].P))
				q[last] = L[i];
		}
		if (first < last)
			p[last - 1] = GetIntersection(q[last - 1], q[last]);
	}
	while (first < last && !OnLeft(q[first], p[last - 1]))
		last--;
	if (last - first <= 1)
		return 0;
	p[last] = GetIntersection(q[last], q[first]);

	int m = 0;
	for (int i = first; i <= last; i++)
		poly[m++] = p[i];
	return m;
}
Line L[MAXN];
Point poly[MAXN];
Point p[MAXN], ch[MAXN];
Vector d[MAXN], v[MAXN], v2[MAXN];
int n, m, num;
int tt;
double x, y, z, px, py;
int main()
{
	//freopen("a.txt","r",stdin);
	cin >> tt;
	while (tt--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		for (int i = n - 1; i >= 1; i--)
		{
			L[i] = Line(p[i], p[i - 1] - p[i]);
		}
		L[0] = Line(p[0], p[n - 1] - p[0]);
		int m = HalfplaneIntersection(L, n, poly);
		double ans = ConvexPolygonArea(poly, m);
		printf("%.2lf\n", ans);
	}

	return 0;
}
