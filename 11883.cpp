#include <bits/stdc++.h>

using namespace std;

#define M 1005
#define oo 1000000000
struct node
{
	int from, to, next;
	double v, a;
} edge[M];
int head[M], tot;
int mark[M];
int Q[M * 10];
double dis[2][M];
void add(int a, int b, double c, double d)
{
	edge[tot].from = a, edge[tot].to = b, edge[tot].v = c;
	edge[tot].a = d, edge[tot].next = head[a], head[a] = tot++;
}
int Min(int a, int b)
{
	return (a > b ? b : a);
}
// Shortest Path Faster Algorithm
void SPFA(int k, int x, int n)
{
	int L, H, i, y;
	L = H = 0;
	for (i = 1; i <= n; i++)
	{
		dis[k][i] = oo;
		mark[i] = 0;
	}
	dis[k][x] = 0;
	Q[H++] = x;
	while (L < H)
	{
		x = Q[L++];
		mark[x] = 0;
		for (i = head[x]; i != -1; i = edge[i].next)
		{
			y = edge[i].to;
			if (dis[k][y] > dis[k][x] + edge[i].v)
			{
				dis[k][y] = dis[k][x] + edge[i].v;
				if (!mark[y])
				{
					mark[y] = 1;
					Q[H++] = y;
				}
			}
		}
	}
}
double get(double v, double a, double t)
{
	if (a == 1)
	{
		return v;
	}
	else
	{
		double b = 1.0 / (v * log(a));
		double x = -log(b) / log(a) - t;
		//printf("%lf %lf %lf %lf\n",v,a,t,x);
		if (x < 0)
		{
			x = 0;
		}
		return v * pow(a, -(t + x)) + x;
	}
}
int main()
{
	int n, m, i, j;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		if (n == 0)
		{
			break;
		}
		for (i = 1; i <= n; i++)
		{
			head[i] = -1;
		}
		tot = 0;
		int x, y;
		double v, a;
		while (m-- && scanf("%d %d %lf %lf", &x, &y, &v, &a))
		{
			add(x, y, v, a);
			add(y, x, v, a);
		}
		SPFA(0, 1, n);
		SPFA(1, n, n);
		double ans = oo;
		for (i = 0; i < tot; i++)
		{
			double tmp = dis[0][edge[i].from] + dis[1][edge[i].to];
			tmp += get(edge[i].v, edge[i].a, dis[0][edge[i].from]);
			if (tmp < ans)
			{
				ans = tmp;
			}
		}
		printf("%.3lf\n", ans);
	}
	return 0;
}
