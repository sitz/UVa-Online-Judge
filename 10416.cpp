#include <bits/stdc++.h>

using namespace std;

#define REP(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) REP(i, 0, n)

typedef complex<double> P;

const double eps = 1e-01;

bool isp(P &a, P &b, P &c)
{
	return abs(a - c) + abs(b - c) < abs(a - b) + eps;
}

bool check(int n, P a, P b, P *in, int lstart, int rstart, int lend, int rend)
{
	for (; rstart != rend; rstart = (rstart + 1) % n, lstart = (lstart + n - 1) % n)
	{
		if (abs(abs(a - in[rstart]) - abs(a - in[lstart])) < eps &&
				abs(abs(b - in[rstart]) - abs(b - in[lstart])) < eps)
			;
		else
		{
			return false;
		}
	}
	if (lstart != lend)
	{
		return false;
	}
	return true;
}

bool solve(int n, P *in)
{
	rep(i, n)
	{
		REP(j, 1, n - 1)
		{
			if (check(n, in[i], in[(i + j) % n], in,
								(i + n - 1) % n, (i + 1) % n,
								(i + j + 1) % n, (i + j + n - 1) % n))
			{
				return true;
			}
		}
	}
	return false;
}

int relax(int n, P *tmp, P *in)
{
	int p = 0;
	bool check[n];
	fill(check, check + n, true);
	rep(i, n)
	{
		if (isp(tmp[(i + n - 1) % n], tmp[(i + 1) % n], tmp[i]))
		{
			check[i] = false;
		}
	}
	rep(i, n) if (check[i])
	{
		in[p++] = tmp[i];
	}
	return p;
}

int put_mid_point(int n, P *tmp, P *in)
{
	int p = 0;
	rep(i, n)
	{
		in[p++] = tmp[i];
		in[p] = (tmp[i] + tmp[(i + 1) % n]);
		in[p++] /= 2;
	}
	return p;
}

int main()
{
	int T = 0;
	P tmp1[100], tmp2[100], in[300];
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		rep(i, n)
		{
			double re, im;
			scanf("%lf%lf", &re,&im);
			tmp1[i] = P(re,im);
		}
		int tmpp = relax(n, tmp1, tmp2);
		int p = put_mid_point(tmpp, tmp2, in);
		puts(solve(p, in) ? "Yes" : "No");
	}
	return 0;
}
