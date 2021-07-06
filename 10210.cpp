#include <bits/stdc++.h>

using namespace std;

typedef long double elem;
typedef complex<elem> point, vec;

const elem pi = acos(-1.0);

elem rad(elem deg)
{
	return (deg / 180) * pi;
}
elem dist(point a, point b)
{
	return abs(b - a);
}
elem cross(vec a, vec b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}
vec uvec(vec v)
{
	return v / abs(v);
}
vec norml(vec v)
{
	return v * vec(0, 1);
}
vec normr(vec v)
{
	return v * vec(0, -1);
}
vec unorml(vec v)
{
	return uvec(norml(v));
}
vec unormr(vec v)
{
	return uvec(normr(v));
}
vec rot(vec v, elem deg)
{
	return v * exp(point(0, rad(deg)));
}

point intersection(point a1, point a2, point b1, point b2)
{
	vec a = a2 - a1;
	vec b = b2 - b1;
	return a1 + (cross(b, b1 - a1) / cross(b, a)) * (a2 - a1);
}

elem RomeoAndJuliet(point a, point b, elem CMD, elem ENF)
{
	elem ret = 0;
	vec ba = a - b;
	vec uam = unormr(ba);
	vec ubm = rot(uam, CMD);
	vec uan = unorml(ba);
	vec ubn = rot(uan, -ENF);
	point M = intersection(a, a + uam, b, b + ubm);
	point N = intersection(a, a + uan, b, b + ubn);
	ret = max(ret, dist(M, N));
	uan = uvec(rot(vec(b - a), -CMD));
	ubn = uvec(rot(vec(b - a), -(CMD + ENF)));
	N = intersection(a, a + uan, b, b + ubn);
	ret = max(ret, dist(N, a));
	return ret;
}

int main()
{
	while (true)
	{
		elem x1, y1, x2, y2, CMD, ENF;
		if (6 != scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2, &CMD, &ENF))
		{
			break;
		}
		printf("%.3Lf\n", RomeoAndJuliet(point(x1, y1), point(x2, y2), CMD, ENF));
	}
	return 0;
}
