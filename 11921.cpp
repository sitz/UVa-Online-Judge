#include <bits/stdc++.h>

using namespace std;

#define eps 1.0e-8
#define sgn(f) ((f) < (-eps) ? -1 : ((f) > eps))
#define clc(f) sgn(f) == 0 ? ((f) = 0.0) : (f)

struct Edge
{
	int to, nxt;
	double w;
	Edge(int _t = -1, double _w = -1, int _n = -1)
	{
		to = _t;
		w = _w;
		nxt = _n;
	}
} e[2555555];

bool isinq[23333];
double d[23333];
int n, N, cnt_edge, head[23333];
queue<int> q;

void add_edge(int u, int v, double w)
{
	e[cnt_edge] = Edge(v, w, head[u]);
	head[u] = cnt_edge++;
	e[cnt_edge] = Edge(u, w, head[v]);
	head[v] = cnt_edge++;
}

void spfa()
{
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < N; ++i)
	{
		isinq[i] = false;
		d[i] = -1;
	}
	d[0] = 0;
	q.push(0);
	isinq[0] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		isinq[u] = false;
		for (int p = head[u]; p != -1; p = e[p].nxt)
		{
			int v = e[p].to;
			double w = e[p].w;
			if (sgn(d[v] + 1) == 0 || sgn(d[v] - d[u] - w) > 0)
			{
				d[v] = d[u] + w;
				if (!isinq[v])
				{
					isinq[v] = true;
					q.push(v);
				}
			}
		}
	}
}

