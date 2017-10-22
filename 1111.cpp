#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define SQR(x) ((x) * (x))

const int maxint = -1u >> 1;
const double eps = 1e-9;
const double inf = 1e10;

int sgn(double x)
{
	return (x > eps) - (x < -eps);
}

struct P
{
	double x, y;
	P() {}
	P(double _x, double _y) : x(_x), y(_y) {}
	P operator-(const P &a) const
	{
		return P(x - a.x, y - a.y);
	}
	double cross(const P &a, const P &b) const
	{
		return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
	}
	double length() const
	{
		return sqrt(SQR(x) + SQR(y));
	}
	void input()
	{
		scanf("%lf%lf", &x, &y);
	}
	void output() const
	{
		printf("%lf %lf\n", x, y);
	}
};

int n;
vector<P> c1, c2;

bool cmp(const P &p1, const P &p2)
{
	return sgn(p1.y - p2.y) < 0 || (sgn(p1.y - p2.y) == 0 && p1.x < p2.x);
}

vector<P> get_convex(vector<P> &con)
{
	sort(con.begin(), con.end(), cmp);
	//for (int i = 0; i < con.size(); ++i) con[i].output();
	vector<P> res;
	for (int i = 0; i < (int)con.size(); ++i)
	{
		while (res.size() > 1 && sgn(res[res.size() - 2].cross(res.back(), con[i])) <= 0)
		{
			res.pop_back();
		}
		res.push_back(con[i]);
	}
	int c = res.size();
	for (int i = con.size() - 1; i >= 0; --i)
	{
		while ((int)res.size() > c && sgn(res[res.size() - 2].cross(res.back(), con[i])) <= 0)
		{
			res.pop_back();
		}
		res.push_back(con[i]);
	}
	res.pop_back();
	return res;
}
double get_dist(const P &a, const P &b, const P &c)
{
	double area = a.cross(b, c);
	return fabs(area) / (b - c).length();
}

int main()
{
	int ca = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		c1.resize(n);
		for (int i = 0; i < n; ++i)
		{
			c1[i].input();
		}
		c2 = get_convex(c1);
		double mn = inf;
		for (int i = 0; i < (int)c2.size(); ++i)
		{
			P p1 = c2[i], p2 = c2[(i + 1) % c2.size()];
			double mx = 0;
			for (int j = 0; j < (int)c2.size(); ++j)
			{
				mx = max(mx, get_dist(c2[j], p1, p2));
			}
			mn = min(mn, mx);
		}
		printf("Case %d: %.2lf\n", ++ca, ceil(mn * 100) * 0.01);
	}
	return 0;
}
