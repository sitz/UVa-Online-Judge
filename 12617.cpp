#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-6;
const int inf = 1000;
#define sqr(x) ((x) * (x))
inline int sign(double x)
{
	return x < -eps ? -1 : x > eps;
}

struct Point
{
	double x, y;
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	void rd()
	{
		scanf("%lf %lf", &x, &y);
	}
	void show()
	{
		cout << x << ' ' << y << endl;
	}
	Point operator-(const Point &o) const
	{
		return Point(x - o.x, y - o.y);
	}
	Point operator+(const Point &o) const
	{
		return Point(x + o.x, y + o.y);
	}
	Point operator*(double o) const
	{
		return Point(x * o, y * o);
	}
	Point operator/(double o)
	{
		return Point(x / o, y / o);
	}
	bool operator==(const Point &o) const
	{
		return sign(x - o.x) == 0 and sign(y - o.y) == 0;
	}
	double det(const Point &o)
	{
		return x * o.y - y * o.x;
	}
	double dot(const Point &o)
	{
		return x * o.x + y * o.y;
	}
	double abs()
	{
		return sqrt(sqr(x) + sqr(y));
	}
	Point unit()
	{
		return *this / abs();
	}
};

struct Segment
{
	Point a, b;
	Segment() {}
	Segment(Point a, Point b) : a(a), b(b) {}
	friend bool intersect(const Segment &u, const Segment &v)
	{
		return (max(u.a.x, u.b.x) >= min(v.a.x, v.b.x)) &&
					 (max(v.a.x, v.b.x) >= min(u.a.x, u.b.x)) &&
					 (max(u.a.y, u.b.y) >= min(v.a.y, v.b.y)) &&
					 (max(v.a.y, v.b.y) >= min(u.a.y, u.b.y)) &&
					 sign((v.a - u.a).det(u.b - u.a) * ((u.b - u.a).det(v.b - u.a))) >= 0 &&
					 sign((u.a - v.a).det(v.b - v.a) * ((v.b - v.a).det(u.b - v.a))) >= 0;
	}
	Point commonPoint(const Segment &o) const
	{
		double a1 = (o.b - a).det(o.a - a), a2 = (o.a - b).det(o.b - b);
		return Point((a.x * a2 + b.x * a1) / (a2 + a1), (a.y * a2 + b.y * a1) / (a2 + a1));
	}
};
int s, T, r;
Point p[7], a, b, dir;

inline double dis(const Point &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
inline double P2S(const Point &p, const Segment &s)
{
	if ((p - s.a).dot(s.b - s.a) > eps && (p - s.b).dot(s.a - s.b) > eps)
		return fabs((p - s.a).det(s.b - s.a)) / dis(s.b - s.a);
	return min(dis(p - s.a), dis(p - s.b));
}
Point rotate(const Segment &mirror, const Point &interPt)
{
	Point m_dir = (mirror.b - mirror.a).unit();
	Point cz_dir = Point(m_dir.y, -1 * m_dir.x).unit();
	Point tem = Segment(a - (m_dir * inf), a + (m_dir * inf)).commonPoint(Segment(interPt - (cz_dir * inf), interPt + (cz_dir * inf)));
	Point res = (tem * 2) - a;
	return (res - interPt).unit();
}
void solve()
{
	while (T > 0)
	{
		// cout << T << endl;
		Segment cur = Segment(a, a + (dir * inf));
		// cur.a.show();
		// cur.b.show();
		if (P2S(Point(0, 0), cur) < r + eps)
		{
			printf("%d\n", T);
			return;
		}
		for (int i = 0; i < 6; ++i)
		{
			if (intersect(cur, Segment(p[i], p[i + 1])))
			{
				Point interPt = cur.commonPoint(Segment(p[i], p[i + 1]));
				if (interPt == a)
					continue;
				// interPt.show();cout << "---" << endl;
				if (interPt == p[i] or interPt == p[i + 1])
				{
					a = interPt, dir = dir * -1;
					T -= 2;
				}
				else
				{
					dir = rotate(Segment(p[i], p[i + 1]), interPt);
					a = interPt;
					T -= 1;
				}
				break;
			}
		}
	}
	puts("Stops");
}

int main()
{
	int t, cas = 1;
	for (scanf("%d", &t); t--;)
	{
		printf("Case %d: ", cas++);
		scanf("%d", &s);
		p[0] = Point(0.5 * s, sqrt(3.0) * s / 2);
		p[1] = Point(s, 0);
		p[2] = Point(0.5 * s, -sqrt(3.0) * s / 2);
		p[3] = Point(-0.5 * s, -sqrt(3.0) * s / 2);
		p[4] = Point(-s, 0);
		p[5] = Point(-0.5 * s, sqrt(3.0) * s / 2);
		p[6] = p[0];
		a.rd();
		b.rd();
		scanf("%d %d", &r, &T);
		dir = (b - a).unit();
		solve();
	}
	return 0;
}
