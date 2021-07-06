#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10005;

double x[MAXN], y[MAXN], z[MAXN], distO[MAXN];
int n;

double geth(double r)
{
	double mxh = 0.0f;
	for (int i = 0; i < n; i++)
	{
		mxh = max(mxh, z[i] * r / (r - distO[i]));
	}
	return mxh;
}

double f(double r)
{
	return r * r * M_PI * geth(r) / 3;
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf%lf", &x[i], &y[i], &z[i]);
		}
		for (int i = 0; i < n; i++)
		{
			distO[i] = hypot(x[i], y[i]);
		}
		double l = 0.0f, r = 10000.0f, mid, midmid, md, mmd;
		for (int it = 0; it < 100; it++)
		{
			mid = (l + r) / 2;
			midmid = (mid + r) / 2;
			md = f(mid);
			mmd = f(midmid);
			if (md < mmd)
			{
				r = midmid;
			}
			else
			{
				l = mid;
			}
		}
		printf("%.3lf %.3lf\n", geth(mid), mid);
	}
	return 0;
}
