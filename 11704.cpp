#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define ALL(C) (C).begin(), (C).end()
#define pb push_back

typedef complex<double> P;

const double PI = 2 * acos(0);
const double eps = 1e-10;

class state
{
public:
	double ang;
	bool isc, isupper;
	bool operator<(const state &a) const
	{
		return ang < a.ang;
	}
};

int solve(vector<state> &in, int c, int p)
{
	int bc = 0, bp = 0;
	double st = in[0].ang - eps, ste = in[0].ang + PI - eps;
	rep(i, in.size())
	{
		double tmp = in[i].ang;
		if (in[i].isupper)
		{
			tmp += PI;
		}
		if (st - eps < tmp && tmp < ste + eps)
		{
			if (in[i].isc)
			{
				bc++;
			}
			else
			{
				bp++;
			}
		}
	}
	if (c - bc == bc && p - bp == bp)
	{
		return true;
	}
	rep(i, in.size())
	{
		if (in[i].isupper)
		{
			if (in[i].isc)
			{
				bc++;
			}
			else
			{
				bp++;
			}
		}
		else
		{
			if (in[i].isc)
			{
				bc--;
			}
			else
			{
				bp--;
			}
		}
		if ((i + 1 == in.size()
		|| in[i + 1].ang - in[i].ang > 1e-7)
		&& c - bc == bc && p - bp == bp)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	int c, p;
	while (scanf("%d%d", &c,&p) == 2 && c != -1)
	{
		vector<state> in;
		double ang;
		rep(i, c)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			P tmp = P(re,im);
			ang = atan2(im, re);
			if (ang >= 0)
			{
				in.pb((state){ang - PI, true, true});
			}
			else
			{
				in.pb((state){ang, true, false});
			}
		}
		rep(j, p)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			P tmp = P(re,im);
			ang = atan2(im, re);
			if (ang >= 0)
			{
				in.pb((state){ang - PI, false, true});
			}
			else
			{
				in.pb((state){ang, false, false});
			}
		}
		sort(ALL(in));
		if (solve(in, c, p))
		{
			puts("YES");
		}
		else
		{
			puts("NO");
		}
	}
	return 0;
}
