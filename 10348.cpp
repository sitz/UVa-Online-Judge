#include <bits/stdc++.h>

using namespace std;

#define inf 2100000000
#define EP 1e-10

typedef struct
{
	double x, y;
} TPoint;
typedef struct
{
	TPoint a, b;
} TLineSeg;
double max(double a, double b)
{
	return a > b ? a : b;
}
double min(double a, double b)
{
	return a < b ? a : b;
}
double the_distance(TPoint p1, TPoint p2)
{
	return (sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)));
}
double xmult(TPoint p1, TPoint p2, TPoint p0)
{
	return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}
double dmult(TPoint p1, TPoint p2, TPoint p0)
{
	return ((p1.x - p0.x) * (p2.x - p0.x) + (p1.y - p0.y) * (p2.y - p0.y));
}
int euqal_point(TPoint p1, TPoint p2)
{
	return ((fabs(p1.x - p2.x) < EP) && (fabs(p1.y - p2.y) < EP));
}

int intersect(TLineSeg u, TLineSeg v);
int Done();
int insidepolygon(int vcount, TPoint polygon[], TPoint q);

TLineSeg ship[110];
TPoint id[60][25];
int ge[60];
int N, M;

int main()
{
	int i;
	cin >> N;
	for (i = 0; i < N; i++)
	{
		cin >> ship[i].a.x >> ship[i].a.y;
		cin >> ship[i].b.x >> ship[i].b.y;
	}
	cin >> M;
	for (i = 0; i < M; i++)
	{
		cin >> ge[i];
		for (int j = 0; j < ge[i]; j++)
		{
			cin >> id[i][j].x >> id[i][j].y;
		}
	}
	Done();
	return 0;
}

int Done()
{
	TLineSeg l1;
	for (int i = 0; i < N; i++)
	{
		int flag = 0;
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < ge[j]; k++)
			{
				l1.a.x = id[j][k].x;
				l1.a.y = id[j][k].y;
				int k1 = (k + 1) % ge[j];
				l1.b.x = id[j][k1].x;
				l1.b.y = id[j][k1].y;
				if (intersect(l1, ship[i]))
				{
					flag = 1;
					j = M;
					break;
				}
			}
		}
		if (flag)
		{
			cout << "Submarine " << i + 1 << " is partially on land." << endl;
		}
		else
		{
			int ff = 0;
			for (int j = 0; j < M; j++)
			{
				if (insidepolygon(ge[j], id[j], ship[i].a))
				{
					ff = 1;
					break;
				}
			}
			if (ff)
			{
				cout << "Submarine " << i + 1 << " is completely on land." << endl;
			}
			else
			{
				cout << "Submarine " << i + 1 << " is still in water." << endl;
			}
		}
	}
	return 0;
}

int intersect(TLineSeg u, TLineSeg v)
{
	return ((max(u.a.x, u.b.x) >= min(v.a.x, v.b.x)) &&
					(max(v.a.x, v.b.x) >= min(u.a.x, u.b.x)) &&
					(max(u.a.y, u.b.y) >= min(v.a.y, v.b.y)) &&
					(max(v.a.y, v.b.y) >= min(u.a.y, u.b.y)) &&
					(xmult(v.a, u.b, u.a) * xmult(u.b, v.b, u.a) >= 0) &&
					(xmult(u.a, v.b, v.a) * xmult(v.b, u.b, v.a) >= 0));
}

int insidepolygon(int vcount, TPoint polygon[], TPoint q)
{
	int c, i, j;
	double t, angle1, angle2;
	TLineSeg l1, l2;
	TPoint dir[16] = {{100, 0}, {0, 100}, {-100, 0}, {0, -100}, {100, 100}, {-100, 100}, {-100, -100}, {100, -100}, {50, 100}, {-50, 100}, {-50, -100}, {50, -100}, {100, 50}, {-100, 50}, {-100, -50}, {100, -50}};
	l1.a = q;
	for (i = 0; i < 16; i++)
	{
		l1.b.x = q.x + dir[i].x;
		l1.b.y = q.y + dir[i].y;
		for (c = 0, j = 0; j < vcount; j++)
		{
			l2.a = polygon[j];
			l2.b = polygon[(j + 1) % vcount];
			t = xmult(l2.a, l1.b, l1.a) * xmult(l1.b, l2.b, l1.a);
			if (t > 1e-6)
			{
				if (xmult(l1.a, l2.b, l2.a) * xmult(l2.b, l1.b, l2.a) >= 0)
				{
					c++;
				}
				else
				{
					double one = dmult(l1.a, l2.b, l2.a);
					double two = the_distance(l2.a, l1.a);
					double three = the_distance(l2.a, l2.b);
					angle1 = one / (two * three);
					one = dmult(l1.b, l2.b, l2.a);
					two = the_distance(l2.a, l1.b);
					three = the_distance(l2.a, l2.b);
					angle2 = one / (two * three);
					if (angle1 < angle2)
					{
						c++;
					}
				}
			}
			else if (t < -1e-6)
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if (j == vcount)
		{
			break;
		}
	}
	return (c % 2 != 0);
}
