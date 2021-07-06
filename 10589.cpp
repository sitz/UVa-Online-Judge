#include <bits/stdc++.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main()
{
	int N, a;
	while (scanf("%d%d", &N, &a) != EOF && N != 0 && a != 0)
	{
		int i;
		int M = 0;
		for (i = 0; i < N; i++)
		{
			double x, y;
			scanf("%lf%lf", &x, &y);
			if (distance(x, y, 0.0, 0.0) <= (double)(a * a))
				if (distance(x, y, 0.0, (double)a) <= (double)(a * a))
					if (distance(x, y, (double)a, (double)a) <= (double)(a * a))
						if (distance(x, y, (double)a, 0.0) <= (double)(a * a))
						{
							M++;
						}
		}
		printf("%.5lf\n", (double)M / (double)N * (double)a * (double)a);
	}
	return 0;
}
