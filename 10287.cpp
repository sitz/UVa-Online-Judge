#include <bits/stdc++.h>

using namespace std;

int main()
{
	double r;
	while (scanf("%lf", &r) == 1)
	{
		double a, b, c, d;
		a = sqrt(3.0) / 2 * r;
		b = (2 * sqrt(3.0) - 3) * r;
		c = sqrt(3.0) / 4 * r;
		d = (3 * sqrt(28) - 7 * sqrt(3)) / 10 * r;
		printf("%.10lf %.10lf %.10lf %.10lf\n", a, b, c, d);
	}
	return 0;
}
