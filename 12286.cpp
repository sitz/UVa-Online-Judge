#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const LD eps = 1e-18;

struct Point
{
	double x, y;
	Point(LD _x = 0, LD _y = 0) : x(_x), y(_y) {}

	Point operator+(const Point &rhs) const
	{
		return Point(x + rhs.x, y + rhs.y);
	}
	Point operator-(const Point &rhs) const
	{
		return Point(x - rhs.x, y - rhs.y);
	}
	Point operator*(LD d) const
	{
		return Point(x * d, y * d);
	}
	Point operator/(LD d) const
	{
		return Point(x / d, y / d);
	}
};

Point d[4] = {Point(0, 1), Point(0, -1), Point(1, 0), Point(-1, 0)};
Point p[3];

int dcmp(LD x)
{
	return x < -eps ? -1 : x > eps;
}

LD sqrt_(LD x)
{
	if (!dcmp(x))
	{
		return 0;
	}
	return sqrt(x);
}

LD abs(Point p)
{
	return sqrt_(p.x * p.x + p.y * p.y);
}

LD dis(Point q)
{
	return abs(q - p[0]) + abs(q - p[1]) * 2 + abs(q - p[2]) * 2;
}

LD calc()
{
	Point now = (p[0] + p[1] + p[2]) / 3.0;
	for (LD step = 1e4; dcmp(step) > 0; step /= 2)
	{
		bool flag = true;
		while (flag)
		{
			flag = false;
			for (int i = 0; i < 4; i++)
			{
				Point cnt = now + d[i] * step;
				if (dcmp(dis(cnt) - dis(now)) < 0)
				{
					now = cnt;
					flag = true;
					break;
				}
			}
		}
	}
	return dis(now);
}

int main()
{
	int t = 0;
	while (true)
	{
		int x1, y1, x2, y2, x3, y3;
		scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
		if (x1 == -1)
		{
			break;
		}
		p[0] = Point((LD)x1, (LD)y1);
		p[1] = Point((LD)x2, (LD)y2);
		p[2] = Point((LD)x3, (LD)y3);
		LD ans = 1e20;
		for (int i = 0; i < 3; i++)
		{
			swap(p[0], p[i]);
			ans = min(ans, calc());
		}
		printf("Case %d: %.8lf\n", ++t, (double)ans);
	}
	return 0;
}
