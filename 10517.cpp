#include <bits/stdc++.h>

using namespace std;

int main()
{
	int test, i = 1;
	double n, m, t;
	scanf("%d", &test);
	double angle, R = 6378.0, pi = 2 * acos(0), min, sec;
	while (i <= test)
	{
		scanf("%lf%lf", &n, &m);
		printf("Case %d: ", i++);
		if (n >= 1001.0)
		{
			printf("Invalid or impossible.\n");
			continue;
		}
		if ((m > -0.0000001 && m < 0.0000001) || (n > -0.0000001 && n < 0.0000001))
		{
			angle = pi / 2;
		}
		else
		{
			t = (m * cos(n / R) - n) / (m * sin(n / R));
			angle = atan(t);
		}
		double lim = 0.388888888888888888889 * pi;
		if (angle < 0.000001 || angle > lim)
		{
			printf("Invalid or impossible.\n");
		}
		else
		{
			angle *= (180 / pi);
			int dg = (int)angle;
			min = angle - (long)angle;
			min *= 60;
			int mn = (int)min;
			sec = min - (long)min;
			sec *= 60;
			int sc = (int)(sec + 0.5);// sec should be rounded
			printf("%d deg %d min %d sec\n", dg, mn, sc);
		}
	}
	return 0;
}
