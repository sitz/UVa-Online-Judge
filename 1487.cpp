#include <bits/stdc++.h>

using namespace std;

#define Mod (1000000009LL)
#define Pi (acos(-1.0))

double R, H, h;
double ans, tmp;
double f(double x)
{
	return 16.0 / 3.0 * x * sqrt(x);
}
int main()
{
	while (~scanf("%lf%lf", &R, &H))
	{
		ans = 2.0 * R * R * Pi * H;
		h = H /= 2.0;
		h = min(h, R);
		tmp = f(R * R) - f(R * R - h * h);
		//printf("%.2lf %.2lf\n",ans,tmp);
		printf("%.4f\n", ans - tmp);
	}
	return 0;
}
