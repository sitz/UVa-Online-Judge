#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;
const double eps = 1e-10;

void output(P in)
{
	printf("%.2lf %.2lf\n", in.real(), in.imag());
}

void solve(vector<P> &in, double ori)
{
	int i = 0;
	double req = ori;
	output(in[0]);
	while (i < (int)in.size() - 1)
	{
		P e = in[i + 1] - in[i];
		double dist = abs(in[i + 1] - in[i]);
		e /= dist;
		if (dist + eps > req)
		{
			output(in[i] + e * req);
			P inv = -in[i + 1] + in[i];
			inv /= abs(inv);
			double rem = dist - req;
			in[i] = in[i + 1] + inv * rem;
			req = ori;
		}
		else
		{
			req -= dist;
			i++;
		}
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	rep(t, T)
	{
		printf("Road #%d:\n", t + 1);
		int n, k;
		scanf("%d%d", &n,&k);
		vector<P> in(n);
		rep(i, n)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			in[i] = P(re,im);
		}
		double all = 0.0f;
		REP(i, 1, n)
		{
			all += abs(in[i] - in[i - 1]);
		}
		double req = all / (k - 1);
		solve(in, req);
		printf("\n");
	}
	return 0;
}
