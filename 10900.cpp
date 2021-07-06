#include <bits/stdc++.h>

using namespace std;

int main()
{
	int i, n;
	double p, pr, nw, th;
	while (scanf("%d%lf", &n, &p) == 2)
	{
		if (n == 0 && p == 0.0)
		{
			break;
		}
		if (p == 1.0)
		{
			printf("%.3lf\n", pow(2.0, n));
			continue;
		}
		pr = pow(2.0, n);
		for (i = n; i > 0; i--)
		{
			nw = pow(2.0, i - 1.0);
			th = nw / pr;
			if (th < p)
			{
				th = p;
			}
			pr = (nw * (th - p) + pr / 2.0 * (1 - th * th)) / (1.0 - p);
		}
		printf("%.3lf\n", pr);
	}
	return 0;
}
