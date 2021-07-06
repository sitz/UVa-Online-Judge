#include <bits/stdc++.h>

using namespace std;

typedef long long lld;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define eps 1e-8
#define inf 1e10

int Sig(double a)
{
	if (a < -eps)
	{
		return -1;
	}
	return a > eps;
}
struct Point
{
	double x, y;
	Point() {}
	Point(double x0, double y0) : x(x0), y(y0) {}
	void in()
	{
		scanf("%lf %lf", &x, &y);
	}
	Point operator*(double t)
	{
		return Point(x * t, y * t);
	}
	double operator*(Point pt)
	{
		return x * pt.y - y * pt.x;
	}
	double operator^(Point pt)
	{
		return x * pt.x + y * pt.y;
	}
	Point operator+(Point pt)
	{
		return Point(x + pt.x, y + pt.y);
	}
	Point operator-(Point pt)
	{
		return Point(x - pt.x, y - pt.y);
	}
	double len()
	{
		return sqrt(x * x + y * y);
	}
};
double dis(Point x, Point y)
{
	return (x - y).len();
}
struct Line
{
	Point p, q;
	Line() {}
	Line(Point p0, Point q0) : p(p0), q(q0) {}
};
bool isinline(Point o, Line l)
{
	if (Sig((o - l.p) * (o - l.q)) != 0)
	{
		return false;
	}
	double f1 = (o - l.p) ^ (l.p - l.q);
	double f2 = (o - l.q) ^ (l.p - l.q);
	if (Sig(f1) == 0 || Sig(f2) == 0)
	{
		return true;
	}
	return Sig(f1) != Sig(f2);
}
bool iscross(Line l1, Line l2)
{
	if (isinline(l1.p, l2) || isinline(l1.q, l2))
	{
		return true;
	}
	swap(l1, l2);
	if (isinline(l1.p, l2) || isinline(l1.q, l2))
	{
		return true;
	}
	Point o1 = l1.p - l1.q;
	Point o2 = l2.p - l2.q;
	if (Sig(o1 * o2) == 0)
	{
		return false;
	}
	if (Sig((l1.p - l2.q) * (l2.q - l2.p)) == Sig((l1.q - l2.q) * (l2.q - l2.p)))
	{
		return false;
	}
	swap(l1, l2);
	if (Sig((l1.p - l2.q) * (l2.q - l2.p)) == Sig((l1.q - l2.q) * (l2.q - l2.p)))
	{
		return false;
	}
	return true;
}
bool cross(Line dec, Line l)
{
	Point o = dec.q - dec.p;
	Point p = l.q - dec.p;
	Point q = l.p - dec.p;
	return Sig((p * q) * (p * o)) > 0 && Sig((p * o) * (q * o)) < 0;
}
bool inside(Point o, Point p[], int n)
{
	p[n] = p[0];
	for (int i = 0; i < n; i++)
		if (isinline(o, Line(p[i], p[i + 1])))
		{
			return true;
		}
	Point next = Point(o.x + rand() % 10000, o.y + rand() % 10000);
	Line l1 = Line(o, next);
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		if (Sig((next - o) * (p[i + 1] - p[i])) == 0)
		{
			continue;
		}
		Line l2 = Line(p[i], p[i + 1]);
		if (cross(l1, l2))
		{
			tmp++;
		}
	}
	return tmp & 1;
}
Point p[110];
bool can[110][110];
double dp[110][110];
int main()
{
	int cc = 1;
	int n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 0; i < n; i++)
		{
			p[i].in();
		}
		p[n] = p[0];
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
			{
				if (i == j)
				{
					continue;
				}
				bool flag = true;
				for (int k = 0; k < n && flag; k++)
				{
					int l = (k + 1) % n;
					if (k == i || k == j || l == i || l == j)
					{
						continue;
					}
					if (iscross(Line(p[i], p[j]), Line(p[k], p[l])))
					{
						flag = false;
					}
				}
				if (flag)
				{
					Point o = (p[i] + p[j]) * 0.5;
					if (!inside(o, p, n))
					{
						flag = false;
					}
				}
				can[i][j] = can[j][i] = flag;
			}
		//		for (int i=0;i<n;i++)
		//			for (int j=i+1;j<n;j++)
		//				if (can[i][j])
		//					printf("%d %d\n",i,j);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = inf;
			}
		for (int i = 0; i < n; i++)
		{
			int j = (i + 1) % n;
			dp[i][j] = 0;
		}
		for (int len = 2; len < n; len++)
			for (int i = 0; i < n; i++)
			{
				int j = (i + len) % n;
				if (!can[i][j])
				{
					continue;
				}
				for (int k = (i + 1) % n; k != j; k = (k + 1) % n)
				{
					if (dp[i][k] != inf && dp[k][j] != inf)
					{
						dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + dis(p[i], p[j]));
					}
				}
			}
		double ans = inf;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (dp[i][j] != inf)
				{
					ans = min(ans, dp[i][j] + dp[j][i] - dis(p[i], p[j]));
				}
		printf("Case %d: %.4f\n", cc++, ans);
	}
	return 0;
}
