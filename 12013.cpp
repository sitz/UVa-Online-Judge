#include <bits/stdc++.h>

using namespace std;

double x, y;

int main()
{
	int test;
	scanf("%d", &test);
	for (int ii = 1; ii <= test; ii++)
	{
		scanf("%lf%lf", &x, &y);
		x /= 100.0;
		y /= 100.0;
		double tmp = 0;
		tmp += x * x * x * x;
		tmp += 4.0 * x * x * x * x * (1 - x);
		tmp += 10.0 * x * x * x * x * (1 - x) * (1 - x);
		double tx = x * x / (1.0 - 2.0 * x * (1 - x));
		tmp += 20.0 * tx * x * x * x * (1 - x) * (1 - x) * (1 - x);
		x = tmp;
		tmp = 0;
		tmp += y * y * y * y;
		tmp += 4.0 * y * y * y * y * (1 - y);
		tmp += 10.0 * y * y * y * y * (1 - y) * (1 - y);
		double ty = y * y / (1.0 - 2.0 * y * (1 - y));
		tmp += 20.0 * ty * y * y * y * (1 - y) * (1 - y) * (1 - y);
		y = tmp;
		tmp = 0;
		double c1, c2;
		tmp += x * x * x * y * y * y;
		tmp += 3.0 * x * x * x * (1 - x) * y * y * y;
		tmp += 3.0 * x * x * x * x * y * y * (1 - y);
		tmp += 6.0 * x * x * (1 - x) * (1 - x) * y * y * y * y;
		tmp += 3.0 * x * x * x * x * (1 - y) * (1 - y) * y * y;
		tmp += 12.0 * x * x * x * (1 - x) * y * y * y * (1 - y);
		tmp += 4.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * y;
		tmp += 4.0 * x * x * x * x * x * y * (1 - y) * (1 - y) * (1 - y);
		tmp += 24.0 * x * x * x * (1 - x) * (1 - x) * y * y * y * (1 - y);
		tmp += 24.0 * x * x * x * x * (1 - x) * y * y * (1 - y) * (1 - y);
		tmp += 5.0 * x * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * y;
		tmp += x * x * x * x * x * (1 - y) * (1 - y) * (1 - y) * (1 - y) * y;
		tmp += 20.0 * x * x * x * x * (1 - x) * y * (1 - y) * (1 - y) * (1 - y) * y;
		tmp += 60.0 * x * x * x * (1 - x) * (1 - x) * y * y * y * (1 - y) * (1 - y);
		tmp += 40.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * (1 - y);
		double tt;
		tt = (1 - x) * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * y;
		tt += x * x * x * x * x * (1 - y) * (1 - y) * (1 - y) * (1 - y) * (1 - y);
		tt += 25.0 * x * x * x * x * (1 - x) * y * (1 - y) * (1 - y) * (1 - y) * (1 - y);
		tt += 100.0 * x * x * x * (1 - x) * (1 - x) * y * y * (1 - y) * (1 - y) * (1 - y);
		tt += 100.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * (1 - y) * (1 - y);
		tt += 25.0 * x * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * (1 - y);
		double s = x * y / (1 - x * (1 - y) - y * (1 - x));
		tt *= s;
		c1 = tmp + tt;
		double z = y;
		y = x;
		x = z;
		tmp = 0;
		tmp += x * x * x * y * y * y;
		tmp += 3.0 * x * x * x * (1 - x) * y * y * y;
		tmp += 3.0 * x * x * x * x * y * y * (1 - y);
		tmp += 6.0 * x * x * (1 - x) * (1 - x) * y * y * y * y;
		tmp += 3.0 * x * x * x * x * (1 - y) * (1 - y) * y * y;
		tmp += 12.0 * x * x * x * (1 - x) * y * y * y * (1 - y);
		tmp += 4.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * y;
		tmp += 4.0 * x * x * x * x * x * y * (1 - y) * (1 - y) * (1 - y);
		tmp += 24.0 * x * x * x * (1 - x) * (1 - x) * y * y * y * (1 - y);
		tmp += 24.0 * x * x * x * x * (1 - x) * y * y * (1 - y) * (1 - y);
		tmp += 5.0 * x * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * y;
		tmp += x * x * x * x * x * (1 - y) * (1 - y) * (1 - y) * (1 - y) * y;
		tmp += 20.0 * x * x * x * x * (1 - x) * y * (1 - y) * (1 - y) * (1 - y) * y;
		tmp += 60.0 * x * x * x * (1 - x) * (1 - x) * y * y * y * (1 - y) * (1 - y);
		tmp += 40.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * (1 - y);
		tt = (1 - x) * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * y;
		tt += x * x * x * x * x * (1 - y) * (1 - y) * (1 - y) * (1 - y) * (1 - y);
		tt += 25.0 * x * x * x * x * (1 - x) * y * (1 - y) * (1 - y) * (1 - y) * (1 - y);
		tt += 100.0 * x * x * x * (1 - x) * (1 - x) * y * y * (1 - y) * (1 - y) * (1 - y);
		tt += 100.0 * x * x * (1 - x) * (1 - x) * (1 - x) * y * y * y * (1 - y) * (1 - y);
		tt += 25.0 * x * (1 - x) * (1 - x) * (1 - x) * (1 - x) * y * y * y * y * (1 - y);
		s = x * y / (1 - x * (1 - y) - y * (1 - x));
		tt *= s;
		c2 = tmp + tt;
		double ans = 0;
		ans += c1 * c2 * c1;
		ans += c1 * c1 * (1 - c2) * c2;
		ans += 2.0 * c1 * (1 - c1) * c2 * c2;
		ans += c1 * c1 * c1 * (1 - c2) * (1 - c2);
		ans += c1 * (1 - c1) * (1 - c1) * c2 * c2;
		ans += 4.0 * (1 - c1) * c1 * c1 * c2 * (1 - c2);
		ans *= 100.0;
		printf("Case #%d: %.4lf%%\n", ii, ans);
	}
	return 0;
}
