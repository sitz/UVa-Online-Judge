#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

struct Point
{
	double x, y;
	double dist(const Point &a)
	{
		return hypot(a.x - x, a.y - y);
	}
} point[10000];

int main()
{
	int n;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &point[i].x, &point[i].y);
		}

		sort(point, point + n, [](const Point &a, const Point &b) -> bool
				 {
					 return a.x < b.x;
				 });

		double ans = 10000.0f;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				// dist > this pt + shortest dist; two pts cannot be < curr shortest dist
				if (point[i].x + ans < point[j].x)
				{
					break;
				}
				double d = point[i].dist(point[j]);
				ans = min(ans, d);
			}
		}

		if (fabs(ans - 10000.0f) < EPS)
		{
			printf("INFINITY\n");
		}
		else
		{
			printf("%.4lf\n", ans);
		}
	}
	return 0;
}
