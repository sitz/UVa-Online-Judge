#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a, area1, area2;
	while (scanf("%lf", &a) == 1)
	{
		area1 = (M_PI / 3.0 - sqrt(3) + 1.0) * a * a;
		area2 = (M_PI / 3.0 + 2.0 * sqrt(3) - 4.0) * a * a;
		printf("%.3lf %.3lf %.3lf\n", area1, area2, a * a - area1 - area2);
	}
	return 0;
}
