#include <bits/stdc++.h>

using namespace std;

class Rect
{
public:
	double x1, y1, x2, y2;
};

class Circle
{
public:
	double x, y, r;
};

class Triangle
{
public:
	double x1, y1, x2, y2, x3, y3;
};

class Point
{
public:
	double x, y;
};

bool cmp1(double x, double y, Rect &a);

bool cmp2(double m, double n, Circle &a);

double distance(double x1, double y1, double x2, double y2);

double area(double x1, double y1, double x2, double y2, double x3, double y3);

int main()
{
	char shape;
	char figure[11];
	Circle ci[11];
	Rect re[11];
	Triangle tri[11];
	Point po;
	int numfigure = 1, numpoint = 1, num = 1;
	while (cin >> shape)
	{
		if (shape == '*')
		{
			break;
		}
		if (shape == 'r')
		{
			figure[num] = 'r';
			cin >> re[numfigure].x1 >> re[numfigure].y1 >> re[numfigure].x2 >> re[numfigure].y2;
			numfigure++;
			num++;
		}
		if (shape == 'c')
		{
			figure[num] = 'c';
			cin >> ci[numfigure].x >> ci[numfigure].y >> ci[numfigure].r;
			numfigure++;
			num++;
		}
		if (shape == 't')
		{
			figure[num] = 't';
			cin >> tri[numfigure].x1 >> tri[numfigure].y1;
			cin >> tri[numfigure].x2 >> tri[numfigure].y2;
			cin >> tri[numfigure].x3 >> tri[numfigure].y3;
			numfigure++;
			num++;
		}
	}
	while (cin >> po.x >> po.y)
	{
		if (po.x == 9999.9 && po.y == 9999.9)
		{
			break;
		}
		int flag = 0;
		int j;
		for (j = 1; j <= numfigure; j++)
		{
			if (figure[j] == 'r')
			{
				if (cmp1(po.x, po.y, re[j]) == true)
				{
					cout << "Point " << numpoint << " is contained in figure " << j << endl;
					flag = 1;
				}
			}
			if (figure[j] == 'c')
			{
				if (cmp2(po.x, po.y, ci[j]) == true)
				{
					cout << "Point " << numpoint << " is contained in figure " << j << endl;
					flag = 1;
				}
			}
			if (figure[j] == 't')
			{
				double area0, area1, area2, area3;
				area0 = area(tri[j].x1, tri[j].y1, tri[j].x2, tri[j].y2, tri[j].x3, tri[j].y3);
				area1 = area(tri[j].x1, tri[j].y1, tri[j].x2, tri[j].y2, po.x, po.y);
				area2 = area(tri[j].x1, tri[j].y1, po.x, po.y, tri[j].x3, tri[j].y3);
				area3 = area(po.x, po.y, tri[j].x2, tri[j].y2, tri[j].x3, tri[j].y3);
				if (fabs(area0 - (area1 + area2 + area3)) <= 0.01)
				{
					cout << "Point " << numpoint << " is contained in figure " << j << endl;
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			cout << "Point " << numpoint << " is not contained in any figure" << endl;
		}
		numpoint++;
	}
	return 0;
}

bool cmp1(double x, double y, Rect &a)
{
	if (x > a.x1 && x < a.x2 && y > a.y2 && y < a.y1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmp2(double m, double n, Circle &a)
{
	double tmp = (m - a.x) * (m - a.x) + (n - a.y) * (n - a.y);
	if (tmp < (a.r) * (a.r))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double distance(double x1, double y1, double x2, double y2)
{
	double t;
	t = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	return sqrt(t);
}
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double A, AC, AB, BC;
	AC = distance(x1, y1, x3, y3);
	AB = distance(x1, y1, x2, y2);
	BC = distance(x2, y2, x3, y3);
	double tmp = (AC * AC + AB * AB - BC * BC) / (2 * AC * AB);
	A = acos(tmp);
	return (0.5 * AC * AB * sin(A));
}
