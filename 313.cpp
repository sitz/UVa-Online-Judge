#include <bits/stdc++.h>

using namespace std;

struct Seg
{
	double a, b;
} s[500];
double cx, cy, r, bx, by;
int n;
void solve(double &x, double &y)
{
	double delta = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
	double k2 = r / sqrt(delta - r * r);
	double k1 = -(bx - cx) / (by - cy);
	y = (k1 + k2) / (1 - k1 * k2) * by + bx;
	x = (k1 - k2) / (1 + k1 * k2) * by + bx;
}
int compare(const void *a, const void *b)
{
	double t = ((Seg *)a)->a - ((Seg *)b)->a;
	if (t < 0)
	{
		return -1;
	}
	else if (t >= 0)
	{
		return 1;
	}
}
int main()
{
	while (scanf("%d", &n), n)
	{
		scanf("%lf %lf", &bx, &by);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf %lf", &cx, &cy, &r);
			solve(s[i].a, s[i].b);
		}
		qsort(s, n, sizeof(Seg), compare);
		double x1 = s[0].a, x2 = s[0].b;
		for (int i = 1; i < n; i++)
		{
			if (s[i].a <= x2)
			{
				if (s[i].b > x2)
				{
					x2 = s[i].b;
				}
			}
			else
			{
				printf("%.2lf %.2lf\n", x1, x2);
				x1 = s[i].a;
				x2 = s[i].b;
			}
		}
		printf("%.2lf %.2lf\n\n", x1, x2);
	}
	return 0;
}
