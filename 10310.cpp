#include <bits/stdc++.h>

using namespace std;

double distance(double x1, double x2, double y1, double y2)
{
	double dis;
	dis = (x1 - x2) * (x1 - x2);
	dis += (y1 - y2) * (y1 - y2);
	return dis;
}

int main()
{
	int t;
	double gx, gy, dx, dy, rx, ry;
	double hx, hy, disg, disd;
	bool escape;
	while (scanf("%d", &t) == 1)
	{
		escape = false;
		scanf("%lf %lf %lf %lf", &gx, &gy, &dx, &dy);
		while (t--)
		{
			scanf("%lf %lf", &hx, &hy);
			if (escape)
			{
				continue;
			}
			disg = distance(gx, hx, gy, hy);
			disd = distance(dx, hx, dy, hy);
			disd /= 4;
			if (disg <= disd)
			{
				rx = hx;
				ry = hy;
				escape = true;
			}
		}
		if (escape)
		{
			printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", rx, ry);
		}
		else
		{
			printf("The gopher cannot escape.\n");
		}
	}
	return 0;
}
