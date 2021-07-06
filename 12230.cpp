#include <bits/stdc++.h>

using namespace std;

int n;
double d;
double p, l, v;
int main()
{
	int ca = 1;
	while (~scanf("%d%lf", &n, &d))
	{
		if (!n && d == 0)
		{
			break;
		}
		while (n--)
		{
			scanf("%lf%lf%lf", &p, &l, &v);
			d -= l;
			d += 2 * l / v;
		}
		printf("Case %d: %.3f\n\n", ca++, d);
	}
	return 0;
}
