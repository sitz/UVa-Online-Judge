#include <bits/stdc++.h>

using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define INF 0x3f3f3f3f

bool eq(double a, double b)
{
	return fabs(a - b) < 1e-9;
}
const int N = 100005;

int t, n, en;
double w, h, l, r;

struct E
{
	double t;
	int flag;
} e[N * 2];

bool cmp(E a, E b)
{
	if (!eq(a.t, b.t))
		return a.t < b.t;
	return a.flag < b.flag;
}

void g(double x, double xd, double w)
{
	if (eq(xd, 0))
	{
		if (!(x > 0 && x < w))
			r = 0;
	}
	else if (xd > 0)
	{
		l = max(l, -x / xd);
		r = min(r, (w - x) / xd);
	}
	else
	{
		l = max(l, (w - x) / xd);
		r = min(r, -x / xd);
	}
}

void init()
{
	en = 0;
	scanf("%lf%lf%d", &w, &h, &n);
	for (int i = 0; i < n; i++)
	{
		double x, y, xd, yd;
		scanf("%lf%lf%lf%lf", &x, &y, &xd, &yd);
		l = 0, r = INF;
		g(x, xd, w);
		g(y, yd, h);
		if (l < r)
		{
			e[en].t = l;
			e[en++].flag = 1;
			e[en].t = r;
			e[en++].flag = -1;
		}
	}
}

int solve()
{
	int ans = 0, num = 0;
	sort(e, e + en, cmp);
	for (int i = 0; i < en; i++)
	{
		num += e[i].flag;
		ans = max(ans, num);
	}
	return ans;
}

int main()
{
	scanf("%d", &t);
	while (t--)
	{
		init();
		printf("%d\n", solve());
	}
	return 0;
}
