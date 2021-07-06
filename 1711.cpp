#include <bits/stdc++.h>

using namespace std;

const int MAXN = 400;
const int MAXM = 1048576;

struct Node
{
	int x, y, cap;
	long long cost;// x->y, v
	int next;
} edge[MAXM];

const long long INF = 1LL << 30;

class MinCost
{
public:
	int e, head[MAXN], pre[MAXN], record[MAXN], inq[MAXN];
	long long dis[MAXN];
	int n;
	void addedge(int x, int y, int cap, long long cost)
	{
		assert(e < MAXM);
		//    	printf("Edge %d %d cost %lld cap %d\n", x, y, cost, cap);
		edge[e].x = x, edge[e].y = y, edge[e].cap = cap, edge[e].cost = cost;
		edge[e].next = head[x], head[x] = e++;
		edge[e].x = y, edge[e].y = x, edge[e].cap = 0, edge[e].cost = -cost;
		edge[e].next = head[y], head[y] = e++;
	}
	pair<long long, int> mincost(int s, int t)
	{
		long long mncost = 0, oo = INF;
		int flow, totflow = 0;
		int i, x, y;
		while (1)
		{
			for (int i = 0; i < n; i++)
				dis[i] = INF;
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
								Q.push_front(y);
							else
								Q.push_back(y);
						}
					}
				}
			}
			if (dis[t] == oo)
				break;
			// this problem doesn't need full flow
			if (dis[t] >= 0)
				break;
			flow = 0x3f3f3f3f;
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
	void init(int n)
	{
		this->n = n;
		e = 0;
		for (int i = 0; i <= n; i++)
			head[i] = -1;
	}
} g;

int main()
{
	int N, K, c[105][105];
	while (scanf("%d%d", &N,&K) == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i + 1; j < N + 1; j++)
			{
				scanf("%d", &c[i][j]);
			}
		}

		int source = 2 * (N + 1), sink = 2 * (N + 1) + 1;
		g.init(2 * (N + 1) + 2);
		g.addedge(source, 0, K, 0);
		for (int i = 0; i < N + 1; i++)
		{
			g.addedge(2 * i + 1, sink, 1, 0);
			if (i)
				g.addedge(2 * i, 2 * i + 1, 1, -INF);
		}
		for (int i = 0; i < N + 1; i++)
		{
			for (int j = i + 1; j < N + 1; j++)
			{
				if (i == 0)
					g.addedge(2 * i, 2 * j, 1, c[i][j]);
				else
					g.addedge(2 * i + 1, 2 * j, 1, c[i][j]);
			}
		}

		pair<long long, int> ret = g.mincost(source, sink);
		printf("%lld\n", (ret.first % INF + INF) % INF);
	}
	return 0;
}
