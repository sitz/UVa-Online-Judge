#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;
struct point
{
	int x, y;
};
point c[MAX];
int m;
long long crossProduct(point a, point b, point c)//向量 ac 在 ab 的方向
{
	return (c.x - a.x * 1ll) * (b.y - a.y) - (b.x - a.x * 1ll) * (c.y - a.y);
}
long long disp2p(point a, point b)
{
	return (a.x - b.x * 1ll) * (a.x - b.x) + (a.y - b.y * 1ll) * (a.y - b.y);
}
bool cmp1(point a, point b)// 排序
{
	long long len = crossProduct(c[0], a, b);
	if (len == 0)
	{
		return disp2p(c[0], a) < disp2p(c[0], b);
	}
	return len < 0;
}
bool cmp2(point a, point b)
{
	long long len = crossProduct(c[0], a, b);
	if (len == 0)
	{
		return disp2p(c[0], a) > disp2p(c[0], b);
	}
	return len < 0;
}
void output(point *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", p[i].x, p[i].y);
	}
}
void solve()
{
	int tmp = 0;
	for (int i = 1; i < m; i++)
		if (c[i].x < c[tmp].x || c[i].x == c[tmp].x && c[i].y < c[tmp].y)
		{
			tmp = i;
		}
	swap(c[0], c[tmp]);
	point L[MAX], U[MAX];
	int l = 0, u = 0;
	for (int i = 1; i < m; i++)
		if (c[i].y <= c[0].y)
		{
			L[l++] = c[i];
		}
		else
		{
			U[u++] = c[i];
		}
	sort(L, L + l, cmp1);
	sort(U, U + u, cmp2);
	printf("%d\n", m);
	printf("%d %d\n", c[0].x, c[0].y);
	output(L, l);
	output(U, u);
}
int main()
{
	int ncases, n;
	int x, y;
	char ch;
	scanf("%d", &ncases);
	while (ncases--)
	{
		scanf("%d", &n);
		m = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %c", &x, &y, &ch);
			if (ch == 'Y')
			{
				c[m].x = x;
				c[m++].y = y;
			}
		}
		solve();
	}
	return 0;
}
