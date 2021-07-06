#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)

const double EPS = 1e-7;
const double PI = acos(-1);

template <class T>
struct point
{
	T x, y;
	point operator+(const point &a) const
	{
		return (point){
				x + a.x, y + a.y};
	}
	point operator-(const point &a) const
	{
		return (point){
				x - a.x, y - a.y};
	}
};

template <class T>
point<T> operator*(T c, const point<T> &a)
{
	return (point<T>){
			c * a.x, c * a.y};
}

template <class T>
bool operator!=(const point<T> &a, const point<T> &b)
{
	return abs(a.x - b.x) > EPS || abs(a.y - b.y) > EPS;
}

template <class T>
T dot(const point<T> &a, const point<T> &b)
{
	return a.x * b.x + a.y * b.y;
}

template <class T>
T cross(const point<T> &a, const point<T> &b)
{
	return a.x * b.y - a.y * b.x;
}

template <class T>
double abs(const point<T> &a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

template <class T>
double arg(const point<T> &a)
{
	double t = atan2(a.y, a.x);
	return t < 0 ? t + 2 * PI : t;
}

enum
{
	CCW = 1,
	CW = -1,
	ON = 0
};
int ccw(const point<double> &a, const point<double> &b, const point<double> &c)
{
	double rdir = cross(b - a, c - a);
	if (rdir > EPS)
	{
		return CCW;
	}
	if (rdir < -EPS)
	{
		return CW;
	}
	return ON;
}

template <class T>
struct line
{
	point<T> a, b;
};

template <class T>
struct segment
{
	point<T> a, b;
	operator line<T>() const
	{
		return (line<T>){
				a, b};
	}
};

template <class T>
struct circle
{
	point<T> c;
	T r;
};

int tangent(const circle<double> &C, const point<double> &p, vector<point<double>> &res)
{
	double a = abs(p - C.c);
	if (a < C.r - EPS)
	{
		return 0;
	}
	else if (a < C.r + EPS)
	{
		res.push_back(p);
		return 1;
	}
	else
	{
		double b = sqrt(a * a - C.r * C.r);
		double psi = arg(p - C.c), phi = PI - acos(b / a);
		res.push_back(p + b * (point<double>){cos(psi + phi), sin(psi + phi)});
		res.push_back(p + b * (point<double>){cos(psi - phi), sin(psi - phi)});
		return 2;
	}
}

bool intersect(const line<double> &L, const segment<double> &S)
{
	return cross(L.b - L.a, S.a - L.a) * cross(L.b - L.a, S.b - L.a) < EPS;
}

point<double> get_intersect(const line<double> &L1, const line<double> &L2)
{
	double a1 = cross(L1.b - L1.a, L2.b - L2.a);
	double a2 = cross(L1.b - L1.a, L1.b - L2.a);
	if (abs(a1) < EPS)
	{
		return L1.a;
	}
	return L2.a + a2 / a1 * (L2.b - L2.a);
}

template <class T>
double dist(const point<T> &a, const point<T> &b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

template <class T>
double dist(const segment<T> &S, const point<T> &p)
{
	if (dot(S.b - S.a, p - S.a) <= 0)
	{
		return dist(p, S.a);
	}
	if (dot(S.a - S.b, p - S.b) <= 0)
	{
		return dist(p, S.b);
	}
	return abs(cross(S.b - S.a, p - S.a)) / dist(S.a, S.b);
}

bool intersect(const circle<double> &C, const segment<double> &S)
{
	return dist(S, C.c) < C.r + EPS;
}

struct event
{
	int type, i;
	point<double> p;
	int io;
	bool operator<(const event &e) const
	{
		if (type != e.type)
		{
			return type < e.type;
		}
		if (type == 0)
		{
			return p.x + EPS < e.p.x || abs(p.x - e.p.x) < EPS && io < e.io;
		}
		if (type == 1)
		{
			return p.y + EPS < e.p.y || abs(p.y - e.p.y) < EPS && io < e.io;
		}
		if (type == 2)
		{
			return p.x - EPS > e.p.x || abs(p.x - e.p.x) < EPS && io < e.io;
		}
		if (type == 3)
		{
			return p.y - EPS > e.p.y || abs(p.y - e.p.y) < EPS && io < e.io;
		}
		assert(0);
	}
};

int main()
{
	const point<double> O = {0, 0};
	for (int cas = 1, h, w, r, cx, cy, n; scanf("%d%d%d%d%d%d", &h, &w, &r, &cx, &cy, &n), h; cas++)
	{
		static point<double> P[10000];
		rep(i, n) scanf("%lf%lf\n", &P[i].x, &P[i].y);
		circle<double> C = {(point<double>){cx, cy}, r};
		segment<double> B, R, T, L;
		L.b = B.a = (point<double>){0, 0};
		B.b = R.a = (point<double>){w, 0};
		R.b = T.a = (point<double>){w, h};
		T.b = L.a = (point<double>){0, h};
		vector<event> E;
		rep(i, n)
		{
			vector<point<double>> Q;
			tangent(C, P[i], Q);
			rep(j, Q.size()) if (P[i] != Q[j])
			{
				line<double> M = {P[i], Q[j]};
				point<double> q;
				if (intersect(M, B))
				{
					q = get_intersect(B, M), E.push_back((event){0, i, q, ccw(q, Q[j], C.c)});
				}
				if (intersect(M, R))
				{
					q = get_intersect(R, M), E.push_back((event){1, i, q, ccw(q, Q[j], C.c)});
				}
				if (intersect(M, T))
				{
					q = get_intersect(T, M), E.push_back((event){2, i, q, ccw(q, Q[j], C.c)});
				}
				if (intersect(M, L))
				{
					q = get_intersect(L, M), E.push_back((event){3, i, q, ccw(q, Q[j], C.c)});
				}
			}
		}
		sort(E.begin(), E.end());
		int cnt = 0;
		rep(i, n) if (!intersect(C, (segment<double>){O, P[i]})) cnt++;
		int ans = cnt;
		rep(i, E.size())
		{
			event e = E[i];
			if (intersect(C, (segment<double>){e.p, P[e.i]}))
			{
				if (e.io == CCW)
				{
					cnt++;
				}
				else
				{
					cnt--;
				}
			}
			ans = max(ans, cnt);
		}
		printf("Case %d: %d\n", cas, ans);
	}
	return 0;
}
