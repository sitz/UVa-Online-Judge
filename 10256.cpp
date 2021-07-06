#include <bits/stdc++.h>

using namespace std;

#define SMALL 0
#define POW2(x) ((x) * (x))

struct Point
{
	double x, y;
};
struct Poly
{
	vector<Point> p; // last != first
};

// >0:left, <0:right
double Cross(const Point &p0, const Point &p1, const Point &p2)
{
	double dx1 = p1.x - p0.x, dy1 = p1.y - p0.y;
	double dx2 = p2.x - p0.x, dy2 = p2.y - p0.y;
	return dx1 * dy2 - dy1 * dx2;
}

// CONVEX POLYGON ========================================================

Point start;

struct CompareCross
{
	bool operator()(const Point &p1, const Point &p2) const
	{
		double c = Cross(start, p1, p2);
		if (c < 0)
		{
			return false;//counter-clockwise
		}
		else if (c > 0)
		{
			return true;
		}
		double dist = (POW2(p1.x - start.x) + POW2(p1.y - start.y)) -
									(POW2(p2.x - start.x) + POW2(p2.y - start.y));//by dist..
		if (dist > 0)
		{
			return false;
		}
		return true;
	}
} comp_cross;

void SortByCross(Poly &r)
{
	int i, dl;
	for (dl = 0, i = 1; i < r.p.size(); i++)
		if (r.p[i].y < r.p[dl].y ||
				(fabs(r.p[i].y - r.p[dl].y) < SMALL && r.p[i].x < r.p[dl].x))
		{
			dl = i;
		}
	Point tmp = r.p[dl];
	r.p[dl] = r.p[0];
	r.p[0] = tmp;//swap
	start = tmp;
	sort(r.p.begin() + 1, r.p.end(), comp_cross);
}

void GrahamScanCross(Poly &r)//the last != the first
{
	//check more then 2 point!!
	SortByCross(r);
	r.p.push_back(r.p.front());
	int i, j;
	for (j = 1, i = 2; i < r.p.size(); i++)//j=1,i=2 prevent (5,1) (6,1) (7,1) ...
	{
		//counter-clockwise, exclude the side..
		while (j > 0 && Cross(r.p[j - 1], r.p[j], r.p[i]) <= SMALL)
		{
			j--;
		}
		j++;
		Point t = r.p[j];
		r.p[j] = r.p[i];
		r.p[i] = t;//swap..
	}
	r.p.erase(r.p.begin() + j, r.p.end());
	return;
}

bool isInsideConvex(const Point &p0, Poly &r)
{
	if (r.p.size() < 3)
	{
		return false;
	}
	r.p.push_back(r.p.front());
	for (int i = r.p.size(); --i >= 1;)
		if (Cross(r.p[i - 1], r.p[i], p0) < SMALL)//on line false
		{
			r.p.pop_back();
			return false;//counter-clockwise
		}
	r.p.pop_back();
	return true;
}

int main()
{
	int m, c;
	while (scanf("%d%d", &m, &c) == 2)
	{
		if (m == 0 && c == 0)
		{
			break;
		}
		//input
		Poly a, b;
		while (--m >= 0)
		{
			Point t;
			scanf("%lf %lf", &t.x, &t.y);
			a.p.push_back(t);
		}
		while (--c >= 0)
		{
			Point t;
			scanf("%lf %lf", &t.x, &t.y);
			b.p.push_back(t);
		}
		//test
		if (a.p.size() == 1 && b.p.size() == 1)
		{
			puts("Yes");
			goto END;
		}
		if (a.p.size() == 1 && b.p.size() == 2)
		{
			if (fabs(Cross(b.p[0], b.p[1], a.p[0])) < SMALL)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
			goto END;
		}
		if (b.p.size() == 1 && a.p.size() == 2)
		{
			if (fabs(Cross(a.p[0], a.p[1], b.p[0])) < SMALL)
			{
				puts("No");
			}
			else
			{
				puts("Yes");
			}
			goto END;
		}
		//convex
		GrahamScanCross(a);
		GrahamScanCross(b);
		a.p.push_back(a.p.front());
		for (int i = a.p.size(); --i >= 1;)
		{
			int j;
			for (j = b.p.size(); --j >= 0;)
			{
				double ss = Cross(a.p[i - 1], a.p[i], b.p[j]);
				if (ss > SMALL)
				{
					break;
				}
			}
			if (j < 0)
			{
				puts("Yes");
				goto END;
			}
		}
		a.p.pop_back();
		b.p.push_back(b.p.front());
		for (int i = b.p.size(); --i >= 1;)
		{
			int j;
			for (j = a.p.size(); --j >= 0;)
			{
				double ss = Cross(b.p[i - 1], b.p[i], a.p[j]);
				if (ss > SMALL)
				{
					break;
				}
			}
			if (j < 0)
			{
				puts("Yes");
				goto END;
			}
		}
		b.p.pop_back();
		puts("No");
	END:;
	}
}
