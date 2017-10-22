#include <bits/stdc++.h>

using namespace std;

int main()
{
	double S;
	int I;
	double base = log10(1.324717957244746);
	while (scanf("%lf%d", &S, &I) == 2)
	{
		double ans = log10(S);
		ans += (I - 1) * base;
		if (ans < 9)
		{
			printf("%.lf\n", floor(pow(10, ans)));
		}
		else
		{
			printf("%d\n", (int)(ans + 1));
		}
	}
	return 0;
}
