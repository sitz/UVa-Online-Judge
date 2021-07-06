#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES // expose const, e.g. M_PI
#define EPS std::numeric_limits<double>::epsilon()

struct my_compl
{
	double real, imag;
};
double a, b, n;
my_compl roots[101];
double fix(double v)
{
	if (v > 0)
	{
		return v;
	}
	if (v > -0.0005)
	{
		return 0.0;
	}
	return v;
}
double sqr(double arg)
{
	return arg * arg;
}
int sort_func(const void *a, const void *b)
{
	my_compl tmpa, tmpb;
	tmpa = *(my_compl *)a;
	tmpb = *(my_compl *)b;
	double tmp;
	if (fabs(tmpa.real - tmpb.real) < 1e-9)
	{
		tmp = (tmpb.imag - tmpa.imag);
	}
	else
	{
		tmp = (tmpb.real - tmpa.real);
	}
	if (fabs(tmp) < EPS)
	{
		return tmp;
	}
	else if (tmp < 0)
	{
		return (-1);
	}
	else
	{
		return 1;
	}
}
void outdata()
{
	int ansnum;
	ansnum = n;
	for (int i = 0; i < ansnum; i++)
	{
		if ((roots[i].real <= 0) && (roots[i].real > -0.0005))
		{
			roots[i].real = +0.0;
		}
		if ((roots[i].imag <= 0) && (roots[i].imag > -0.0005))
		{
			roots[i].imag = +0.0;
		}
		printf("%.3lf", fix(roots[i].real));
		if (roots[i].imag >= 0)
		{
			printf("+");
		}
		printf("%.3lfi\n", fix(roots[i].imag));
	}
}
int main()
{
	int curcase = 0;
	int in_a, in_b, in_n;
	while (scanf("%d%di %d", &in_a, &in_b, &in_n) == 3)
	{
		curcase++;
		a = in_a;
		b = in_b;
		n = in_n;
		double r, phi;
		r = sqrt(sqr(a) + sqr(b));
		if ((a == 0) && (b == 0))
		{
			phi = M_PI / 2;
		}
		else
		{
			phi = atan2(b, a);
		}
		double r_mod;
		r_mod = pow(r, 1 / n);
		printf("Case %d:\n", curcase);
		double cur_phi, new_a, new_b;
		for (int i = 0; i < in_n; i++)
		{
			cur_phi = (phi + 2 * M_PI * i) / n;
			new_a = r_mod * cos(cur_phi);
			new_b = r_mod * sin(cur_phi);
			roots[i].real = new_a;
			roots[i].imag = new_b;
		}
		qsort((void *)roots, in_n, sizeof(roots[0]), sort_func);
		outdata();
		printf("\n");
	}
	return 0;
}
