#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int sgn(const double x)
{
	return fabs(x) < eps ? 0 : x < -eps ? -1 : 1;
}

#define sqr(x) ((x) * (x))
#define REP(i, x) for (int i = 0; i < x; i++)
#define rep(i, j, k) for (int(i) = (j); (i) < (k); (i)++)
#define maxn 50005
#define maxm maxn

struct matrix
{
	int r, c;
	double v[10][10];
	matrix() {}
	matrix(int a, int b) : r(a), c(b)
	{
		REP(i, r)
		fill(v[i], v[i] + c, 0.0);
		if (r == c)
		{
			REP(i, r)//unit matrix as default matrix
			v[i][i] = 1;
		}
	}
	void init()
	{
		REP(i, r)
		fill(v[i], v[i] + c, 0.0);
		if (r == c)
		{
			REP(i, r)//unit matrix as default matrix
			v[i][i] = 1;
		}
	}
	matrix operator*(const matrix p)
	{
		matrix ans(r, p.c);
		REP(i, r)
		REP(j, ans.c)
		{
			double tmp = 0.0;
			REP(k, c)
			tmp += v[i][k] * p.v[k][j];
			ans.v[i][j] = tmp;
		}
		return ans;
	}
	void print()
	{
		rep(i, 0, r)
				rep(j, 0, c)
						printf("%.2lf%c", v[i][j], j == c - 1 ? '\n' : ' ');
	}
};
struct Tpoint
{
	double x, y, z;
	Tpoint() {}
	Tpoint(double a, double b, double c) : x(a), y(b), z(c) {}
	Tpoint operator-(const Tpoint p)
	{
		return Tpoint(x - p.x, y - p.y, z - p.z);
	}
	Tpoint operator+(const Tpoint p)
	{
		return Tpoint(x + p.x, y + p.y, z + p.z);
	}
	double operator*(const Tpoint p)
	{
		return x * p.x + y * p.y + z * p.z;
	}
	Tpoint operator^(const Tpoint p)
	{
		return Tpoint(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x);
	}
	bool operator==(const Tpoint p)
	{
		return sgn(x - p.x) == 0 && sgn(y - p.y) == 0 && sgn(z - p.z) == 0;
	}
	double norm2()
	{
		return (*this) * (*this);
	}
	double norm()
	{
		return sqrt(norm2());
	}
	Tpoint unit()
	{
		return Tpoint(x / norm(), y / norm(), z / norm());
	}
	Tpoint gao(matrix h)
	{
		matrix o(4, 1);
		o.v[0][0] = x;
		o.v[1][0] = y;
		o.v[2][0] = z;
		o.v[3][0] = 1;
		o = h * o;
		return Tpoint(o.v[0][0], o.v[1][0], o.v[2][0]);
	}
	void scan()
	{
		scanf("%lf%lf%lf", &x, &y, &z);
	}
	void print()
	{
		printf("%.2lf %.2lf %.2lf\n", x, y, z);
	}
} pt[maxn];
Tpoint tZero(0, 0, 0);
struct Tplane
{
	double a, b, c, d;
	//a + b + c = d
	Tplane() {}
	Tplane(double e, double f, double g, double h) : a(e), b(f), c(g), d(-h) {}
	//return a perpendicular vector of the given plane
	Tpoint ndir()
	{
		return Tpoint(a, b, c);
	}
	//shifting transform
	double norm2()
	{
		return sqr(a) + sqr(b) + sqr(c);
	}
	double norm()
	{
		return sqrt(norm2());
	}
	Tplane unit()
	{
		return Tplane(a / norm(), b / norm(), c / norm(), -d / norm());
	}
	void print()
	{
		printf("%.2lf %.2lf %.2lf %.2lf\n", a, b, c, -d);
	}
} tp[maxm];
int n, m, t;
char opt[15];
int main()
{
	double a, b, c, d;
	scanf("%d %d %d", &n, &m, &t);
	REP(i, n)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		pt[i] = Tpoint(a, b, c);
	}
	REP(i, m)
	{
		scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
		tp[i] = Tplane(a, b, c, d);
	}
	matrix handle(4, 4), tran(4, 4);
	REP(i, t)
	{
		scanf("%s", opt);
		if (opt[0] == 'T')
		{
			scanf("%lf %lf %lf", &a, &b, &c);
			tran.init();
			tran.v[0][3] = a;
			tran.v[1][3] = b;
			tran.v[2][3] = c;
			handle = tran * handle;
		}
		else if (opt[0] == 'R')
		{
			scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
			tran.init();
			double t = d / 180.0 * pi;
			double ct = cos(t), st = sin(t);
			double tmp = sqrt(a * a + b * b + c * c);
			a /= tmp;
			b /= tmp;
			c /= tmp;
			tran.v[0][0] = (1.0 - ct) * a * a + ct;
			tran.v[0][1] = (1.0 - ct) * a * b - st * c;
			tran.v[0][2] = (1.0 - ct) * a * c + st * b;
			tran.v[1][0] = (1.0 - ct) * b * a + st * c;
			tran.v[1][1] = (1.0 - ct) * b * b + ct;
			tran.v[1][2] = (1.0 - ct) * b * c - st * a;
			tran.v[2][0] = (1.0 - ct) * c * a - st * b;
			tran.v[2][1] = (1.0 - ct) * c * b + st * a;
			tran.v[2][2] = (1.0 - ct) * c * c + ct;
			handle = tran * handle;
		}
		else if (opt[0] == 'S')
		{
			scanf("%lf %lf %lf", &a, &b, &c);
			tran.init();
			tran.v[0][0] = a;
			tran.v[1][1] = b;
			tran.v[2][2] = c;
			handle = tran * handle;
		}
	}
	REP(i, n)
	{
		pt[i] = pt[i].gao(handle);
		pt[i].print();
	}
	REP(i, m)
	{
		a = tp[i].a, b = tp[i].b, c = tp[i].c, d = tp[i].d;
		double limit = max(fabs(a), max(fabs(b), fabs(c)));
		Tpoint on[3];
		if (fabs(a) == limit)
		{
			on[0] = Tpoint(d / a, 0, 0);
			on[1] = Tpoint((d - b) / a, 1, 0);
			on[2] = Tpoint((d - c) / a, 0, 1);
		}
		else if (fabs(b) == limit)
		{
			on[0] = Tpoint(0, d / b, 0);
			on[1] = Tpoint(1, (d - a) / b, 0);
			on[2] = Tpoint(0, (d - c) / b, 1);
		}
		else
		{
			on[0] = Tpoint(0, 0, d / c);
			on[1] = Tpoint(1, 0, (d - a) / c);
			on[2] = Tpoint(0, 1, (d - b) / c);
		}
		rep(j, 0, 3)
				on[j] = on[j].gao(handle);
		Tpoint dir = (on[2] - on[0]) ^ (on[1] - on[0]);
		tp[i] = Tplane(dir.x, dir.y, dir.z, -(dir * on[0]));
		tp[i].unit().print();
	}
	return 0;
}
