#include <bits/stdc++.h>

using namespace std;

int limit = 200, limit2 = 400;
double lower, upper;

inline int fn(double x, int planes, int total)
{
	double n = (double)upper / lower, fuel, tmp;
	while (true)
	{
		fuel = n - (1 - x);
		tmp = (double)fuel / (planes + 1);
		x = x + tmp, planes++, total++;
		if (x >= .999)
		{
			return planes;
		}
		if (total > limit2)
		{
			return 20000;
		}
	}
}

inline int solve()
{
	lower = 1 - upper;
	double tank;
	int ret = 999999999;
	for (int i = 1; i < limit; i++)
	{
		tank = (double)(i - 1) / (i + 1);
		tank = (double)(tank * upper) / (lower);
		int tmp = fn(tank, 1, i);
		ret = min(ret, i + tmp - 1);
	}
	tank = (double)(3 - 1) / (3 + 1);
	if (ret > 10000)
	{
		ret = -1;
	}
	return ret;
}

int main()
{
	int cases, x, y, p = 1;
	scanf("%d", &cases);
	while (cases--)
	{
		scanf("%d %d", &x, &y);
		if (x >= y)
		{
			printf("Case %d: %d\n", p++, 1);
			continue;
		}
		upper = (double)x / y;
		printf("Case %d: %d\n", p++, solve());
	}
	return 0;
}
