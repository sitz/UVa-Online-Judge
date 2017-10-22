#include <bits/stdc++.h>

using namespace std;

double x[4], y[4], r[4];
double A1, B1, C1, D1;
double A2, B2, C2, D2;

const double ZERO = 1e-6;

bool input()
{
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf", &x[1], &y[1], &r[1], &x[2], &y[2], &r[2], &x[3], &y[3], &r[3]);
	if (r[1] == 0 || r[2] == 0 || r[3] == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

double getY(double x)
{
	double result;
	result = (A2 * B1 - A1 * B2) * x + A2 * C1 - A1 * C2;
	result /= (A1 * D2 - A2 * D1);
	return result;
}

int main()
{
	while (input())
	{
		A1 = r[1] * r[1] - r[2] * r[2];
		B1 = 2 * x[1] * r[2] * r[2] - 2 * x[2] * r[1] * r[1];
		C1 = r[1] * r[1] * x[2] * x[2] - r[2] * r[2] * x[1] * x[1] + r[1] * r[1] * y[2] * y[2] - r[2] * r[2] * y[1] * y[1];
		D1 = 2 * y[1] * r[2] * r[2] - 2 * y[2] * r[1] * r[1];
		A2 = r[2] * r[2] - r[3] * r[3];
		B2 = 2 * x[2] * r[3] * r[3] - 2 * x[3] * r[2] * r[2];
		C2 = r[2] * r[2] * x[3] * x[3] - r[3] * r[3] * x[2] * x[2] + r[2] * r[2] * y[3] * y[3] - r[3] * r[3] * y[2] * y[2];
		D2 = 2 * y[2] * r[3] * r[3] - 2 * y[3] * r[2] * r[2];
		double xx1, yy1, xx2, yy2;
		if (r[1] == r[2] && r[2] == r[3])
		{
			double a1, a2, b1, b2, c1, c2;
			a1 = 2 * (x[2] - x[1]);
			a2 = 2 * (x[3] - x[2]);
			b1 = 2 * (y[2] - y[1]);
			b2 = 2 * (y[3] - y[2]);
			c1 = x[1] * x[1] + y[1] * y[1] - x[2] * x[2] - y[2] * y[2];
			c2 = x[2] * x[2] + y[2] * y[2] - x[3] * x[3] - y[3] * y[3];
			double x, y;
			y = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
			if (fabs(a1) < ZERO)
			{
				x = (-b2 * y - c2) / a2;
			}
			else
			{
				x = (-b1 * y - c1) / a1;
			}
			printf("%.2lf %.2lf\n", x, y);
			continue;
		}
		double m, n;
		m = (A2 * B1 - A1 * B2) / (A1 * D2 - A2 * D1);
		n = (A2 * C1 - A1 * C2) / (A1 * D2 - A2 * D1);
		/*
		        printf( "A2*C1-A1*C2 = %.2lf\n",A2*C1-A1*C2 );
		        printf( "m = %.2lf n = %.2lf\n",m,n );
		        printf( "A1=%.2lf B1=%.2lf C1=%.2lf D1=%.2lf\n",A1,B1,C1,D1 );
		        printf( "A2=%.2lf B2=%.2lf C2=%.2lf D2=%.2lf\n",A2,B2,C2,D2 );
		*/
		double a, b, c;
		if (r[1] == r[2])
		{
			a = A2 + A2 * m * m;
			b = B2 + 2 * A2 * m * n + D2 * m;
			c = A2 * n * n + D2 * n + C2;
		}
		//      else if ( r[2] == r[3] )
		//      {
		//
		//      }
		else
		{
			a = A1 + A1 * m * m;
			b = B1 + 2 * A1 * m * n + D1 * m;
			c = A1 * n * n + D1 * n + C1;
		}
		//      printf( "a = %.2lf b = %.2lf c = %.3lf\n",a,b,c );
		double delta = b * b - 4 * a * c;
		if (delta < 0)
		{
			printf("No solution\n");
			continue;
		}
		else
		{
			delta = sqrt(delta);
		}
		xx1 = (-b + delta) / (2 * a);
		yy1 = m * xx1 + n;
		xx2 = (-b - delta) / (2 * a);
		yy2 = m * xx2 + n;
		double ang1 = r[2] / (sqrt((x[2] - xx1) * (x[2] - xx1) + (y[2] - yy1) * (y[2] - yy1)));
		double ang2 = r[2] / (sqrt((x[2] - xx2) * (x[2] - xx2) + (y[2] - yy2) * (y[2] - yy2)));
		if (ang1 >= ang2)
		{
			printf("%.2lf %.2lf\n", xx1, yy1);
		}
		else
		{
			printf("%.2lf %.2lf\n", xx2, yy2);
		}
	}
	return 0;
}
