#include <bits/stdc++.h>

using namespace std;

#define MAXN 2048
#define MAXM 1048576

struct Node
{
	int x, y, cap;
	double cost;// x->y, v
	int next;
} edge[MAXM];

struct MinCost
{
	const int INF = 0x3f3f3f3f;

	int e, n, head[MAXN], dis[MAXN], pre[MAXN], record[MAXN], inq[MAXN];

	void init(int n)
	{
		this->n = n;
		e = 0;
		for (int i = 0; i <= n; i++)
		{
			head[i] = -1;
		}
	}

	void add_edge(int x, int y, int cap, int cost)
	{
		edge[e].x = x;
		edge[e].y = y;
		edge[e].cap = cap;
		edge[e].cost = cost;
		edge[e].next = head[x];
		head[x] = e++;
		edge[e].x = y;
		edge[e].y = x;
		edge[e].cap = 0;
		edge[e].cost = -cost;
		edge[e].next = head[y];
		head[y] = e++;
	}

	pair<int, int> mincost(int s, int t)
	{
		int mncost = 0, flow, totflow = 0, i, x, y;
		while (1)
		{
			for (int i = 0; i < n; i++)
			{
				dis[i] = INF;
			}
			int oo = dis[0];
			dis[s] = 0;
			deque<int> Q;
			Q.push_front(s);
			while (!Q.empty())
			{
				x = Q.front();
				Q.pop_front();
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
			flow = INF;
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
		return make_pair(mncost, totflow);
	}
} g;

int main()
{
	int N, M, K, u, v, a, c;
	while (scanf("%d%d%d", &N, &M, &K) == 3)
	{
		g.init(N + 1);
		int src = 0, sink = N;
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d%d", &u, &v, &a, &c);
			for (int j = 1; j <= c; j++)
			{
				g.add_edge(u, v, 1, a * (j * j - (j - 1) * (j - 1)));
			}
		}
		g.add_edge(src, 1, K, 0);
		pair<int, int> ret = g.mincost(src, sink);
		printf("%d\n", ret.second == K ? ret.first : -1);
	}
	return 0;
}
