#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

struct node
{
	double l, r;
	bool operator<(const node &p) const
	{
		return r < p.r || (r == p.r && l > p.l);
	}
};
node a[MAXN];

int main()
{
	double x, y, l, d;
	int n;
	while (scanf("%lf", &l) == 1)
	{
		scanf("%lf%d", &d, &n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%lf%lf", &x, &y);
			a[i].l = x - sqrt(d * d - y * y);
			a[i].r = x + sqrt(d * d - y * y);
		}
		sort(a, a + n);
		int cnt = 1;
		double ans = a[0].r;
		for (int i = 0; i < n; ++i)
		{
			if (a[i].l > ans)
			{
				++cnt;
				ans = a[i].r;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
