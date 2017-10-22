#include <bits/stdc++.h>

using namespace std;

typedef int lld;

const int maxn = 1100, maxm = 6000 * 2;
const int maxl = 999999999;

struct Edge
{
	int y;
	int ne;
} e[maxm];
int ee;
int st[maxn];
int n;
int du[maxn];
void addedge(int x, int y)
{
	e[ee].y = y;
	e[ee].ne = st[x];
	st[x] = ee++;
	e[ee].y = x;
	e[ee].ne = st[y];
	st[y] = ee++;
	du[x]++;
	du[y]++;
}
int c[maxn], que[maxn];
int head, tail;
lld bfs(int sx)
{
	int i, j, k;
	int tot = 0;
	memset(c, -1, sizeof(c));
	c[sx] = 0;
	head = 0;
	tail = 1;
	que[0] = sx;
	while (head < tail)
	{
		k = que[head++];
		for (i = st[k]; i != -1; i = e[i].ne)
			if (c[e[i].y] == -1)
			{
				c[e[i].y] = c[k] + 1;
				que[tail++] = e[i].y;
				tot += c[k] + 1;
			}
	}
	return tot;
}
int num(int k)
{
	int tot = 0;
	while (k)
	{
		tot += k & 1;
		k >>= 1;
	}
	return tot;
}
int main()
{
	int m, i, j;
	while (scanf("%d%d", &n, &m), n)
	{
		memset(st, -1, sizeof(st));
		memset(du, 0, sizeof(du));
		ee = 0;
		while (m--)
		{
			scanf("%d%d", &i, &j);
			addedge(i, j);
		}
		lld tot = 0;
		if (num(n) != 1)
		{
			puts("NO");
			continue;
		}
		for (i = 0; i < n; i++)
			if (du[i] != du[0])
			{
				break;
			}
		if (i < n)
		{
			puts("NO");
			continue;
		}
		for (i = 0; i < n; i++)
		{
			tot += bfs(i);
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				tot -= num(i ^ j);
			}
		if (tot)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}
