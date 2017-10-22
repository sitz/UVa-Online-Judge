#include <bits/stdc++.h>

using namespace std;

struct Point
{
	double x, y;
} p[100], temp[100];
double dist(Point &a, Point &b)
{
	double dx = a.x - b.x, dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}
double d, cutarea, costheta, sintheta;
int n;
int main()
{
	while (scanf("%lf %d", &d, &n) == 2)
	{
		if (d == 0 && n == 0)
		{
			break;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		p[n] = p[0];
		cutarea = 0;
		for (int i = 0; i < n; i++)
		{
			double r = dist(p[i + 1], p[i]);
			costheta = (p[i + 1].x - p[i].x) / r;
			sintheta = (p[i].y - p[i + 1].y) / r;
			for (int j = 0; j < n; j++)
			{
				if (j == i)
				{
					continue;
				}
				double tx, ty;
				tx = (p[j].x - p[i].x) * costheta -
						 (p[j].y - p[i].y) * sintheta + p[i].x;
				ty = (p[j].x - p[i].x) * sintheta +
						 (p[j].y - p[i].y) * costheta + p[i].y;
				p[j].x = tx;
				p[j].y = ty;
			}
			p[n] = p[0];
			if (p[(i + 2) % n].y > 0)
			{
				double tx, ty, dx, dy;
				tx = p[(i + n - 1) % n].x - p[i].x;
				ty = p[(i + n - 1) % n].y - p[i].y;
				dy = d / ty;
				dx = dy * tx;
				p[i].x -= dx;
				p[i].y += d;
				tx = p[(i + 2) % n].x - p[(i + 1) % n].x;
				ty = p[(i + 2) % n].y - p[(i + 1) % n].y;
				dy = d / ty;
				dx = dy * tx;
				p[(i + 1) % n].x -= dx;
				p[(i + 1) % n].y += d;
			}
			else
			{
				double tx, ty, dx, dy;
				tx = p[(i + n - 1) % n].x - p[i].x;
				ty = p[(i + n - 1) % n].y - p[i].y;
				dy = d / ty;
				dx = dy * tx;
				p[i].x -= dx;
				p[i].y -= d;
				tx = p[(i + 2) % n].x - p[(i + 1) % n].x;
				ty = p[(i + 2) % n].y - p[(i + 1) % n].y;
				dy = d / ty;
				dx = dy * tx;
				p[(i + 1) % n].x -= dx;
				p[(i + 1) % n].y -= d;
			}
		}
		p[n] = p[0];
		for (int i = 0; i < n; i++)
		{
			cutarea += p[i].x * p[i + 1].y - p[i].y * p[i + 1].x;
		}
		printf("%.3lf\n", fabs(cutarea * 0.5));
	}
	return 0;
}
