#include <bits/stdc++.h>

using namespace std;

int main()
{
	double r, c, d, x, y;
	while (scanf("%lf%lf", &r, &d) == 2)
	{
		if (r == 0 && d == 0)
		{
			break;
		}
		if (d == 0)
		{
			printf("%.6lf\n", r / sqrt(2));
			continue;
		}
		r /= 2;
		y = -d / sqrt(2.0);
		if (r + y <= 0)
		{
			printf("INCORRECT INFORMATION !!!\n");
			continue;
		}
		x = sqrt(r * r - y * y);
		x += y;
		printf("%.6lf\n", (r * r - x * x) / d + 0.0000000001);
	}
	return 0;
}
