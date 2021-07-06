#include <bits/stdc++.h>

using namespace std;

int main()
{
	int y1, y2, t, exit, d;

	scanf("%d", &t);
	for (int n = 1; n <= t; ++n)
	{
		scanf("%d %d %d %d", &exit, &y2, &y1, &d);
		double exp = 0, scale = 5e2;
		int add = 0;

		if (y1 + d == y2)
		{
			double a = hypot(y1, exit), b = hypot(y1 + d, exit), s = (a + b + d) / 2;
			exp += (2 * s * s - a * a - b * b) / 2 / d;
			add = 1;
		}
		else
			for (double step = (y2 - y1 - d) / scale, i = y1 + step / 2; i + d <= y2; i += step)
			{
				double a = hypot(i, exit), b = hypot(i + d, exit), s = (a + b + d) / 2;
				exp += (2 * s * s - a * a - b * b) / 2 / d;
				++add;
			}
		printf("Case %d: %f\n", n, exp / add);
	}
}
