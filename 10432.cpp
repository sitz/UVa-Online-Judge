#include <bits/stdc++.h>

using namespace std;

int main()
{
	double p = 4 * acos(0.0), r, n;
	while (scanf("%lf%lf", &r, &n) != -1)
	{
		printf("%0.3lf\n", n * r * r * sin(p / n) / 2.0);
	}
	return 0;
}
