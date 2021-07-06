#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y;
} p[100000], start, end_;
int len;
double t;

const double sqrt3 = sqrt(3);

int compare(const void *a, const void *b)
{
	Point *c = (Point *)a, *d = (Point *)b;
	if (fabs(c->x - d->x) < 1e-8 && fabs(c->y - d->y) < 1e-8)
	{
		return 0;
	}
	else if (fabs(c->x - d->x) > 1e-8)
	{
		double dx = c->x - d->x;
		if (dx < 0)
		{
			return -1;
		}
		else if (dx == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		double dy = c->y - d->y;
		if (dy < 0)
		{
			return -1;
		}
		else if (dy == 0)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
}
Point find(Point c, Point d)
{
	Point e;
	double a = sqrt(((c.x - d.x) * (c.x - d.x) + (c.y - d.y) * (c.y - d.y)));
	double dx = d.x - c.x, dy = d.y - c.y;
	double sint = dy / a, cost = dx / a;
	e.x = cost * 0.5 * a - 0.5 * sqrt3 * sint * a + c.x;
	e.y = sint * 0.5 * a + 0.5 * sqrt3 * cost * a + c.y;
	return e;
}
void run(Point start, Point end_)
{
	// hypot(a,b)
	double dist = (start.x - end_.x) * (start.x - end_.x) +
								(start.y - end_.y) * (start.y - end_.y);
	if (dist < t)
	{
		return;
	}
	Point c1, c2, c3;
	c1.x = (3 * start.x + end_.x) / 4, c1.y = (3 * start.y + end_.y) / 4;
	c2.x = (start.x + 3 * end_.x) / 4, c2.y = (start.y + 3 * end_.y) / 4;
	c3 = find(c1, c2);
	p[len++] = start;
	run(c1, c3);
	run(c3, c2);
	p[len++] = end_;
}
void rebuild()
{
	int s = 0, i = 0, j;
	while (i < len)
	{
		p[s++] = p[i];
		for (j = i + 1; j < len && fabs(p[j].x - p[i].x) < 1e-8 &&
										fabs(p[j].y - p[i].y) < 1e-8;
				 j++)
			;
		i = j;
	}
	len = s;
}

int main()
{
	int c = 1;
	while (scanf("%lf %lf %lf %lf %lf", &start.x, &start.y, &end_.x, &end_.y, &t) == 5)
	{
		if (t < 1)
		{
			break;
		}
		t *= t;
		printf("Case %d:\n", c++);
		len = 0;
		run(start, end_);
		qsort(p, len, sizeof(Point), compare);
		rebuild();
		printf("%d\n", len);
		for (int i = 0; i < len; i++)
		{
			printf("%.5lf %.5lf\n", p[i].x, p[i].y);
		}
	}
	return 0;
}
