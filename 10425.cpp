#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y, z;
} p[3];
double r1, r2, a, b, c, d;
char name[10];
double dist(Point a, Point b)
{
	double dx = a.x - b.x, dy = a.y - b.y, dz = a.z - b.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}
void print(bool s)
{
	if (s == true)
	{
		puts("y");
	}
	else
	{
		puts("n");
	}
}
int main()
{
	bool in1, in2, s, stat;
	while (scanf("%s", name) == 1)
	{
		scanf("%lf %lf %lf %lf", &p[0].x, &p[0].y, &p[0].z, &r1);
		scanf("%lf %lf %lf %lf", &p[1].x, &p[1].y, &p[1].z, &r2);
		scanf("%lf %lf %lf", &p[2].x, &p[2].y, &p[2].z);
		puts(name);
		in1 = (dist(p[0], p[2]) < r1 || fabs(dist(p[0], p[2]) - r1) < 1e-7) ? true : false;
		in2 = (dist(p[1], p[2]) < r2 || fabs(dist(p[1], p[2]) - r2) < 1e-7) ? true : false;
		a = (p[0].x - p[1].x) * (-2);
		b = (p[0].y - p[1].y) * (-2);
		c = (p[0].z - p[1].z) * (-2);
		d = (r1 * r1 - r2 * r2);
		d -= (p[0].x * p[0].x - p[1].x * p[1].x + p[0].y * p[0].y - p[1].y * p[1].y + p[0].z * p[0].z - p[1].z * p[1].z);
		stat = (fabs(a * p[2].x + b * p[2].y + c * p[2].z - d) < 1e-7) ? true : false;
		s = (in1 && !in2 || !in1 && in2 || in1 && in2 && !stat);
		print(in1);
		print(in2);
		print(s);
	}
	return 0;
}
