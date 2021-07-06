#include <bits/stdc++.h>

using namespace std;

struct point
{
	long double x, y;
};
struct point a, b;

int main()
{
	long double x1, x2, y1, y2, A, B, C, D, k, x, y, mx, my, dx, dy;
	while (scanf("%Lf%Lf%Lf%Lf", &x1, &y1, &x2, &y2) != EOF)
	{
		mx = (x1 + x2) / 2;
		my = (y1 + y2) / 2;
		dx = mx - x1;
		dy = my - y1;
		printf("%.10Lf %.10Lf %.10Lf %.10Lf\n", mx - dy, my + dx, mx + dy, my - dx);
	}
	return 0;
}
