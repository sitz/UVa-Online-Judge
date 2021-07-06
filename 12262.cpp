#include <bits/stdc++.h>

using namespace std;

const int N = 10001;
const double EPS = 1e-10;

double sum, a, b, v, f, x[N], y[N];
int n;

bool judge(double mid, double &tt)
{
	double v = mid;
	double ff = 0;
	tt = 0;
	for (int i = 1; i <= n; i++)
	{
		double c;
		if (y[i] >= 0)
		{
			c = a * v + b * y[i] / x[i];
			tt += hypot(x[i], y[i]) / v;
		}
		else
		{
			c = max(0.0, a * v + b * y[i] / x[i]);
			if (fabs(c) < EPS)
			{
				double vv = min(-b * y[i] / x[i] / a, ::v);
				tt += hypot(x[i], y[i]) / vv;
			}
			else
				tt += hypot(x[i], y[i]) / v;
		}
		ff += c * hypot(x[i], y[i]);
	}
	return ff <= f;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%lf%lf%lf%lf", &a, &b, &v, &f);
		sum = 0;
		scanf("%d", &n);
		assert(n > 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
			x[i] /= 1000;
			y[i] /= 1000;
			sum += hypot(x[i], y[i]);
		}

		double low = 0, high = v, mid, tt, ans;
		bool ok = false;
		while (high - low > EPS)
		{
			mid = (low + high) / 2;
			if (judge(mid, tt))
			{
				ans = tt;
				low = mid;
				ok = true;
			}
			else
				high = mid;
		}

		if (!ok)
			printf("IMPOSSIBLE\n");
		else
			printf("%.10lf\n", ans);
	}
	return 0;
}
