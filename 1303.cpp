#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
struct Point
{
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef Point Vector;

Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }

Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }

Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }

Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }

bool operator<(Point a, Point b)
{
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
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

double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
double PolygonArea(Point *p, int n)
{
	double area = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		area += Cross(p[i] - p[0], p[i + 1] - p[0]);
	}
	return area / 2;
}
//éæ¶éæè½¬ radå¼§åº¦
Vector Rotate(Vector A, double rad)
{
	return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}

//æ±å¸åç¹é
int ConvexHull(Point *p, int n, Point *ch)
{
	sort(p, p + n);
	n = unique(p, p + n) - p;//å»é
	int m = 0;
	for (int i = 0; i < n; ++i)
	{
		while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}

	int k = m;
	for (int i = n - 2; i >= 0; --i)
	{
		while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0)
			m--;
		ch[m++] = p[i];
	}

	if (n > 1)
		m--;
	return m;
}
double sqr(double x)
{
	return x * x;
}
//ç¹ç§¯
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }

double Length(Vector A) { return sqrt(Dot(A, A)); }
double torad(double deg)
{
	return deg / 180 * acos(-1);
}
Point P[1009], ch[1009];
int main()
{
	// freopen("in.txt","r",stdin);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &P[i].x, &P[i].y);
		}
		int m = ConvexHull(P, n, ch);
		double ans = 0;
		for (int i = 1; i < m; i++)
		{
			Vector o(ch[i].x - ch[i - 1].x, ch[i].y - ch[i - 1].y);
			ans += Length(o);
		}
		Vector o(ch[m - 1].x - ch[0].x, ch[m - 1].y - ch[0].y);
		ans += Length(o);
		ans += 2 * pi * l;
		printf("%.0lf\n", ans);
		if (t != 0)
			printf("\n");
	}
	return 0;
}
