#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3;

struct Point
{
	double x, y;
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
} p[MAXN], m[MAXN];

struct Line
{
	double A, B, C;
} l[MAXN];

Point get_pt(Point a, Point b)
{
	double x = a.x + (b.x - a.x) * 2 / 3;
	double y = a.y + (b.y - a.y) * 2 / 3;
	return (Point){x, y};
}

Line get_line(Point a, Point b)
{
	double A = b.y - a.y;
	double B = a.x - b.x;
	double C = a.y * b.x - a.x * b.y;
	return (Line){A, B, C};
}

Point get_c_pt(Line a, Line b)
{
	double x = (a.B * b.C - a.C * b.B) / (a.A * b.B - b.A * a.B);
	double y = (b.C * a.A - a.C * b.A) / (a.B * b.A - a.A * b.B);
	return (Point){x, y};
}

double area(Point a, Point b, Point c)
{
	double A = a.x * b.y - b.x * a.y;
	double B = b.x * c.y - c.x * b.y;
	double C = c.x * a.y - a.x * c.y;
	return fabs((A + B + C) / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		for (int i = 0; i < MAXN; i++)
		{
			p[i].input();
		}

		for (int i = 0; i < MAXN; i++)
		{
			m[i] = get_pt(p[i], p[(i + 1) % MAXN]);
		}

		for (int i = 0; i < MAXN; i++)
		{
			l[i] = get_line(p[i], m[(i + 1) % MAXN]);
		}

		for (int i = 0; i < MAXN; i++)
		{
			p[i] = get_c_pt(l[i], l[(i + 1) % MAXN]);
		}

		printf("%.0lf\n", area(p[0], p[1], p[2]));
	}
	return 0;
}
