#include <bits/stdc++.h>

using namespace std;

struct
{
	int p1, p2, t1, t2, w1, w2;
} a[10000];

int n;
double ans;

double getTime(int pos, int ablity)
{
	if (ablity < a[pos].p1)
	{
		return -1;
	}
	if (ablity >= a[pos].p2)
	{
		return a[pos].t2;
	}
	return (0.0 + ablity - a[pos].p1) / (0.0 + a[pos].p2 - a[pos].p1) * (a[pos].t2 - a[pos].t1) + a[pos].t1;
}

void dfs(int pos, double time, int dbl, int ablity)
{
	if (pos == n)
	{
		if (time < ans)
		{
			ans = time;
		}
		return;
	}
	double addTime = getTime(pos, ablity);
	if (addTime >= 0)
	{
		dfs(pos + 1, time + addTime, dbl + a[pos].w2, ablity + a[pos].w1);
	}
	if (ablity > 100)
	{
		return;
	}
	if (dbl > 0)
	{
		dfs(pos, time, dbl - 1, ablity * 2);
	}
}

int main()
{
	int ablity;
	while (2 == scanf("%d%d", &n, &ablity) && (n || ablity))
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d%d%d%d%d%d", &a[i].p1, &a[i].p2, &a[i].t1, &a[i].t2, &a[i].w1, &a[i].w2);
		}
		ans = 1e300;
		dfs(0, 0, 0, ablity);
		if (ans >= 1e300)
		{
			puts("Impossible");
		}
		else
		{
			printf("%.2f\n", ans);
		}
	}
	return EXIT_SUCCESS;
}
