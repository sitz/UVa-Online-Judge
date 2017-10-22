#include <bits/stdc++.h>

using namespace std;

void add_tri(double x1, double y1, double x2, double y2,
						 double *tot_ar, double *wx)
{
	double ar = x1 * y2 - x2 * y1;
	*tot_ar += ar;
	*wx += ar * (x1 + x2) / 3.0;
}
typedef vector<int> VI;
int main()
{
	int cc;
	cin >> cc;
	while (cc--)
	{
		int n;
		cin >> n;
		VI x(n), y(n);
		for (int i = 0; i < n; i++)
		{
			cin >> x[i] >> y[i];
		}
		x.push_back(x[0]);
		y.push_back(y[0]);
		double tar = 0.0, tx = 0.0, bar = 0.0, bx = 0.0;
		for (int i = 0; i < n; i++)
		{
			if (y[i] >= 0 && y[i + 1] >= 0)
			{
				add_tri(x[i], y[i], x[i + 1], y[i + 1], &tar, &tx);
			}
			else if (y[i] <= 0 && y[i + 1] <= 0)
			{
				add_tri(x[i], y[i], x[i + 1], y[i + 1], &bar, &bx);
			}
			else
			{
				double mx = y[i] * (double)(x[i + 1] - x[i]) / (y[i] - y[i + 1]) + x[i];
				add_tri(x[i], y[i], mx, 0.0, y[i] > 0 ? &tar : &bar,
								y[i] > 0 ? &tx : &bx);
				add_tri(mx, 0.0, x[i + 1], y[i + 1], y[i + 1] > 0 ? &tar : &bar,
								y[i + 1] > 0 ? &tx : &bx);
			}
		}
		tx /= tar;
		bx /= bar;
		if (fabs(tx - bx) < 1e-6)
		{
			printf("Balanced.\n");
		}
		else if (tx < bx)
		{
			printf("CE is aft of CLR by %.02lf units.\n", bx - tx);
		}
		else
		{
			printf("CE is forward of CLR by %.02lf units.\n", tx - bx);
		}
	}
	return 0;
}
