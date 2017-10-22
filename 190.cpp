#include <bits/stdc++.h>

using namespace std;

double g, f, c, A, B, C, R, E, F, G, K, M;
double x1, y1_, x2, y2, x3, y3;

void CENTER()
{
	A = 2 * (x1 - x2);
	B = 2 * (y1_ - y2);
	C = (x2 * x2) + (y2 * y2) - (x1 * x1) - (y1_ * y1_);
	E = 2 * (x2 - x3);
	F = 2 * (y2 - y3);
	G = (x3 * x3) + (y3 * y3) - (x2 * x2) - (y2 * y2);
	g = (C * F - G * B) / (A * F - E * B);
	f = (C * E - G * A) / (B * E - F * A);
	c = -(x2 * x2 + y2 * y2 + 2 * g * x2 + 2 * f * y2);
	K = 2 * g;
	M = 2 * f;
}

void RADIUS()
{
	char p, q, r, s;
	R = sqrt(((x1 - (-g)) * (x1 - (-g))) + ((y1_ - (-f)) * (y1_ - (-f))));
	if (g < 0)
	{
		p = '-';
	}
	else
	{
		p = '+';
	}
	if (f < 0)
	{
		q = '-';
	}
	else
	{
		q = '+';
	}
	g = fabs(g);
	f = fabs(f);
	printf("(x %c %.3lf)^2 + (y %c %.3lf)^2 = %.3lf^2\n", p, g, q, f, R);
	if (c < 0)
	{
		p = '-';
	}
	else
	{
		p = '+';
	}
	c = fabs(c);
	if (K < 0)
	{
		r = '-';
	}
	else
	{
		r = '+';
	}
	K = fabs(K);
	if (M < 0)
	{
		s = '-';
	}
	else
	{
		s = '+';
	}
	M = fabs(M);
	printf("x^2 + y^2 %c %.3lfx %c %.3lfy %c %.3lf = 0\n", r, K, s, M, p, c);
}

int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf", &x1, &y1_, &x2, &y2, &x3, &y3) == 6)
	{
		CENTER();
		RADIUS();
		printf("\n");
	}
	return 0;
}
