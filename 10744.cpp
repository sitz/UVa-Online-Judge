#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

const double eps = 1e-10;

typedef complex<double> P;

class info
{
public:
	double d;
	P p;
	bool operator<(const info &a) const
	{
		return d < a.d;
	}
};

double cross(P a, P b)
{
	return a.real() * b.imag() - a.imag() * b.real();
}

double distance_l_p(P a, P b, P c)
{
	double tmp = cross(b - a, c - a);
	if (tmp < 0)
	{
		tmp *= -1;
	}
	P d = b - a;
	return tmp / sqrt(d.real() * d.real() + d.imag() * d.imag());
}

void calc_dist(info *in, int n, P a1, P a2, info *cpy)
{
	rep(i, n)
	{
		cpy[i] = in[i];
		double tmp = distance_l_p(a1, a2, cpy[i].p);
		cpy[i].d = tmp;
		if (cross(a2 - a1, cpy[i].p - a1) < 0)
		{
			cpy[i].d *= -1;
		}
	}
	return;
}

void solve(info *in, int n, int q)
{
	info cpy[n];
	int tc = 1;
	rep(i, q)
	{
		double re,im;
		scanf("%lf%lf", &re,&im);
		P a1 (re,im);
		scanf("%lf%lf", &re,&im);
		P a2 (re,im);
		P rotate = a2 - a1;
		rotate = P(rotate.imag()*-1, rotate.real());
		rotate /= sqrt(rotate.real() * rotate.real() + rotate.imag() * rotate.imag());
		calc_dist(in, n, a1, a2, cpy);
		sort(cpy, cpy + n);
		double inter[n];
		rep(i, n - 1)
		{
			inter[i + 1] = cpy[i + 1].d - cpy[i].d;
		}
		int r = 0, l = n;
		rotate *= cpy[0].d;
		a1 += rotate;
		a2 += rotate;
		double ans = 0, tmp = 0;
		rep(i, n)
		{
			ans += cpy[i].d - cpy[0].d;
		}
		REP(i, 1, n)
		{
			l--;
			r++;
			ans = min(ans, ans + r * inter[i] - l * inter[i]);
		}
		printf("Case %d: %0.lf\n", tc++, ans);
	}
	return;
}

int main()
{
	int n, q;
	while (scanf("%d%d", &n, &q) != -1)
	{
		info in[n];
		rep(i, n)
		{
			double re,im;
			scanf("%lf%lf", &re,&im);
			in[i].p = P(re,im);
		}
		solve(in, n, q);
	}
	return 0;
}
