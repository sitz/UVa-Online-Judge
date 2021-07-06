#include <bits/stdc++.h>

using namespace std;

main()
{
	int n, i;
	double x1, y1, x2, y2, x3, y3, cx1, cy1, m1, b1, cx2, cy2, m2, b2, r1, rx, ry;
	scanf("%d\n", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
		if ((x1 == x2 && y1 == y2) || (x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3))
		{
			printf("There is an infinity of possible locations.\n");
		}
		else
		{
			cx1 = (x1 + x2) / 2.0;
			cy1 = (y1 + y2) / 2.0;
			if (y1 == y2)
			{
				m1 = 1e30;
				b1 = cx1;
			}
			else
			{
				m1 = -(x2 - x1) / (y2 - y1);
				b1 = cy1 - m1 * cx1;
			}
			cx2 = (x1 + x3) / 2.0;
			cy2 = (y1 + y3) / 2.0;
			if (y1 == y3)
			{
				m2 = 1e30;
				b2 = cx2;
			}
			else
			{
				m2 = -(x3 - x1) / (y3 - y1);
				b2 = cy2 - m2 * cx2;
			}
			if (m1 == m2 || (m1 != 0.0 && m2 != 0.0 && m1 / m2 >= 1 - 1e-14 && m1 / m2 <= 1 + 1e-14))
			{
				printf("There is no possible location.\n");
			}
			else
			{
				if (m1 == 1e30)
				{
					rx = b1;
					ry = m2 * rx + b2;
				}
				else if (m2 == 1e30)
				{
					rx = b2;
					ry = m1 * rx + b1;
				}
				else
				{
					rx = (b1 - b2) / (m2 - m1);
					ry = (b1 * m2 - b2 * m1) / (m2 - m1);
				}
				if (rx > 0)
				{
					rx += 1e-8;
				}
				if (rx < 0)
				{
					rx -= 1e-8;
				}
				if (ry > 0)
				{
					ry += 1e-8;
				}
				if (ry < 0)
				{
					ry -= 1e-8;
				}
				if (rx < 0.0 && rx > -0.05)
				{
					rx = 0.0;
				}
				if (ry < 0.0 && ry > -0.05)
				{
					ry = 0.0;
				}
				printf("The equidistant location is (%.1lf, %.1lf).\n", rx, ry);
			}
		}
	}
}
