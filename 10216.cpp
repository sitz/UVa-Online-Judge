#include <bits/stdc++.h>

using namespace std;

#define EPS std::numeric_limits<double>::epsilon()

int T;
double a, b, c;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%lf%lf%lf", &a, &b, &c);
		double s = 0.5 * (double)(a + b + c);
		double S = sqrt(s * (s - a) * (s - b) * (s - c));
		// fermat point
		double dm;
		// a - BC; b - AC; c - AB
		double gamma_A = acos((b * b + c * c - a * a) / (2.0 * b * c));
		double gamma_B = acos((a * a + c * c - b * b) / (2.0 * a * c));
		double gamma_C = acos((a * a + b * b - c * c) / (2.0 * a * b));
		if (gamma_A + EPS > M_PI * (2.0 / 3.0))
		{
			dm = b + c;
		}
		else if (gamma_B + EPS > M_PI * (2.0 / 3.0))
		{
			dm = a + c;
		}
		else if (gamma_C + EPS > M_PI * (2.0 / 3.0))
		{
			dm = a + b;
		}
		else
		{
			dm = sqrt(a * a + b * b - 2 * a * b * cos(M_PI / 3.0 + gamma_C));
		}
		double r = 2.0 * S / (a + b + c);
		double ah = (c + b - a) / 2.0;
		double ai = sqrt(ah * ah + r * r);
		double bh = (c + a - b) / 2.0;
		double bi = sqrt(bh * bh + r * r);
		double ch = (a + b - c) / 2.0;
		double ci = sqrt(ch * ch + r * r);
		double di = ai + bi + ci;
		double ma = sqrt((c * c) / 2 + (b * b) / 2 - (a * a) / 4);
		double mb = sqrt((a * a) / 2 + (c * c) / 2 - (b * b) / 4);
		double mc = sqrt((a * a) / 2 + (b * b) / 2 - (c * c) / 4);
		double dg = (2.0 / 3.0) * (ma + mb + mc);
		// circumcentre
		double d0 = 3.0 * ((a * b * c) / (double)(4.0 * S));
		if (std::isinf(d0))
		{
			d0 = -1.0;
		}
		if (a > b + c)
		{
			printf("-1.000 -1.000 -1.000 -1.000\n");
		}
		else
		{
			printf("%.3lf %.3lf %.3lf %.3lf\n", dm, di, dg, d0);
		}
	}
	return 0;
}
