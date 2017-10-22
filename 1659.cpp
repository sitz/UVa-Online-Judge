#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8
struct Node
{
	int x, y, cap;
	double cost;// x->y, v
	int next;
} edge[1000005];
int e, head[600], prev_[600], record[600], inq[600];
double dis[600];
void addEdge(int x, int y, int cap, double cost)
{
	edge[e].x = x, edge[e].y = y, edge[e].cap = cap, edge[e].cost = cost;
	edge[e].next = head[x], head[x] = e++;
	edge[e].x = y, edge[e].y = x, edge[e].cap = 0, edge[e].cost = -cost;
	edge[e].next = head[y], head[y] = e++;
}
double mincost(int s, int t, int n)
{
	double mncost = 0;
	int flow, totflow = 0;
	int i, x, y;
	double oo = 1e+30;
	while (1)
	{
		for (int i = 0; i <= n; i++)
			dis[i] = oo;
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
					prev_[y] = x, record[y] = i;
					if (inq[y] == 0)
					{
						inq[y] = 1;
						if (Q.size() && dis[Q.front()] > dis[y])
							Q.push_front(y);
						else
							Q.push_back(y);
					}
				}
			}
		}
		if (dis[t] == oo)
			break;
		flow = 0x3f3f3f3f;
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
	int cases = 0;
	int N, X, Y;
	int x[128], y[128], u;
	while (scanf("%d %d %d", &N, &X, &Y) == 3 && N)
	{
		vector<int> g[128];
		for (int i = 1; i <= N; i++)
		{
			scanf("%d %d", &x[i], &y[i]);
			while (scanf("%d", &u) == 1 && u)
				g[i].push_back(u);
		}

		e = 0;
		memset(head, -1, sizeof(head));
		int deg[128] = {};
		double sumCost = 0;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 0; j < g[i].size(); j++)
			{
				u = g[i][j];
				double d = hypot(x[i] - x[u], y[i] - y[u]);
				double cost = d * X - Y;
				if (cost < 0)
				{
					addEdge(u, i, 1, -cost);
				}
				else
				{
					sumCost += cost;
					addEdge(i, u, 1, cost);
					deg[u]--, deg[i]++;
				}
			}
		}
		int source = 0, sink = N + 1;
		for (int i = 1; i <= N; i++)
		{
			if (deg[i] > 0)
				addEdge(source, i, deg[i], 0);
			if (deg[i] < 0)
				addEdge(i, sink, -deg[i], 0);
		}
		double mncost = mincost(source, sink, N + 1);
		printf("Case %d: %.2lf\n", ++cases, sumCost - mncost + eps);
	}
	return 0;
}
