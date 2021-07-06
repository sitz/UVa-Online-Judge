#include <bits/stdc++.h>

using namespace std;

const int maxint = -1u >> 1;

template <class T>
bool get_max(T &a, const T &b)
{
	return b > a ? a = b, 1 : 0;
}
template <class T>
bool get_min(T &a, const T &b)
{
	return b < a ? a = b, 1 : 0;
}

const int maxn = 15;
int n;
double a[maxn];

double calc(double s)
{
	double ret = a[0];
	double fac = 1.0 + s;
	double m = 1.0;
	for (int i = 1; i <= n; i++)
	{
		m *= fac;
		ret += a[i] / m;
	}
	return ret;
}

int main()
{
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i <= n; i++)
		{
			scanf("%lf", a + i);
		}
		double l = -1.0, r = 10000.0, mid;
		int cnt = 0;
		while (++cnt < 100)
		{
			mid = (l + r) * 0.5;
			double val = calc(mid);
			if (val < 0)
			{
				r = mid;
			}
			else
			{
				l = mid;
			}
		}
		printf("%.2lf\n", mid);
	}
	return 0;
}
