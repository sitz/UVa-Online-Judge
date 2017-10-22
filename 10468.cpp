#include <bits/stdc++.h>

using namespace std;

#define NINE 7.022509503430381
#define TEN 7.519130890631598

int main()
{
	double x;
	while (scanf("%lf", &x) != EOF)
	{
		printf("%.5lf %.5lf\n", NINE * x, TEN * x);
	}
	return 0;
}
