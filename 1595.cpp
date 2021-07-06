#include <bits/stdc++.h>

using namespace std;

int T, n, x[1024], y[1024];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
		}
		int mx, mn;
		mx = mn = x[0];
		for (int i = 0; i < n; i++)
		{
			mx = max(mx, x[i]);
			mn = min(mn, x[i]);
		}
		double mid = (mx + mn) / 2.0;
		set<pair<int, int> > S;
		for (int i = 0; i < n; i++)
		{
			S.insert(make_pair((int)((x[i] - mid) * 2), y[i]));
		}
		int ret = 1;
		for (int i = 0; i < n && ret; i++)
		{
			ret &= S.find(make_pair((int)(-(x[i] - mid) * 2), y[i])) != S.end();
		}
		printf(ret ? "YES\n" : "NO\n");
	}
	return 0;
}
