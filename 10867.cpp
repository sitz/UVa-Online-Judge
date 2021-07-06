#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;
typedef vector<P> Polygon;

const double eps = 1e-10;

double cross(P a, P b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

double dot(P a, P b, P c)
{
	return a.real() * b.real() + a.imag() * b.imag();
}

bool is_point_online_seg(P a, P b, P c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + eps;
}

P intersect_ll(P a1, P a2, P b1, P b2)
{
	P a = a2 - a1, b = b2 - b1;
	return a1 + a * cross(b, b1 - a1) / cross(b, a);
}
double distance_l_p(P &a, P &b, P &c)
{
	return abs(cross(b - a, c - a)) / abs(b - a);
}

bool is_in(Polygon &in, P &a)
{
	int cnt = 0;
	rep(i, in.size())
	{
		P cur = in[i] - a, next = in[(i + 1) % in.size()] - a;
		if (cur.imag() > next.imag())
		{
			swap(cur, next);
		}
		if (cur.imag() < 0 && 0 <= next.imag() &&
				cross(next, cur) >= 0)
		{
			cnt++;
		}
		if (is_point_online_seg(in[i], in[(i + 1) % in.size()], a))
		{
			return true;
		}
	}
	if (cnt % 2 == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool cmp(const P &a, const P &b)
{
	if (abs(a.real() - b.real()) > eps)
	{
		return a.real() < b.real();
	}
	return a.imag() < b.imag();
}

double solve(Polygon &in, P l1, P l2)
{
	vector<P> CP;
	rep(i, in.size())
	{
		double leng = distance_l_p(l1, l2, in[i]);
		if (leng < eps)
		{
			CP.push_back(in[i]);
		}
		else if (cross(l2 - l1, in[i] - l1) * cross(l2 - l1, in[(i + 1) % in.size()] - l1) < 0)
		{
			CP.push_back(intersect_ll(l1, l2, in[i], in[(i + 1) % in.size()]));
		}
	}
	sort(CP.begin(), CP.end(), cmp);
	if (CP.size() == 0)
	{
		return 0;
	}
	double ret = 0;
	rep(i, CP.size() - 1)
	{
		P mid = (CP[i] + CP[(i + 1) % CP.size()]);
		mid /= 2;
		if (is_in(in, mid))
		{
			ret += abs(CP[i] - CP[(i + 1) % CP.size()]);
		}
	}
	return ret;
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) && n)
	{
		Polygon a;
		rep(i, n)
		{
			double re, im;
			scanf("%lf%lf", &re, &im);
			P tmp(re, im);
			a.push_back(tmp);
		}
		rep(i, q)
		{
			double re, im;
			scanf("%lf%lf", &re, &im);
			P l1(re, im);
			scanf("%lf%lf", &re, &im);
			P l2(re, im);
			printf("%.3lf\n", solve(a, l1, l2));
		}
	}
	return 0;
}
