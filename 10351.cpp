#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t = 1, x, y, z, xx, yy, zz;
	while (scanf("%d%d%d%d%d%d", &x, &y, &z, &xx, &yy, &zz) == 6)
	{
		double a, b, c, diff = 0.0f;
		if (x < xx)
		{
			a = y;
			b = z;
			c = xx;
			diff = xx - (xx * 2 - x * 2);
		}
		else if (y < yy)
		{
			a = x;
			b = z;
			c = yy;
			diff = yy - (yy * 2 - y * 2);
		}
		else if (z < zz)
		{
			a = x;
			b = y;
			c = zz;
			diff = zz - (zz * 2 - z * 2);
		}
		else
		{
			printf("Set #%d\n", t++);
			printf("%.06lf\n", 0.0f);
			continue;
		}
		double a1 = sqrt(a * a * (1 - (diff * diff) / (c * c)));
		double b1 = sqrt(b * b * (1 - (diff * diff) / (c * c)));
		printf("Set #%d\n", t++);
		printf("%.06lf\n", M_PI / 4 * a1 * b1);
	}
	return 0;
}
