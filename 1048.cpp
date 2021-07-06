#include <bits/stdc++.h>

using namespace std;

#define inf 1 << 28
#define maxn 4000

vector<int> ticket[25];
vector<int> trip;
map<int, int> city;
int cost[25], n, cnt;

struct Edge
{
	int from, to, dist;
	int id;
	Edge(int from_, int to_, int dis_, int iid)
	{
		from = from_;
		to = to_;
		dist = dis_;
		id = iid;
	}
};
struct HeapNode
{
	int d, u;
	HeapNode(int d_, int u_)
	{
		d = d_;
		u = u_;
	}
	bool operator<(const HeapNode &rhs) const
	{
		return d > rhs.d;
	}
};
struct Dijkstra
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n_)
	{
		int i;
		n = n_;
		for (i = 0; i <= n; i++)
		{
			G[i].clear();
		}
		edges.clear();
	}

	void addedge(int from, int to, int dist, int id)
	{
		edges.push_back(Edge(from, to, dist, id));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s, int t)
	{
		int i;
		priority_queue<HeapNode> q;
		for (i = 0; i <= n; i++)
		{
			d[i] = inf;
		}
		d[s] = 0;
		memset(done, 0, sizeof(done));
		q.push(HeapNode(0, s));
		while (!q.empty())
		{
			HeapNode x = q.top();
			q.pop();
			int u = x.u;
			if (done[u])
			{
				continue;
			}
			done[u] = true;
			for (i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];//最短路的上一条边
					q.push(HeapNode(d[e.to], e.to));
				}
			}
		}
		stack<int> st;
		int cur = t;
		while (cur != s)
		{
			st.push(edges[p[cur]].id);
			cur = edges[p[cur]].from;
		}
		printf("%d\n", d[t]);
		printf("  Tickets used: ");
		while (!st.empty())
		{
			printf("%d", st.top() + 1);
			st.pop();
			if (st.empty())
				printf("\n");
			else
				printf(" ");
		}
	}
};

Dijkstra solver;
void init()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		ticket[i].clear();
	}
	city.clear();
	cnt = 0;
}

int main()
{
	int i, j, k, test = 0;
	while (scanf("%d", &n) == 1 && n)
	{
		init();
		int m;
		for (i = 0; i < n; i++)
		{
			scanf("%d", &cost[i]);
			scanf("%d", &m);
			while (m--)
			{
				int temp;
				scanf("%d", &temp);
				if (city.find(temp) == city.end())
					city[temp] = cnt++;
				ticket[i].push_back(city[temp]);
			}
		}
		scanf("%d", &m);
		int ts = 0;
		while (m--)
		{
			trip.clear();
			int tn;
			scanf("%d", &tn);
			while (tn--)
			{
				int temp;
				scanf("%d", &temp);
				trip.push_back(city[temp]);
			}
			solver.init(5000);
			for (i = 0; i < trip.size(); i++)
			{
				int vis;
				for (j = 0; j < n; j++)
				{
					vis = i + 1;
					for (k = 1; k < ticket[j].size(); k++)
					{
						if (vis < trip.size() && trip[vis] == ticket[j][k])
							vis++;
						solver.addedge(12 * ticket[j][0] + i + 1, 12 * ticket[j][k] + vis, cost[j], j);
					}
				}
			}
			printf("Case %d, Trip %d: Cost = ", test + 1, ++ts);
			solver.dijkstra(12 * trip[0] + 1, 12 * trip[trip.size() - 1] + trip.size());
		}
		test++;
	}
	return 0;
}
