#include <bits/stdc++.h>

using namespace std;

int n;
double A;
int kase = 1;

const double PI = acos(-1.0);

int main()
{
	while (scanf("%d%lf", &n, &A) == 2)
	{
		if (n < 3)
		{
			break;
		}
		double R, r;
		R = sqrt(2.0 * A / n / (sin(2 * PI / n)));
		r = R * cos(PI / n);
		printf("Case %d: %.5lf %.5lf\n", kase++, PI * R * R - A, A - PI * r * r);
	}
	return 0;
}
