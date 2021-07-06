#include <bits/stdc++.h>

using namespace std;

char time_[2000];
int h, m, s, speed, newspeed, now;
float dist = 0;

int main()
{
	int n, oldtime_ = 0;
	speed = 0;
	while (gets(time_))
	{
		n = sscanf(time_, "%d:%d:%d %d", &h, &m, &s, &newspeed);
		now = h * 3600 + m * 60 + s;
		dist += (now - oldtime_) / 3600.0 * speed;
		oldtime_ = now;
		if (n == 3)
		{
			printf("%02d:%02d:%02d %.2f km\n", h, m, s, dist);
		}
		else if (n == 4)
		{
			speed = newspeed;
		}
	}
	return 0;
}
