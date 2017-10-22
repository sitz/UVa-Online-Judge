#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

const int maxn = 10005;
const int offset = 1000001;
const int inf = 0x3f3f3f3f;
const double eps = 1e-8;
const double pi = acos(-1.0);

struct point
{
	double x, y;
	point(double _x = 0, double _y = 0) : x(_x), y(_y) {}
};

struct point3
{
	double x, y, z;
	point3(double _x = 0, double _y = 0, double _z = 0) : x(_x), y(_y), z(_z) {}
};

bool mult(point sp, point ep, point op)
{
	return (sp.x - op.x) * (ep.y - op.y) > (ep.x - op.x) * (sp.y - op.y) - eps;
}

bool operator<(const point &l, const point &r)
{
	return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[])
{
	int i, len, k = 0, top = 1;
	sort(pnt, pnt + n);
	if (n == 0)
	{
		return 0;
	}
	res[0] = pnt[0];
	if (n == 1)
	{
		return 1;
	}
	res[1] = pnt[1];
	if (n == 2)
	{
		return 2;
	}
	res[2] = pnt[2];
	for (i = 2; i < n; i++)
	{
		while (top && mult(pnt[i], res[top], res[top - 1]))
		{
			top--;
		}
		res[++top] = pnt[i];
	}
	len = top;
	res[++top] = pnt[n - 2];
	for (i = n - 3; i >= 0; i--)
	{
		while (top != len && mult(pnt[i], res[top], res[top - 1]))
		{
			top--;
		}
		res[++top] = pnt[i];
	}
	return top;
}

int n, m, zmin, zmax;
point3 p[maxn];
point pnt[maxn], res[maxn];

int main()
{
	//freopen("input.txt","r",stdin);
	bool flag = false;
	while (scanf("%d %d %d", &n, &zmin, &zmax) != EOF)
	{
		if (flag)
		{
			printf("\n");
		}
		flag = true;
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
		}
		for (int z = zmin; z <= zmax; z++)
		{
			m = 0;
			for (int i = 0; i < n; i++)
				if (fabs(p[i].z - z) < eps)
				{
					pnt[m++] = point(p[i].x, p[i].y);
				}
			for (int i = 0; i < n; i++)
				for (int j = i + 1; j < n; j++)
				{
					if ((p[i].z - z) * (p[j].z - z) >= 0)
					{
						continue;
					}
					double u = abs(p[i].z - z);
					double v = abs(p[j].z - z);
					pnt[m++] = point(1.0 * (p[i].x * v + p[j].x * u) / (u + v),
													 1.0 * (p[i].y * v + p[j].y * u) / (u + v));
					/*
					point3 a = p[i], b = p[j];
					if (fabs(a.z - b.z) < eps)
					    continue;
					if (a.z > b.z)
					    swap(a, b);
					if (a.z < z - eps && b.z > z + eps)
					{
					    double temp = b.z - a.z;
					    point pp;
					    pp.x = a.x + (b.x - a.x) * (z - a.z) / (temp);
					    pp.y = a.y + (b.y - a.y) * (z - a.z) / (temp);
					    pnt[m++] = pp;
					}*/
				}
			/*
			point3 s1 = point3(-10000, -10000, z), s2 = point3(10000, -10000, z), s3 = point3(0, 20000, z);
			m = 0;
			for (int i = 0; i < n; i++)
			    for (int j = i + 1; j < n; j++)
			        if (!parallel(p[i], p[j], s1, s2, s3) && intersect_in(p[i], p[j], s1, s2, s3))
			        {
			            point3 jiao = intersection(p[i], p[j], s1, s2, s3);
			            pnt[m++] = point(jiao.x, jiao.y);
			        }
			*/
			m = graham(pnt, m, res);
			if (m < 3)
			{
				printf("0.000000000\n");
				continue;
			}
			double s = res[0].y * (res[m - 1].x - res[1].x);
			res[m] = res[0];
			for (int i = 1; i < m; i++)
			{
				s += res[i].y * (res[i - 1].x - res[i + 1].x);
			}
			printf("%.10lf\n", fabs(s / 2));
		}
	}
	return 0;
}
