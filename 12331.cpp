#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-7;
const double pi = acos(-1.0);

struct point
{
	double x, y;
} p[6], q[6], r[8];

double lp[6], lq[6], lr[8], ls[8], lt[8];
double ap[6], aq[6], ar[8];

double dist(point a, point b)
{
	a.x -= b.x;
	a.y -= b.y;
	return sqrt(a.x * a.x + a.y * a.y);
}

double cross(point a, point b, point c)
{
	a.x -= c.x;
	a.y -= c.y;
	b.x -= c.x;
	b.y -= c.y;
	return a.x * b.y - a.y * b.x;
}

double getAngle(point a, point b, point c)
{
	double angle = atan2(b.y - a.y, b.x - a.x) - atan2(c.y - a.y, c.x - a.x);
	while (angle < 0)
	{
		angle += pi + pi;
	}
	while (angle > pi + pi - eps)
	{
		angle -= pi + pi;
	}
	return angle;
}

void normalize(point p[], int n)
{
	double area = 0;
	for (int i = 1; i + 1 < n; i++)
	{
		area += cross(p[0], p[i], p[i + 1]);
	}
	assert(fabs(area) > eps);
	if (area > 0)
	{
		reverse(p, p + n);
	}
}

bool same(double l1[], double l2[])
{
	double b1[3];
	double b2[3];
	for (int i = 0; i < 3; i++)
	{
		b1[i] = l1[i];
	}
	for (int i = 0; i < 3; i++)
	{
		b2[i] = l2[i];
	}
	sort(b1, b1 + 3);
	sort(b2, b2 + 3);
	for (int i = 0; i < 3; i++)
		if (fabs(b1[i] - b2[i]) > eps)
		{
			return false;
		}
	return true;
}

bool checkTri()
{
	for (int i = 0; i < 4; i++)
	{
		if (fabs(ar[i] - pi) < eps)
		{
			for (int j = 0, u = 0; j < 4; j++)
			{
				if (j == i)
				{
					lt[u++] = lr[j] + lr[j + 3];
				}
				else if (j == (i + 3) % 4)
				{
					continue;
				}
				else
				{
					lt[u++] = lr[j];
				}
			}
		}
	}
	for (int a1 = 0; a1 < 3; a1++)
	{
		for (int b1 = 0; b1 < 3; b1++)
			if (a1 != b1)
			{
				for (int a2 = 0; a2 < 3; a2++)
				{
					for (int b2 = 0; b2 < 3; b2++)
						if (a2 != b2)
						{
							double l1 = dist(p[a1], p[b1]);
							double l2 = dist(q[a2], q[b2]);
							int c1 = 3 - a1 - b1;
							int c2 = 3 - a2 - b2;
							if (fabs(l1 - l2) > eps)
							{
								continue;
							}
							if (fabs(ap[a1] + aq[a2] - pi) > eps)
							{
								continue;
							}
							ls[0] = dist(p[a1], p[c1]) + dist(q[a2], q[c2]);
							ls[1] = dist(p[b1], p[c1]);
							ls[2] = dist(q[b2], q[c2]);
							if (same(lt, ls))
							{
								return true;
							}
						}
				}
			}
	}
	return false;
}

bool checkSame(double lt[], double lp[], double lq[])
{
	return same(lt, lp) && same(lt + 3, lq) || same(lt, lq) && same(lt + 3, lp);
}

bool checkConvex()
{
	for (int i = 0; i < 4; i++)
	{
		lt[0] = dist(r[i], r[i + 1]);
		lt[1] = dist(r[i + 1], r[i + 2]);
		lt[2] = dist(r[i], r[i + 2]);
		lt[3] = dist(r[i], r[i + 2]);
		lt[4] = dist(r[i], r[i + 3]);
		lt[5] = dist(r[i + 2], r[i + 3]);
		if (checkSame(lt, lp, lq))
		{
			return true;
		}
	}
	return false;
}

void getCut(point a, point b, point c, point d, double &u, double &v)
{
	double p = cross(a, c, d);
	double q = cross(b, c, d);
	double l = dist(a, b);
	u = l / (q - p) * p;
	p = cross(a, b, c);
	q = cross(a, b, d);
	l = dist(c, d);
	v = l / (p - q) * p;
}

