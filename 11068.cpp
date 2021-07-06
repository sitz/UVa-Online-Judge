#include <bits/stdc++.h>

using namespace std;

int main()
{
	double x, y, x1, x2, y1, y2, c1, c2, k, r, u;
	while (1)
	{
		u = 0;
		scanf("%lf %lf %lf", &x1, &y1, &c1);
		scanf("%lf %lf %lf", &x2, &y2, &c2);
		if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0 && c1 == 0 && c2 == 0)
		{
			break;
		}
		else if (x1 == x2 && y1 == y2)
		{
			printf("No fixed point exists.\n");
		}
		else
		{
			if (x1 == x2 && y1 != y2)
			{
				if (y1 > y2)
				{
					r = x1;
					k = y1 - y2;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						y = (c1 - c2) / k;
					}
					if (r != 0)
					{
						x = (c1 - (y1 * y)) / r;
					}
				}
				else
				{
					r = x2;
					k = y2 - y1;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						y = (c2 - c1) / k;
					}
					if (r != 0)
					{
						x = (c2 - (y2 * y)) / r;
					}
				}
			}
			else if (x1 != x2 && y1 == y2)
			{
				if (x1 > x2)
				{
					r = y1;
					k = x1 - x2;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						x = (c1 - c2) / k;
					}
					if (r != 0)
					{
						y = (c1 - (x1 * x)) / r;
					}
				}
				else
				{
					r = y2;
					k = x2 - x1;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						x = (c2 - c1) / k;
					}
					if (r != 0)
					{
						y = (c2 - (x2 * x)) / r;
					}
				}
			}
			else
			{
				double a1, a2, b1, b2;
				a1 = y1;
				a2 = y2;
				b1 = c1;
				b2 = c2;
				y1 = x2 * y1;
				c1 = x2 * c1;
				y2 = x1 * y2;
				c2 = x1 * c2;
				if (y1 > y2)
				{
					k = y1 - y2;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						y = (c1 - c2) / k;
					}
				}
				else
				{
					k = y2 - y1;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						y = (c2 - c1) / k;
					}
				}
				y1 = a1;
				y2 = a2;
				c1 = b1;
				c2 = b2;
				x1 = x1 * y2;
				c1 = c1 * y2;
				x2 = y1 * x2;
				c2 = y1 * c2;
				if (x1 > x2)
				{
					k = x1 - x2;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						x = (c1 - c2) / k;
					}
				}
				else
				{
					k = x2 - x1;
					if (k == 0)
					{
						u = 1;
					}
					if (u == 0)
					{
						x = (c2 - c1) / k;
					}
				}
			}
			if (u == 0 && r != 0)
			{
				printf("The fixed point is at %.2lf %.2lf.\n", x, y);
			}
			else
			{
				printf("No fixed point exists.\n");
			}
		}
	}
	return 0;
}