struct Point
{
	double x, y;
	Point(double _x = 0, double _y = 0) : x(_x), y(_y){};
	Point operator+(Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator-(Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator*(double p)
	{
		return Point(x * p, y * p);
	}
	Point operator/(double p)
	{
		return Point(x / p, y / p);
	}
	bool operator==(Point a)
	{
		return sgn(x - a.x) == 0 && sgn(y - a.y) == 0;
	}
	bool operator<(const Point &a) const
	{
		if (sgn(x - a.x) != 0)
		{
			return sgn(x - a.x) < 0;
		}
		else
		{
			return sgn(y - a.y) < 0;
		}
	}
} robot, tgt, p[23333];

map<Point, int> mp;

struct Circle
{
	double r;
	Point c;
	Point pt_get(double a)
	{
		return Point(c.x + cos(a) * r, c.y + sin(a) * r);
	}
	int chk_pos(Point a)
	{
		double d = (a.x - c.x) * (a.x - c.x) + (a.y - c.y) * (a.y - c.y), sr = r * r;
		if (sgn(d - sr) > 0)
		{
			return 1;
		}
		else if (sgn(d - sr) == 0)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
} rock[55];

typedef Point Vector;

double dmult(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}
double xmult(Vector a, Vector b)
{
	return a.x * b.y - a.y * b.x;
}
double xmult(Point a, Point b, Point o)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
Vector xmult(Vector a)
{
	return Vector(a.y, -a.x);
}
double dis(Vector a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
double dis(Point a, Point b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double angle(Vector v)
{
	return atan2(v.y, v.x);
}
double intersection_angle(Vector a, Vector b)
{
	return acos(dmult(a, b) / dis(a) / dis(b));
}
double DistanceToLine(Point p, Point a, Point b)
{
	return fabs(xmult(b - a, p - a)) / dis(b - a);
}
bool CheckPoint(Point a)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int f = rock[i].chk_pos(a);
		if (f == -1)
		{
			return false;
		}
		if (f == 0)
		{
			cnt++;
		}
	}
	return cnt <= 1;
}
void pt_add(Point a)
{
	if (!CheckPoint(a))
	{
		return;
	}
	if (mp.find(a) != mp.end())
	{
		return;
	}
	mp[a] = N;
	p[N++] = a;
}
int pt_find(Point a)
{
	if (mp.find(a) != mp.end())
	{
		return mp[a];
	}
	else
	{
		return -1;
	}
}
int tan_get(Point p, Circle c, Point *pt)
{
	Vector u = p - c.c;
	double d = dmult(u, u), rr = c.r * c.r;
	int flag = sgn(d - rr);
	if (flag < 0)
	{
		return 0;
	}
	else if (flag == 0)
	{
		pt[0] = p;
		return 1;
	}
	else
	{
		Vector v = xmult(u);
		pt[0] = (c.c * d + u * rr - v * c.r * sqrt(d - rr)) / d;
		pt[1] = (c.c * d + u * rr + v * c.r * sqrt(d - rr)) / d;
		return 2;
	}
}
Point GetLineProjection(Point p, Point a, Point b)
{
	if (sgn(xmult(p - a, p - b)) == 0)
	{
		return p;
	}
	return a + (b - a) * (dmult(b - a, p - a) / dmult(b - a, b - a));
}
int line_Circle_intersect(Point a, Point b, Circle c, Point *pt)
{
	double d = DistanceToLine(c.c, a, b);
	if (sgn(d - c.r) > 0)
	{
		return 0;
	}
	Point p = GetLineProjection(c.c, a, b);
	Vector v = (b - a) / dis(b - a);
	double l = sqrt(c.r * c.r - d * d);
	pt[0] = p - v * l;
	pt[1] = p + v * l;
	if (sgn(d - c.r) == 0)
	{
		return 1;
	}
	else
	{
		return 2;
	}
}
bool chk(Point a, Point b)
{
	Point pt[15];
	Vector v = b - a;
	int cnt, ct = 0;
	double dv = dmult(v, v), t[5];
	for (int i = 0; i < n; ++i)
	{
		cnt = line_Circle_intersect(a, b, rock[i], pt);
		if (cnt == 0)
		{
			continue;
		}
		else if (cnt == 1)
		{
			t[0] = dmult(pt[0] - a, v) / dv;
			clc(t[0]);
			if (sgn(t[0]) > 0 && sgn(t[0] - 1) < 0)
			{
				return false;
			}
		}
		else
		{
			t[0] = dmult(pt[0] - a, v) / dv;
			t[1] = dmult(pt[1] - a, v) / dv;
			clc(t[0]);
			clc(t[1]);
			if (sgn(t[0] - t[1]) > 0)
			{
				swap(t[0], t[1]);
			}
			if (sgn(t[1]) <= 0 || sgn(t[0] - 1) >= 0)
			{
				continue;
			}
			t[0] = max(t[0], 0.0);
			t[1] = min(t[1], 1.0);
			if (sgn(t[0] - t[1]) < 0)
			{
				return false;
			}
		}
	}
	return true;
}
double arc_len(Circle c, Point a, Point b)
{
	if (a == b)
	{
		return 2 * M_PI * c.r;
	}
	Vector va = a - c.c, vb = b - c.c;
	double alpha = intersection_angle(va, vb);
	if (sgn(xmult(va, vb)) < 0)
	{
		alpha = 2 * M_PI - alpha;
	}
	return alpha * c.r;
}
bool cmp(const Point &a, const Point &b)
{
	if (sgn(a.y) >= 0)
	{
		if (sgn(b.y) < 0)
		{
			return true;
		}
		else if (sgn(xmult(a, b)) != 0)
		{
			return sgn(xmult(a, b)) > 0;
		}
		else
		{
			return sgn(a.x) > 0;
		}
	}
	else
	{
		if (sgn(b.y) >= 0)
		{
			return false;
		}
		else
		{
			return sgn(xmult(a, b)) > 0;
		}
	}
}
int chk_dir(Vector v, Vector u)
{
	if (sgn(xmult(u, v)) == 0)
	{
		if (sgn(dmult(u, v)) >= 0)
		{
			return 1;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return 0;
	}
}
bool chkin(Vector v, Vector L, Vector R)
{
	if (chk_dir(L, R) == 1 || chk_dir(v, L) == 1 || chk_dir(v, R) == 1)
	{
		return false;
	}
	if (sgn(xmult(L, R)) >= 0)
	{
		return sgn(xmult(L, v)) > 0 && sgn(xmult(v, R)) > 0;
	}
	else
	{
		return sgn(xmult(v, L)) <= 0 || sgn(xmult(R, v)) <= 0;
	}
}
int tan_get(Circle A, Circle B, Point *a, Point *b)
{
	int cnt = 0;
	if (sgn(A.r - B.r) < 0)
	{
		swap(a, b);
		swap(A, B);
	}
	double d2 = dmult(A.c - B.c, A.c - B.c), rdiff = A.r - B.r, rsum = A.r + B.r;
	if (sgn(d2 - rdiff * rdiff) < 0)
	{
		return 0;
	}
	double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
	if (sgn(d2) == 0 && sgn(A.r - B.r) == 0)
	{
		return -1;
	}
	if (sgn(d2 - rdiff * rdiff) == 0)
	{
		a[cnt] = A.pt_get(base);
		b[cnt] = B.pt_get(base);
		cnt++;
		return 1;
	}
	double ang = acos((A.r - B.r) / sqrt(d2));
	a[cnt] = A.pt_get(base + ang);
	b[cnt] = B.pt_get(base + ang);
	cnt++;
	a[cnt] = A.pt_get(base - ang);
	b[cnt] = B.pt_get(base - ang);
	cnt++;
	if (sgn(d2 - rsum * rsum) == 0)
	{
		a[cnt] = A.pt_get(base);
		b[cnt] = B.pt_get(M_PI + base);
		cnt++;
	}
	else if (sgn(d2 - rsum * rsum) > 0)
	{
		double ang = acos((A.r + B.r) / sqrt(d2));
		a[cnt] = A.pt_get(base + ang);
		b[cnt] = B.pt_get(M_PI + base + ang);
		cnt++;
		a[cnt] = A.pt_get(base - ang);
		b[cnt] = B.pt_get(M_PI + base - ang);
		cnt++;
	}
	return cnt;
}
void init()
{
	N = 0;
	mp.clear();
	cnt_edge = 0;
	memset(head, -1, sizeof(head));
	pt_add(robot);
	pt_add(tgt);
	int cnt;
	Point pt[10], ptt[10];
	for (int i = 0; i < n; ++i)
	{
		cnt = tan_get(robot, rock[i], pt);
		for (int j = 0; j < cnt; ++j)
		{
			pt_add(pt[j]);
		}
		cnt = tan_get(tgt, rock[i], pt);
		for (int j = 0; j < cnt; ++j)
		{
			pt_add(pt[j]);
		}
		for (int j = i + 1; j < n; ++j)
		{
			cnt = tan_get(rock[i], rock[j], pt, ptt);
			for (int k = 0; k < cnt; ++k)
			{
				pt_add(pt[k]);
				pt_add(ptt[k]);
			}
		}
	}
}
void graph_build()
{
	int cnt, u, v;
	Point tp[10];
	for (int i = 0; i < n; ++i)
	{
		cnt = tan_get(robot, rock[i], tp);
		for (int j = 0; j < cnt; ++j)
		{
			u = pt_find(tp[j]);
			if (u == -1)
			{
				continue;
			}
			if (chk(robot, tp[j]))
			{
				add_edge(0, u, dis(robot, tp[j]));
			}
		}
		cnt = tan_get(tgt, rock[i], tp);
		for (int j = 0; j < cnt; ++j)
		{
			u = pt_find(tp[j]);
			if (u == -1)
			{
				continue;
			}
			if (chk(tgt, tp[j]))
			{
				add_edge(1, u, dis(tgt, tp[j]));
			}
		}
		for (int j = i + 1; j < n; ++j)
		{
			Point tpp[10];
			cnt = tan_get(rock[i], rock[j], tp, tpp);
			for (int k = 0; k < cnt; ++k)
			{
				u = pt_find(tp[k]);
				v = pt_find(tpp[k]);
				if (u == -1 || v == -1)
				{
					continue;
				}
				if (chk(tp[k], tpp[k]))
				{
					add_edge(u, v, dis(tp[k], tpp[k]));
				}
			}
		}
	}
	Point pt[23333];
	int m;
	for (int i = 0; i < n; ++i)
	{
		m = 0;
		for (int j = 0; j < N; ++j)
		{
			if (rock[i].chk_pos(p[j]) == 0)
			{
				pt[m++] = p[j];
			}
		}
		for (int j = 0; j < m; ++j)
		{
			pt[j] = pt[j] - rock[i].c;
		}
		sort(pt, pt + m, cmp);
		pt[m] = pt[0];
		for (int j = 0; j < m; ++j)
		{
			bool ok = true;
			for (int k = 0; k < n; ++k)
			{
				if (k == i)
				{
					continue;
				}
				double d = dis(rock[i].c, rock[k].c), sr = rock[i].r + rock[k].r;
				if (sgn(d - sr) == 0)
				{
					if (chkin(rock[k].c - rock[i].c, pt[j], pt[j + 1]))
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
			{
				int u = pt_find(rock[i].c + pt[j]), v = pt_find(rock[i].c + pt[j + 1]);
				double w = arc_len(rock[i], pt[j] + rock[i].c, pt[j + 1] + rock[i].c);
				add_edge(u, v, w);
			}
		}
	}
}
int main()
{
	int T, cas = 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%lf%lf%lf", &robot.x, &robot.y, &tgt.x, &tgt.y);
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf%lf", &rock[i].c.x, &rock[i].c.y, &rock[i].r);
		}
		if (chk(robot, tgt))
		{
			printf("Case %d: %.8f\n", cas++, dis(robot, tgt));
		}
		else
		{
			init();
			graph_build();
			spfa();
			printf("Case %d: %.8f\n", cas++, d[1]);
		}
	}
	return 0;
}
