#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, t = 1;
	double ang, x;
	while (scanf("%d : %d", &a, &b) == 2)
	{
		ang = acos(double(a * a - b * b) / (a * a + b * b));
		x = 400 / (2 * a + ang * sqrt(a * a + b * b));
		printf("Case %d: %.10f %.10f\n", t++, a * x, b * x);
	}
	return 0;
}
