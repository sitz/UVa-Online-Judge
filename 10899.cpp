#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-8

typedef struct
{
	double x, y, dx, dy;
} Pt;
Pt S, Q;

double height, width, vel0, stop, decel;

double len(Pt A, Pt B)
{
	return hypot(A.x - B.x, A.y - B.y);
}

double fmin(double a, double b)
{
	return (a < b) ? a : b;
}

// shortest dist from segment AB to Q
double qdist(Pt A, Pt B)
{
	double a, b, q, t, r;
	double cos_a, cos_b;
	a = len(B, Q);
	b = len(A, Q);
	q = len(A, B);
	r = fmin(a, b);
	cos_a = (b * b + q * q - a * a) / (2. * b * q);
	cos_b = (a * a + q * q - b * b) / (2. * a * q);
	if (cos_a > -EPS && cos_b > -EPS)
	{
		t = b * sqrt(1. - cos_a * cos_a);
		r = fmin(r, t);
	}
	return r;
}

double posiroot(double a, double b, double c)
{
	double D, x1, x2;
	D = b * b - 4 * a * c;
	if (D < -EPS)
	{
		// fprintf(stderr, "posiroot: D=%.5lf\n", D);
		abort();
	}
	D = sqrt(D);
	if (D < EPS)
	{
		x1 = x2 = -b / (2. * a);
		if (x1 < -EPS)
		{
			// fprintf(stderr, "posiroot: D=0, x=%.5lf\n", x1);
			abort();
		}
		if (x1 < EPS)
		{
			x1 = 0.;
		}
		return x1;
	}
	else
	{
		x1 = (-b + D) / (2. * a);
		x2 = (-b - D) / (2. * a);
		if (fabs(x1) < EPS)
		{
			x1 = 0.;
		}
		if (fabs(x2) < EPS)
		{
			x2 = 0.;
		}
		if (x1 > -EPS && x2 > -EPS)
		{
			// fprintf(stderr, "posiroot: multi +ve roots %.5lf, %.5lf; choosing smaller\n", x1, x2);
		}
		if (x1 < 0 && x2 < EPS)
		{
			// fprintf(stderr, "posiroot: no +ve roots\n");
			abort();
		}
		return (x1 < x2) ? x1 : x2;
	}
}

double sim()
{
	Pt A, B;
	double tm, vel, shortest;
	double d, u, t, z;
	shortest = len(S, Q);
	A = S;
	tm = 0;
	vel = vel0;
	decel = vel0 / stop;
	while (vel > EPS)
	{
		// fprintf(stderr, "*** sim step: A=(%.5lf,%.5lf) v=(%.5lf,%.5lf) t=%.5lf |v|=%.5lf\n",
		// 				A.x, A.y, A.dx, A.dy, tm, vel);
		d = 1. / 0.;
		if (fabs(A.dx) > EPS)
		{
			u = -A.x / A.dx;
			if (u > EPS)
			{
				d = fmin(d, u);
			}
			u = (width - A.x) / A.dx;
			if (u > EPS)
			{
				d = fmin(d, u);
			}
		}
		if (fabs(A.dy) > EPS)
		{
			u = -A.y / A.dy;
			if (u > EPS)
			{
				d = fmin(d, u);
			}
			u = (height - A.y) / A.dy;
			if (u > EPS)
			{
				d = fmin(d, u);
			}
		}
		// fprintf(stderr, "dist before nxt collision = %.5lf\n", d);
		if (d > 1e50)
		{
			printf("mistake?\n");
			abort();
		}
		// fprintf(stderr, "decel=%.5lf vel=%.5lf\n", decel, vel);
		t = vel / decel;
		u = vel * t - decel * t * t / 2.;
		// fprintf(stderr, "can still go: %.5lf units\n", u);
		if (u < EPS)
		{
			break;
		}
		if (d > u)
		{
			d = u;
		}
		// fprintf(stderr, "to go: %.5lf\n", d);
		B.x = A.x + d * A.dx;
		B.y = A.y + d * A.dy;
		if ((B.x + 1 * A.dx) < -EPS || (B.x + 1 * A.dx) > (width + EPS))
		{
			B.dx = -A.dx;
		}
		else
		{
			B.dx = A.dx;
		}
		if ((B.y + 1 * A.dy) < -EPS || (B.y + 1 * A.dy) > (height + EPS))
		{
			B.dy = -A.dy;
		}
		else
		{
			B.dy = A.dy;
		}
		// fprintf(stderr, "new pos (w/o time): (%.5lf,%.5lf), new dir: (%.5lf,%.5lf)\n", B.x, B.y, B.dx, B.dy);
		// fprintf(stderr, "dist to Q = %.5lf\n", qdist(A, B));
		shortest = fmin(shortest, qdist(A, B));
		A = B;
		if (fabs(d - u) < EPS)
		{
			break;
		}
		z = posiroot(-decel / 2., vel, -d);
		// fprintf(stderr, "time consumed = %.5lf\n", z);
		tm += z;
		vel = vel0 - decel * tm;
	}
	return shortest;
}

int main()
{
	int i, j, z[8];
	double ang0, pi;
	pi = 2. * acos(0.);
	for (;;)
	{
		for (i = j = 0; i < 7 && scanf("%d", &z[i]) == 1; i++)
		{
			j |= z[i];
		}
		if (i < 7 || j == 0)
		{
			break;
		}
		width = z[0];
		height = z[1];
		vel0 = z[2];
		ang0 = z[3] * pi / 180.;
		stop = z[4];
		Q.x = z[5];
		Q.y = z[6];
		S.x = width / 2.;
		S.y = height / 2.;
		S.dx = cos(ang0);
		S.dy = sin(ang0);
		// fprintf(stderr, "width=%.0lf height=%.0lf S=(%.2lf,%.2lf) dS=(%.5lf,%.5lf) Q=(%.2lf,%.2lf)\n",
		// 				width, height, S.x, S.y, S.dx, S.dy, Q.x, Q.y);
		printf("%.2lf\n", sim());
	}
	return 0;
}
