#include <bits/stdc++.h>

using namespace std;

const int maxn = 501;
struct node
{
	int s;
	int d;
	bool operator<(const node &a) const
	{
		if (d == a.d)
		{
			return s < a.s;
		}
		return d < a.d;
	}
} a[maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &a[i].s, &a[i].d);
		}
		sort(a, a + n);
		int now = 0, ta = 0, tb = 0, pos = 0;
		for (int i = 0; i < n; i++)
		{
			now += a[i].s;
			int t = max(now - a[i].d, 0);
			if (t > ta)
			{
				tb = ta;
				ta = t;
				pos = i;
			}
			else if (t > tb)
			{
				tb = t;
				pos = i;
			}
		}
		int ans = ta + tb;
		for (int i = 0; i <= pos; i++)
		{
			now = 0, ta = 0, tb = 0;
			for (int j = 0; j <= pos; j++)
			{
				if (i == j)
				{
					continue;
				}
				now += a[j].s;
				int t = max(now - a[j].d, 0);
				if (t > ta)
				{
					tb = ta;
					ta = t;
				}
				else if (t > tb)
				{
					tb = t;
				}
			}
			now += a[i].s;
			int t = max(now - a[i].d, 0);
			if (t > ta)
			{
				tb = ta;
				ta = t;
			}
			else if (t > tb)
			{
				tb = t;
			}
			ans = min(ans, ta + tb);
		}
		printf("%d\n", ans);
	}
	return 0;
}
