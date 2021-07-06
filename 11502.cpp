#include <bits/stdc++.h>

using namespace std;

struct Stage
{
	long long s;
	long long l;
	double t;
	double c;
};

Stage stages[1010];
double dp1[1010][10010];
double ln[12000];

double velStage(int stage, long long masa)
{
	Stage &t = stages[stage];
	if (t.l == 0)
	{
		return 0;
	}
	long long k = masa + t.s + t.l;
	if (t.t / k < 9.8)
	{
		return -1e100;
	}
	double res = t.t / t.c;
	double k1 = (ln[k] - ln[k - t.l]);
	res *= k1;
	res -= (9.8 * t.l) / t.c;
	return res;
}

double dp(int stage, long long masa)
{
	Stage &t = stages[stage];
	double v = dp1[stage + 1][masa];
	long long k = masa + t.s + t.l;
	if (k > 10000)
	{
		return v;
	}
	double v1 = dp1[stage + 1][k] + velStage(stage, masa);
	if (v1 > v)
	{
		return v1;
	}
	return v;
}

int main()
{
	for (int i = 0; i < 12000; i++)
	{
		ln[i] = log(i);
	}
	int casos;
	scanf("%d", &casos);
	for (int caso = 0; caso < casos; caso++)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld %lld %lf %lf", &stages[i].s, &stages[i].l, &stages[i].t, &stages[i].c);
		}
		for (int j = 0; j < 10001; j++)
		{
			dp1[n][j] = 0;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 10000; j >= 0; j--)
			{
				dp1[i][j] = dp(i, j);
			}
		}
		printf("%.0lf\n", dp1[0][0]);
	}
}
