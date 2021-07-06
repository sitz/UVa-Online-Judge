#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
vector<pair<double, double>> planes;

int p[15];
bool vis[15];
double maxmin;
double eps = 1e-3;

bool equal(double x, double y)
{
	return fabs(x - y) <= eps;
}

bool valid(double gap)
{
	double current = planes[p[0]].first;
	REP(i, 1, n - 1)
	{
		current += gap;
		if (planes[p[i]].second < current && !equal(planes[p[i]].second, current))
		{
			return false;
		}
		else if (planes[p[i]].first > current && !equal(planes[p[i]].first, current))
		{
			current = planes[p[i]].first;
		}
	}
	return true;
}

void validate()
{
	double st = 0.0;
	double end = (1440 * 60) * 1.0;
	int itr = 100;
	double mid = -1.0;
	while (itr--)
	{
		mid = (st + end) / 2.0;
		if (valid(mid))
		{
			st = mid;
		}
		else
		{
			end = mid;
		}
	}
	maxmin = max(maxmin, mid);
}

void permute(int index)
{
	if (index == n)
	{
		validate();
		return;
	}
	REP(i, 0, n - 1)
	{
		if (vis[i])
		{
			continue;
		}
		p[index] = i;
		vis[i] = true;
		permute(index + 1);
		vis[i] = false;
	}
}

int main()
{
	int tc = 1;
	while (true)
	{
		scanf("%d", &n);
		if (n == 0)
		{
			break;
		}
		planes.clear();
		REP(i, 0, n - 1)
		{
			int a, b;
			scanf("%d %d", &a, &b);
			planes.push_back(make_pair((double)(a * 60), (double)(b * 60)));
		}
		memset(vis, false, sizeof(vis));
		maxmin = -1.0;
		permute(0);
		int res = (int)(maxmin + 0.5);
		printf("Case %d: %d:", tc++, res / 60);
		if (res % 60 < 10)
		{
			printf("0%d\n", res % 60);
		}
		else
		{
			printf("%d\n", res % 60);
		}
	}
	return 0;
}
