#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

struct point
{
	double x, y;
};
struct line
{
	point a, b;
};
int n, dnum = 1, multi, i;
point beg;
line lines[MAX];
point door[MAX];

void readin(point &p)
{
	cin >> p.x >> p.y;
}

void init()
{
	int i;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		readin(lines[i].a);
		readin(lines[i].b);
	}
	lines[n].a.x = 0;
	lines[n].a.y = 100;
	lines[n].b.x = 100;
	lines[n].b.y = 100;
	n++;
	lines[n].a.x = 100;
	lines[n].a.y = 100;
	lines[n].b.x = 100;
	lines[n].b.y = 0;
	n++;
	lines[n].a.x = 100;
	lines[n].a.y = 0;
	lines[n].b.x = 0;
	lines[n].b.y = 0;
	n++;
	lines[n].a.x = 0;
	lines[n].a.y = 0;
	lines[n].b.x = 0;
	lines[n].b.y = 100;
	n++;
	readin(beg);
}

int equ(double a, double b)
{
	if (fabs(a - b) < 1e-6)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double cra(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

double cr(point a, point b, point c)
{
	return cra(b.x - a.x, b.y - a.y, c.x - a.x, c.y - a.y);
}

int cross(line a, line b)
{
	double i, j, k, l;
	i = cr(a.a, b.a, b.b);
	j = cr(a.b, b.a, b.b);
	k = cr(b.a, a.a, a.b);
	l = cr(b.b, a.a, a.b);
	if (equ(i * j, 0) || equ(k * l, 0))
	{
		return 1;
	}
	else if (i * j < 0 && k * l < 0)
	{
		return 2;
	}
	return 0;
}

void makeco(double &a, double &b, double &c, line l)
{
	double x1 = l.a.x, y1 = l.a.y, x2 = l.b.x, y2 = l.b.y;
	c = (x1 * y2 - x2 * y1);
	a = (y2 - y1);
	b = (x2 - x1);
}

void getcross(point &q, line a, line b)
{
	double a1, b1, c1, a2, b2, c2;
	makeco(a1, b1, c1, a);
	makeco(a2, b2, c2, b);
	q.x = -(b1 * c2 - b2 * c1) / (b2 * a1 - b1 * a2);
	q.y = -(a1 * c2 - a2 * c1) / (b2 * a1 - b1 * a2);
}

void getmid(point &p, point a, point b)
{
	p.x = (a.x + b.x) / 2;
	p.y = (a.y + b.y) / 2;
}

void makecross()
{
	int i, j, k, ii;
	point list[MAX], temp;
	memset(list, 0, sizeof(list));
	memset(door, 0, sizeof(door));
	dnum = 1;
	for (i = 0; i < n; i++)
	{
		for (k = 0, j = 0; j < n; j++)
			if (i != j)
			{
				if (cross(lines[i], lines[j]) > 0)
				{
					getcross(list[k++], lines[i], lines[j]);
				}
			}
		for (ii = 0; ii < k - 1; ii++)
			for (j = ii + 1; j < k; j++)
				if (list[ii].y > list[j].y ||
						equ(list[ii].y, list[j].y) && list[ii].x > list[j].x)
				{
					temp = list[ii];
					list[ii] = list[j];
					list[j] = temp;
				}
		for (ii = 0; ii < k - 1; ii++)
		{
			getmid(door[dnum++], list[ii], list[ii + 1]);
		}
	}
}

int good(point a, point b)
{
	line l;
	int i;
	l.a = a;
	l.b = b;
	for (i = 0; i < n; i++)
		if (cross(l, lines[i]) == 2)
		{
			return 0;
		}
	return 1;
}

void dijkstra()
{
	int i, j, k;
	int set[MAX];
	int dis[MAX];
	memset(set, 0, sizeof(set));
	memset(dis, 0, sizeof(dis));
	dis[0] = 1;
	door[0] = beg;
	for (i = 1;; i++)
	{
		for (j = 0; j < dnum; j++)
			if (dis[j] == i && !set[j])
			{
				set[j] = 1;
				for (k = 0; k < dnum; k++)
					if (!set[k] && good(door[j], door[k]) && (i + 1 < dis[k] || !dis[k]))
					{
						dis[k] = i + 1;
						if (equ(door[k].x, 0) || equ(door[k].y, 0) || equ(door[k].x, 100) || equ(door[k].y, 100))
						{
							cout << "Number of doors = " << i << endl;
							return;
						}
					}
			}
	}
}

int main()
{
	cin >> multi;
	for (i = 0; i < multi; i++)
	{
		init();
		makecross();
		dijkstra();
		if (i < multi - 1)
		{
			printf("\n");
		}
	}
	return 0;
}
