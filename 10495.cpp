#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES
int main()
{
	double r, h, d1, A1, d2, A2;
	double x1, x2, y1, y2;
	double l, A, Ap;
	while (scanf("%lf%lf%lf%lf%lf%lf", &r, &h, &d1, &A1, &d2, &A2) == 6)
	{
		l = sqrt(r * r + h * h);
		assert(d1 >= 0 && d1 <= l && 0 <= A1 && A1 < 360);
		assert(d2 >= 0 && d1 <= l && 0 <= A2 && A2 < 360);
		A = r / l * 2 * M_PI;
		Ap = fabs(A1 - A2) / 360 * A;
		if (Ap > A - Ap)
		{
			Ap = A - Ap;
		}
		x1 = d1;
		y1 = 0;
		x2 = d2 * cos(Ap);
		y2 = d2 * sin(Ap);
		printf("%.2f\n", sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
	}
	return 0;
}
