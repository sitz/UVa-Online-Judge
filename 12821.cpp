#include <bits/stdc++.h>

using namespace std;

struct Node
{
	// x->y, v
	int x, y, cap, cost, nxt;
} edge[100005];
int e, head[505], dis[505], prev_[505], record[505], inq[505];

void add_edge(int x, int y, int cap, int cost)
{
	edge[e].x = x, edge[e].y = y, edge[e].cap = cap, edge[e].cost = cost;
	edge[e].nxt = head[x], head[x] = e++;
	edge[e].x = y, edge[e].y = x, edge[e].cap = 0, edge[e].cost = -cost;
	edge[e].nxt = head[y], head[y] = e++;
}

int min_cost(int s, int t)
{
	int mncost = 0, flow, totflow = 0;
	int i, x, y;
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
			for (i = head[x]; i != -1; i = edge[i].nxt)
			{
				y = edge[i].y;
				if (edge[i].cap > 0 && dis[y] > dis[x] + edge[i].cost)
				{
					dis[y] = dis[x] + edge[i].cost;
					prev_[y] = x, record[y] = i;
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
		for (x = t; x != s; x = prev_[x])
		{
			int ri = record[x];
			flow = min(flow, edge[ri].cap);
		}
		for (x = t; x != s; x = prev_[x])
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

int main()
{
	int n, m, t = 0;
	int x, y, d, a;
	while (scanf("%d %d", &n, &m) == 2)
	{
		e = 0;
		memset(head, -1, sizeof(head));
		int source = n + 1, sink = n + 2;
		for (int i = 0; i < m; i++)
		{
			scanf("%d %d %d %d", &x, &y, &d, &a);
			add_edge(x, y, 1, d);
			add_edge(x, y, 1, d + a);
		}
		add_edge(source, 1, 2, 0);
		add_edge(n, sink, 2, 0);
		printf("Case %d: %d\n", ++t, min_cost(source, sink));
	}
	return 0;
}
