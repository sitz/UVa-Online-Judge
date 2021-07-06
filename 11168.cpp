#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y;
};
Point p[10001], vertex[10001];
Point center;
int pc, vc;
inline double cross(Point a, Point b, Point c)
{
	return (a.x - c.x) * (b.y - c.y) - (a.y - c.y) * (b.x - c.x);
}
inline double dist(double x, double y)
{
	return x * x + y * y;
}
inline void swap(Point &a, Point &b)
{
	Point t = a;
	a = b;
	b = t;
}
bool comp(Point a, Point b)
{
	Point &t = p[0];
	double c = cross(a, b, t);
	if ((c > 0) ||
			((c == 0) && dist(a.x - t.x, a.y - t.y) < dist(b.x - t.x, b.y - t.y)))
	{
		return true;
	}
	return false;
}
void qsort(int left, int right)
{
	if (left < right)
	{
		int s = (rand() % (right - left + 1)) + left;
		swap(p[left], p[s]);
		int i = left, j = right + 1;
		Point pivot = p[left];
		do
		{
			do
			{
				i++;
			} while (comp(p[i], pivot) && i <= right);
			do
			{
				j--;
			} while (comp(pivot, p[j]) && j >= left);
			if (i < j)
			{
				swap(p[i], p[j]);
			}
		} while (i < j);
		swap(p[left], p[j]);
		qsort(left, j - 1);
		qsort(j + 1, right);
	}
}
void ConvexHull()
{
	int i, l = 0, ptr = 1;
	for (i = 1; i < pc; i++)
		if ((p[i].y < p[l].y) ||
				((p[i].y == p[l].y) && (p[i].x < p[l].x)))
		{
			l = i;
		}
	swap(p[0], p[l]);
	qsort(1, pc - 1);
	vertex[0] = p[0];
	vertex[1] = p[1];
	for (i = 2; ptr < 2 && i < pc; i++)
	{
		double t1 = (p[i].y - p[0].y) * (p[i - 1].x - p[0].x);
		double t2 = (p[i - 1].y - p[0].y) * (p[i].x - p[0].x);
		if (t1 == t2)
		{
			vertex[ptr] = p[i];
		}
		else
		{
			vertex[++ptr] = p[i];
		}
	}
	for (; i < pc; i++)
	{
		while (cross(p[i], vertex[ptr], vertex[ptr - 1]) >= 0 && ptr >= 2)
		{
			ptr--;
		}
		vertex[++ptr] = p[i];
	}
	vertex[++ptr] = p[0];
	vc = ptr + 1;
}
void calcline(Point *p1, Point *p2, double &a, double &b, double &c)
{
	if (p1->x == p2->x)
	{
		a = 1;
		b = 0;
		c = -p1->x;
	}
	else if (p1->y == p2->y)
	{
		a = 0;
		b = 1;
		c = -p1->y;
	}
	else
	{
		double m = (p2->y - p1->y) / (p2->x - p1->x);
		double bb = p1->y - m * p1->x;
		a = m;
		b = -1;
		c = bb;
	}
}
int main()
{
	srand(time(NULL));
	int n, t, t1;
	scanf("%d", &n);
	for (int cases = 1; cases <= n; cases++)
	{
		scanf("%d", &pc);
		center.x = center.y = 0;
		for (int i = 0; i < pc; i++)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
			center.x += p[i].x;
			center.y += p[i].y;
		}
		if (pc <= 2)
		{
			printf("Case #%d: %.3lf\n", cases, 0.000);
			continue;
		}
		center.x /= (double)pc;
		center.y /= (double)pc;
		ConvexHull();
		double min = 999999999;
		for (int i = 0; i < vc - 1; i++)
		{
			double a, b, c;
			calcline(&vertex[i], &vertex[i + 1], a, b, c);
			double dist = fabs(a * center.x + b * center.y + c) / sqrt(a * a + b * b);
			if (dist < min)
			{
				min = dist;
			}
		}
		printf("Case #%d: %.3lf\n", cases, min);
	}
}
