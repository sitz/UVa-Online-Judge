#include <bits/stdc++.h>

using namespace std;

struct Point
{
	long long x, y, z;
	long long dis(Point a)
	{
		return (a.x - x) * (a.x - x) + (a.y - y) * (a.y - y) + (a.z - z) * (a.z - z);
	}
} po[600050];
pair<long long, long long> dis[600050];
long long tree[25][600050];
long long sorted[600050];
int toleft[25][600050];
void build(int l, int r, int dep)
{
	if (l == r)
		return;
	int mid = (l + r) >> 1;
	int same = mid - l + 1;
	for (int i = l; i <= r; i++)
		if (tree[dep][i] < sorted[mid])
			same--;
	int lpos = l;
	int rpos = mid + 1;
	for (int i = l; i <= r; i++)
	{
		if (tree[dep][i] < sorted[mid])
			tree[dep + 1][lpos++] = tree[dep][i];
		else if (tree[dep][i] == sorted[mid] && same > 0)
			tree[dep + 1][lpos++] = tree[dep][i], same--;
		else
			tree[dep + 1][rpos++] = tree[dep][i];
		toleft[dep][i] = toleft[dep][l - 1] + lpos - l;
	}
	build(l, mid, dep + 1);
	build(mid + 1, r, dep + 1);
}
inline long long query(int L, int R, int l, int r, int dep, int k)
{
	if (l == r)
		return tree[dep][l];
	int mid = (L + R) >> 1;
	int cnt = toleft[dep][r] - toleft[dep][l - 1];
	if (cnt >= k)
	{
		int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
		int newr = newl + cnt - 1;
		return query(L, mid, newl, newr, dep + 1, k);
	}
	else
	{
		int newr = r + toleft[dep][R] - toleft[dep][r];
		int newl = newr - (r - l - cnt);
		return query(mid + 1, R, newl, newr, dep + 1, k - cnt);
	}
}
int p1[600050], p2[600050];
long long sa1[600050], sa2[600050], temp[600050];
long long sb[600050];
int n, k1, k2;
inline int cro(long long x, long long y)
{
	int ed = upper_bound(sb + 1, sb + n + 1, x) - sb - 1;
	int l = 0, r = ed - 1, mid;
	while (l < r)
	{
		mid = (l + r + 1) >> 1;
		if (query(1, n - 1, 2, ed, 0, mid) <= y)
			l = mid;
		else
			r = mid - 1;
	}
	return l;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld%lld", &po[i].x, &po[i].y, &po[i].z);
	for (int i = 2; i < n; i++)
		dis[i] = make_pair(po[0].dis(po[i]), po[1].dis(po[i]));
	sort(dis + 2, dis + n);
	for (int i = 2; i < n; i++)
		sorted[i] = tree[0][i] = sa2[i] = dis[i].second, sa1[i] = sb[i] = dis[i].first;
	sb[n] = sa1[n] = sa2[n] = (1ll << 60);
	sort(sa2 + 2, sa2 + n);
	sb[1] = sa2[1] = sa1[1] = 0.0;
	sorted[1] = tree[0][1] = 0.0;
	sort(sorted + 1, sorted + n);
	build(1, n - 1, 0);
	k1 = k2 = 1;
	for (int i = 2; i < n; i++)
	{
		while (sa1[i] == sa1[i + 1])
			i++, p1[k1]++;
		p1[k1] += p1[k1 - 1] + 1;
		temp[k1++] = sa1[i];
	}
	for (int i = 0; i < k1; i++)
		sa1[i] = temp[i];
	for (int i = 2; i < n; i++)
	{
		while (sa2[i] == sa2[i + 1])
			i++, p2[k2]++;
		p2[k2] += p2[k2 - 1] + 1;
		temp[k2++] = sa2[i];
	}
	for (int i = 0; i < k2; i++)
		sa2[i] = temp[i];
	sa1[k1++] = sa2[k2++] = (1ll << 60);
	int q, ss, bb;
	scanf("%d", &q);
	long long x, y;
	while (q--)
	{
		scanf("%lld%lld", &x, &y);
		x *= x;
		y *= y;
		ss = p1[upper_bound(sa1, sa1 + k1, x) - sa1 - 1];
		bb = p2[upper_bound(sa2, sa2 + k2, y) - sa2 - 1];
		printf("%d\n", ss + bb - cro(x, y));
	}
	return 0;
}
