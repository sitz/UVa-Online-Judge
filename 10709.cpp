#include <bits/stdc++.h>

using namespace std;

#define eps 0.00000001
int main()
{
	int is;
	double x1, y1, x2, y2, x3, y3, x4, y4, xp, yp;
	double v, d, d1, d2, d3, d4, a1, b1, c1, a2, b2, c2;
	char s1[5], s2[5];
	while (scanf("%lf%lf%lf%lf%s%lf%lf%lf%lf%s", &x1, &y1, &x2, &y2, s1, &x3, &y3, &x4, &y4, s2) == 10)
	{
		if (s1[0] == 'E')
		{
			break;
		}
		is = 1;
		a1 = y2 - y1, b1 = x2 - x1, c1 = x1 * y2 - x2 * y1;
		v = sqrt(a1 * a1 + b1 * b1);
		a1 /= v, b1 /= v, c1 /= v;
		a2 = y4 - y3, b2 = x4 - x3, c2 = x3 * y4 - x4 * y3;
		v = sqrt(a2 * a2 + b2 * b2);
		a2 /= v, b2 /= v, c2 /= v;
		d1 = a2 * x1 - b2 * y1 - c2;
		d2 = a2 * x2 - b2 * y2 - c2;
		d3 = a1 * x3 - b1 * y3 - c1;
		d4 = a1 * x4 - b1 * y4 - c1;
		/*printf("d1=%.2lf d2=%.2lf d3=%.2lf d4=%.2lf\n",d1,d2,d3,d4);*/
		if (s1[1])
		{
			if (s2[1])
			{
				if (d1 * d2 >= 0 || d3 * d4 >= 0)
				{
					d = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
					v = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
					if (v < d)
					{
						d = v;
					}
					v = (x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1);
					if (v < d)
					{
						d = v;
					}
					v = (x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2);
					if (v < d)
					{
						d = v;
					}
					xp = x1 - a2 * d1, yp = y1 + b2 * d1;
					if ((xp - x3) * (xp - x4) < 0 || (yp - y3) * (yp - y4) < 0)
					{
						v = (xp - x1) * (xp - x1) + (yp - y1) * (yp - y1);
						if (v < d)
						{
							d = v;
						}
					}
					xp = x2 - a2 * d2, yp = y2 + b2 * d2;
					if ((xp - x3) * (xp - x4) < 0 || (yp - y3) * (yp - y4) < 0)
					{
						v = (xp - x2) * (xp - x2) + (yp - y2) * (yp - y2);
						if (v < d)
						{
							d = v;
						}
					}
					xp = x3 - a1 * d3, yp = y3 + b1 * d3;
					if ((xp - x1) * (xp - x2) < 0 || (yp - y1) * (yp - y2) < 0)
					{
						v = (xp - x3) * (xp - x3) + (yp - y3) * (yp - y3);
						if (v < d)
						{
							d = v;
						}
					}
					xp = x4 - a1 * d4, yp = y4 + b1 * d4;
					if ((xp - x1) * (xp - x2) < 0 || (yp - y1) * (yp - y2) < 0)
					{
						v = (xp - x4) * (xp - x4) + (yp - y4) * (yp - y4);
						if (v < d)
						{
							d = v;
						}
					}
					d = sqrt(d);
				}
				else
				{
					d = 0.0;
				}
			}
			else
			{
				if (d1 * d2 <= 0)
				{
					d = 0.0;
				}
				else
				{
					d1 = fabs(d1), d2 = fabs(d2);
					if (d1 < d2)
					{
						d = d1;
					}
					else
					{
						d = d2;
					}
				}
			}
		}
		else
		{
			if (s2[1])
			{
				if (d3 * d4 <= 0)
				{
					d = 0.0;
				}
				else
				{
					d3 = fabs(d3), d4 = fabs(d4);
					if (d3 < d4)
					{
						d = d3;
					}
					else
					{
						d = d4;
					}
				}
			}
			else if (fabs(a1 * b2 - b1 * a2) < eps)
			{
				d = fabs(d1);
			}
			else
			{
				d = 0;
			}
		}
		printf("%.5lf\n", d);
	}
	return 0;
}
