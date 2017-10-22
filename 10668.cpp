#include <bits/stdc++.h>

using namespace std;

int main()
{
	double l, n, c, pt, th, tmp, r;
	while (scanf("%lf%lf%lf", &l, &n, &c) == 3)
	{
		if (l < 0.0 && n < 0.0 && c < 0.0)
		{
			break;
		}
		if (n * c == 0.0)
		{
			printf("0.000\n");
			continue;
		}
		n = l * (1 + n * c);
		c = n / l;
		for (pt = 3.141592653 / 8.0, th = 3.141592653 / 4.0; pt != 0; pt /= 2)
		{
			tmp = th / sin(th);
			if (tmp == c)
			{
				break;
			}
			th += (th / sin(th) > c) ? (-pt) : pt;
		}
		r = n / th / 2.0;
		printf("%.3lf\n", r * (1 - cos(th)));
	}
	return 0;
}
