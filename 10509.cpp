#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a, n, dx;
	while (1)
	{
		scanf("%lf", &n);
		if (n == 0)
		{
			break;
		}
		a = 1;
		while (1)
		{
			if (a * a * a >= n)
			{
				break;
			}
			a++;
		}
		if (a * a * a == n)
		{
			printf("%.4lf\n", a);
			continue;
		}
		a--;
		dx = (n - a * a * a) / (3 * a * a);
		printf("%.4lf\n", a + dx);
	}
	return 0;
}
