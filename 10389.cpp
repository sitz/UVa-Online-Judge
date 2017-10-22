#include <bits/stdc++.h>

using namespace std;

const int Max = 205;
const double inf = 999999999;

struct tag_nodes
{
	int x, y;
} the_nodes[Max];
int cc, m, n, i, j;
double d, edge[Max][Max], dis[Max];
bool vis[Max];
char buf[3];
void init_data()
{
	vis[0] = true;
	for (int i = 1; i < n; i++)
	{
		dis[i] = inf;
	}
}
double dijkstra()
{
	init_data();
	int now = 0, count = n - 1;
	while (count--)
	{
		int k;
		double min_dis = inf;
		for (int i = 1; i < n; ++i)
			if (!vis[i])
			{
				if (dis[i] > dis[now] + edge[now][i])
				{
					dis[i] = dis[now] + edge[now][i];
				}
				if (min_dis > dis[i])
				{
					min_dis = dis[k = i];
				}
			}
		if (k == 1)
		{
			break;
		}
		now = k;
		vis[k] = true;
	}
	return dis[1];
}
double math_dis(int i, int j)
{
	int a = (the_nodes[i].x - the_nodes[j].x) * (the_nodes[i].x - the_nodes[j].x);
	int b = (the_nodes[i].y - the_nodes[j].y) * (the_nodes[i].y - the_nodes[j].y);
	return sqrt(1.0 * a + b);
}

int main()
{
	scanf("%d", &cc);
	while (cc--)
	{
		for (i = 0; i < Max; ++i)
		{
			the_nodes[i].x = 0;
			the_nodes[i].y = 0;
		}
		for (i = 0; i < Max; ++i)
			for (j = 0; j < Max; ++j)
			{
				edge[i][j] = 0.0;
			}
		for (i = 0; i < Max; ++i)
		{
			vis[i] = false;
		}
		scanf("%d%d%d%d", &the_nodes[0].x, &the_nodes[0].y, &the_nodes[1].x, &the_nodes[1].y);
		n = m = 2;
		while (scanf("%d%d", &the_nodes[n].x, &the_nodes[n].y) == 2)
		{
			if (the_nodes[n].x == -1 && the_nodes[n].y == -1)
			{
				m = n;
				scanf("%2[\n]", buf);
				if (buf[1] != '\0')
				{
					break;
				}
				else
				{
					continue;
				}
			}
			if (m != n)
			{
				d = math_dis(n, n - 1);
				edge[n][n - 1] = edge[n - 1][n] = 3 * d / 2000;
			}
			n++;
		}
		for (i = 0; i < n; ++i)
			for (j = i + 1; j < n; ++j)
			{
				if (edge[i][j] == 0)
				{
					d = math_dis(i, j);
					edge[i][j] = edge[j][i] = 3 * d / 500;
				}
			}
		printf("%.0lf\n", dijkstra());
		if (cc > 0)
		{
			printf("\n");
		}
	}
	return 0;
}
