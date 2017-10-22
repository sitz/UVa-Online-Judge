#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

const double eps = 1e-10;

class Point
{
public:
	P a;
	Point(){};
	Point(P in)
	{
		a = in;
	}
	bool operator<(const Point &b) const
	{
		if (abs(a.real() - b.a.real()) > eps)
		{
			return a.real() < b.a.real();
		}
		else if (abs(a.imag() - b.a.imag()) > eps)
		{
			return a.imag() < b.a.imag();
		}
		return false;
	}
};

double cross(P a, P b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

bool isp(P a, P b, P c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + eps;
}

bool is_intersectedls(P a1, P a2, P b1, P b2)
{
	if (cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < eps &&
			cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < eps)
	{
		return true;
	}
	return false;
}

Point intersection_ls(P a1, P a2, P b1, P b2)
{
	P b = b2 - b1;
	double d1 = abs(cross(b, a1 - b1));
	double d2 = abs(cross(b, a2 - b1));
	double t = d1 / (d1 + d2);
	return Point(a1 + (a2 - a1) * t);
}

int solve(int n, P *in, P *in2, bool *flag)
{
	int cnt = 1;
	Point data;
	rep(i, n)
	{
		if (flag[i] == false)
		{
			continue;
		}
		set<Point> S;
		rep(j, i)
		{
			if (is_intersectedls(in[i], in2[i], in[j], in2[j]))
			{
				data = intersection_ls(in[i], in2[i], in[j], in2[j]);
				if (data.a.real() > 0 && data.a.real() < 1000 &&
						data.a.imag() > 0 && data.a.imag() < 1000 && S.find(data) == S.end())
				{
					S.insert(data);
				}
			}
		}
		cnt += S.size() + 1;
	}
	return cnt;
}

int main()
{
	int te, tc = 0;
	scanf("%d", &te);
	while (te--)
	{
		if (tc)
		{
			puts("");
		}
		tc = 1;
		int n;
		scanf("%d", &n);
		bool flag[n];
		P in[n], in2[n];
		rep(i, n)
		{
			double re,im;
			scanf("%lf%lf%", &re,&im);
			in[i] = P(re,im);
			scanf("%lf%lf%", &re,&im);
			in2[i] = P(re,im);
			flag[i] = true;
		}
		rep(i, n)
		{
			REP(j, i + 1, n)
			{
				if (in[i].real() == in[j].real() && in[i].imag() == in[j].imag() &&
						in2[i].real() == in2[j].real() && in2[i].imag() == in2[j].imag())
				{
					flag[j] = false;
				}
				if (in[i].real() == in2[j].real() && in[i].imag() == in2[j].imag() &&
						in2[i].real() == in[j].real() && in2[i].imag() == in[j].imag())
				{
					flag[j] = false;
				}
			}
		}
		cout << solve(n, in, in2, flag) << endl;
	}
	return 0;
}
