#include <bits/stdc++.h>

using namespace std;

int ncase, minute, kk;
double sx, sy, X1, X2, Y1, Y2;
double dx, dy, dist, time1, time2, total_time;
char str[256];

int main()
{
	gets(str);
	ncase = atoi(str);
	for (kk = 0; kk < ncase; ++kk)
	{
		gets(str);
		sscanf(str, "%lf %lf", &sx, &sy);
		total_time = time1 = time2 = 0;
		while (gets(str))
		{
			if (!strlen(str))
			{
				break;
			}
			sscanf(str, "%lf%lf%lf%lf", &X1, &Y1, &X2, &Y2);
			dx = X1 - X2;
			dy = Y1 - Y2;
			dist = sqrt(dx * dx + dy * dy);
			time1 += dist / 10000;
		}
		total_time = time1;
		minute = (int)(total_time * 60 + 0.5);
		if (kk)
		{
			puts("");
		}
		printf("%d:%02d\n", minute / 60, minute % 60);
	}
	return 0;
}
