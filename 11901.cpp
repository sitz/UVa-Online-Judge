#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1.0);

struct point
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}

	void input()
	{
		scanf("%lf%lf", &x, &y);
	}

	void output()
	{
		cout << x << " " << y << endl;
	}
} A, B, C, D;
double a1, b1, a2, b2, ang1, ang2;

queue<point> q;
vector<double> ans;

const double eps = 1e-6;

int sgn(double x)
{
	return x < -eps ? -1 : x > eps;
}

point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}

point operator+(point a, point b)
{
	return point(a.x + b.x, a.y + b.y);
}

point operator*(double k, point a)
{
	return point(k * a.x, k * a.y);
}

double dist(point a, point b)
{
	a.x -= b.x, a.y -= b.y;
	return sqrt(a.x * a.x + a.y * a.y);
}

void rotate(point &a, double ang)
{
	a = point(a.x * cos(ang) - a.y * sin(ang), a.x * sin(ang) + a.y * cos(ang));
}

point to_p(double ang)
{
	return point(a1 * cos(ang), b1 * sin(ang));
}

double cal(point a)
{
	return dist(a, C) + dist(a, D) - 2 * a2;
}

void solve(point u)
{
	double l = u.x, r = u.y;
	int sgnl = sgn(cal(to_p(l)));
	int sgnr = sgn(cal(to_p(r)));
	if (sgnl * sgnr > 0)
	{
		double low = l, high = r;
		for (int tim = 0; tim < 50; tim++)
		{
			double m1 = (2 * low + high) / 3;
			double m2 = (low + 2 * high) / 3;
			double d1 = cal(to_p(m1));
			double d2 = cal(to_p(m2));
			if ((sgnl > 0) ^ (d1 > d2))
			{
				high = m2;
			}
			else
			{
				low = m1;
			}
		}
		if (sgn(cal(to_p(low))) != sgnl)
		{
			q.push(point(l, low));
			q.push(point(low, r));
		}
	}
	else if (sgnl * sgnr < 0)
	{
		double low = l, high = r;
		for (int tim = 0; tim < 50; tim++)
		{
			double mid = (low + high) / 2;
			if ((sgnl > 0) ^ (cal(to_p(mid)) > 0.0))
			{
				high = mid;
			}
			else
			{
				low = mid;
			}
		}
		low = (low + high) / 2;
		q.push(point(l, low));
		q.push(point(low, r));
	}
	else
	{
		if (sgnl == 0)
		{
			ans.push_back(l);
			while (!sgn(cal(to_p(l))))
			{
				l += 1e-3;
			}
		}
		if (sgnr == 0)
		{
			ans.push_back(r);
			while (!sgn(cal(to_p(r))))
			{
				r -= 1e-3;
			}
		}
		if (sgn(r - l) >= 0)
		{
			q.push(point(l, r));
		}
	}
}

int main()
{
	int cas = 0;
	while (scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &a1, &b1, &ang1, &B.x, &B.y, &a2, &b2, &ang2) != EOF)
	{
		ang1 /= 180.0 / PI;
		ang2 /= 180.0 / PI;
		if (a1 < b1)
		{
			swap(a1, b1);
			ang1 -= PI / 2;
		}
		if (a2 < b2)
		{
			swap(a2, b2);
			ang2 -= PI / 2;
		}
		B = B - A;
		rotate(B, -ang1);
		ang2 = ang2 - ang1;
		point v = point(cos(ang2), sin(ang2));
		C = B + sqrt(a2 * a2 - b2 * b2) * v;
		D = B - sqrt(a2 * a2 - b2 * b2) * v;
		ans.clear();
		while (!q.empty())
		{
			q.pop();
		}
		q.push(point(0.0, PI / 2));
		q.push(point(PI / 2, PI));
		q.push(point(PI, PI / 2 * 3));
		q.push(point(PI / 2 * 3, 2 * PI));
		while (!q.empty())
		{
			solve(q.front());
			q.pop();
		}
		sort(ans.begin(), ans.end());
		vector<double> res;
		for (int i = 0; i < ans.size(); i++)
		{
			if (!i || sgn(ans[i] - ans[i - 1]))
			{
				point t = to_p(ans[i]);
				rotate(t, ang1);
				t = t + A;
				res.push_back(t.x + t.y);
			}
		}
		printf("Case %d:\n", ++cas);
		if (res.empty())
		{
			puts("Do_not_intersect.");
		}
		else
		{
			sort(res.begin(), res.end());
			for (int i = 0; i < res.size(); i++)
			{
				printf("%.8f\n", res[i]);
			}
		}
	}
	return 0;
}
