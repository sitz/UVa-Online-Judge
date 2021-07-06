#include <bits/stdc++.h>

using namespace std;

double dis[10000];
int almostSame(double a, double b)
{
	return a - 1E-9 <= b && b <= a + 1E-9;
}
int main()
{
	int kase = 0;
	while (true)
	{
		kase++;
		int n;
		double base, power;
		scanf("%d", &n);
		if (!n)
		{
			break;
		}
		for (int q = 0; q < n; ++q)
		{
			scanf("%lf", &dis[q]);
		}
		scanf("%lf", &base);
		sort(dis, dis + n);
		for (int q = n - 1; q >= 0; q--)
		{
			dis[q] -= dis[0];
		}
		power = base;
		double time = 0;
		for (int q = 1; q < n; ++q)
			if (dis[q] < power || almostSame(dis[q], power))
			{
				power = dis[q] + base;
			}
			else if (dis[q] - 2 * time < power || almostSame(dis[q] - 2 * time, power))
			{
				power += base;
			}
			else
			{
				double delta = dis[q] - power;
				time = delta / 2;
				power += base;
			}
		printf("Case %d: %.3lf\n", kase, time);
	}
	return 0;
}
