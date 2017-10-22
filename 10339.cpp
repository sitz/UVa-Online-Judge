#include <bits/stdc++.h>

using namespace std;

double k, m, d, kd;
int mins;

int main()
{
	while (scanf("%lf %lf", &k, &m) == 2)
	{
		d = (double)(43200 / fabs(k - m));
		kd = d * (86400.0 - k) / 86400;
		mins = (int)floor(1440.0 * fmod(kd + 1e-7, 0.5) + 0.5);
		int hours = mins / 60;
		if (hours == 0)
		{
			hours = 12;
		}
		printf("%.lf %.lf %02d:%02d\n", k, m, hours, mins % 60);
	}
	return 0;
}
