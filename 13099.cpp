#include <bits/stdc++.h>

using namespace std;

int main()
{
	double xl, yl, xr, yr;
	while (scanf("%lf%lf%lf%lf", &xl, &yl, &xr, &yr) == 4)
	{
		printf("%.6lf\n", ((xr - xl) * (xr - xl) + (yr - yl) * (yr - yl)) / 6);
	}
	return 0;
}
