#include <bits/stdc++.h>

using namespace std;

#define N 1005
#define INF (1 << 30)
#define LL long long
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define sqr(x) ((x) * (x))

struct node
{
	int v, w;
	bool operator<(const node &a) const
	{
		return w > a.w;
	}
};
struct Point
{
	int u, v, w;
} ed[N * N * 4];
int n, m, s, num;
int ma[N][N], dis[N], use[N];
priority_queue<node> que;
void init()
{
	int i, j, t;
	scanf("%d%d%d", &n, &m, &s);
	num = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			ma[i][j] = INF;
		}
	for (int k = 0; k < m; k++)
	{
		scanf("%d%d%d", &i, &j, &t);
		ed[num].u = i;
		ed[num].v = j;
		ed[num++].w = t;
		if (ma[i][j] > t)
		{
			ma[i][j] = ma[j][i] = t;
		}
	}
}
void dijstra()
{
	int i, j, k;
	double ans, tmp;
	node p;
	for (i = 0; i < n; i++)
	{
		dis[i] = ma[s][i];
		p.v = i;
		p.w = dis[i];
		if (dis[i] != INF)
		{
			que.push(p);
		}
		use[i] = 0;
	}
	dis[s] = 0;
	use[s] = 1;
	p.v = s;
	p.w = 0;
	que.push(p);
	while (!que.empty())
	{
		p = que.top();
		que.pop();
		use[p.v] = 1;
		k = p.v;
		for (j = 0; j < n; j++)
			if (!use[j] && dis[k] + ma[k][j] < dis[j])
			{
				dis[j] = dis[k] + ma[k][j];
				p.v = j;
				p.w = dis[j];
				que.push(p);
			}
	}
	for (i = 0; i < n; i++)
		if (dis[i] == INF)
		{
			printf("Sorry Amoo, your domino does not complete!\n");
			return;
		}
	ans = 0;
	for (i = 0; i < m; i++)
	{
		j = abs(dis[ed[i].v] - dis[ed[i].u]);
		j = ed[i].w - j;
		if (j < 0)
		{
			tmp = MAX(dis[ed[i].v], dis[ed[i].u]);
		}
		else
		{
			tmp = j;
			tmp /= 2.0;
			tmp += MAX(dis[ed[i].v], dis[ed[i].u]);
		}
		if (tmp > ans)
		{
			ans = tmp;
		}
	}
	printf("%.2lf\n", ans + 0.001);
}
int main()
{
	int ca;
	scanf("%d", &ca);
	while (ca--)
	{
		init();
		dijstra();
	}
	return 0;
}
