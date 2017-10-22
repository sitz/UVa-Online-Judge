#include <bits/stdc++.h>

using namespace std;

#define EPS 1.0e-10
#define PI (acos(-1.0))
#define ALPHA 0.000001

typedef long double elem;
typedef complex<elem> point, vec;
typedef pair<point, point> line;

bool eq(elem a, elem b)
{
	return abs(a - b) < EPS;
}

bool lessthan(elem a, elem b)
{
	return !eq(a, b) && a < b;
}

elem cross(point a, point b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

elem len(vec a)
{
	return abs(a);
}

vec uvec(vec x)
{
	return x / abs(x);
}

vec norml(vec x)
{
	return x * vec(0, 1);
}

vec unorml(vec x)
{
	return norml(x) / len(x);
}

bool prll(point a1, point a2, point b1, point b2)
{
	return eq(cross(a2 - a1, b2 - b1), 0);
}

bool intersected(line a, line b)
{
	return !prll(a.first, a.second, b.first, b.second);
}

point intersection(line a, line b)
{
	vec va = a.second - a.first;
	vec vb = b.second - b.first;
	return a.first +
				 (cross(vb, b.first - a.first) / cross(vb, va)) *
						 (a.second - a.first);
}

bool LineCrossPoint(line a, line b, point &ret)
{
	if (intersected(a, b))
	{
		ret = intersection(a, b);
	}
	else
	{
		return false;
	}
	return true;
}

elem Circumference(elem r)
{
	return 2.0 * r * PI;
}

point InscribedCircleCenter(point a, point b, point c)
{
	elem A = len(vec(c - b));
	elem B = len(vec(c - a));
	elem C = len(vec(b - a));
	elem S = A + B + C;
	return (A / S) * a + (B / S) * b + (C / S) * c;
}

elem AreaOfTriangle(elem a, elem b, elem c)
{
	elem s = (a + b + c) / 2.0;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}

elem InradiusOfTriangle(point a, point b, point c)
{
	elem A = len(vec(c - b));
	elem B = len(vec(c - a));
	elem C = len(vec(b - a));
	return 2 * AreaOfTriangle(A, B, C) / (A + B + C);
}

elem Solve(elem b, elem h)
{
	elem ret = 0;
	point center = InscribedCircleCenter(point(0, 0),
																			 point(-b / 2, -h),
																			 point(b / 2, -h));
	line upper_edge = line(point(0, 0), point(-b / 2, -h));
	line downer_edge = line(point(0, 0), point(b / 2, -h));
	vector<elem> rs;
	rs.push_back(InradiusOfTriangle(point(0, 0),
																	point(-b / 2, -h),
																	point(b / 2, -h)));
	while (lessthan(ALPHA, rs.back()))
	{
		elem next = len(center) - rs.back();
		point p = next * uvec(center);
		point upper_cross, downer_cross;
		LineCrossPoint(line(p, p + unorml(p)), upper_edge, upper_cross);
		LineCrossPoint(line(p, p + unorml(p)), downer_edge, downer_cross);
		rs.push_back(InradiusOfTriangle(point(0, 0),
																		upper_cross,
																		downer_cross));
		center = InscribedCircleCenter(point(0, 0),
																	 downer_cross,
																	 upper_cross);
	}
	rs.pop_back();
	for (unsigned int i = 0; i < rs.size(); ++i)
	{
		ret += Circumference(rs[i]);
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i)
	{
		elem B, H;
		scanf("%Lf%Lf", &B, &H);
		printf("%13.6Lf\n", Solve(B, H));
		if (i != T - 1)
		{
			puts("");
		}
	}
	return 0;
}
