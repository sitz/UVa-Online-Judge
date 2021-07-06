#include <bits/stdc++.h>

using namespace std;

#define _USE_MATH_DEFINES
#define N 1000
double x[100], y[100], xx, yy, base, scale;
int rep, n, i, j, k, T;

int main()
{
	double minx, maxx, miny, maxy, dx, dy, dd, best;
	int besti;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%lf%lf", &x[i], &y[i]);
		}
		best = 1000;
		base = 0;
		scale = 1;
		for (rep = 0; rep < 10; rep++)
		{
			besti = 0;
			for (i = 0; i < N; i++)
			{
				double sininc = sin(base + scale * i * M_PI / 2 / N);
				double cosinc = cos(base + scale * i * M_PI / 2 / N);
				maxx = maxy = -1e99;
				minx = miny = 1e99;
				for (j = 0; j < n; j++)
				{
					xx = cosinc * x[j] - sininc * y[j];
					yy = sininc * x[j] + cosinc * y[j];
					//printf("x y xx yy %lg %lg %lg %lg\n",x[j],y[j],xx,yy);
					if (xx < minx)
					{
						minx = xx;
					}
					if (xx > maxx)
					{
						maxx = xx;
					}
					if (yy < miny)
					{
						miny = yy;
					}
					if (yy > maxy)
					{
						maxy = yy;
					}
				}
				dx = maxx - minx;
				dy = maxy - miny;
				dd = dx;
				if (dy > dd)
				{
					dd = dy;
				}
				if (dd < best)
				{
					best = dd;
					besti = i;
				}
				//printf("i %d dd %0.5lf\n",i,dd);
			}
			base += scale * (besti - 1) * M_PI / 2 / N;
			scale = scale / N * 2;
		}
		printf("%0.2lf\n", best * best);
	}
	return 0;
}
