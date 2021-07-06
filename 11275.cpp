#include <bits/stdc++.h>

using namespace std;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x, y) memset(x, y, sizeof(x))
#define CLR(x) x.clear()
#define ph(x) push(x)
#define pb(x) push_back(x)
#define Len(x) x.length()
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x) * (x))
#define MP(x, y) make_pair(x, y)
#define EPS 1e-10

#define FOR0(i, x) for (i = 0; i < x; i++)
#define FOR1(i, x) for (i = 1; i <= x; i++)
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define FORL0(i, a) for (i = a; i >= 0; i--)
#define FORL1(i, a) for (i = a; i >= 1; i--)
#define FORL(i, a, b) for (i = a; i >= b; i--)

#define rush() \
	int CC;      \
	for (scanf("%d", &CC); CC--;)
#define Rush(n) while (scanf("%d", &n) != -1)

void RD(int &x) { scanf("%d", &x); }
void RD(i64 &x) { scanf("%lld", &x); }
void RD(u64 &x) { scanf("%I64u", &x); }
void RD(u32 &x) { scanf("%u", &x); }
void RD(double &x) { scanf("%lf", &x); }
void RD(int &x, int &y) { scanf("%d%d", &x, &y); }
void RD(i64 &x, i64 &y) { scanf("%lld%lld", &x, &y); }
void RD(u32 &x, u32 &y) { scanf("%u%u", &x, &y); }
void RD(double &x, double &y) { scanf("%lf%lf", &x, &y); }
void RD(double &x, double &y, double &z) { scanf("%lf%lf%lf", &x, &y, &z); }
void RD(int &x, int &y, int &z) { scanf("%d%d%d", &x, &y, &z); }
void RD(i64 &x, i64 &y, i64 &z) { scanf("%lld%lld%lld", &x, &y, &z); }
void RD(u32 &x, u32 &y, u32 &z) { scanf("%u%u%u", &x, &y, &z); }
void RD(char &x) { x = getchar(); }
void RD(char *s) { scanf("%s", s); }
void RD(string &s) { cin >> s; }

void PR(int x) { printf("%d\n", x); }
void PR(int x, int y) { printf("%d %d\n", x, y); }
void PR(i64 x) { printf("%lld\n", x); }
void PR(i64 x, i64 y) { printf("%lld %lld\n", x, y); }
void PR(u32 x) { printf("%u\n", x); }
void PR(u64 x) { printf("%llu\n", x); }
void PR(double x) { printf("%.10lf\n", x); }
void PR(double x, double y) { printf("%.3lf %.3lf\n", x, y); }
void PR(char x) { printf("%c\n", x); }
void PR(char *x) { printf("%s\n", x); }
void PR(string x) { cout << x << endl; }

const int mod = 10007;
const i64 inf = ((i64)1) << 40;
const double dinf = 1000000000000000000.0;
const int INF = 100000000;
const int N = 10005;

int sgn(double x)
{
	if (x > EPS)
		return 1;
	if (x < -EPS)
		return -1;
	return 0;
}

struct point
{
	double x, y;

	point() {}
	point(double _x, double _y)
	{
		x = _x;
		y = _y;
	}

	void get()
	{
		RD(x);
		RD(y);
	}

	point operator+(point a)
	{
		return point(x + a.x, y + a.y);
	}

	point operator-(point a)
	{
		return point(x - a.x, y - a.y);
	}

	double operator*(point a)
	{
		return x * a.y - y * a.x;
	}

	point operator*(double t)
	{
		return point(x * t, y * t);
	}

	double operator^(point a)
	{
		return x * a.x + y * a.y;
	}

	double len()
	{
		return sqrt(x * x + y * y);
	}

	void print()
	{
		printf("%.3lf %.3lf\n", x + EPS, y + EPS);
	}
};

double len(point a)
{
	return a.len();
}

struct point3
{
	double x, y, z;

	point3() {}
	point3(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void get()
	{
		RD(x);
		RD(y);
		RD(z);
	}

	point3 operator+(point3 a)
	{
		return point3(x + a.x, y + a.y, z + a.z);
	}

	point3 operator-(point3 a)
	{
		return point3(x - a.x, y - a.y, z - a.z);
	}

	point3 operator*(point3 a)
	{
		return point3(y * a.z - z * a.y, z * a.x - x * a.z, x * a.y - y * a.x);
	}

	point3 operator*(double t)
	{
		return point3(x * t, y * t, z * t);
	}

	double operator^(point3 a)
	{
		return x * a.x + y * a.y + z * a.z;
	}

	point3 operator/(double t)
	{
		return point3(x / t, y / t, z / t);
	}

	double len()
	{
		return sqrt(x * x + y * y + z * z);
	}

	point3 adjust(double L)
	{
		double t = len();
		L /= t;
		return point3(x * L, y * L, z * L);
	}

	void print()
	{
		printf("%.10lf %.10lf %.10lf\n", x + EPS, y + EPS, z + EPS);
	}
};

double len(point3 a)
{
	return a.len();
}

int opposite(point3 p, point3 q, point3 a, point3 b, point3 c)
{
	point3 v = (b - a) * (c - a);
	double x = v ^ (p - a);
	double y = v ^ (q - a);
	return sgn(x * y) <= 0;
}

int segCrossTri(point3 p, point3 q, point3 a, point3 b, point3 c)
{
	return opposite(p, q, a, b, c) &&
				 opposite(a, b, p, q, c) &&
				 opposite(a, c, p, q, b) &&
				 opposite(b, c, p, q, a);
}

point3 a1, b1, c1, a2, b2, c2;

int main()
{
	rush()
	{
		a1.get();
		b1.get();
		c1.get();

		a2.get();
		b2.get();
		c2.get();

		if (segCrossTri(a1, b1, a2, b2, c2) ||
				segCrossTri(a1, c1, a2, b2, c2) ||
				segCrossTri(b1, c1, a2, b2, c2) ||
				segCrossTri(a2, b2, a1, b1, c1) ||
				segCrossTri(a2, c2, a1, b1, c1) ||
				segCrossTri(b2, c2, a1, b1, c1))
		{
			puts("1");
		}
		else
			puts("0");
	}
}
