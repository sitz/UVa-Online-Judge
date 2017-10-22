#include <bits/stdc++.h>

using namespace std;

#define EPS 1E-4
int main()
{
	double x1, y1, r1, x2, y2, r2;
	double diff_x, diff_y, sum_r, diff_r, dis;
	double X1, Y1, X2, Y2;
	double a, b, c, p, q, r, t;
	double cos1, cos2, t1, t2;
	while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &r1, &x2, &y2, &r2) == 6)
	{
		if (fabs(x1 - x2) < EPS && fabs(y1 - y2) < EPS && fabs(r1 - r2) < EPS)
		{
			if (fabs(r1) < EPS && fabs(r2) < EPS)
			{
				printf("(%.3lf,%.3lf)\n", x1, y1);
			}
			else
			{
				printf("THE CIRCLES ARE THE SAME\n");
			}
		}
		else
		{
			diff_x = x1 - x2;
			diff_y = y1 - y2;
			sum_r = r1 + r2;
			diff_r = r1 - r2;
			dis = diff_x * diff_x + diff_y * diff_y;
			if (dis > sum_r * sum_r + EPS || dis + EPS < diff_r * diff_r)
			{
				printf("NO INTERSECTION\n");
			}
			else if (fabs(dis - sum_r * sum_r) < EPS)
			{
				printf("(%.3lf,%.3lf)\n",
							 x2 + diff_x * r2 / sum_r,
							 y2 + diff_y * r2 / sum_r);
			}
			else if (fabs(dis - diff_r * diff_r) < EPS)
			{
				printf("(%.3lf,%.3lf)\n",
							 x2 - diff_x * r2 / diff_r,
							 y2 - diff_y * r2 / diff_r);
			}
			else
			{
				if (fabs(x1 - x2) < EPS)
				{
					Y1 = ((y1 + y2) + (r2 * r2 - r1 * r1) / diff_y) / 2.0;
					Y2 = Y1;
					X1 = x1 - sqrt(r1 * r1 - (Y1 - y1) * (Y1 - y1));
					X2 = x1 + sqrt(r1 * r1 - (Y1 - y1) * (Y1 - y1));
				}
				else if (fabs(y1 - y2) < EPS)
				{
					X1 = ((x1 + x2) + (r2 * r2 - r1 * r1) / diff_x) / 2.0;
					X2 = X1;
					Y1 = y1 - sqrt(r1 * r1 - (X1 - x1) * (X1 - x1));
					Y2 = y1 + sqrt(r1 * r1 - (X1 - x1) * (X1 - x1));
				}
				else
				{
					a = 2.0 * r1 * diff_x;
					b = 2.0 * r1 * diff_y;
					c = r2 * r2 - r1 * r1 - (diff_x * diff_x + diff_y * diff_y);
					p = a * a + b * b;
					q = -2.0 * a * c;
					r = c * c - b * b;
					cos1 = (sqrt(q * q - 4 * p * r) - q) / (p * 2.0);
					cos2 = (-sqrt(q * q - 4 * p * r) - q) / (p * 2.0);
					X1 = x1 + r1 * cos1;
					X2 = x1 + r1 * cos2;
					t1 = y1 - sqrt(r1 * r1 - (X1 - x1) * (X1 - x1));
					t2 = y1 + sqrt(r1 * r1 - (X1 - x1) * (X1 - x1));
					Y1 = fabs((X1 - x2) * (X1 - x2) + (t1 - y2) * (t1 - y2) - r2 * r2) <
											 fabs((X1 - x2) * (X1 - x2) + (t2 - y2) * (t2 - y2) - r2 * r2)
									 ? t1
									 : t2;
					t1 = y1 - sqrt(r1 * r1 - (X2 - x1) * (X2 - x1));
					t2 = y1 + sqrt(r1 * r1 - (X2 - x1) * (X2 - x1));
					Y2 = fabs((X2 - x2) * (X2 - x2) + (t1 - y2) * (t1 - y2) - r2 * r2) <
											 fabs((X2 - x2) * (X2 - x2) + (t2 - y2) * (t2 - y2) - r2 * r2)
									 ? t1
									 : t2;
				}
				if (X1 > X2 + EPS)
				{
					t = X1;
					X1 = X2;
					X2 = t;
					t = Y1;
					Y1 = Y2;
					Y2 = t;
				}
				else if (fabs(X1 - X2) < EPS && Y1 > Y2 + EPS)
				{
					t = Y1;
					Y1 = Y2;
					Y2 = t;
				}
				if (fabs(X1 - 0) < 0.0001)
				{
					X1 = fabs(X1);
				}
				if (fabs(X2 - 0) < 0.0001)
				{
					X2 = fabs(X2);
				}
				if (fabs(Y1 - 0) < 0.0001)
				{
					Y1 = fabs(Y1);
				}
				if (fabs(Y2 - 0) < 0.0001)
				{
					Y2 = fabs(Y2);
				}
				printf("(%.3lf,%.3lf)(%.3lf,%.3lf)\n", X1, Y1, X2, Y2);
			}
		}
	}
	return 0;
}
