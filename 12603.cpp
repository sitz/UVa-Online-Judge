#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for (int a = b; a < c; a++)
#define rp(a, b) fr(a, 0, b)
#define cl(a, b) memset((a), (b), sizeof(a))
#define EPS 1e-9

struct PT
{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT operator+(const PT &p) const { return PT(x + p.x, y + p.y); }
	PT operator-(const PT &p) const { return PT(x - p.x, y - p.y); }
	PT operator*(double c) const { return PT(x * c, y * c); }
	PT operator/(double c) const { return PT(x / c, y / c); }
};

double dot(PT p, PT q)
{
	return p.x * q.x + p.y * q.y;
}

PT Project(PT a, PT b, PT c)
{
	return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}

double dist2(PT p, PT q)
{
	return dot(p - q, p - q);
}

double dist(PT a, PT b, PT c)
{
	return sqrt(dist2(c, Project(a, b, c)));
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		double T, x;
		scanf("%lf", &T);
		T *= 100.0f;
		scanf("%lf", &x);
		double xd = x;
		xd = (xd / 360.0f) * 2 * M_PI;
		xd = (M_PI / 2.0f) - xd;
		double alfa = tan(xd) * 42.50f;
		double L = 85.0f * tan(xd);
		int qnts = floor((T - alfa) / L);
		double xf = T - qnts * L - alfa;
		double yf = (qnts % 2 == 0) ? 10.0f : 95.0f;
		PT b = PT(xf - alfa, (qnts % 2 == 0) ? (yf + 42.50f) : (yf - 42.50f));
		double D = dist(PT(xf, yf), b, PT(0.0f, 52.500f));
		char sim = 0;
		sim = (D - 16.0f < EPS);
		if (sim)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
