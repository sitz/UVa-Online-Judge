#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)

const double PI = acos(-1);
const double EPS = 1e-12;

struct PT
{
	double x, y, r;
	PT() {}
	PT(double x, double y, double r = 0) : x(x), y(y), r(r) {}
	PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator*(double c) const { return PT(x * c, y * c); }
	PT operator/(double c) const { return PT(x / c, y / c); }
} Center, Cannon;

double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
PT RotateCCW(PT p, double t) { return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t)); }
double norm(PT p) { return sqrt(dot(p, p)); }
double ang(PT p, PT q) { return acos(dot(p, q) / (norm(p) * norm(q))); }
//Centro a, pontos da borda b e c, raio da circunferencia r
double areaCircleSeg(PT c, PT p, PT q, double r) { return fabs(r * r * (ang(p - c, q - c) - sin(ang(p - c, q - c))) / 2.0); }

vector<PT> CLIntersect(PT a, PT b, PT c)
{
	PT _a = a, _b = b;
	double r = c.r;
	vector<PT> ret;
	b = b - a;
	a = a - c;
	double A = dot(b, b);
	double B = dot(a, b);
	double C = dot(a, a) - r * r;
	double D = B * B - A * C;
	if (D < -EPS)
		return ret;
	ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
	if (D > EPS)
		ret.push_back(c + a + b * (-B - sqrt(D)) / A);
	//printf("> %lf %lf, %lf %lf, %lf %lf\n", _a.x, _a.y, _b.x, _b.y, ret[0].x, ret[0].y);
	if (dot(_b - _a, ret[0] - _a) < 0)
		ret.clear();
	return ret;
}

double X, Y, R, A, T;
PT p1, p2;
vector<PT> v1, v2;

int main()
{
	PT eixoX = PT(1.0, 0.0);
	while (scanf("%lf%lf%lf", &X, &Y, &R) == 3 && R > 0)
	{
		Center = PT(X, Y, R);
		scanf("%lf%lf%lf%lf", &X, &Y, &A, &T);
		A *= PI / 180.0;
		T *= PI / 180.0;
		Cannon = PT(X, Y);
		T /= 2.0;
		p1 = RotateCCW(eixoX, A - T) + Cannon;
		p2 = RotateCCW(eixoX, A + T) + Cannon;
		//printf("%lf %lf, %lf %lf\n", p1.x, p1.y, p2.x, p2.y);
		if (cross(Center - Cannon, p1 - Cannon) * cross(Center - Cannon, p2 - Cannon) > 0)
		{
			if (cross(Center - Cannon, p1 - Cannon) < 0)
			{
				v1 = CLIntersect(Cannon, p1, Center);
				v2 = CLIntersect(Cannon, p2, Center);
			}
			else
			{
				v1 = CLIntersect(Cannon, p2, Center);
				v2 = CLIntersect(Cannon, p1, Center);
			}
			//printf("> %d %d\n", v1.size(), v2.size());
			if (v2.size() < 2)
				printf("0.0\n");
			else
			{
				if (v1.size() < 2)
					printf("%.1lf\n", areaCircleSeg(Center, v2[0], v2[1], R));
				else
					printf("%.1lf\n", areaCircleSeg(Center, v2[0], v2[1], R) - areaCircleSeg(Center, v1[0], v1[1], R));
			}
		}
		else
		{
			v1 = CLIntersect(Cannon, p1, Center);
			v2 = CLIntersect(Cannon, p2, Center);
			//printf("> %d %d %lf\n", v1.size(), v2.size(), PI*R*R);
			if (v1.size() < 2 && v2.size() < 2)
			{
				if (dot(RotateCCW(eixoX, A), Center - Cannon) < 0)
					printf("0.0\n");
				else
					printf("%.1lf\n", PI * R * R);
			}
			else if (v1.size() < 2)
			{
				if (dot(RotateCCW(eixoX, A), Center - Cannon) < 0)
					printf("%.1lf\n", areaCircleSeg(Center, v2[0], v2[1], R));
				else
					printf("%.1lf\n", PI * R * R - areaCircleSeg(Center, v2[0], v2[1], R));
			}
			else if (v2.size() < 2)
			{
				if (dot(RotateCCW(eixoX, A), Center - Cannon) < 0)
					printf("%.1lf\n", areaCircleSeg(Center, v1[0], v1[1], R));
				else
					printf("%.1lf\n", PI * R * R - areaCircleSeg(Center, v1[0], v1[1], R));
			}
			else
				printf("%.1lf\n", PI * R * R - areaCircleSeg(Center, v1[0], v1[1], R) - areaCircleSeg(Center, v2[0], v2[1], R));
		}
	}
	return 0;
}
