#include <bits/stdc++.h>

using namespace std;

#define ran 1010

int n;
int fat[ran];
double b[ran], c[ran];
map<int, double> e[ran];
double ans[ran];
double mon[ran], tim[ran], num[ran];
void dfs(int x, bool isRoot, double &bes, int &v)
{
	mon[x] = b[x];
	tim[x] = c[x];
	for (map<int, double>::iterator it = e[x].begin(); it != e[x].end(); it++)
	{
		int y = it->first;
		double z = it->second;
		num[y] = num[x] * z;
		dfs(y, false, bes, v);
		mon[x] += mon[y] * z;
		tim[x] += tim[y] * z;
	}
	if (!isRoot)
	{
		double R = mon[x] / tim[x];
		if (R > bes)
		{
			bes = R, v = x;
		}
	}
}

void process(int root, double add)
{
	double bes = -1;
	int v;
	num[root] = 1;
	dfs(root, true, bes, v);
	if (bes < -.5)
	{
		ans[root] += add * c[root];
		return;
	}
	double nm = num[v], w = mon[v], t = tim[v];
	e[fat[v]].erase(v);
	process(v, add);
	ans[root] += nm * (nm - 1) / 2 * w * t + nm * ans[v];
	process(root, add + nm * w);
}

int main()
{
	int _, t;
	scanf("%d", &_);
	for (t = 1; t <= _; t++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf", &b[i], &c[i]);
			e[i].clear();
			int x, z;
			double y;
			for (scanf("%d", &x); x--;)
			{
				scanf("%d%lf", &z, &y);
				e[i][z] = y;
				fat[z] = i;
			}
			ans[i] = 0;
		}
		process(1, 0);
		printf("Case #%d: %.0lf\n", t, ans[1]);
	}
	return 0;
}
