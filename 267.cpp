#include <bits/stdc++.h>

using namespace std;

int main()
{
	double ws, wd, dc, ta;
	double wdd, dcd;
	double ah, gs;
	double angle;
	double b, c;
	double x, y;
	double pi = acos(-1);
	while (scanf("%lf %lf %lf %lf", &ws, &wd, &dc, &ta) == 4)
	{
		wdd = wd * pi / 180;
		dcd = dc * pi / 180;
		angle = pi - (wdd - dcd);
		b = -2 * ws * cos(angle);
		c = ws * ws - ta * ta;
		gs = (-b + sqrt(b * b - 4 * c)) / 2;
		x = ws * cos(wdd) + gs * cos(dcd);
		y = ws * sin(wdd) + gs * sin(dcd);
		ah = atan2(y, x);
		if (ah < 0)
		{
			ah = ah + pi * 2;
		}
		ah = ah * 180 / pi;
		printf("WIND SPEED %.2lf\nWIND DIRECTION %.2lf\n", ws, wd);
		printf("DESIRED COURSE %.2lf\nTRUE AIRSPEED %.2lf\n", dc, ta);
		printf("AIRCRAFT HEADING %.2lf\nGROUND SPEED %.2lf\n\n", ah, gs);
	}
	return 0;
}
