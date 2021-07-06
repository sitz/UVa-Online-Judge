#include <bits/stdc++.h>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

int n, t, cnt[11];
struct Seg_tree
{

	short col[55555 << 2];

	inline void update(int a, int b, int c, int l, int r, int rt)
	{
		if (a <= l && r <= b)
		{
			col[rt] = c;
			return;
		}
		int m = (l + r) >> 1;
		if (col[rt])
		{
			col[rt << 1] = col[rt << 1 | 1] = col[rt], col[rt] = 0;
		}
		if (a <= m)
		{
			update(a, b, c, lson);
		}
		if (m < b)
		{
			update(a, b, c, rson);
		}
	}

	inline void query(int l, int r, int rt)
	{
		if (col[rt] != 0)
		{
			cnt[col[rt]] += r - l + 1;
			return;
		}
		if (l == r)
		{
			return;
		}
		int m = (l + r) >> 1;
		query(lson);
		query(rson);
	}

} tree[202];
char s[11];
inline int Abs(int x)
{
	return x >= 0 ? x : -x;
}

int main()
{
	int i, j, k, q, x, y, h, xc, yc, r, c, l, w;
	while (scanf("%d%d%d", &n, &t, &q) != EOF)
	{
		for (i = 0; i < n; i++)
			for (j = 0; j <= (t << 2); j++)
			{
				tree[i].col[j] = 0;
			}
		memset(cnt, 0, sizeof(cnt));
		while (q--)
		{
			scanf("%s", s);
			if (s[0] == 'R')
			{
				scanf("%d%d", &x, &y);
				scanf("%d%d%d", &w, &h, &c);
				if (w == 0 || h == 0)
				{
					continue;
				}
				for (i = x; i <= x + w - 1 && i < n; i++)
				{
					int r = min(y + h - 1, t - 1);
					tree[i].update(y, r, c, 0, t - 1, 1);
				}
			}
			else if (s[0] == 'D')
			{
				scanf("%d%d", &x, &y);
				scanf("%d%d", &w, &c);
				if (w == 0)
				{
					tree[x].update(y, y, c, 0, t - 1, 1);
					continue;
				}
				for (i = -w; i <= w; i++)
				{
					if (x + i < 0 || x + i >= n)
					{
						continue;
					}
					int l = max(0, y - w + Abs(i)), r = min(t - 1, y + w - Abs(i));
					tree[i + x].update(l, r, c, 0, t - 1, 1);
				}
			}
			else if (s[0] == 'T')
			{
				scanf("%d%d", &x, &y);
				scanf("%d%d", &w, &c);
				h = (w + 1) / 2;
				for (i = 0; i < h; i++)
				{
					if (x + i < 0 || x + i >= n)
					{
						continue;
					}
					int l = max(0, y - h + i + 1), r = min(t - 1, y + h - i - 1);
					r = min(r, t - 1);
					tree[i + x].update(l, r, c, 0, t - 1, 1);
				}
			}
			else
			{
				scanf("%d%d", &x, &y);
				scanf("%d%d", &w, &c);
				if (w == 0)
				{
					tree[x].update(y, y, c, 0, t - 1, 1);
					continue;
				}
				for (i = -w; i <= w; i++)
				{
					if (x + i < 0 || x + i >= n)
					{
						continue;
					}
					double h = sqrt(1.0 * w * w - 1.0 * i * i);
					int l = max(0, (int)ceil(y - h));
					int r = min(t - 1, (int)floor(y + h));
					tree[i + x].update(l, r, c, 0, t - 1, 1);
				}
			}
		}
		for (i = 0; i < n; i++)
		{
			tree[i].query(0, t - 1, 1);
		}
		for (i = 1; i <= 9; i++)
		{
			if (i != 1)
			{
				printf(" ");
			}
			printf("%d", cnt[i]);
		}
		puts("");
	}
}
