#include <bits/stdc++.h>

using namespace std;

#define INF 0x7f7f7f7f
const double eps = 1e-11;

struct point
{
	double x, y;
};

double X;
int n;

int dep(double num)
{
	if (fabs(num) < eps)
	{
		return 0;
	}
	else
	{
		return num > 0 ? 1 : -1;
	}
}

double xmul(point p1, point p2, point p3)
{
	return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

bool judge(point A, point B, point C, point D)
{
	double s1, s2;
	int d1, d2;
	s1 = xmul(A, B, C);
	s2 = xmul(A, B, D);
	d1 = dep(s1);
	d2 = dep(s2);
	if (d1 * d2 < 0)
	{
		X = (C.x * s2 - D.x * s1) / (s2 - s1);
		return true;
	}
	if (d1 * d2 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	while (~scanf("%d", &n) && n)
	{
		vector<point> up(n);
		vector<point> down(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &up[i].x, &up[i].y);
			down[i].x = up[i].x;
			down[i].y = up[i].y - 1;
		}
		double Y = -INF;
		X = -INF;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int k = 0;
				while (k < n)
				{
					if (!judge(up[i], down[j], up[k], down[k]))
					{
						break;
					}
					k++;
				}
				if (k == n)
				{
					Y = up[n - 1].x;
				}
				else if (k > max(i, j))
				{
					judge(up[i], down[j], up[k - 1], up[k]);
					if (X > Y)
					{
						Y = X;
					}
					judge(up[i], down[j], down[k - 1], down[k]);
					if (X > Y)
					{
						Y = X;
					}
				}
			}
		}
		if (Y == up[n - 1].x)
		{
			printf("Through all the pipe.\n");
		}
		else
		{
			printf("%.2lf\n", Y);
		}
	}
	return 0;
}
