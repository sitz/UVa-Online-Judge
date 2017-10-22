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

class Point
{
public:
	double x, y;
};

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

int main()
{
	char shape;
	char figure[11];
	Circle ci[11];
	Rect re[11];
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
		}
		if (flag == 0)
		{
			cout << "Point " << numpoint << " is not contained in any figure" << endl;
		}
		numpoint++;
	}
	return 0;
}
