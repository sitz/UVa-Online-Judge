#include <bits/stdc++.h>

using namespace std;

double a[101], v[101], vs[101];
const double pi = 2 * acos(0), eps = 1e-10;
int r, n;
int main()
{
	int cases = 1, l;
	while (scanf("%d %d", &r, &n), r && n)
	{
		printf("Set %d:\n", cases++);
		l = (n - 1) / 2 + 1;
		printf("%d\n", l);
		double theta = pi / n, d = pi / 2 - fmod(pi / 2 - eps, theta);
		for (int i = 1; i <= l; i++, d -= theta)
		{
			double alpha = pi - 2 * d;
			a[i] = alpha - sin(alpha);
			a[i] *= n * r * r;
			v[i] = a[i] - a[i - 1] - vs[i - 1];
			vs[i] = v[i] + vs[i - 1];
			printf("%.4lf %.4lf\n", a[i], v[i]);
		}
	}
}
