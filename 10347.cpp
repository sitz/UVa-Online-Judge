#include <bits/stdc++.h>

using namespace std;

int main()
{
	double m1, m2, m3, s;
	while (scanf("%lf%lf%lf", &m1, &m2, &m3) == 3)
	{
		double temp;
		s = (m1 + m2 + m3) / 2.0;
		temp = s * (s - m1) * (s - m2) * (s - m3);
		if (temp > 0)
		{
			printf("%.3lf\n", 4.0 * sqrt(temp) / 3.0);
		}
		else
		{
			printf("-1.000\n");
		}
	}
	return 0;
}
