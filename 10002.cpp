#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for (int(i) = int(a); (i) < int(b); (i)++)

const int MAX_POINT = 101;
struct Point
{
	double x, y;
};

inline double crsProd(const Point &start1, const Point &end1,
											const Point &start2, const Point &end2)
{
	return (end1.x - start1.x) * (end2.y - start2.y) - (end2.x - start2.x) * (end1.y - start1.y);
}
inline double vecLenSqr(const Point &start, const Point &end)
{
	double x1 = start.x, y1 = start.y;
	double x2 = end.x, y2 = end.y;
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
class Polygon
{
public:
	Point m_point[MAX_POINT];
	int m_pntCnt;
	void addPoint(const Point &p)
	{
		m_point[m_pntCnt] = p;
		m_pntCnt++;
	}
	//Find convex hull, sorted in counter clockwise order
	void getConvexHull(const Point *const points, const int pntCnt)
	{
		init();
		//Find the lowest and leftest point
		int leftLow = 0;
		FOR(i, 1, pntCnt)
		{
			if (points[i].y < points[leftLow].y && points[i].x < points[leftLow].x)
			{
				leftLow = i;
			}
		}
		bool used[MAX_POINT];
		memset(used, 0, sizeof(used));
		int next = leftLow;
		do
		{
			int current = next;
			addPoint(points[current]);
			used[current] = true;
			next = leftLow;
			FOR(i, 0, pntCnt)
			{
				if (!used[i])
				{
					double crossP;
					crossP = crsProd(points[current], points[i],
													 points[current], points[next]);
					if (crossP > 0)
					{
						next = i;
					}
					else if (crossP == 0 && vecLenSqr(points[current], points[i]) > vecLenSqr(points[current], points[next]))
					{
						next = i;
					}
				}
			}
		} while (next != leftLow);
	}
	void init()
	{
		m_pntCnt = 0;
	}
	int pointCnt() const
	{
		return m_pntCnt;
	}
	Point point(int i) const
	{
		return m_point[i];
	}
};

int main()
{
	Point m_point[MAX_POINT];
	int m_pntCnt;
	while (scanf("%d", &m_pntCnt) == 1 && m_pntCnt >= 3)
	{
		// input
		for (int i = 0; i < m_pntCnt; i++)
		{
			scanf("%lf%lf", &m_point[i].x, &m_point[i].y);
		}
		// solve
		Polygon convex;
		convex.getConvexHull(m_point, m_pntCnt);
		double A = 0.0;
		Point center = {0.0, 0.0};
		for (int i = 2; i < convex.pointCnt(); i++)
		{
			double a = crsProd(convex.point(0), convex.point(i - 1),
												 convex.point(0), convex.point(i));
			Point c;
			c.x = (convex.point(0).x + convex.point(i - 1).x + convex.point(i).x) / 3.0;
			c.y = (convex.point(0).y + convex.point(i - 1).y + convex.point(i).y) / 3.0;
			center.x = (center.x * A + c.x * a) / (a + A);
			center.y = (center.y * A + c.y * a) / (a + A);
			A += a;
		}
		printf("%.3lf %.3lf\n", center.x, center.y);
	}
	return 0;
}
