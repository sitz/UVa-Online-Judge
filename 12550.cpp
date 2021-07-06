#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-8;

char s[1000000];
double a[1000000];

inline int sig(double x)
{
	return (x > eps) - (x < -eps);
}

int main()
{
	while (gets(s))
	{
		int ans = 0;
		int lens = strlen(s);
		double tt = 0;
		bool yes = 0;
		for (int i = 0; i < lens; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				tt = tt * 10 + s[i] - '0';
				yes = 1;
			}
			else if (yes)
			{
				a[++ans] = tt;
				yes = 0;
				tt = 0;
			}
		}
		if (tt)
		{
			a[++ans] = tt;
		}
		double p = a[2];
		int d = a[1];
		int temp = -1;
		for (int i = 3; i <= ans; i++)
		{
			a[++temp] = a[i];
		}
		if (sig(a[0] - p) > 0)
		{
			printf("The spider is going to fall!\n");
			continue;
		}
		if (temp < d)
		{
			double ts1, ts2;
			ts1 = a[1] * a[3] - a[2] * a[2];
			ts1 /= (a[1] * a[1] - a[0] * a[2]);
			ts2 = (a[3] - ts1 * a[1]) / a[2];
			for (int i = temp + 1; i <= d; i++)
			{
				a[i] = ts2 * a[i - 1] + ts1 * a[i - 2];
			}
		}
		int res = 0;
		for (int i = 0; i <= d; i++)
		{
			if (sig(a[i] - p) <= 0)
				res = i;
			else
				break;
		}
		if (res == d)
			printf("The spider may fall!\n");
		else
			printf("%d\n", d - res);
	}
	return 0;
}
