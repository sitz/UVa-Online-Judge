#include <bits/stdc++.h>

using namespace std;

//#pragma comment(linker, "/STACK:16777216")

typedef long long LL;
const int N = 2005;

const double eps = 1e-6, pi = acos(-1.0);
inline int dcmp(double x)
{
	return (x > eps) - (x < -eps);
}

struct Point
{
	double x, y;
	Point()
	{
		x = y = 0;
	}
	Point(double _x, double _y)
	{
		x = _x, y = _y;
	}
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
	void output()
	{
		printf("(%f,%f)", x + eps, y + eps);
	}
	bool operator<(const Point &R) const
	{
		if (dcmp(x - R.x) == 0)
		{
			return dcmp(y - R.y) < 0;
		}
		return dcmp(x - R.x) < 0;
	}
	bool operator==(const Point &R) const
	{
		return dcmp(x - R.x) == 0 && dcmp(y - R.y) == 0;
	}
	Point operator+(const Point &R) const
	{
		return Point(x + R.x, y + R.y);
	}
	Point operator-(const Point &R) const
	{
		return Point(x - R.x, y - R.y);
	}
	Point operator*(const double &R) const
	{
		return Point(x * R, y * R);
	}
	Point operator/(const double &R) const
	{
		return Point(x / R, y / R);
	}// Cross Product
	double operator^(const Point &R) const
	{
		return x * R.y - y * R.x;
	}// dot
	double operator%(const Point &R) const
	{
		return x * R.x + y * R.y;
	}
	double len()
	{
		return sqrt(*this % *this);
	}
};
Point Rotate(Point A, double rad)
{
	double Sin = sin(rad), Cos = cos(rad);
	return Point(A.x * Cos - A.y * Sin, A.x * Sin + A.y * Cos);
}
Point Normal(Point A)
{
	double L = A.len();
	return Point(-A.y / L, A.x / L);
}
double GetLineIntersection(Point P, Point v, Point Q, Point w)
{
	Point u = P - Q;
	assert(dcmp(v ^ w) != 0);
	return (w ^ u) / (v ^ w);
}
bool OnSegment(Point P, Point a1, Point a2)
{
	return dcmp((a1 - P) ^ (a2 - P)) == 0 && dcmp((a1 - P) % (a2 - P)) <= 0;
}

int n, m, K, ca;
double arc, g[N][N], d[N];
bool f[N];
Point a[N];

void work()
{
	int i, j, k, x;
	arc = asin(1.0 / K);
	printf("Case %d: ", ++ca);
	for (i = 0; i <= n; ++i)
	{
		a[i].input();
	}
	m = n + 1;
	for (i = 0; i <= n; ++i)
	{
		for (j = 0; j < n; ++j)
		{
			Point Vec = Normal(a[j + 1] - a[j]);
			Point Vl = Rotate(Vec, arc), Vr = Rotate(Vec, -arc);
			double X = GetLineIntersection(a[j], a[j + 1] - a[j], a[i], Vl);
			double Y = GetLineIntersection(a[j], a[j + 1] - a[j], a[i], Vr);
			if (0 < dcmp(X - 0) && dcmp(X - 1) < 0)
			{
				a[m++] = a[j] + (a[j + 1] - a[j]) * X;
			}
			if (0 < dcmp(Y - 0) && dcmp(Y - 1) < 0)
			{
				a[m++] = a[j] + (a[j + 1] - a[j]) * Y;
			}
		}
	}
	for (i = 0; i < m; ++i)
	{
		for (j = 0; j < m; ++j)
		{
			g[i][j] = (a[j] - a[i]).len();
			for (k = 0; k < n; ++k)
			{
				if (OnSegment(a[i], a[k], a[k + 1]) && OnSegment(a[j], a[k], a[k + 1]))
				{
					if ((a[i] - a[k]).len() < (a[j] - a[k]).len())
					{
						break;
					}
				}
			}
			if (k >= n)
			{
				g[i][j] *= K;
			}
		}
	}
	//    for (i = 0; i < m; ++ i) {
	//        for (j = 0; j < m; ++ j)
	//            printf("%3.3f%c" , g[i][j] , " \n"[j + 1 == m]);
	//    }
	for (i = 0; i < m; ++i)
	{
		d[i] = 1e60, f[i] = 0;
	}
	d[0] = 0;
	while (1)
	{
		x = -1;
		for (i = 0; i < m; ++i)
			if (!f[i] && (!~x || d[i] < d[x]))
			{
				x = i;
			}
		if (!~x)
		{
			break;
		}
		f[x] = 1;
		for (i = 0; i < m; ++i)
			if (!f[i])
			{
				d[i] = min(d[i], d[x] + g[x][i]);
			}
	}
	printf("%f\n", d[n]);
}

int main()
{
	while (scanf("%d%d", &n, &K), n || K)
	{
		work();
	}
	return 0;
}
