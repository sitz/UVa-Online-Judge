#include <bits/stdc++.h>

using namespace std;

#define MAXN 2048
#define MAXM 1048576

struct Node
{
	int x, y, cap, cost;// x->y, v
	int next;
} edge[MAXM];

struct MinCost
{
	int e, head[MAXN], dis[MAXN], pre[MAXN], record[MAXN], inq[MAXN];

	void init(int n)
	{
		e = 0;
		for (int i = 0; i <= n; i++)
		{
			head[i] = -1;
		}
	}

	void add_edge(int x, int y, int cap, int cost)
	{
		edge[e].x = x, edge[e].y = y, edge[e].cap = cap, edge[e].cost = cost;
		edge[e].next = head[x], head[x] = e++;
		edge[e].x = y, edge[e].y = x, edge[e].cap = 0, edge[e].cost = -cost;
		edge[e].next = head[y], head[y] = e++;
	}

	int min_cost(int s, int t)
	{
		int mncost = 0, flow, totflow = 0, i, x, y;
		while (1)
		{
			memset(dis, 63, sizeof(dis));
			int oo = dis[0];
			dis[s] = 0;
			deque<int> Q;
			Q.push_front(s);
			while (!Q.empty())
			{
				x = Q.front(), Q.pop_front();
				inq[x] = 0;
				for (i = head[x]; i != -1; i = edge[i].next)
				{
					y = edge[i].y;
					if (edge[i].cap > 0 && dis[y] > dis[x] + edge[i].cost)
					{
						dis[y] = dis[x] + edge[i].cost;
						pre[y] = x, record[y] = i;
						if (inq[y] == 0)
						{
							inq[y] = 1;
							if (Q.size() && dis[Q.front()] > dis[y])
							{
								Q.push_front(y);
							}
							else
							{
								Q.push_back(y);
							}
						}
					}
				}
			}
			if (dis[t] == oo)
			{
				break;
			}
			flow = oo;
			for (x = t; x != s; x = pre[x])
			{
				int ri = record[x];
				flow = min(flow, edge[ri].cap);
			}
			for (x = t; x != s; x = pre[x])
			{
				int ri = record[x];
				edge[ri].cap -= flow;
				edge[ri ^ 1].cap += flow;
				edge[ri ^ 1].cost = -edge[ri].cost;
			}
			totflow += flow;
			mncost += dis[t] * flow;
		}
		return mncost;
	}
} g;

int main()
{
	int n, m, x, y, v;
	while (scanf("%d%d", &n, &m) == 2)
	{
		g.init(2 * n + 2);
		int src = 2 * n, sink = 2 * n + 1;
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &x, &y, &v);
			x--, y--;
			g.add_edge(2 * x + 1, 2 * y, 1, v);
		}
		for (int i = 0; i < n; i++)
		{
			g.add_edge(2 * i, 2 * i + 1, 1, 0);
		}
		g.add_edge(src, 1, 2, 0);
		g.add_edge(2 * (n - 1), sink, 2, 0);
		int min_cost = g.min_cost(src, sink);
		printf("%d\n", min_cost);
	}
	return 0;
}
