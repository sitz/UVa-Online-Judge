#include <bits/stdc++.h>

using namespace std;

struct point
{
	int x, y;
};

inline int dist(point a, point b)
{
	return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

// (p1,p2) x (p1,p3)
inline int cross(point p1, point p2, point p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

inline bool min_y(point a, point b)
{
	if (a.y == b.y)
	{
		return a.x < b.x;
	}
	return a.y < b.y;
}

static point base;
inline bool ccw(point a, point b)
{
	int c = cross(base, a, b);
	if (c == 0)
	{
		return dist(base, a) < dist(base, b);
	}
	return c > 0;
}

class kingdom
{
public:
	vector<point> house;
	kingdom();
	bool is_destroyed;
	void convex_hull();
	void destroy(point);
	bool is_inside(point);
	double area();
};

kingdom::kingdom()
{
	is_destroyed = false;
}

// Graham Scan
inline void kingdom::convex_hull()
{
	swap(house[0], *min_element(house.begin(), house.end(), min_y));
	base = house[0];
	sort(house.begin(), house.end(), ccw);
	house.push_back(house[0]);
	int CH = 1;
	for (int i = 2; i < house.size(); ++i)
	{
		while (cross(house[CH - 1], house[CH], house[i]) <= 0)
		{
			if (CH == 1)
			{
				house[CH] = house[i];
				i++;
			}
			else
			{
				CH--;
			}
		}
		CH++;
		house[CH] = house[i];
	}
	house.resize(CH + 1);
}

inline void kingdom::destroy(point missile)
{
	if (is_destroyed)
	{
		return;
	}
	if (is_inside(missile))
	{
		is_destroyed = true;
	}
}

inline double kingdom::area()
{
	if (!is_destroyed)
	{
		return 0;
	}
	double area = 0;
	for (int i = 1; i < house.size(); ++i)
	{
		area += (house[i - 1].x * house[i].y) - (house[i].x * house[i - 1].y);
	}
	return area / 2;
}

inline bool kingdom::is_inside(point missile)
{
	for (int i = 1; i < house.size(); ++i)
	{
		if (cross(house[i - 1], house[i], missile) < 0)
		{
			return false;
		}
	}
	return true;
}

inline kingdom build_kingdom(int house_count)
{
	kingdom k;
	int x, y;
	for (int i = 0; i < house_count; ++i)
	{
		point p;
		scanf("%d%d", &p.x, &p.y);
		k.house.push_back(p);
	}
	return k;
}

int main()
{
	// 1. build world
	vector<kingdom> king;
	int house_count;
	while (scanf("%d", &house_count) == 1)
	{
		if (house_count == -1)
		{
			break;
		}
		king.push_back(build_kingdom(house_count));
	}

	// 2. convex hull
	for (int i = 0; i < king.size(); ++i)
	{
		king[i].convex_hull();
	}

	// 3. missiles atk
	double total_area = 0;
	point missile;
	while (scanf("%d%d", &missile.x, &missile.y) == 2)
	{
		for (int i = 0; i < king.size(); ++i)
		{
			king[i].destroy(missile);
		}
	}

	// 4. calc sum of destroyed area
	int sz = king.size();
	for (int i = 0; i < sz; ++i)
	{
		total_area += king[i].area();
	}

	printf("%.2lf\n", total_area);
	return 0;
}
