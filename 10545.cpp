#include <bits/stdc++.h>

using namespace std;

const double pi = acos(-1);
double p, a, b, c, d, s;
int main()
{
	int t;
	scanf("%d", &t);
	for (int cases = 1; cases <= t; cases++)
	{
		scanf("%lf %lf %lf", &p, &a, &b);
		s = p / 2;
		c = s - a;
		d = s - b;
		double temp = (a * c + b * d) * (a * c + b * d) - (a - b) * (a - b) * (a + b - s) * (a + b - s);
		printf("Case %d: ", cases);
		if (c <= 0 || d <= 0 || temp < 0)
		{
			puts("Eta Shombhob Na.");
		}
		else
		{
			printf("%.6lf\n", sqrt(temp) / 2 / s);
		}
	}
}
