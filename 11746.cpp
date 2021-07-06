#include <bits/stdc++.h>

using namespace std;

#define eps 1e-6

double f_abs(double x)
{
	return x < 0 ? -x : x;
}
double x[3], y[3], p[3];
void get_data()
{
	int i;
	for (i = 0; i < 3; i++)
	{
		scanf("%lf%lf%lf", &x[i], &y[i], &p[i]);
	}
}
double a[3], b[3], c[3], d[3], e[3];
struct Res
{
	double x, y;
};
Res res[100];
int rn;
int cmp(const void *a, const void *b)
{
	Res *c = (Res *)a, *d = (Res *)b;
	if (f_abs(c->x - d->x) < eps)
	{
		return c->y > d->y ? 1 : -1;
	}
	else
	{
		return c->x > d->x ? 1 : -1;
	}
}
void insert(double rx, double ry)
{
	if (rx > -eps && rx <= 1000 + eps && ry > -eps && ry <= 1000 + eps)
	{
		res[rn].x = rx;
		res[rn++].y = ry;
	}
}
void solve(double ax, int w)
{
	double temp, t = c[w] * ax * ax + d[w] * ax + e[w];
	if (f_abs(a[w]) < eps)
	{
		if (f_abs(b[w]) > 0)
		{
			insert(ax, -t / b[w]);
		}
	}
	else
	{
		temp = b[w] * b[w] - 4 * a[w] * t;
		if (temp < -eps)
		{
			return;
		}
		temp = sqrt(temp);
		if (temp < eps)
		{
			insert(ax, -b[w] / (2 * a[w]));
		}
		else
		{
			insert(ax, (-b[w] + temp) / (2 * a[w]));
			insert(ax, (-b[w] - temp) / (2 * a[w]));
		}
	}
}
void solvex(int w)
{
	double temp;
	if (f_abs(c[w]) < eps)
	{
		if (f_abs(d[w]) > eps)
		{
			solve(-e[w] / d[w], w ^ 1);
		}
	}
	else
	{
		temp = d[w] * d[w] - 4 * c[w] * e[w];
		if (temp < -eps)
		{
			return;
		}
		temp = sqrt(temp);
		if (temp < eps)
		{
			solve(-d[w] / (2 * c[w]), w ^ 1);
		}
		else
		{
			solve((-d[w] + temp) / (2 * c[w]), w ^ 1);
			solve((-d[w] - temp) / (2 * c[w]), w ^ 1);
		}
	}
}
void run()
{
	a[0] = p[0] - p[1];
	c[0] = p[0] - p[1];
	b[0] = (-2 * y[0] * p[0]) + 2 * y[1] * p[1];
	d[0] = (-2 * x[0] * p[0]) + 2 * x[1] * p[1];
	e[0] = (y[0] * y[0] + x[0] * x[0]) * p[0] - (y[1] * y[1] + x[1] * x[1]) * p[1];
	a[1] = p[2] - p[1];
	c[1] = p[2] - p[1];
	b[1] = (-2 * y[2] * p[2]) + 2 * y[1] * p[1];
	d[1] = (-2 * x[2] * p[2]) + 2 * x[1] * p[1];
	e[1] = (y[2] * y[2] + x[2] * x[2]) * p[2] - (y[1] * y[1] + x[1] * x[1]) * p[1];
	//	printf("%f %f %f %f %f\n",a[0],b[0],c[0],d[0],e[0]);
	//	printf("%f %f %f %f %f\n",a[1],b[1],c[1],d[1],e[1]);
	rn = 0;
	double tx;
	if (f_abs(a[0]) < eps)
	{
		if (f_abs(b[0]) < eps)
		{
			if (f_abs(d[0]) > eps)
			{
				tx = -e[0] / d[0];
				solve(tx, 1);//x已知，求式1
			}
		}
		else
		{
			c[1] += d[0] * d[0] / (b[0] * b[0]) * a[1];
			d[1] += -b[1] * d[0] / b[0] + 2 * d[0] * e[0] * a[1] / (b[0] * b[0]);
			e[1] += e[0] * e[0] / (b[0] * b[0]) * a[1] - b[1] * e[0] / b[0];
			a[1] = b[1] = 0;
			solvex(1);//从1式求x的解
		}
	}
	else
	{
		double k = a[1] / a[0];
		a[1] = c[1] = 0;
		b[1] -= b[0] * k;
		d[1] -= d[0] * k;
		e[1] -= e[0] * k;
		if (f_abs(b[1]) < eps)
		{
			if (f_abs(d[1]) > eps)
			{
				tx = -e[1] / d[1];
				solve(tx, 0);
			}
		}
		else
		{
			c[0] += d[1] * d[1] / (b[1] * b[1]) * a[0];
			d[0] += -b[0] * d[1] / b[1] + 2 * d[1] * e[1] * a[0] / (b[1] * b[1]);
			e[0] += e[1] * e[1] / (b[1] * b[1]) * a[0] - b[0] * e[1] / b[1];
			a[0] = b[0] = 0;
			solvex(0);//从0式求x的解
		}
	}
	printf("%d", rn);
	qsort(res, rn, sizeof(Res), cmp);
	int i;
	for (i = 0; i < rn; i++)
	{
		printf(" %.2f %.2f", res[i].x, res[i].y);
	}
	printf("\n");
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		get_data();
		run();
	}
	return 0;
}
