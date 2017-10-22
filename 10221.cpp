#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);

int main()
{
	double s, a;
	char info[10];
	while (scanf("%lf %lf %s", &s, &a, info) == 3)
	{
		if (strcmp(info, "min") == 0)
		{
			a /= 60;
		}
		s += 6440.0;
		if (a > 180)
		{
			a = 360 - a;
		}
		a = a * pi / 180.0;
		printf("%.6lf %.6lf\n", a * s, sqrt(2 * s * s * (1 - cos(a))));
	}
	return 0;
}
