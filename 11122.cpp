#include <bits/stdc++.h>

using namespace std;

#define EPS std::numeric_limits<double>::epsilon()

/**
    Two triangles have common internal point <-> there exist one edge in one triangle which can separate this triangle from the other one.
*/
struct Point
{
	double x, y;
	Point(double _x, double _y) : x(_x), y(_y) {}
};
struct Convex
{
	double tx, ty;
	vector<Point *> p;
	Convex() : tx(0), ty(0) {}
};

bool sat(Convex c1, Convex c2)
{
	int c1_faces = c1.p.size();
	int c2_faces = c2.p.size();
	// For every face in c1
	for (int i = 0; i < c1_faces; i++)
	{
		// Grab a face (face x, face y)
		double fx = c1.p[i]->x - c1.p[(i + 1) % c1_faces]->x;
		double fy = c1.p[i]->y - c1.p[(i + 1) % c1_faces]->y;
		// Create a perpendicular axis to project on (axis x, axis y)
		double ax = -fy, ay = fx;
		// Normalize the axis
		double len_v = sqrt(ax * ax + ay * ay);
		ax /= len_v;
		ay /= len_v;
		// Carve out the min and max values
		double c1_min = std::numeric_limits<double>::max(), c1_max = -c1_min;
		double c2_min = std::numeric_limits<double>::max(), c2_max = -c2_min;
		// Project every point in c1 on the axis and store min and max
		for (int j = 0; j < c1_faces; j++)
		{
			double c1_proj = (ax * (c1.p[j]->x + c1.tx) + ay * (c1.p[j]->y + c1.ty)) / (ax * ax + ay * ay);
			c1_min = min(c1_proj, c1_min);
			c1_max = max(c1_proj, c1_max);
		}
		// Project every point in c2 on the axis and store min and max
		for (int j = 0; j < c2_faces; j++)
		{
			double c2_proj = (ax * (c2.p[j]->x + c2.tx) + ay * (c2.p[j]->y + c2.ty)) / (ax * ax + ay * ay);
			c2_min = min(c2_proj, c2_min);
			c2_max = max(c2_proj, c2_max);
		}
		// separated => no overlap
		// EQUAL => count as 'no overlap'
		if (c1_max <= c2_min || c1_min >= c2_max)
		{
			return true;
		}
	}
	return false;
}

int T;
Convex *c1, *c2;

int main()
{
	scanf("%d", &T);
	for (int cc = 0; cc < T; ++cc)
	{
		//fprintf(stderr, "test case: ");
		c1 = new Convex();
		for (int i = 0; i < 3; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			//fprintf(stderr, "%d %d ",x,y);
			c1->p.push_back(new Point(x, y));
		}
		//fprintf(stderr, "\n");
		c2 = new Convex();
		for (int i = 0; i < 3; ++i)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			//fprintf(stderr, "%d %d ",x,y);
			c2->p.push_back(new Point(x, y));
		}
		//fprintf(stderr, "\n");
		/*// is vertex of one triangle on edge/vertex of the other?
		bool is_on_edge = false;
		for (int i=0; i<3; ++i)
		{
		    Point *p1 = c1->p[i%3];
		    Point *p2 = c1->p[(i+1)%3];
		    Point *p3 = new Point(p2->x-p1->x, p2->y-p1->y);
		    for (int j=0; j<3; ++j)
		    {
		        Point *q = c2->p[j];
		        Point *qq = new Point(q->x-p1->x, q->y-p1->y);

		        //printf("p1: (%lf,%lf); p2: (%lf,%lf); q: (%lf,%lf)\n", p1->x,p1->y,p2->x,p2->y,q->x,q->y);
		        if ( fabs( (p3->y * (qq->x / p3->x)) - qq->y) < EPS )
		        {
		            is_on_edge = true;
		            break;
		        }
		    }
		}
		bool is_on_vertex = false;
		for (int i=0; i<3; ++i)
		{
		    Point *p = c1->p[i];
		    for (int j=0; j<3; ++j)
		    {
		        Point *q = c2->p[j];
		        if (fabs(p->x-q->x) < EPS && fabs(p->y-q->y) < EPS)
		        {
		            is_on_vertex = true;
		            break;
		        }
		    }
		}*/
		bool separated = sat(*c1, *c2) || sat(*c2, *c1);
		if (separated)
		{
			printf("pair %d: no\n", cc + 1);
		}
		else
		{
			printf("pair %d: yes\n", cc + 1);
		}
	}
	return 0;
}
