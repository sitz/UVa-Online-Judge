#include <bits/stdc++.h>

using namespace std;

#define LB(x) (x) & (-x)

const int maxn = 200005;
int as[23][maxn];
int bs[23][maxn];
int tmp[maxn], cs[maxn];
int n, m;
long long tot;
void add(int a[], int x, int v, int n)
{
	for (; x <= n; x += LB(x))
	{
		a[x] += v;
	}
}
int getsum(int a[], int x, int n = 0)
{
	int v = 0;
	for (; x > n; x -= LB(x))
	{
		v += a[x];
	}
	return v;
}
void build(int rt, int l, int r, int d)
{
	int md = (l + r) >> 1;
	for (int i = l; i <= r; ++i)
	{
		as[d][i] = as[d - 1][i], bs[d][i] = 0;
	}
	if (l == r)
	{
		return;
	}
	build(rt << 1, l, md, d + 1);
	build(rt << 1 | 1, md + 1, r, d + 1);
	sort(as[d] + l, as[d] + r + 1);//排序
}
//二分区间[a,b]，得到v所在的位置
int bitser(int a, int b, int d, int v)
{
	int l = a, r = b, md;
	while (l < r)
	{
		md = (l + r) >> 1;
		if (as[d][md] >= v)
		{
			r = md;
		}
		else
		{
			l = md + 1;
		}
	}
	if (as[d][l] > v)
	{
		--l;
	}
	return l;
}
void query(int rt, int l, int r, int L, int R, int v, int d, int f)
{
	int md = (l + r) >> 1;
	if (L <= l && r <= R)
	{
		int k = bitser(l, r, d, v);
		int t = getsum(bs[d], k, l - 1);//求[l,r]区间上k位置前有多少个数删除了
		if (!f)
		{
			k = r - k;
			t = getsum(bs[d], r, l - 1) - t;
		}
		else
		{
			k -= l - 1;
		}
		tot -= k - t;
		return;
	}
	if (l >= r)
	{
		return;
	}
	if (L <= md)
	{
		query(rt << 1, l, md, L, R, v, d + 1, f);
	}
	if (R > md)
	{
		query(rt << 1 | 1, md + 1, r, L, R, v, d + 1, f);
	}
}
void update(int rt, int l, int r, int L, int v, int d)
{
	int md = (l + r) >> 1;
	if (l == r)
	{
		add(bs[d], l, 1, r);
		return;
	}
	if (l >= r)
	{
		return;
	}
	if (L <= md)
	{
		update(rt << 1, l, md, L, v, d + 1);
	}
	else
	{
		update(rt << 1 | 1, md + 1, r, L, v, d + 1);
	}
	int k = bitser(l, r, d, v);
	add(bs[d], k, 1, r);
}
int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		tot = 0;
		for (int i = 0; i <= n + 1; ++i)
		{
			tmp[i] = 0;
		}
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d", &as[0][i]);
			cs[as[0][i]] = i;
			tot += i - 1 - getsum(tmp, as[0][i]);
			add(tmp, as[0][i], 1, n);
		}
		build(1, 1, n, 1);
		int k;
		while (m--)
		{
			scanf("%d", &k);
			printf("%lld\n", tot);
			if (tot)
			{
				query(1, 1, n, 1, cs[k] - 1, k, 1, 0);
				query(1, 1, n, cs[k] + 1, n, k, 1, 1);
				update(1, 1, n, cs[k], k, 1);
			}
		}
	}
	return 0;
}
