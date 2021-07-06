#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

double cross(P a, P b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

bool is_point_online(P a, P b, P c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + 1e-10;
}

bool is_intersect_ls(P a1, P a2, P b1, P b2)
{
	if (is_point_online(a1, a2, b1))
	{
		return true;
	}
	if (is_point_online(a1, a2, b2))
	{
		return true;
	}
	if (is_point_online(b1, b2, a1))
	{
		return true;
	}
	if (is_point_online(b1, b2, a2))
	{
		return true;
	}
	if (cross(a2 - a1, b1 - a1) * cross(a2 - a1, b2 - a1) < 0 &&
			cross(b2 - b1, a1 - b1) * cross(b2 - b1, a2 - b1) < 0)
	{
		return true;
	}
	return false;
}

bool check(int n, P *p1, P *p2, int me)
{
	rep(i, n)
	{
		if (i == me)
		{
			continue;
		}
		if (is_intersect_ls(p1[me], p2[me], p1[i], p2[i]))
		{
			return false;
		}
	}
	return true;
}

int solve(int n, P *p1, P *p2)
{
	int cnt = 0;
	rep(i, n)
	{
		if (check(n, p1, p2, i))
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		P p1[n], p2[n];
		rep(i, n)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			p1[i] = P(re,im);
			scanf("%lf%lf", &re,&im);
			p2[i] = P(re,im);
		}
		cout << solve(n, p1, p2) << endl;
	}
	return 0;
}
