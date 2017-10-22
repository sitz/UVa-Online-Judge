#include <bits/stdc++.h>

using namespace std;

#define N 110

struct node
{
	double C, T, R;
	void in()
	{
		scanf("%lf%lf%lf", &C, &T, &R);
	}
} in[N];
int n;
double rat;
bool judge(double mid, int cnt)
{
	double cost = 0, get = mid * rat * cnt;
	for (int i = 0; i < n; i++)
	{
		if (in[i].C * mid <= in[i].T * in[i].R)
		{
			continue;
		}
		get += in[i].R;
		cost += in[i].C / in[i].T * mid;
	}
	return get <= cost;
}
double gao(int m)
{
	double l = 0, r = 100010, best = -1;
	while (r - l > 1e-4)
	{
		double mid = (r + l) * 0.5;
		if (judge(mid, m))
		{
			r = mid;
		}
		else
		{
			best = mid;
			l = mid;
		}
	}
	return best;
}
int main()
{
	int q, m;
	for (int ca = 1;; ca++)
	{
		scanf("%d%d", &n, &q);
		if (!n && !q)
		{
			break;
		}
		scanf("%lf", &rat);
		double sum = 0;
		double mi = 1e20;
		for (int i = 0; i < n; i++)
		{
			in[i].in(), sum += in[i].C / in[i].T, mi = min(mi, in[i].R * in[i].T / in[i].C);
		}
		printf("Case %d:\n", ca);
		int j = 1;
		for (j = 1; rat * j < sum; j++)
			;
		printf("%d\n", j);
		while (q--)
		{
			scanf("%d", &m);
			if (!m)
			{
				printf("%.3lf\n", mi);
				continue;
			}
			double ans = gao(m);
			if (ans > 100000)
			{
				puts("-1.000");
			}
			else
			{
				printf("%.3lf\n", ans);
			}
		}
	}
	return 0;
}
