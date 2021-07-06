#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int L;
const int maxn = 100 + 10;
const LL INF = (LL)1 << 62;

struct HeapNode
{
	int u;
	LL d;
	HeapNode(int u, LL d) : u(u), d(d) {}
	bool operator<(const HeapNode &rhs) const
	{
		return d > rhs.d;
	}
};

struct Edge
{
	int from, to, dist;
	Edge(int a, int b, int c) : from(a), to(b), dist(c) {}
};

struct Dijkstra
{
	int n;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	LL d[maxn];
	int p[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
		}
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back(Edge(from, to, dist));
		edges.push_back(Edge(to, from, dist));
		int m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	void dijkstra(int s, int td)
	{
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
		{
			d[i] = INF;
		}
		d[s] = 0;
		memset(done, 0, sizeof(done));
		memset(p, -1, sizeof(p));
		Q.push(HeapNode(s, 0));
		while (!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u])
			{
				continue;
			}
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (G[u][i] == td / 2 * 2 || G[u][i] == td / 2 * 2 + 1)
				{
					continue;
				}
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push(HeapNode(e.to, d[e.to]));
				}
			}
		}
	}
} p;

int td[maxn];
LL A[maxn];
LL S[maxn * 10][maxn];

int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m;
	while (scanf("%d%d%d", &n, &m, &L) != EOF)
	{
		p.init(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--, v--;
			p.AddEdge(u, v, w);
		}
		LL res = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				S[i][j] = -1;
			}
		for (int i = 0; i < n; i++)
		{
			p.dijkstra(i, -10);
			LL sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (p.d[j] == INF)
				{
					p.d[j] = L;
				}
				sum += p.d[j], td[j] = p.p[j];
			}
			//printf("i = %d %lld\n", i+1, sum);
			A[i] = sum;
			//printf("\n");
			res += sum;
			for (int j = 0; j < n; j++)
			{
				if (j == i || td[j] == -1)
				{
					continue;
				}
				LL s2 = 0;
				p.dijkstra(i, td[j]);
				for (int k = 0; k < n; k++)
				{
					if (p.d[k] == INF)
					{
						p.d[k] = L;
					}
					//printf("k = %d %lld\n", k, p.d[k]);
					s2 += p.d[k];
				}
				//printf("j = %d s2 - sum = %d\n", j+1, s2-sum);
				S[td[j] / 2][i] = s2;
				//printf("-->%d %d\n", i+1, td[j]/2+1);
			}
		}
		LL n_max = 0;
		for (int i = 0; i < m; i++)
		{
			LL sum = 0;
			for (int j = 0; j < n; j++)
			{
				if (S[i][j] == -1)
				{
					sum += A[j];
				}
				else
				{
					sum += S[i][j];
				}
			}
			n_max = max(n_max, sum);
		}
		printf("%lld %lld\n", res, n_max);
		//printf("----------\n");
	}
	return 0;
}
