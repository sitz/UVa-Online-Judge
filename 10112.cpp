#include <bits/stdc++.h>

using namespace std;

int numOfPoint;

class Point
{
public:
	double x, y;
	char alpha;
} point[20];

class MaxRecord
{
public:
	double maxArea;
	int i, j, k;
} maxRec;

double distance(Point *a, Point *b)
{
	// hypot(a,b)?
	double t = (a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y);
	return sqrt(t);
}

double area(Point *a, Point *b, Point *c)
{
	double A, AC, AB, BC;
	AC = distance(a, c);
	AB = distance(a, b);
	BC = distance(b, c);
	double tmp;
	tmp = (AC * AC + AB * AB - BC * BC) / (2.0 * AC * AB);
	A = acos(tmp);
	return 0.5 * AC * AB * sin(A);
}

bool isLegal(Point *a, Point *b, Point *c, Point *judge)
{
	double area0, area1, area2, area3;
	area0 = area(a, b, c);
	area1 = area(a, b, judge);
	area2 = area(a, judge, c);
	area3 = area(judge, b, c);
	if (fabs(area0 - (area1 + area2 + area3)) <= 0.00001)
	{
		return false;
	}
	return true;
}

bool notContain(int i, int j, int k)
{
	int t;
	for (t = 0; t < numOfPoint; t++)
	{
		if (t != i && t != j && t != k)
		{
			if (!isLegal(&point[i], &point[j], &point[k], &point[t]))
			{
				return false;
			}
		}
	}
	return true;
}

void solve()
{
	double ar;
	int i, j, k;
	maxRec.maxArea = 0;
	for (i = 0; i < numOfPoint - 2; i++)
	{
		for (j = i + 1; j < numOfPoint - 1; j++)
		{
			for (k = j + 1; k < numOfPoint; k++)
			{
				ar = area(&point[i], &point[j], &point[k]);
				if (ar > maxRec.maxArea && notContain(i, j, k))
				{
					maxRec.maxArea = ar;
					maxRec.i = i;
					maxRec.j = j;
					maxRec.k = k;
				}
			}
		}
	}
	cout << point[maxRec.i].alpha << point[maxRec.j].alpha << point[maxRec.k].alpha << endl;
}

int main()
{
	while (cin >> numOfPoint && numOfPoint)
	{
		int i;
		for (i = 0; i < numOfPoint; i++)
		{
			cin >> point[i].alpha >> point[i].x >> point[i].y;
		}
		solve();
	}
	return 0;
}
