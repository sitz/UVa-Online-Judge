#include <bits/stdc++.h>

using namespace std;

#define MAXK 11
#define MAXD 60010
int N, K, M, len[4 * MAXD][MAXK], cnt[4 * MAXD], ty[MAXD];
struct Seg
{
	int x, y1, y2, col;
} seg[MAXD];
int cmpint(const void *_p, const void *_q)
{
	int *p = (int *)_p, *q = (int *)_q;
	return *p < *q ? -1 : 1;
}
int cmps(const void *_p, const void *_q)
{
	Seg *p = (Seg *)_p, *q = (Seg *)_q;
	return p->x < q->x ? -1 : 1;
}
void build(int cur, int x, int y)
{
	int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
	memset(len[cur], 0, sizeof(len[cur]));
	len[cur][0] = ty[y + 1] - ty[x];
	cnt[cur] = 0;
	if (x == y)
	{
		return;
	}
	build(ls, x, mid);
	build(rs, mid + 1, y);
}
void init()
{
	int i, j, k, x1, y1, x2, y2;
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++)
	{
		j = i << 1, k = (i << 1) | 1;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		++x2, ++y2;
		seg[j].x = x1, seg[k].x = x2;
		seg[j].y1 = seg[k].y1 = y1, seg[j].y2 = seg[k].y2 = y2;
		seg[j].col = 1, seg[k].col = -1;
		ty[j] = y1, ty[k] = y2;
	}
	qsort(ty, N << 1, sizeof(ty[0]), cmpint);
	M = -1;
	for (i = 0; i < (N << 1); i++)
		if (i == 0 || ty[i] != ty[i - 1])
		{
			ty[++M] = ty[i];
		}
	build(1, 0, M - 1);
}
int BS(int x)
{
	int mid, min = 0, max = M + 1;
	for (;;)
	{
		mid = (min + max) >> 1;
		if (mid == min)
		{
			break;
		}
		if (ty[mid] <= x)
		{
			min = mid;
		}
		else
		{
			max = mid;
		}
	}
	return mid;
}
void update(int cur, int x, int y)
{
	int ls = cur << 1, rs = (cur << 1) | 1;
	memset(len[cur], 0, sizeof(len[cur]));
	if (cnt[cur] >= K)
	{
		len[cur][K] = ty[y + 1] - ty[x];
	}
	else if (x == y)
	{
		len[cur][cnt[cur]] = ty[y + 1] - ty[x];
	}
	else
	{
		int i;
		for (i = cnt[cur]; i <= K; i++)
		{
			len[cur][i] += len[ls][i - cnt[cur]] + len[rs][i - cnt[cur]];
		}
		for (i = K - cnt[cur] + 1; i <= K; i++)
		{
			len[cur][K] += len[ls][i] + len[rs][i];
		}
	}
}
void refresh(int cur, int x, int y, int s, int t, int c)
{
	int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
	if (x >= s && y <= t)
	{
		cnt[cur] += c;
		update(cur, x, y);
		return;
	}
	if (mid >= s)
	{
		refresh(ls, x, mid, s, t, c);
	}
	if (mid + 1 <= t)
	{
		refresh(rs, mid + 1, y, s, t, c);
	}
	update(cur, x, y);
}
void solve()
{
	int i, j, k;
	long long int ans = 0;
	qsort(seg, N << 1, sizeof(seg[0]), cmps);
	seg[N << 1].x = seg[(N << 1) - 1].x;
	for (i = 0; i < (N << 1); i++)
	{
		j = BS(seg[i].y1), k = BS(seg[i].y2);
		refresh(1, 0, M - 1, j, k - 1, seg[i].col);
		ans += (long long int)len[1][K] * (seg[i + 1].x - seg[i].x);
	}
	printf("%lld\n", ans);
}
int main()
{
	int t, tt;
	scanf("%d", &t);
	for (tt = 0; tt < t; tt++)
	{
		init();
		printf("Case %d: ", tt + 1);
		solve();
	}
	return 0;
}
