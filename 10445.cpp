#include <bits/stdc++.h>

using namespace std;

typedef long double elem;
typedef complex<elem> point, vec;

const elem eps = 1.0e-10;
const elem pi = acos(-1.0);

inline elem deg(elem rad)
{
	return (rad / pi) * 180;
}
bool eq(elem a, elem b)
{
	return abs(b - a) < eps;
}
bool lessthan(elem a, elem b)
{
	return !eq(a, b) && a < b;
}
elem dot(vec a, vec b)
{
	return a.real() * b.real() + a.imag() * b.imag();
}
elem cross(vec a, vec b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}
elem len(vec v)
{
	return abs(v);
}
elem Radians(vec a, vec b)
{
	return acos(dot(a, b) / (len(a) * len(b)));
}

bool isRight(vec base, vec isv)
{
	if (eq(cross(base, isv), 0))
	{
		return len(isv) < len(base);
	}
	else
	{
		return lessthan(cross(base, isv), 0);
	}
}
bool isLeft(vec base, vec isv)
{
	if (eq(cross(base, isv), 0))
	{
		return len(isv) < len(base);
	}
	else
	{
		return lessthan(0, cross(base, isv));
	}
}

struct Point
{
	int id;
	point p;
	Point() : p(0, 0) {}
	Point(point p) : p(p) {}
	bool operator<(const Point &t) const
	{
		if (p.imag() < t.p.imag())
		{
			return true;
		}
		else if (eq(p.imag(), t.p.imag()))
		{
			return p.real() < t.p.real();
		}
		return false;
	}
};

int main()
{
	while (true)
	{
		int n;
		elem min_rad = 2 * pi, max_rad = 0;
		bool brevclk = true;
		cin >> n;
		if (n < 3)
		{
			break;
		}
		vector<Point> vp, tmpvp;
		for (int i = 0; i < n; ++i)
		{
			elem x, y;
			cin >> x >> y;
			Point p(point(x, y));
			p.id = i;
			vp.push_back(p);
		}
		Point topmost;
		topmost = vp[0];
		for (int i = 0; i < n; ++i)
		{
			if (topmost < vp[i])
			{
				topmost = vp[i];
			}
		}
		//cout << topmost.p << endl;
		if (isLeft(vec(topmost.p - vp[(topmost.id - 1 + n) % n].p), vec(vp[(topmost.id + 1) % n].p - topmost.p)))
		{
			brevclk = true;
		}
		else
		{
			brevclk = false;
		}
		for (int i = 0; i < n; ++i)
		{
			point p = vp[(i + 1) % n].p;
			point a = vp[i].p;
			point b = vp[(i + 2) % n].p;
			vec pa = a - p;
			vec pb = b - p;
			elem rad = Radians(pa, pb);
			bool rev = brevclk ? isLeft(pa, pb) : isRight(pa, pb);
			if (rev)
			{
				rad = 2 * pi - rad;
			}
			max_rad = max(max_rad, rad);
			min_rad = min(min_rad, rad);
		}
		printf("%.6Lf %.6Lf\n", deg(min_rad), deg(max_rad));
	}
	return 0;
}
