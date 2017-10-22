#include <bits/stdc++.h>

using namespace std;

/**
 * UVa 579 ClockHands
 * Author: chchwy
 * Last Modified: 2011.04.06
 * Blog: http://chchwy.blogspot.com
 */

float angle_between(float hr, float min)
{
	float hr_angle = (hr / 12 * 360) + (min / 60 * (360 / 12));
	float min_angle = min / 60 * 360;
	float dif_angle = fabs(hr_angle - min_angle);
	return (dif_angle < 180) ? dif_angle : (360.0 - dif_angle);
}

int main()
{
	int hr, min;
	char tmp;
	while (scanf("%d%c%d", &hr, &tmp, &min))
	{
		if (hr == 0 && min == 0)
		{
			break;
		}
		printf("%.3f\n", angle_between(hr, min));
	}
}
