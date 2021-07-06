#include <bits/stdc++.h>

using namespace std;

const int maxn = 410;
const double eps = 1e-6;
const double pi = acos(-1.0);
int dcmp(double x)
{
	if (fabs(x) < eps)
	{
		return 0;
	}
	else
	{
		return x < 0 ? -1 : 1;
	}
}
int n, m;
double d;
struct interval
{
	double s, e;
	interval(double s = 0, double e = 0) : s(s), e(e) {}
	bool operator<(const interval &tmp) const
	{
		if (dcmp(e - tmp.e) < 0)
		{
			return true;
		}
		if (dcmp(e - tmp.e) == 0)
		{
			double s1 = dcmp(e - s) < 0 ? s - 2 * pi : s;
			double s2 = dcmp(tmp.e < tmp.s) < 0 ? tmp.s - 2 * pi : tmp.s;
			if (dcmp(s1 - s2) > 0)
			{
				return true;
			}
		}
		return false;
	}
	bool operator==(const interval &tmp) const
	{
		return dcmp(e - tmp.e) == 0 && dcmp(s - tmp.s) == 0;
	}
} p[maxn];
double length(double x, double y)
{
	return sqrt(x * x + y * y);
}
double formal(double rad)
{
	if (dcmp(rad - 2 * pi) >= 0)
	{
		return rad - 2 * pi;
	}
	if (dcmp(rad) < 0)
	{
		return rad + 2 * pi;
	}
	return rad;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%lf", &n, &d);
		m = 0;
		for (int i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			if (dcmp(length(x, y) - d) <= 0)
			{
				continue;
			}
			double angle = asin(d / length(x, y));
			p[m++] = interval(formal(atan2(y, x) - angle), formal(atan2(y, x) + angle));
		}
		sort(p, p + m);
		m = unique(p, p + m) - p;
		for (int i = 0; i < m; i++)
		{
			p[i + m] = p[i];
		}
		int ans = m;
		for (int i = 0; i < m; i++)
		{
			if (i && dcmp(p[i].e - p[i - 1].e) == 0)
			{
				continue;
			}
			int tmp = 1, pre = i;
			for (int j = i + 1; j < m + i; j++)
			{
				double s = dcmp(p[j].e - p[j].s) < 0 ? p[j].s - 2 * pi : p[j].s;
				if (dcmp(s - p[pre].e) <= 0)
				{
					continue;
				}
				else
				{
					pre = j;
					tmp++;
				}
			}
			ans = min(ans, tmp);
			double v = p[i].e + 2 * eps;
			for (int j = 0; j < 2 * m; j++)
			{
				p[j] = interval(formal(p[j].s - v), formal(p[j].e - v));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
