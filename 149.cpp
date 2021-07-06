#include <bits/stdc++.h>

using namespace std;

#define EPS 1.0e-10
#define MAX 16
#define PI (acos(-1.0))
#define RAD(deg) (((deg) / 180) * PI)
#define DISCERNIBLE_GAP RAD(0.01)
#define SQ(a) ((a) * (a))

typedef double elem;
typedef complex<elem> point, vec;

const double ok_gap = DISCERNIBLE_GAP;

struct circle
{
	point c;
	elem r;
};

struct tree
{
	circle c;
	bool visible;
	pair<vec, vec> tangential;
};

inline bool eq(elem a, elem b)
{
	return abs(a - b) < EPS;
}
inline bool eqless(elem a, elem b)
{
	return eq(a, b) || a < b;
}
inline elem dist(point a, point b)
{
	return abs(b - a);
}
inline point rotp(point p, elem theta)
{
	return p * exp(point(0, theta));
}
inline point rotp_base(point base, point p, elem theta)
{
	point ret = rotp(p - base, theta);
	return ret + base;
}
inline vec uvec(vec a)
{
	return a / abs(a);
}
inline vec normr(vec a)
{
	return a * vec(0, -1);
}
inline vec norml(vec a)
{
	return a * vec(0, 1);
}
inline vec unormr(vec a)
{
	return normr(a) / abs(a);
}
inline vec unorml(vec a)
{
	return norml(a) / abs(a);
}
inline elem dot(vec a, vec b)
{
	return (a.real() * b.real() + a.imag() * b.imag());
}
inline elem len(vec a)
{
	return abs(a);
}

// unit vector ret.first which passes through a and contacts c is for the left side a->c.c
int UnitTangentialVecs(circle c, point a, pair<vec, vec> &ret)
{
	if (dist(c.c, a) < c.r)
	{
		return 0;
	}
	if (dist(c.c, a) == c.r)
	{
		vec v = c.c - a;
		ret.first = unorml(v);
		ret.second = unormr(v);
		return 2;
	}
	else
	{
		vec v = c.r * uvec(a - c.c);
		elem d = dist(a, c.c);
		elem xx = SQ(d) - SQ(c.r);
		//cout << "d:"<< d << "xx:" << xx << endl;
		elem theta = acos((SQ(c.r) + SQ(d) - xx) / (2 * c.r * d));
		//cout << "theta:" << theta << endl;
		point p = c.c + rotp(v, theta);
		ret.second = uvec(p - a);
		p = c.c + rotp(v, -theta);
		ret.first = uvec(p - a);
		return 2;
	}
}

// ret radian val rad <=pi
inline elem Radians(vec a, vec b)
{
	return acos(dot(a, b) / len(a) * len(b));
}

// whether pt p lies btw two dir vect a, b, starting from pt base
bool IsBetween(point p, point base, vec a, vec b)
{
	point t = p - base;
	elem rad_ab = Radians(a, b);
	elem rad_ta = Radians(t, a);
	elem rad_tb = Radians(t, b);
	return eqless(rad_ta, rad_ab) && eqless(rad_tb, rad_ab);
}

int SubForest(int quad, double diam, double x, double y)
{
	int ret = 0;
	tree forest[MAX][MAX];
	int ix = 1, iy = 1;
	const int ox[] = {1, 0, 0, 1};
	const int oy[] = {1, 1, 0, 0};
	const int dx[] = {1, -1, -1, 1};
	const int dy[] = {1, 1, -1, -1};
	ix = ox[quad];
	iy = oy[quad];
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			forest[i][j].c.c = point(ix, iy);
			forest[i][j].c.r = diam / 2.0;
			forest[i][j].visible = true;
			UnitTangentialVecs(forest[i][j].c, point(x, y), forest[i][j].tangential);
			ix += dx[quad];
		}
		ix = ox[quad];
		iy += dy[quad];
	}
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			//if( !forest[i][j].visible )
			//continue;
			//cout << "Forest "<<forest[i][j].c.c<<" IS VISIBLE.\n";
			pair<vec, vec> tans = forest[i][j].tangential;
			if (eqless(Radians(tans.first, tans.second), ok_gap))
			{
				forest[i][j].visible = false;
			}
			for (int k = i; k < MAX; ++k)
			{
				for (int l = j; l < MAX; ++l)
				{
					if (k == i && l == j)
					{
						continue;
					}
					if (!forest[k][l].visible)
					{
						continue;
					}
					pair<vec, vec> this_tans = forest[k][l].tangential;
					if (IsBetween(this_tans.second, point(0, 0),
												tans.first,
												tans.second) ||
							IsBetween(this_tans.first, point(0, 0),
												tans.first,
												tans.second) ||
							eqless(Radians(tans.first, this_tans.second), ok_gap) ||
							eqless(Radians(tans.second, this_tans.first), ok_gap))
					{
						forest[k][l].visible = false;
					}
				}
			}
		}
	}
	for (int i = 0; i < MAX; ++i)
	{
		for (int j = 0; j < MAX; ++j)
		{
			if (forest[i][j].visible)
			{
				++ret;
			}
		}
	}
	return ret;
}

int Forests(double diam, double x, double y)
{
	int ret = 0;
	for (int q = 0; q < 4; ++q)
	{
		ret += SubForest(q, diam, x, y);
	}
	return ret;
}

int main()
{
	while (1)
	{
		double d, x, y;
		cin >> d >> x >> y;
		if (d == 0 && x == 0 && y == 0)
		{
			break;
		}
		cout << Forests(d, x, y) << endl;
	}
	return 0;
}
