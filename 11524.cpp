#include <bits/stdc++.h>

using namespace std;

/*
 *  Algorithm:
 *      Math Problem.
 * */

int main()
{
	int n;
	double n1, m1, n2, m2, n3, m3;
	double a, b, c;
	double k;
	double o;
	double r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf", &r, &m1, &n1, &m2, &n2, &m3, &n3);
		a = 1 + n1 / m1;
		b = n1 / m1 + n1 * n2 / m1 / m2;
		c = 1 + n1 * n2 / m1 / m2;
		o = acos((a * a + b * b - c * c) / (2.0 * a * b));
		k = r * m1 / n1 / tan(o / 2);
		double ans = a * b * sin(o) * k * k / 2 + 1e-10;
		printf("%.4lf\n", ans);
	}
	return 0;
}
