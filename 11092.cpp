#include <bits/stdc++.h>

using namespace std;

int main()
{
	double sq3 = sqrt(3.0) / 2.0, ax, ay, bx, by, d1, d2;
	double NX[6] = {0.5, -0.5, -1.0, -0.5, 0.5, 1.0}, NY[6] = {sq3, sq3, 0.0, -sq3, -sq3, 0.0};
	double UX[6] = {0.5, 1.0, 0.5, -0.5, -1.0, -0.5}, UY[6] = {-sq3, 0.0, sq3, sq3, 0.0, -sq3};
	int a, b, ra, rb, ta, tb, ma, mb;
	while (scanf("%d%d", &a, &b) == 2)
	{
		if (a)
		{
			ra = (int)(sqrt(a / 6.0) + 0.00001);
			while (3 * (ra + 1) * ra < a)
			{
				ra++;
			}
			if (a == 3 * ra * (ra + 1))
			{
				ma = 0;
			}
			else
			{
				ma = a - 3 * (ra - 1) * ra;
			}
			ax = ra * UX[ma / ra] + (ma % ra) * NX[ma / ra];
			ay = ra * UY[ma / ra] + (ma % ra) * NY[ma / ra];
		}
		else
		{
			ax = ay = 0.0;
		}
		if (b)
		{
			rb = (int)(sqrt(b / 6.0) + 0.00001);
			while (3 * (rb + 1) * rb < b)
			{
				rb++;
			}
			if (b == 3 * rb * (rb + 1))
			{
				mb = 0;
			}
			else
			{
				mb = b - 3 * (rb - 1) * rb;
			}
			bx = rb * UX[mb / rb] + (mb % rb) * NX[mb / rb];
			by = rb * UY[mb / rb] + (mb % rb) * NY[mb / rb];
		}
		else
		{
			bx = by = 0.0;
		}
		d1 = (double)abs(a - b) + 0.00000000001;
		d2 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
		d2 = sqrt(d2) + 0.00000000001;
		printf("%.3lf %.3lf\n", d1, d2);
	}
	return 0;
}
