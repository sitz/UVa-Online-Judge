#include <bits/stdc++.h>

using namespace std;

/*
 * 634.cpp
 *
 *  Created on: Jul 20, 2011
 *      Author: Mauricio
 */

struct point
{
	double x, y;
};

int point_in_polygon(vector<point> &polygon, point &p)
{
	//C is the number of times a line from point t
	//towards the polygon intersect segments of the polygon
	//if C is even = the point is outside the polygon
	//if C is odd = the point is inside the polygon
	int i, j;
	int size;
	int c;
	c = 0;//assume the point is not inside the polygon
	size = polygon.size();
	for (i = 0, j = size - 1; i < size; j = i++)
	{
		//the point crosses the segment's y-bound
		if (((polygon[i].y > p.y) != (polygon[j].y > p.y)) &&
				//the point passes through a vertex
				(p.x < (polygon[j].x - polygon[i].x) * (p.y - polygon[i].y) / (polygon[j].y - polygon[i].y) + polygon[i].x))
		{
			c = !c;
		}
	}
	return c;
}

int main()
{
	int n_points;//number of points
	int i;
	point p;//point to check
	while (scanf("%d", &n_points) && n_points != 0)
	{
		vector<point> polygon(n_points);
		for (i = 0; i < n_points; ++i)
		{
			scanf("%lf%lf", &polygon[i].x, &polygon[i].y);
		}
		scanf("%lf%lf", &p.x, &p.y);
		bool inside;
		inside = point_in_polygon(polygon, p);
		if (inside == 1)
		{
			printf("T\n");
		}
		else
		{
			printf("F\n");
		}
	}
	return 0;
}
