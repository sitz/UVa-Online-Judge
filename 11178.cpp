#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y;
	Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
typedef Point Vector;
Vector operator+(Vector A, Vector B)
{
	return Vector(A.x + B.x, A.y + B.y);
}
Vector operator-(Vector A, Vector B)
{
	return Vector(A.x - B.x, A.y - B.y);
}
Vector operator*(Vector A, double p)
{
	return Vector(A.x * p, A.y * p);
}
Vector operator/(Vector A, double p)
{
	return Vector(A.x / p, A.y / p);
}
double Dot(Vector A, Vector B)
{
	return A.x * B.x + A.y * B.y;
}
double Length(Vector A)
{
	return sqrt(Dot(A, A));
}
double Angle(Vector A, Vector B)
{
	return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Vector A, Vector B)
{
	return A.x * B.y - A.y * B.x;
}
double Area(Point A, Point B, Point C)
{
	return Cross(B - A, C - A);
}
Vector Rotate(Vector A, double rad)
{
	return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}
Point GetPoint(Point P, Vector v, Point Q, Vector w)
{
	Vector u = P - Q;
	double t = Cross(w, u) / Cross(v, w);
	return P + v * t;
}

Point GetAns(Point A, Point B, Point C)
{
	Vector v1 = C - B;
	double a1 = Angle(A - B, v1);
	v1 = Rotate(v1, a1 / 3);
	Vector v2 = B - C;
	double a2 = Angle(A - C, v2);
	v2 = Rotate(v2, -a2 / 3);
	return GetPoint(B, v1, C, v2);
}

int main()
{
	int test;
	Point A, B, C, D, E, F;
	scanf("%d", &test);
	for (int cas = 1; cas <= test; cas++)
	{
		scanf("%lf%lf", &A.x, &A.y);
		scanf("%lf%lf", &B.x, &B.y);
		scanf("%lf%lf", &C.x, &C.y);
		D = GetAns(A, B, C);
		E = GetAns(B, C, A);
		F = GetAns(C, A, B);
		printf("%.6lf %.6lf ", D.x, D.y);
		printf("%.6lf %.6lf ", E.x, E.y);
		printf("%.6lf %.6lf\n", F.x, F.y);
	}
	return 0;
}
