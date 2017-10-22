#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a, b, c, s, r;
	while (scanf("%lf%lf%lf", &a, &b, &c) == 3)
	{
		s = (a + b + c) / 2.0;
		if (s != 0)
		{
			r = sqrt((s - a) * (s - b) * (s - c) / s);
		}
		else
		{
			r = 0;
		}
		printf("The radius of the round table is: %.3lf\n", r);
	}
	return 0;
}
