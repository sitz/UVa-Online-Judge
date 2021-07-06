#include <bits/stdc++.h>

using namespace std;

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define MAX_DIR 4
#define SEARCH_RECT 1
#define SEARCH_WRAP 2
#define EPS 1e-8

const double double_inf = (double)5.0 * pow(10, 9);

#define FORIT(type, obj, var) for (type::iterator var = (obj).begin(); var != (obj).end(); ++var)

typedef double elem;
typedef complex<elem> point;
typedef pair<point, point> line;

inline bool eq(elem a, elem b)
{
	return abs(a - b) < EPS;
}

inline bool eqless(elem a, elem b)
{
	return eq(a, b) || a < b;
}

inline elem cross(const point &a, const point &b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

inline elem dist(const point &a, const point &b, const point &x)
{
	return abs(cross(b - a, x - a)) / abs(b - a);
}

inline bool intersected_seg(const line &a, const line &b)
{
	double d1 = dist(b.first, b.second, a.first);
	double d2 = dist(b.first, b.second, a.second);
	if (eq(d1 + d2, 0.0))
	{
		return false;
	}
	return (cross(a.second - a.first, b.first - a.first) *
									cross(a.second - a.first, b.second - a.first) <=
							EPS &&
					cross(b.second - b.first, a.first - b.first) *
									cross(b.second - b.first, a.second - b.first) <=
							EPS);
}

inline point intersection_seg(const line &a, const line &b)
{
	double d1 = dist(b.first, b.second, a.first);
	double d2 = dist(b.first, b.second, a.second);
	double t = d1 / (d1 + d2);
	return a.first + t * (a.second - a.first);
}

inline bool LineCrossPoint(line a, line b, point &ret)
{
	if (intersected_seg(a, b))
	{
		ret = intersection_seg(a, b);
		return true;
	}
	return false;
}

class Point
{
public:
	Point()
	{
		fill(bcon, bcon + MAX_DIR, false);
	}
	Point(point p) : p(p)
	{
		fill(bcon, bcon + MAX_DIR, false);
	}

	point p;
	bool bcon[MAX_DIR];
	point con[MAX_DIR];

	bool operator<(const Point &t) const
	{
		if (eq(p.real(), t.p.real()))
		{
			return !eq(p.imag(), t.p.imag()) && p.imag() > t.p.imag();
		}
		else if (p.real() < t.p.real())
		{
			return true;
		}
		return false;
	}
	bool operator==(const Point &t) const
	{
		return eq(p.real(), t.p.real()) && eq(p.imag(), t.p.imag());
	}

	bool SetEdge(const line &l, const set<Point> &cross_points)
	{
		set<Point>::iterator itcp = cross_points.find(Point(p));
		set<Point>::iterator beg = cross_points.begin();
		set<Point>::iterator last = cross_points.end();
		if (beg == last)
		{
			return false;
		}
		--last;
		if (l.first.real() == l.second.real())
		{
			// 垂直な線分
			if (distance(beg, itcp))
			{
				Point t = *(--itcp);
				++itcp;
				con[UP] = bcon[UP] ? (t < Point(con[UP]) ? con[UP] : t.p) : t.p;
				bcon[UP] = true;
			}
			if (distance(itcp, last))
			{
				Point t = *(++itcp);
				--itcp;
				con[DOWN] = bcon[DOWN] ? (Point(con[DOWN]) < t ? con[DOWN] : t.p) : t.p;
				bcon[DOWN] = true;
			}
		}
		else
		{
			// 水平な線分
			if (distance(itcp, last))
			{
				Point t = *(++itcp);
				--itcp;
				con[RIGHT] = bcon[RIGHT] ? (Point(con[RIGHT]) < t ? con[RIGHT] : t.p) : t.p;
				bcon[RIGHT] = true;
			}
			if (distance(beg, itcp))
			{
				Point t = *(--itcp);
				++itcp;
				con[LEFT] = bcon[LEFT] ? (t < Point(con[LEFT]) ? con[LEFT] : t.p) : t.p;
				bcon[LEFT] = true;
			}
		}
		return true;
	}
};

class Line
{
public:
	Line() {}
	Line(point a, point b) : l(a, b) {}

	int id;
	line l;
	set<Point> cross_points;
};

class State
{
public:
	int dir;
	Point p;
};

bool dfs(State now, const set<Point> &cpset, vector<Point> &ret, set<Point> &visited)
{
	if (visited.find(now.p) != visited.end())
	{
		vector<Point>::iterator itc = find(ret.begin(), ret.end(), now.p);
		ret.erase(ret.begin(), itc);
		return true;
	}
	else
	{
		visited.insert(Point(now.p));
		ret.push_back(Point(now.p));
		for (int i = -1; i <= 2; ++i)
		{
			State new_state;
			new_state.dir = (now.dir + i + MAX_DIR) % MAX_DIR;
			if (now.p.bcon[new_state.dir])
			{
				set<Point>::iterator itcp = cpset.find(Point(now.p.con[new_state.dir]));
				if (itcp == cpset.end())
				{
					continue;
				}
				new_state.p = *itcp;
				if (dfs(new_state, cpset, ret, visited))
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
		return false;
	}
}

void CreateGraph(set<Point> &cross_set,
								 map<Point, bool> &vis,
								 map<Point, set<int>> &T,
								 const vector<Line> &lines)
{
	vector<Point> v;
	FORIT(set<Point>, cross_set, its)
	{
		v.push_back(*its);
	}
	for (int i = 0; i < v.size(); ++i)
	{
		if (T.find(v[i]) != T.end())
		{
			FORIT(set<int>, T[v[i]], itv)
			{
				int l = *itv;
				v[i].SetEdge(lines[l].l, lines[l].cross_points);
			}
		}
	}
	cross_set.clear();
	vis.clear();
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		cross_set.insert(v[i]);
		vis.insert(make_pair(v[i], false));
	}
}

void CrossPoints(vector<Line> &lines,
								 set<Point> &cross_point,
								 map<Point, set<int>> &T)
{
	for (int i = 0; i < (int)lines.size(); ++i)
	{
		for (int j = 0; j < (int)lines.size(); ++j)
		{
			if (i != j)
			{
				point cross;
				Point cp;
				if (LineCrossPoint(lines[i].l, lines[j].l, cross))
				{
					cp = Point(cross);
					cross_point.insert(cp);
					lines[i].cross_points.insert(cp);
					lines[j].cross_points.insert(cp);
					T[cp].insert(i);
					T[cp].insert(j);
				}
			}
		}
	}
}

bool LineConnected(const line &a, const line &b, line &conn)
{
	bool ret = false;
	elem aminx = min(a.first.real(), a.second.real());
	elem amaxx = max(a.first.real(), a.second.real());
	elem aminy = min(a.first.imag(), a.second.imag());
	elem amaxy = max(a.first.imag(), a.second.imag());
	elem bminx = min(b.first.real(), b.second.real());
	elem bmaxx = max(b.first.real(), b.second.real());
	elem bminy = min(b.first.imag(), b.second.imag());
	elem bmaxy = max(b.first.imag(), b.second.imag());
	if (eq(aminx, amaxx) && eq(aminx, bminx) && eq(bminx, bmaxx))
	{
		if (eqless(aminy, bminy) && eqless(bminy, amaxy))
		{
			conn = line(point(aminx, aminy), point(aminx, max(amaxy, bmaxy)));
			ret = true;
		}
		else if (eqless(bminy, aminy) && eqless(aminy, bmaxy))
		{
			conn = line(point(aminx, bminy), point(aminx, max(amaxy, bmaxy)));
			ret = true;
		}
	}
	else if (eq(aminy, amaxy) && eq(aminy, bminy) && eq(bminy, bmaxy))
	{
		if (eqless(aminx, bminx) && eqless(bminx, amaxx))
		{
			conn = line(point(aminx, aminy), point(max(amaxx, bmaxx), aminy));
			ret = true;
		}
		else if (eqless(bminx, aminx) && eqless(aminx, bmaxx))
		{
			conn = line(point(bminx, aminy), point(max(amaxx, bmaxx), aminy));
			ret = true;
		}
	}
	return ret;
}

void ConnectLines(vector<Line> &lines)
{
	int sz = 1, aftersz = 0;
	while (sz != aftersz)
	{
		sz = lines.size();
		for (unsigned int i = 0; i < lines.size(); ++i)
		{
			for (unsigned int j = i + 1; j < lines.size(); ++j)
			{
				line conn;
				if (LineConnected(lines[i].l, lines[j].l, conn))
				{
					lines[i].l = conn;
					lines.erase(lines.begin() + j);
				}
			}
		}
		aftersz = lines.size();
	}
}

int main()
{
	while (true)
	{
		int n;
		int ans = 0;
		set<Point> cross_point;
		map<Point, set<int>> T;
		map<Point, bool> vis_map;
		vector<Line> lines;
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		for (int i = 0; i < n; ++i)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			Line l = Line(point(x1, y1), point(x2, y2));
			l.id = i;
			lines.push_back(l);
		}
		ConnectLines(lines);
		CrossPoints(lines, cross_point, T);
		CreateGraph(cross_point, vis_map, T, lines);
		while (true)
		{
			vector<Point> circuit;
			set<Point> visited;
			State ini_state;
			bool bEnd = true;
			ini_state.dir = RIGHT;
			for (set<Point>::iterator itcp = cross_point.begin(); itcp != cross_point.end(); ++itcp)
			{
				if (!vis_map[*itcp])
				{
					ini_state.p = *itcp;
					bEnd = false;
					break;
				}
			}
			if (bEnd)
			{
				break;
			}
			visited.clear();
			if (dfs(ini_state, cross_point, circuit, visited))
			{
				vector<line> vperim;
				bool bErased = false;
				if (circuit.size() >= 4)
				{
					++ans;
					vis_map[ini_state.p] = true;
					visited.clear();
					for (unsigned int i = 0; i < circuit.size() - 1; ++i)
					{
						vperim.push_back(make_pair(circuit[i].p, circuit[i + 1].p));
						visited.insert(circuit[i]);
					}
					visited.insert(circuit.back());
					vperim.push_back(make_pair(circuit.back().p, circuit.front().p));
					FORIT(set<Point>, cross_point, itc)
					{
						set<Point> cross_set;
						if (bErased)
						{
							itc = cross_point.begin();
							bErased = false;
						}
						point from = point(itc->p.real(), itc->p.imag() + 0.5);
						point to = point(itc->p.real() + double_inf, itc->p.imag() + 0.5);
						line l(from, to);
						if (visited.find(*itc) != visited.end())
						{
							continue;
						}
						for (unsigned int i = 0; i < vperim.size(); ++i)
						{
							point cross;
							if (LineCrossPoint(l, vperim[i], cross))
							{
								cross_set.insert(Point(cross));
							}
						}
						if (cross_set.size() & 1)
						{
							cross_point.erase(itc);
							itc = cross_point.begin();
							bErased = true;
						}
					}
				}
				for (unsigned int i = 1; i < circuit.size(); ++i)
				{
					set<Point>::iterator itc = cross_point.find(circuit[i]);
					if (itc != cross_point.end())
					{
						cross_point.erase(itc);
					}
				}
			}
			else
			{
				for (unsigned int i = 0; i < circuit.size(); ++i)
				{
					vis_map[circuit[i]] = true;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
