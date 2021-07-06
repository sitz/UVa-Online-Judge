#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INT (0x3f3f3f3f) * 2
#define LL (0x3f3f3f3f3f3f3f3f) * 2

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
const double eps = 1e-9;
inline int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	else if (x > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
struct Point
{
	double x, y;
	Point(){};
	Point(double xx, double yy)
	{
		x = xx, y = yy;
	}
};
typedef Point Vector;
Vector operator+(const Vector a, const Vector b)
{
	return Vector(a.x + b.x, a.y + b.y);
}
Vector operator-(const Vector a, const Vector b)
{
	return Vector(a.x - b.x, a.y - b.y);
}
double operator*(const Vector a, const Vector b)
{
	return a.x * b.x + a.y * b.y;
}
double Length(Vector v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}
double angle(Vector a, Vector b)
{
	return acos((a * b) / (Length(a) * Length(b)));
}
double W, H, x, xe, ye, u;
int main()
{
	//freopen("/Users/peteryuanpan/data.txt","r",stdin);
	int T = read();
	for (int kase = 1; kase <= T; kase++)
	{
		W = read(), H = read(), x = read(), xe = read(), ye = read();
		scanf("%lf", &u);
		Vector AE = Point(xe, ye) - Point(W, H);
		Vector V = Vector(0, 1);
		double a = angle(AE, V);
		double tana = (W - xe) / (H - ye);
		double b = asin(sin(a) / u);
		double h = (W - x - H * tana) / (tan(b) - tana);
		if ((h - H) > (3e-6))
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%.4f\n", h);
		}
	}
	return 0;
}
