#include <bits/stdc++.h>

using namespace std;

int main()
{
	double aa = 10000;
	double r = 26405.593003588347000;
	double a;
	while (scanf("%lf", &a) != EOF)
	{
		if (a == -1)
		{
			break;
		}
		printf("%.10lf\n", a * r / aa);
	}
	return 0;
}
