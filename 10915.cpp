#include <bits/stdc++.h>

using namespace std;

double x[200], y[200], z[200], xx[200], yy[200], zz[200];
double dist(double x, double y, double z)
{
	return x * x + y * y + z * z;
}

int main()
{
	int i, j, k, m, ret;
	while (1)
	{
		scanf("%d %d ", &k, &m);
		if (!k && !m)
		{
			break;
		}
		for (i = 0; i < k; i++)
		{
			scanf("%lf %lf %lf ", &x[i], &y[i], &z[i]);
		}
		for (j = 0; j < m; j++)
		{
			scanf("%lf %lf %lf ", &xx[j], &yy[j], &zz[j]);
		}
		ret = 0;
		for (j = 0; j < m; j++)
		{
			double d3 = dist(xx[j], yy[j], zz[j]);
			for (i = 0; i < k; i++)
			{
				double d1 = dist(x[i], y[i], z[i]);
				double d2 = dist(x[i] - xx[j], y[i] - yy[j], z[i] - zz[j]);
				if (d2 + d3 <= d1)
				{
					ret++;
					break;
				}
			}
		}
		printf("%d\n", ret);
	}
}
