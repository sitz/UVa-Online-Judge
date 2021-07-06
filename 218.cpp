#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000 + 10;
const double eps = 1e-8;
struct point
{
	double x, y;
};

point points[maxn];
struct convex
{
	point c[maxn];
	int len;
};
convex cn[maxn];
int n1, n2, len1, len2;
inline double multiply(point a, point b, point o)
{
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}
inline double dot(point a, point b, point o)
{
	return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}
inline double getdis(point a, point b)//两个点之间的距离
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double dis2(point a, point b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline bool cmpp(point a, point b)//按极角排序
{
	//从小到大排序
	double m = multiply(a, b, points[0]);
	if (m > 0)
	{
		return true;
	}
	else if (m == 0)
	{
		return dis2(a, points[0]) > dis2(b, points[0]);
	}
	return false;
}
int grahamConvex(point points[], int n, point done[])
{
	int u = 0;
	int top = 0;
	for (int i = 1; i < n; i++)
	{
		if ((points[i].x < points[u].x) || (points[i].x == points[u].x && points[i].y < points[u].y))
		{
			u = i;
		}
	}
	std::swap(points[0], points[u]);
	std::sort(points + 1, points + n, cmpp);
	for (int i = 0; i <= 2; i++)
	{
		done[i] = points[i];
	}
	top = 2;
	for (int i = 3; i < n; i++)
	{
		while (multiply(done[top], done[top - 1], points[i]) >= 0)
		{
			top--;
		}
		done[++top] = points[i];
	}
	return top + 1;
}

int main()
{
	int n, s = 0;
	while (scanf("%d", &n), n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &points[i].x, &points[i].y);
		}
		cn[s].len = grahamConvex(points, n, cn[s].c);
		s++;
	}
	for (int i = 0; i < s; i++)
	{
		printf("Region #%d:\n", i + 1);
		printf("(%.1lf,%.1lf)", cn[i].c[0].x, cn[i].c[0].y);
		double p = 0;
		cn[i].c[cn[i].len] = cn[i].c[0];
		for (int j = cn[i].len - 1; j >= 0; j--)
		{
			printf("-(%.1lf,%.1lf)", cn[i].c[j].x, cn[i].c[j].y);
			p += getdis(cn[i].c[j], cn[i].c[j + 1]);
		}
		printf("\nPerimeter length = %.2lf\n\n", p);
	}
	return 0;
}
