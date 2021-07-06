#include <bits/stdc++.h>

using namespace std;

double dis[50], from[50], to[50];
double v, s, m, acctime, accdis;

double givetime(double d)
{
	return acctime * 2 + (d - accdis * 2) / v;
}

int main()
{
	int t = 0;
	while (true)
	{
		int end = 0, c = 0;
		double a;
		while (scanf("%lf", &a) == 1)
		{
			if (a == -1)
			{
				end = 1;
				break;
			}
			if (a <= 1e-13)
			{
				break;
			}
			dis[++c] = a * 5280;
		}
		for (int i = c; i >= 1; i--)
		{
			dis[i] -= dis[i - 1];
		}
		if (end)
		{
			break;
		}
		if (t)
		{
			printf("\n");
		}
		scanf("%lf%lf%lf", &v, &s, &m);
		acctime = v / s;
		accdis = s * acctime * acctime / 2.0;
		for (int i = 1; i <= c; i++)
		{
			from[i] = from[i - 1] + givetime(dis[i]) + m;
		}
		to[c] = 0;
		for (int i = c - 1; i >= 0; i--)
		{
			to[i] = to[i + 1] + givetime(dis[i + 1]) + m;
		}
		printf("Scenario #%d:\n", ++t);
		double disacu = 0;
		for (int i = 0; i <= c; i++)
		{
			disacu += dis[i];
			if (fabs(from[i] - to[i]) <= m)
			{
				printf("   Meeting time: %.1lf minutes\n", max(to[i] - m, from[i] - m));
				printf("   Meeting distance: %.3lf miles from metro center hub, in station %d\n", disacu / 5280, i);
				break;
			}
			else if (from[i] > to[i])
			{
				disacu -= dis[i];
				double duration = (dis[i] - accdis * 2) / v;
				double t1 = from[i - 1] + acctime;
				double t2 = from[i - 1] + acctime + duration;
				double t3 = to[i] + acctime;
				double t4 = to[i] + acctime + duration;
				double tt = 0.0f;
				if (t1 >= t4)
				{
					tt = (acctime + t4 + from[i - 1]) / 2;
					disacu += (tt - from[i - 1]) * (tt - from[i - 1]) * s / 2;
				}
				else if (t3 >= t2)
				{
					tt = (acctime + t2 + to[i]) / 2;
					disacu += dis[i] - (from[i] - tt - m) * (from[i] - tt - m) * s / 2;
				}
				else
				{
					tt += (duration + t1 + t3) / 2;
					disacu += accdis + (tt - t1) * v;
				}
				printf("   Meeting time: %.1lf minutes\n", tt);
				printf("   Meeting distance: %.3lf miles from metro center hub\n", disacu / 5280);
				break;
			}
		}
	}
	return 0;
}
