#include <bits/stdc++.h>

using namespace std;

double r1, P, r2, area, pi = 2 * acos(0);
double f(double r2)
{
	double theta1 = acos((r2 * r2) / (2 * r1 * r2)),
				 theta2 = acos(((2 * r1 * r1) - (r2 * r2)) / (2 * r1 * r1));
	double t = r2 * r2 * theta1;
	t += r1 * r1 * theta2;
	t -= r1 * r1 * sin(theta2);
	return t - area;
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		if (i)
		{
			puts("");
		}
		scanf("%lf %lf", &r1, &P);
		double left = 0, right = 2 * r1, mid = (left + right) / 2;
		area = pi * r1 * r1 * P;
		while (true)
		{
			double t = f(mid);
			if (fabs(t) < 1e-6)
			{
				r2 = mid;
				break;
			}
			else if (t > 0)
			{
				right = mid;
			}
			else
			{
				left = mid;
			}
			mid = (left + right) / 2;
		}
		printf("R = %.lf, P = %.2lf, Rope = %.2lf\n", r1, P, r2);
	}
	return 0;
}
