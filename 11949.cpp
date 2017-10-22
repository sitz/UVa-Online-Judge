#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;
double a[120000];
char buf[1200000];
int _, n, i, j;
double lo, up, mid, s, ts, rt;

int main()
{
	scanf("%d", &_);
	gets(buf);
	while (_--)
	{
		gets(buf);
		istringstream is(buf);
		n = 0;
		while (is >> a[n])
		{
			n++;
		}
		n--;
		lo = -1.0;
		up = 1.0;
		if (fabs(a[0]) < eps)
		{
			puts("-100.000%");
			continue;
		}
		for (int tt = 0; tt < 200; tt++)
		{
			mid = (lo + up) / 2.0;
			ts = 0.0;
			rt = 1.0 + mid;
			for (i = 1; i <= n; i++)
			{
				ts += a[i] / rt;
				rt *= (1.0 + mid);
			}
			if ((a[0] > 0 && ts > a[0] + eps) || (a[0] < 0 && ts < a[0] - eps))
			{
				lo = mid;
			}
			else
			{
				up = mid;
			}
		}
		lo *= 100.0;
		printf("%.3f", lo);
		puts("%");
	}
	return 0;
}
