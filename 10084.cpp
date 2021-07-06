#include <bits/stdc++.h>

using namespace std;

const int MAX = 55;

struct point
{
	double x, y;
};
struct line
{
	point a, b;
	double ang;
};
line ln[MAX], deq[MAX], ltmp[MAX];
point s[MAX];
const double eps = 1e-6;
bool dy(double x, double y)
{
	return x > y + eps;// x > y
}
bool xy(double x, double y)
{
	return x < y - eps;// x < y
}
bool dyd(double x, double y)
{
	return x > y - eps;// x >= y
}
bool xyd(double x, double y)
{
	return x < y + eps;// x <= y
}
bool dd(double x, double y)
{
	return fabs(x - y) < eps;// x == y
}
double crossProduct(point a, point b, point c)//?? ac ? ab ???
{
	return (c.x - a.x) * (b.y - a.y) - (b.x - a.x) * (c.y - a.y);
}
void makeline(double x1, double y1, double x2, double y2, line &l)
{
	l.a.x = x1;
	l.a.y = y1;
	l.b.x = x2;
	l.b.y = y2;
	l.ang = atan2(y1 - y2, x1 - x2);
}
point foot_line(point a, point l1, point l2)//ac?l1l2??????
{
	point c;
	c.x = a.x - l2.y + l1.y;
	c.y = a.y + l2.x - l1.x;
	return c;
}
bool cmphp(line a, line b)
{
	if (dd(a.ang, b.ang))
	{
		return xy(crossProduct(b.a, b.b, a.a), 0.0);
	}
	return xy(a.ang, b.ang);
}
bool equalcmp(line a, line b)
{
	return dd(a.ang, b.ang);
}
bool parallel(line u, line v)
{
	return dd((u.a.x - u.b.x) * (v.a.y - v.b.y) - (v.a.x - v.b.x) * (u.a.y - u.b.y), 0.0);
}
bool equalp(point a, point b)
{
	return dd(a.x, b.x) && dd(a.y, b.y);
}
double area_polygon(point p[], int n)
{
	double s = 0.0;
	for (int i = 0; i < n; i++)
	{
		s += p[(i + 1) % n].y * p[i].x - p[(i + 1) % n].x * p[i].y;
	}
	return fabs(s) / 2.0;
}
point l2l_inst_p(line l1, line l2)
{
	point ans = l1.a;
	double t = ((l1.a.x - l2.a.x) * (l2.a.y - l2.b.y) - (l1.a.y - l2.a.y) * (l2.a.x - l2.b.x)) /
						 ((l1.a.x - l1.b.x) * (l2.a.y - l2.b.y) - (l1.a.y - l1.b.y) * (l2.a.x - l2.b.x));
	ans.x += (l1.b.x - l1.a.x) * t;
	ans.y += (l1.b.y - l1.a.y) * t;
	return ans;
}
void inst_hp_nlogn(line *ln, int n, point *s, int &len)
{
	len = 0;
	sort(ln, ln + n, cmphp);
	n = unique(ln, ln + n, equalcmp) - ln;
	int bot = 0, top = 1;
	deq[0] = ln[0];
	deq[1] = ln[1];
	for (int i = 2; i < n; i++)
	{
		if (parallel(deq[top], deq[top - 1]) || parallel(deq[bot], deq[bot + 1]))
		{
			return;
		}
		while (bot < top && dy(crossProduct(ln[i].a, ln[i].b,
																				l2l_inst_p(deq[top], deq[top - 1])),
													 0.0))
		{
			top--;
		}
		while (bot < top && dy(crossProduct(ln[i].a, ln[i].b,
																				l2l_inst_p(deq[bot], deq[bot + 1])),
													 0.0))
		{
			bot++;
		}
		deq[++top] = ln[i];
	}
	while (bot < top && dy(crossProduct(deq[bot].a, deq[bot].b,
																			l2l_inst_p(deq[top], deq[top - 1])),
												 0.0))
	{
		top--;
	}
	while (bot < top && dy(crossProduct(deq[top].a, deq[top].b,
																			l2l_inst_p(deq[bot], deq[bot + 1])),
												 0.0))
	{
		bot++;
	}
	if (top <= bot + 1)
	{
		return;
	}
	for (int i = bot; i < top; i++)
	{
		s[len++] = l2l_inst_p(deq[i], deq[i + 1]);
	}
	if (bot < top + 1)
	{
		s[len++] = l2l_inst_p(deq[bot], deq[top]);
	}
	len = unique(s, s + len, equalp) - s;
}

int main()
{
	double x, y;
	char str[100];
	point a, b;
	a.x = a.y = 0.0;
	int cnt = 0;
	double area = 1e20;
	makeline(0, 0, 10, 0, ln[cnt++]);
	makeline(10, 0, 10, 10, ln[cnt++]);
	makeline(10, 10, 0, 10, ln[cnt++]);
	makeline(0, 10, 0, 0, ln[cnt++]);
	while (~scanf("%lf%lf%s", &b.x, &b.y, str))
	{
		if (strcmp(str, "Same") == 0)
		{
			area = 0.0;
		}
		point c;
		c.x = (a.x + b.x) / 2.0;
		c.y = (a.y + b.y) / 2.0;
		point d;
		if (strcmp(str, "Colder") == 0)
		{
			d = foot_line(c, a, b);
			makeline(c.x, c.y, d.x, d.y, ln[cnt++]);
		}
		if (strcmp(str, "Hotter") == 0)
		{
			d = foot_line(c, a, b);
			makeline(d.x, d.y, c.x, c.y, ln[cnt++]);
		}
		a = b;
		if (area == 0.0)
		{
			printf("0.00\n");
			continue;
		}
		int len = 0;
		memcpy(ltmp, ln, sizeof(ln));
		inst_hp_nlogn(ltmp, cnt, s, len);
		area = area_polygon(s, len);
		if (len < 3)
		{
			printf("0.00\n");
			continue;
		}
		printf("%.2lf\n", area);
	}
	return 0;
}
