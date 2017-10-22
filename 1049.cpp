#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define sz(x) ((x).size())

const int N = 510;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;

struct CostFlow
{
	struct node
	{
		int from, to, next, cap;
		double w;
	} edge[N * N];
	int box[N], ecnt;

	void _make_edge(int from, int to, int cap, double w)
	{
		edge[ecnt].w = w;
		edge[ecnt].to = to;
		edge[ecnt].cap = cap;
		edge[ecnt].from = from;
		edge[ecnt].next = box[from];
		box[from] = ecnt++;
	}
	void make_edge(int from, int to, int cap, double w)
	{
		//cout << from << " " << to << " " << cap << " " << w << endl;
		_make_edge(from, to, cap, w);
		_make_edge(to, from, 0, -w);
	}

	int pre[N];
	double dis[N];
	bool vis[N];

	bool spfa(int s, int t)
	{
		queue<int> que;
		memset(vis, 0, sizeof(vis));
		memset(pre, -1, sizeof(pre));
		for (int i = 0; i < N; i++)
		{
			dis[i] = 1e100;
		}
		que.push(s);
		vis[s] = 1;
		dis[s] = 0;
		while (que.size())
		{
			int u = que.front();
			que.pop();
			vis[u] = 0;
			//cout << u << " " << dis[u] << " tt" << endl;
			for (int i = box[u]; i + 1; i = edge[i].next)
			{
				if (!edge[i].cap)
				{
					continue;
				}
				int v = edge[i].to;
				double w = edge[i].w;
				if (dis[v] - eps <= dis[u] + w)
				{
					continue;
				}
				dis[v] = dis[u] + w;
				pre[v] = i;
				if (vis[v])
				{
					continue;
				}
				vis[v] = 1;
				que.push(v);
			}
		}
		return dis[t] < 1e100;
	}

	double min_cost(int s, int t)
	{
		double ans = 0;
		int flow = inf;
		while (spfa(s, t))
		{
			flow = inf;
			for (int i = pre[t]; i + 1; i = pre[edge[i].from])
			{
				if (flow > edge[i].cap)
				{
					flow = edge[i].cap;
				}
			}
			for (int i = pre[t]; i + 1; i = pre[edge[i].from])
			{
				edge[i].cap -= flow;
				edge[i ^ 1].cap += flow;
			}
			ans += flow * dis[t];
		}
		return ans;
	}

	void clear()
	{
		ecnt = 0;
		memset(box, -1, sizeof(box));
	}
};

int a[N], b[N];
double w[N][N];

CostFlow cf;

int main()
{
	int n, m, ca = 0;
	while (scanf("%d%d", &n, &m), n + m)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
		}
		for (int i = 1; i <= m; i++)
		{
			scanf("%d", b + i);
		}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				scanf("%lf", w[i] + j);
			}
		cf.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (w[i][j] < 0)
				{
					continue;
				}
				cf.make_edge(i, j + n, inf, w[i][j]);
			}
		for (int i = 1; i <= n; i++)
		{
			cf.make_edge(0, i, a[i], 0);
		}
		for (int i = 1; i <= m; i++)
		{
			cf.make_edge(i + n, m + n + 1, b[i], 0);
		}
		double mn = cf.min_cost(0, 1 + n + m);
		cf.clear();
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (w[i][j] < 0)
				{
					continue;
				}
				cf.make_edge(i, j + n, inf, -w[i][j]);
			}
		for (int i = 1; i <= n; i++)
		{
			cf.make_edge(0, i, a[i], 0);
		}
		for (int i = 1; i <= m; i++)
		{
			cf.make_edge(i + n, m + n + 1, b[i], 0);
		}
		double mx = -cf.min_cost(0, 1 + n + m);
		printf("Problem %d: %.2f to %.2f\n", ++ca, mn, mx);
	}
	return 0;
}
