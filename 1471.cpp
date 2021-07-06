#include <bits/stdc++.h>

using namespace std;

const int maxn = 200010;

int num[maxn], ab[maxn];
int un[maxn], e;

struct T
{
	int ll, rr, v;
} p[maxn * 3];

void build(int s, int e, int num)
{
	p[num].ll = s, p[num].rr = e;
	p[num].v = 0;
	if (s != e)
	{
		int mid = (s + e) / 2;
		build(s, mid, num * 2 + 1);
		build(mid + 1, e, num * 2 + 2);
	}
}

void update(int pos, int k, int num)
{
	if (p[num].ll == p[num].rr)
	{
		p[num].v = max(p[num].v, k);
		return;
	}
	int mid = (p[num].ll + p[num].rr) / 2;
	if (pos <= mid)
	{
		update(pos, k, num * 2 + 1);
	}
	else
	{
		update(pos, k, num * 2 + 2);
	}
	p[num].v = max(p[num * 2 + 1].v, p[num * 2 + 2].v);
}

int query(int s, int e, int num)
{
	if (p[num].ll == s && p[num].rr == e)
	{
		return p[num].v;
	}
	int mid = (p[num].ll + p[num].rr) / 2;
	if (e <= mid)
	{
		return query(s, e, num * 2 + 1);
	}
	else if (s > mid)
	{
		return query(s, e, num * 2 + 2);
	}
	else
	{
		return max(query(s, mid, num * 2 + 1), query(mid + 1, e, num * 2 + 2));
	}
}

int main()
{
	int T, n, i, j, k;
	int ans;
	scanf("%d", &T);
	while (T--)
	{
		ans = 1;
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
		{
			scanf("%d", &num[i]);
			un[i - 1] = num[i];
		}
		sort(un, un + n);
		e = unique(un, un + n) - un;
		for (i = 1; i <= n; ++i)
		{
			num[i] = lower_bound(un, un + e, num[i]) - un;
		}
		build(0, e, 0);
		ab[0] = 0;
		num[0] = num[n + 1] = -1;
		for (i = 1; i <= n; ++i)
		{
			if (num[i] > num[i - 1])
			{
				ab[i] = ab[i - 1] + 1;
			}
			else
			{
				ab[i] = 1;
			}
		}
		k = 0;
		for (i = n; i >= 1; --i)
		{
			ans = max(ans, ab[i] + query(num[i] + 1, e, 0));
			if (num[i] < num[i + 1])
			{
				k++;
			}
			else
			{
				k = 1;
			}
			update(num[i], k, 0);
		}
		printf("%d\n", ans);
	}
	return 0;
}
