#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1);
int sgn(double x)
{
	return (x < -eps) ? -1 : (x > eps);
}

//2D PT
struct PT
{
	double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	void rd()
	{
		scanf("%lf %lf", &x, &y);
	}
	PT operator-(const PT o)
	{
		return PT(x - o.x, y - o.y);
	}
	PT operator+(const PT o)
	{
		return PT(x + o.x, y + o.y);
	}
	PT operator*(double s)
	{
		return PT(x * s, y * s);
	}
	PT operator/(double s)
	{
		return PT(x / s, y / s);
	}
	bool operator<(const PT &o) const
	{
		return x < o.x - eps || (x < o.x + eps && y < o.y - eps);
	}
	bool operator==(const PT &o) const
	{
		return !sgn(y - o.y) && !sgn(x - o.x);
	}
	bool operator!=(const PT &o) const
	{
		return sgn(y - o.y) || sgn(x - o.x);
	}
};

double cpr(PT a, PT b)
{
	return a.x * b.y - a.y * b.x;
}
double dpr(PT a, PT b)
{
	return a.x * b.x + a.y * b.y;
}

double cpr(PT a, PT b, PT c)
{
	return cpr(b - a, c - a);
}
double dpr(PT a, PT b, PT c)
{
	return dpr(b - a, c - a);
}

double vlen(PT a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}
double dist(PT a, PT b)
{
	return vlen(a - b);
}

struct LE
{
	PT a, b;
	LE() {}
	LE(PT a, PT b) : a(a), b(b) {}
};

//å¤ä¸¤ç¹abä¸ç´çº¿cdç¸å¯¹ä½ç½®, ç¹å¨ç´çº¿ä¸0, åä¾§1, å¼ä¾§-1
int plside(PT a, PT b, PT c, PT d)
{
	return sgn(cpr(c, a, d) * cpr(c, b, d));
}

//å¤ä¸¤çº¿æ®µab cdéä¸¥æ ¼ç¸äº¤
bool ints_in(PT a, PT b, PT c, PT d)
{
	int d1 = plside(a, b, c, d), d2 = plside(c, d, a, b);
	if (d1 == 1 || d2 == 1)
	{
		return 0;
	}
	if (d1 == -1 || d2 == -1)
	{
		return 1;
	}
	return dpr(c, a, b) < eps || dpr(d, a, b) < eps || dpr(a, c, d) < eps || dpr(b, c, d) < eps;
}

int lineints(LE l1, LE l2)
{
	return ints_in(l1.a, l1.b, l2.a, l2.b);
}

struct EVENT
{
	double x;
	int a, b, c;
	EVENT() {}
	EVENT(double x, int a, int b, int c) : x(x), a(a), b(b), c(c) {}
	bool operator<(const EVENT &b) const
	{
		return sgn(x - b.x) ? x < b.x : c < b.c;
	}
};

const int NN = 300005;
LE le[NN];
EVENT ev[NN];
int ty[NN], dep[NN];

double nowx;

struct cmp
{
	double gety(LE ll)
	{
		double dx = ll.b.x - ll.a.x;
		double dy = ll.b.y - ll.a.y;
		return sgn(dx) ? (nowx - ll.a.x) / dx * dy + ll.a.y : ll.a.y;
	}
	bool operator()(int a, int b)
	{
		double y1 = gety(le[a]);
		double y2 = gety(le[b]);
		return sgn(y1 - y2) ? y1 < y2 : ty[a] < ty[b];
	}
};

int work(int n)
{
	set<int, cmp> ss;
	set<int, cmp>::iterator it;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		nowx = ev[i].x;
		int a = ev[i].a, b = ev[i].b;
		if (ev[i].c == 0)
		{
			it = ss.lower_bound(a);
			dep[a] = dep[b] = (it == ss.end() ? 1 : dep[*it] + ty[*it]);
			ans = max(ans, dep[a]);
			if (it != ss.end() && (lineints(le[a], le[*it]) || lineints(le[b], le[*it])))
			{
				return -1;
			}
			if (it != ss.begin() && (--it, lineints(le[a], le[*it]) || lineints(le[b], le[*it])))
			{
				return -1;
			}
			ss.insert(a);
			ss.insert(b);
		}
		if (ev[i].c == 1)
		{
			dep[b] = dep[a];
			ss.erase(a);
			it = ss.lower_bound(b);
			if (it != ss.end() && (b / 3 != *it / 3 && lineints(le[b], le[*it])))
			{
				return -1;
			}
			if (it != ss.begin() && (--it, b / 3 != *it / 3 && lineints(le[b], le[*it])))
			{
				return -1;
			}
			ss.insert(b);
		}
		if (ev[i].c == 2)
		{
			ss.erase(a);
			ss.erase(b);
			it = ss.lower_bound(a);
			if (it != ss.end() && it != ss.begin())
			{
				int x = *it;
				int y = *--it;
				if (x / 3 != y / 3 && lineints(le[x], le[y]))
				{
					return -1;
				}
			}
		}
	}
	return ans;
}

int main()
{
	//freopen("1.txt", "r", stdin);
	int n, cas = 0;
	while (cin >> n, ~n)
	{
		n *= 3;
		for (int i = 0; i < n; i += 3)
		{
			PT p[3];
			for (int j = 0; j < 3; j++)
			{
				p[j].rd();
			}
			sort(p, p + 3);
			le[i + 0] = LE(p[0], p[1]);
			le[i + 1] = LE(p[0], p[2]);
			le[i + 2] = LE(p[1], p[2]);
			ty[i + 0] = ty[i + 2] = (cpr(p[0], p[1], p[2]) < 0);
			ty[i + 1] = 1 ^ ty[i];
			ev[i + 0] = EVENT(p[0].x, i + 0, i + 1, 0);
			ev[i + 1] = EVENT(p[1].x, i + 0, i + 2, 1);
			ev[i + 2] = EVENT(p[2].x, i + 1, i + 2, 2);
		}
		sort(ev, ev + n);
		int ans = work(n);
		printf("Case %d: ", ++cas);
		if (ans > -1)
		{
			printf("%d shades\n", ans + 1);
		}
		else
		{
			puts("ERROR");
		}
	}
	return 0;
}
