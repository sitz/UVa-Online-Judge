#include <bits/stdc++.h>

using namespace std;

#define foreach(x, v) for (typeof(v).begin() x = (v).begin(); x != (v).end(); ++x)
#define For(i, a, b) for (int i = (a); i < (b); ++i)
#define D(x) cout << #x " is " << x << endl
#define EPS 1e-9

typedef pair<int, int> point;
typedef vector<point> polygon;

vector<polygon> polygons;

const int MAXN = 50;
int p[MAXN];

int find(int u)
{
	return p[u] == u ? u : p[u] = find(p[u]);
}

void link(int u, int v)
{
	if (find(u) != find(v))
	{
		p[find(u)] = find(v);
	}
}

// ret angle in range [0, 2*Pi) of a given Cartesian pt
// if pt == (0,0), -1.0 is returned
double polarAngle(point p)
{
	double x = p.first, y = p.second;
	if (fabs(x) <= EPS && fabs(y) <= EPS)
	{
		return -1.0f;
	}
	if (fabs(x) <= EPS)
	{
		return y > EPS ? 1.0f : 3.0f;
	}
	double theta = atan(1.0f * y / x);
	if (x > EPS)
	{
		return y >= -EPS ? theta : (4 * acos(0.0f) + theta);
	}
	return 2 * acos(0.0f) + theta;
}

// ret true iff p is inside poly.
// PRE: vertices of poly are ordered
// POST: Modify code inside to handle the special case of "on edge".
bool pointInPoly(point p, const polygon &poly)
{
	int n = poly.size();
	double ang = 0.0;
	for (int i = n - 1, j = 0; j < n; i = j++)
	{
		point v(poly[i].first - p.first, poly[i].second - p.second);
		point w(poly[j].first - p.first, poly[j].second - p.second);
		double va = polarAngle(v);
		double wa = polarAngle(w);
		double xx = wa - va;
		if (va < -0.5 || wa < -0.5 || fabs(fabs(xx) - 2 * acos(0)) < EPS)
		{
			// POINT IS ON THE EDGE
			return true;
			assert(false);
			ang += 2 * acos(0);
			continue;
		}
		if (xx < -2 * acos(0))
		{
			ang += xx + 4 * acos(0);
		}
		else if (xx > 2 * acos(0))
		{
			ang += xx - 4 * acos(0);
		}
		else
		{
			ang += xx;
		}
	}
	return (ang * ang > 1.0);
}

// ret true if point (x, y) lies inside (or in the border)
// of box defined by points (x0, y0) and (x1, y1).
bool point_in_box(double x, double y,
									double x0, double y0,
									double x1, double y1)
{
	return min(x0, x1) <= x && x <= max(x0, x1) &&
				 min(y0, y1) <= y && y <= max(y0, y1);
}

// finds the intersection between two segments (not infinite
// lines!)
// segment 1 goes from point (x0, y0) to (x1, y1).
// segment 2 goes from point (x2, y2) to (x3, y3).
// (can be modified to find the intersection between a segment
// and a line)
// handles the case when the 2 segments are:
// *parallel but don't lie on the same line (no intersection)
// *parallel and both lie on the same line (infinite
// *intersections or no intersections)
// *not parallel (one intersection or no intersections)
// returns true if the segments do intersect in any case
bool segment_segment_intersection(double x0, double y0,
																	double x1, double y1,
																	double x2, double y2,
																	double x3, double y3)
{
	double t0 = (y3 - y2) * (x0 - x2) - (x3 - x2) * (y0 - y2);
	double t1 = (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0);
	double det = (y1 - y0) * (x3 - x2) - (y3 - y2) * (x1 - x0);
	if (fabs(det) < EPS)
	{
		// parallel
		if (fabs(t0) < EPS || fabs(t1) < EPS)
		{
			// lie on same line, but they may or may not intersect.
			return (point_in_box(x0, y0, x2, y2, x3, y3) ||
							point_in_box(x1, y1, x2, y2, x3, y3) ||
							point_in_box(x2, y2, x0, y0, x1, y1) ||
							point_in_box(x3, y3, x0, y0, x1, y1));
		}
		else
		{
			// just parallel, no intersection
			return false;
		}
	}
	else
	{
		t0 /= det;
		t1 /= det;
		// 0 <= t0 <= 1 iff the intersection point lies in segment 1.
		// 0 <= t1 <= 1 iff the intersection point lies in segment 2.
		if (0.0 <= t0 && t0 <= 1.0 && 0.0 <= t1 && t1 <= 1.0)
		{
			double x = x0 + t0 * (x1 - x0);
			double y = y0 + t0 * (y1 - y0);
			// intersection pt (x, y)
			return true;
		}
		// intersection pts don't lie on both segments
		return false;
	}
}

bool polygonsIntersect(const polygon &a, const polygon &b)
{
	int na = a.size(), nb = b.size();
	for (int i = 0; i < na; ++i)
	{
		if (pointInPoly(a[i], b))
		{
			return true;
		}
	}
	for (int i = 0; i < nb; ++i)
	{
		if (pointInPoly(b[i], a))
		{
			return true;
		}
	}
	for (int i = 0; i < na; ++i)
	{
		for (int j = 0; j < nb; ++j)
		{
			int xa1 = a[i].first, ya1 = a[i].second;
			int xa2 = a[(i + 1) % na].first, ya2 = a[(i + 1) % na].second;
			int xb1 = b[j].first, yb1 = b[j].second;
			int xb2 = b[(j + 1) % nb].first, yb2 = b[(j + 1) % nb].second;
			if (segment_segment_intersection(xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2))
			{
				return true;
			}
		}
	}
	return false;
}

void solve()
{
	int n = polygons.size();
	for (int i = 0; i < n; ++i)
	{
		p[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (polygonsIntersect(polygons[i], polygons[j]))
			{
				link(i, j);
			}
		}
	}
	set<int> ans;
	for (int i = 0; i < n; ++i)
	{
		ans.insert(find(i));
	}
	cout << ans.size() << endl;
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		string s;
		getline(cin, s);
		polygons.clear();
		for (int i = 0; i < n; ++i)
		{
			polygons.push_back(polygon());
			getline(cin, s);
			stringstream sin(s);
			int x, y;
			while (sin >> x >> y)
			{
				polygons.back().push_back(point(x, y));
			}
			assert(polygons.back().size() >= 3);
		}
		assert(polygons.size() == n);
		solve();
	}
	return 0;
}
