#include <bits/stdc++.h>

using namespace std;

const int maxn = 60005;
const double eps = 1e-8;
const double pi = acos(-1);

struct point
{
	double x, y;
	int z;
	point() {}
	point(double _x, double _y) : x(_x), y(_y), z(-1) {}
	point(double _x, double _y, int _z) : x(_x), y(_y), z(_z) {}
	point operator+(const point &i) const
	{
		return point(x + i.x, y + i.y, z);
	}
	point operator-(const point &i) const
	{
		return point(x - i.x, y - i.y, z);
	}
	double operator^(const point &i) const
	{
		return x * i.y - y * i.x;
	}
	void out()
	{
		printf("(%.9lf , %.9lf)\n", x, y);
	}
} p[maxn];
struct circle
{
	double x, y, r;
	circle() {}
	circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r) {}
} c[102];
int q[maxn], m;
int tt, t, n, pn, cn;

double sqr(double x)
{
	return x * x;
}

bool cmp(point a, point b)
{
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

void graham()
{
	int i, k;
	sort(p, p + pn, cmp);
	m = 0;
	for (i = 1; i < pn; ++i)
		if (p[i].x != p[i - 1].x || p[i].y != p[i - 1].y)
		{
			p[++m] = p[i];
		}
		else
		{
			p[m] = p[i];
		}
	pn = ++m;
	q[0] = 0;
	if (pn == 1)
	{
		return;
	}
	q[1] = 1;
	if (pn == 2)
	{
		return;
	}
	k = 1;
	for (i = 2; i < pn; ++i)
	{
		while (k && ((p[q[k]] - p[q[k - 1]]) ^ (p[i] - p[q[k - 1]])) <= 0)
		{
			--k;
		}
		q[++k] = i;
	}
	m = k;
	for (i = pn - 1; i >= 0; --i)
	{
		while (k > m && ((p[q[k]] - p[q[k - 1]]) ^ (p[i] - p[q[k - 1]])) <= 0)
		{
			--k;
		}
		q[++k] = i;
	}
	m = k;
}

void circleTangent(int i, int j)
{
	circle &a = c[i], &b = c[j];
	double x0 = b.x - a.x, y0 = b.y - a.y, r0 = a.r - b.r, coso, sino;
	point ans0, ans1;
	if (fabs(y0) < eps)
	{
		coso = r0 / x0;
		sino = sqrt(1 - sqr(coso));
		ans0 = point(a.r * coso, a.r * sino, i);
		ans1 = point(a.r * coso, -a.r * sino, i);
	}
	else
	{
		double A = sqr(x0 / y0) + 1;
		double B = -2 * x0 / y0 * r0 / y0;
		double C = sqr(r0 / y0) - 1;
		double d = sqrt(B * B - 4 * A * C);
		coso = (d - B) / 2 / A;
		sino = (r0 - x0 * coso) / y0;
		ans0 = point(a.r * coso, a.r * sino, i);
		coso = (-d - B) / 2 / A;
		sino = (r0 - x0 * coso) / y0;
		ans1 = point(a.r * coso, a.r * sino, i);
	}
	p[pn++] = ans0 + point(a.x, a.y);
	p[pn++] = ans1 + point(a.x, a.y);
}

void pointTangent(int i, point &b)
{
	circle &a = c[i];
	double x0 = 2 * (b.x - a.x), y0 = 2 * (b.y - a.y), r0 = 2 * (sqr(a.r) - sqr(a.x) - sqr(a.y) + a.x * b.x + a.y * b.y);
	point ans0, ans1;
	if (fabs(y0) < eps)
	{
		double d = sqrt(a.r * a.r - sqr(a.x - r0 / x0));
		ans0 = point(r0 / x0, a.y - d, i);
		ans1 = point(r0 / x0, a.y + d, i);
	}
	else
	{
		double A = sqr(x0 / y0) + 1;
		double B = 2 * (x0 / y0 * (a.y - r0 / y0) - a.x);
		double C = sqr(a.x) + sqr(a.y - r0 / y0) - sqr(a.r);
		double d = sqrt(B * B - 4 * A * C);
		ans0.x = (d - B) / 2 / A;
		ans0.y = (r0 - x0 * ans0.x) / y0;
		ans1.x = (-d - B) / 2 / A;
		ans1.y = (r0 - x0 * ans1.x) / y0;
		ans0.z = ans1.z = i;
	}
	p[pn++] = ans0;
	p[pn++] = ans1;
}

double dis(point &a, point &b)
{
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double arc(point &a, point &b, circle &c)
{
	point o(c.x, c.y);
	double A = dis(o, a);
	double B = dis(o, b);
	double C = dis(a, b);
	double alpha = acos((A * A + B * B - C * C) / (2 * A * B));
	if (((o - a) ^ (o - b)) > 0)
	{
		return alpha * c.r;
	}
	return (2 * pi - alpha) * c.r;
}

int main()
{
	int i, j;
	char cc[2];
	double x, y, r;
	scanf("%d", &t);
	for (tt = 1; tt <= t; ++tt)
	{
		cn = pn = 0;
		scanf("%d", &n);
		while (n--)
		{
			scanf("%s", cc);
			if (cc[0] == 'c')
			{
				scanf("%lf%lf%lf", &x, &y, &r);
				c[cn++] = circle(x, y, r);
			}
			else
				for (scanf("%d", &m); m--;)
				{
					scanf("%lf%lf", &x, &y);
					p[pn++] = point(x, y, -pn - 1);
				}
		}
		n = pn;
		for (i = 0; i < cn; ++i)
		{
			for (j = i + 1; j < cn; ++j)
			{
				circleTangent(i, j);
				circleTangent(j, i);
			}
			for (j = 0; j < n; ++j)
			{
				pointTangent(i, p[j]);
			}
		}
		graham();
		q[m] = q[0];
		r = 0;
		for (i = 0; i < m; ++i)
		{
			if (p[q[i]].z == p[q[i + 1]].z)
			{
				r += arc(p[q[i]], p[q[i + 1]], c[p[q[i]].z]);
			}
			else
			{
				r += dis(p[q[i]], p[q[i + 1]]);
			}
		}
		printf("Case #%d: %.6f\n", tt, r);
	}
	return 0;
}
