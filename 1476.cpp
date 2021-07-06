#include <bits/stdc++.h>

using namespace std;

#define Mod (1000000007LL)
#define eps (1e-6)
#define inf (-10000000000.0)

double a[10010], b[10010], c[10010];
double x1, x2, m1, m2;
double y, y2;
int n;
inline double Abs(double x)
{
	return max(x, -x);
}
inline double f(double x)
{
	double tmp = inf;
	for (int i = 1; i <= n; i++)
		tmp = max(tmp, x * x * a[i] + b[i] * x + c[i]);
	return tmp;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		x1 = 0;
		x2 = 1000;
		for (int i = 1; i <= n; i++)
			scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
		y = 0;
		y2 = f(1000.0);
		while (Abs(y - y2) > eps)
		{
			//printf("%.2lf %.2lf\n",x1,x2);
			m1 = x1 + (x2 - x1) / 3.0;
			m2 = x2 - (x2 - x1) / 3.0;
			y = f(m1);
			y2 = f(m2);
			if (y < y2)
				x2 = m2;
			else
				x1 = m1;
		}
		printf("%.4lf\n", y);
	}
	return 0;
}
