#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

int main()
{
	double l, w, x;
	while (scanf("%lf %lf", &l, &w) != EOF)
	{
		// Calc x at maximum
		x = (w + l - sqrt(w * w + l * l - w * l)) / 6.0;
		printf("%.3f 0.000 ", x + EPS);
		// Calc x at minimum
		if (l > 0 & w > 0)
		{
			if (l < w)
			{
				printf("%.3f", l / 2.0 + EPS);
			}
			else
			{
				printf("%.3f", w / 2.0 + EPS);
			}
		}
		printf("\n");
	}
	return 0;
}
