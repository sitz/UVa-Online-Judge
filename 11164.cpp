#include <bits/stdc++.h>

using namespace std;

int main()
{
	double a, b, c;
	int cases = 1;
	while (scanf("%lf %lf %lf", &a, &b, &c) == 3)
	{
		if (a < 0)
		{
			break;
		}
		printf("Set %d:\n", cases++);
		if (b * b - a * c == 0)
		{
			puts("Poor King!");
		}
		else
		{
			double d = b * b - a * c;
			double x = (a * b * c + a * a * c) / d;
			double y = (a * b * c + a * c * c) / d;
			if ((x + y) >= 0)
			{
				printf("%.4lf\n", x + y);
			}
			else
			{
				puts("Poor King!");
			}
		}
	}
	return 0;
}
