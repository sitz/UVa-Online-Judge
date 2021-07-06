#include <bits/stdc++.h>

using namespace std;

const double pi = 2 * acos(0), k = 180.0 / pi;
double r, n;
int main()
{
	int caseno = 1;
	while (scanf("%lf %lf", &r, &n) == 2)
	{
		if (!r && !n)
		{
			break;
		}
		printf("Case %d:\n", caseno++);
		for (int i = 1; i <= 10; i++)
		{
			double t = n / r, s = acos((n / 2 / pi / r / i));
			printf("%.5lf\n", (s - t) * k);
		}
	}
}
