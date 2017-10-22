#include <bits/stdc++.h>

using namespace std;

int main()
{
	int L, W, x, y, R, v, s, i, j, k, aa;
	double x1, x0, y0, y1, f, a, vy, vx;
	while (scanf("%d%d%d%d%d%d%d%d", &L, &W, &x, &y, &R, &aa, &v, &s), L)
	{
		a = aa * 2 * asin(1.0) / 180;
		x1 = v * cos(a) * s + x;
		y1 = v * sin(a) * s + y;
		while (1)
		{
			if (y1 > (W - R))
			{
				y1 = 2 * (W - R) - y1;
			}
			else if (y1 < R)
			{
				y1 = 2 * R - y1;
			}
			else
			{
				break;
			}
		}
		while (1)
		{
			if (x1 > (L - R))
			{
				x1 = 2 * (L - R) - x1;
			}
			else if (x1 < R)
			{
				x1 = 2 * R - x1;
			}
			else
			{
				break;
			}
		}
		printf("%.2f %.2f\n", x1, y1);
	}
}
