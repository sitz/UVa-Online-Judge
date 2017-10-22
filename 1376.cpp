#include <bits/stdc++.h>

using namespace std;

// LA3661 Animal Runï¼å¦ä¸ç§å»ºæ¨¡æ¹æ³ï¼ä¹¦ä¸ä½¿ç¨çæ¹æ³ï¼ï¼å¾çç»ç¹è¾å¤ï¼éåº¦è¾æ¢
// Rujia Liu

const int INF = 1000000000;
const int maxn = 3000000 + 10;

struct Edge
{
	int from, to, dist;
};

struct HeapNode
{
	int d, u;
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
	bool done[maxn];// æ¯å¦å·²æ°¸ä¹æ å·
	int d[maxn];		// så°åä¸ªç¹çè·ç¦»
	int p[maxn];		// æç­è·¯ä¸­çä¸ä¸æ¡å¼§

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
			d[i] = INF;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode){0, s});
		while (!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode){d[e.to], e.to});
				}
			}
		}
	}
};

//////// é¢ç®ç¸å³
#define REP(i, n) for (int i = 0; i < (n); ++i)

int n, m;
int ID(int r, int c, int type) { return type * n * m + r * m + c + 1; }

const int maxsize = 1000;
int cost[maxsize][maxsize][3];

Dijkstra solver;

void AddTriangleEdges(int *s1, int *s2, int *s3)
{
	int *edges[3] = {s1, s2, s3};
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (i != j)
			{
				int id1 = ID(edges[i][0], edges[i][1], edges[i][2]);
				int id2 = ID(edges[j][0], edges[j][1], edges[j][2]);
				int c = cost[edges[j][0]][edges[j][1]][edges[j][2]];
				solver.AddEdge(id1, id2, c);
			}
}

int main()
{
	int kase = 0;
	while (scanf("%d%d", &n, &m) == 2 && n && m)
	{
		REP(i, n)
		REP(j, m - 1) scanf("%d", &cost[i][j][0]);// æ¨ªçº¿
		REP(i, n - 1)
		REP(j, m) scanf("%d", &cost[i][j][1]);// ç«çº¿
		REP(i, n - 1)
		REP(j, m - 1) scanf("%d", &cost[i][j][2]);// æçº¿
		solver.init(3 * n * m + 1);
		REP(i, n - 1)
		REP(j, m - 1)
		{
			int top[] = {i, j, 0};
			int bottom[] = {i + 1, j, 0};
			int left[] = {i, j, 1};
			int right[] = {i, j + 1, 1};
			int slash[] = {i, j, 2};
			AddTriangleEdges(top, slash, right);
			AddTriangleEdges(left, slash, bottom);
		}
		// ä»èµ·ç¹å°å·¦/ä¸è¾¹ççå¼§
		REP(i, n - 1)
		solver.AddEdge(0, ID(i, 0, 1), cost[i][0][1]);// å·¦
		REP(i, m - 1)
		solver.AddEdge(0, ID(n - 1, i, 0), cost[n - 1][i][0]);// ä¸
		solver.dijkstra(0);

		// æ¾åºå³/ä¸è¾¹ççæå°då¼
		int ans = 2000000000;
		REP(i, n - 1)
		ans = min(ans, solver.d[ID(i, m - 1, 1)]);// å³
		REP(i, m - 1)
		ans = min(ans, solver.d[ID(0, i, 0)]);// ä¸
		printf("Case %d: Minimum = %d\n", ++kase, ans);
	}
	return 0;
}
