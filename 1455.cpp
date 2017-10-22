#include <bits/stdc++.h>

using namespace std;

#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1

const int maxn = 1000002;

int sum[2][maxn << 2], add[2][maxn << 2];

struct FA
{
	int fa, u, d, size;
} f[maxn];

int find(int a)
{
	return f[a].fa = (a == f[a].fa ? a : find(f[a].fa));
}
int p[maxn];

void push_down(int rt, int flag)
{
	if (add[flag][rt])
	{
		add[flag][rt << 1] += add[flag][rt], add[flag][rt << 1 | 1] += add[flag][rt];
		sum[flag][rt << 1] += add[flag][rt], sum[flag][rt << 1 | 1] += add[flag][rt];
		add[flag][rt] = 0;
	}
}

void update(int a, int b, int flag, int c, int l, int r, int rt)
{
	if (a > b)
	{
		return;
	}
	if (a <= l && r <= b)
	{
		//		printf ( "sum[%d][%d]" );
		sum[flag][rt] += c;
		//    	printf ( "a = %d, b = %d, l = %d, r = %d, c = %d\n", a, b, l, r, c );
		add[flag][rt] += c;
		return;
	}
	push_down(rt, flag);
	int m = (l + r) >> 1;
	if (a <= m)
	{
		update(a, b, flag, c, lson);
	}
	if (m < b)
	{
		update(a, b, flag, c, rson);
	}
	sum[flag][rt] = sum[flag][rt << 1 | 1] + sum[flag][rt << 1];
}

int query(int a, int flag, int l, int r, int rt)
{
	if (l == r)
	{
		return sum[flag][rt];
	}
	push_down(rt, flag);
	int m = (l + r) >> 1, ret = 0;
	if (a <= m)
	{
		ret = query(a, flag, lson);
	}
	else
	{
		ret = query(a, flag, rson);
	}
	return ret;
}

char s[111];

int main()
{
	int n, i, j, k, cas, a, b, m, l, r, x, y;
	double c;
	scanf("%d", &cas);
	while (cas--)
	{
		scanf("%d", &n);
		for (i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			f[i].u = f[i].d = p[i] = b * 2;
			f[i].size = 1, f[i].fa = i;
			update(b, b, 0, 1, 0, maxn - 111, 1);
			update(b, b, 1, 1, 0, maxn - 111, 1);
		}
		memset(sum, 0, sizeof(sum));
		memset(add, 0, sizeof(add));
		scanf("%d", &m);
		while (m--)
		{
			scanf("%s", s);
			if (s[0] == 'l')
			{
				scanf("%lf", &c);
				c *= 2;
				printf("%d %d\n", query(c, 1, 0, maxn - 111, 1), query(c, 0, 0, maxn - 111, 1));
			}
			else
			{
				scanf("%d%d", &l, &r);
				x = find(l), y = find(r);
				if (x == y)
				{
					continue;
				}
				int u1 = f[x].u, u2 = f[y].u, d1 = f[x].d, d2 = f[y].d;
				//			printf ( "%d %d %d %d %d %d\n", x, y, u1, u2, d1, d2 );
				if (d1 > u2)
				{
					update(u2 + 1, u1, 0, f[y].size, 0, maxn - 111, 1);
					update(d2, d1 - 1, 0, f[x].size, 0, maxn - 111, 1);
					if (d1 > u2 + 1)
					{
						update(u2 + 1, d1 - 1, 1, 1, 0, maxn - 111, 1);
					}
				}
				else if (d2 > u1)
				{
					update(u1 + 1, u2, 0, f[x].size, 0, maxn - 111, 1);
					update(d1, d2 - 1, 0, f[y].size, 0, maxn - 111, 1);
					if (d2 > u1 + 1)
					{
						update(u1 + 1, d2 - 1, 1, 1, 0, maxn - 111, 1);
					}
				}
				else if (u2 >= d1 && u2 <= u1)
				{
					update(u2 + 1, u1, 0, f[y].size, 0, maxn - 111, 1);
					if (d2 < d1)
					{
						update(d2, d1 - 1, 0, f[x].size, 0, maxn - 111, 1);
					}
					else
					{
						update(d1, d2 - 1, 0, f[y].size, 0, maxn - 111, 1);
					}
					update(max(d1, d2), u2, 1, -1, 0, maxn - 111, 1);
				}
				else
				{
					update(u1 + 1, u2, 0, f[x].size, 0, maxn - 111, 1);
					if (d1 < d2)
					{
						update(d1, d2 - 1, 0, f[y].size, 0, maxn - 111, 1);
					}
					else
					{
						update(d2, d1 - 1, 0, f[x].size, 0, maxn - 111, 1);
					}
					update(max(d1, d2), u1, 1, -1, 0, maxn - 111, 1);
				}
				f[y].u = max(f[y].u, f[x].u);
				f[y].d = min(f[y].d, f[x].d);
				f[x].fa = y;
				f[y].size += f[x].size;
				//			printf ( "%d %d\n", query ( 9, 1, 0, maxn - 111, 1 ), query ( 9, 0, 0, maxn - 111, 1 ) );
			}
		}
	}
	return 0;
}