bool checkNonConvex()
{
	for (int i = 0; i < 4; i++)
		if (ar[i] > pi)
		{
			lt[0] = dist(r[i], r[i + 1]);
			lt[1] = dist(r[i + 1], r[i + 2]);
			lt[2] = dist(r[i], r[i + 2]);
			lt[3] = dist(r[i], r[i + 2]);
			lt[4] = dist(r[i], r[i + 3]);
			lt[5] = dist(r[i + 2], r[i + 3]);
			if (checkSame(lt, lp, lq))
			{
				return true;
			}
			double u, v;
			getCut(r[i], r[i + 1], r[i + 2], r[i + 3], u, v);
			//		fprintf(stderr, "%lf %lf\n", u, v);
			lt[0] = dist(r[i], r[i + 1]) + u;
			lt[1] = dist(r[i + 1], r[i + 2]);
			lt[2] = v;
			lt[3] = dist(r[i + 2], r[i + 3]) - v;
			lt[4] = dist(r[i + 3], r[i]);
			lt[5] = u;
			//		fprintf(stderr, "%lf %lf %lf %lf %lf %lf\n", lt[0], lt[1], lt[2], lt[3], lt[4], lt[5]);
			if (checkSame(lt, lp, lq))
			{
				return true;
			}
			reverse(r + i + 1, r + i + 4);
			getCut(r[i], r[i + 1], r[i + 2], r[i + 3], u, v);
			//		fprintf(stderr, "%lf %lf\n", u, v);
			lt[0] = dist(r[i], r[i + 1]) + u;
			lt[1] = dist(r[i + 1], r[i + 2]);
			lt[2] = v;
			lt[3] = dist(r[i + 2], r[i + 3]) - v;
			lt[4] = dist(r[i + 3], r[i]);
			lt[5] = u;
			//		fprintf(stderr, "%lf %lf %lf %lf %lf %lf\n", lt[0], lt[1], lt[2], lt[3], lt[4], lt[5]);
			if (checkSame(lt, lp, lq))
			{
				return true;
			}
		}
	return false;
}

bool checkQuad()
{
	bool convex = true;
	for (int i = 0; i < 4; i++)
	{
		if (ar[i] > pi)
		{
			convex = false;
		}
	}
	if (convex)
	{
		return checkConvex();
	}
	else
	{
		return checkNonConvex();
	}
}

int pp[205];

void gen_special_1()
{
	memset(pp, 0, sizeof(pp));
	for (int x = 1; x * x <= 200; x++)
	{
		for (int y = x + 1; x * x + y * y <= 200; y++)
		{
			pp[x * x + y * y]++;
		}
	}
	int x, y, z = 200;
	while (pp[z] < 2)
	{
		z--;
	}
	for (x = 1; x * x <= z; x++)
	{
		for (y = x + 1; x * x + y * y <= z; y++)
		{
			if (x * x + y * y == z)
			{
				printf("%d %d %d\n", x, y, z);
			}
		}
	}
}

/*
 * 1) edge length ?
 * 2) angle ?
 * 3) area ?
 *
 * matched 1) and 2) yes
 * unordered 1) and 2) maybe
 * ordered 1) and 3) no
 * unordered 1) and 3) no
 * 2) and 3) no
 */

int main()
{
	int ntest;
	scanf("%d", &ntest);
	for (int test = 1; test <= ntest; test++)
	{
		for (int i = 0; i < 3; i++)
		{
			scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		for (int i = 0; i < 3; i++)
		{
			scanf("%lf%lf", &q[i].x, &q[i].y);
		}
		for (int i = 0; i < 4; i++)
		{
			scanf("%lf%lf", &r[i].x, &r[i].y);
		}
		for (int i = 0; i < 3; i++)
		{
			assert(-15000 <= p[i].x && p[i].x <= 15000);
		}
		for (int i = 0; i < 3; i++)
		{
			assert(-15000 <= q[i].x && q[i].x <= 15000);
		}
		for (int i = 0; i < 4; i++)
		{
			assert(-15000 <= r[i].x && r[i].x <= 15000);
		}
		normalize(p, 3);
		normalize(q, 3);
		normalize(r, 4);
		for (int i = 0; i < 3; i++)
		{
			p[i + 3] = p[i];
		}
		for (int i = 0; i < 3; i++)
		{
			q[i + 3] = q[i];
		}
		for (int i = 0; i < 4; i++)
		{
			r[i + 4] = r[i];
		}
		for (int i = 0; i < 3; i++)
		{
			lp[i] = lp[i + 3] = dist(p[i], p[i + 1]);
		}
		for (int i = 0; i < 3; i++)
		{
			lq[i] = lq[i + 3] = dist(q[i], q[i + 1]);
		}
		for (int i = 0; i < 4; i++)
		{
			lr[i] = lr[i + 4] = dist(r[i], r[i + 1]);
		}
		for (int i = 0; i < 3; i++)
		{
			ap[i] = ap[i + 3] = getAngle(p[i], p[i + 1], p[i + 2]);
		}
		for (int i = 0; i < 3; i++)
		{
			aq[i] = aq[i + 3] = getAngle(q[i], q[i + 1], q[i + 2]);
		}
		for (int i = 0; i < 4; i++)
		{
			ar[i] = ar[i + 4] = getAngle(r[i], r[i + 1], r[i + 3]);
		}
		bool isTri = false;
		for (int i = 0; i < 4; i++)
		{
			if (fabs(ar[i] - pi) < eps)
			{
				isTri = true;
			}
		}
		if (isTri)
		{
			printf("Case #%d: %s\n", test, checkTri() ? "Yes" : "No");
		}
		else
		{
			printf("Case #%d: %s\n", test, checkQuad() ? "Yes" : "No");
		}
	}
	return 0;
}
