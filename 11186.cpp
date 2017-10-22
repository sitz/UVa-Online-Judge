#include <bits/stdc++.h>

using namespace std;

double r, s, p[555];

int main()
{
	int n;
	while (scanf("%d%lf", &n, &r) == 2 && n)
	{
		s = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf", &p[i]);
			p[i] *= M_PI / 180;
		}
		sort(p, p + n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 1; j < n; ++j)
			{
				s += (n + 2 * i - 2 * j) * sin(p[j] - p[i]);
			}
		}
		s *= r * r / 2;
		printf("%.0lf\n", s);
	}
	return 0;
}
