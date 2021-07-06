#include <bits/stdc++.h>

using namespace std;

#define MAXN 128
#define MAXCYCLE 2520
#define INF (1LL << 60)

struct Edge
{
	int to, c, w;
	Edge(int x = 0, int y = 0, int z = 0)
			: to(x), c(y), w(z)
	{
	}
};
vector<Edge> g[MAXN], invg[MAXN];

long long distFromSt[MAXN][MAXCYCLE], kpath[MAXN][MAXCYCLE];

struct Info
{
	int x, t;
	long long d;
	Info(int a = 0, int b = 0, long long c = 0)
			: x(a), t(b), d(c)
	{
	}
	bool operator<(const Info &a) const
	{
		return d > a.d;
	}
};

void kthSSSP(int st, int ed, int K, int N, int T)
{
	int kpathCnt[MAXN];
	priority_queue<Info, vector<Info> > pQ;
	Info u;
	int cycle = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < g[i].size(); j++)
		{
			int lcm = cycle * g[i][j].c / __gcd(cycle, g[i][j].c);
			cycle = lcm;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < cycle; j++)
		{
			distFromSt[i][j] = INF, kpath[i][j] = 0;
		}
		kpathCnt[i] = 0;
	}
	pQ.push(Info(st, 0, 0));
	while (!pQ.empty())
	{
		u = pQ.top(), pQ.pop();
		if (kpath[u.x][u.t] > K)
		{
			continue;
		}
		kpath[u.x][u.t]++, distFromSt[u.x][u.t] = u.d;
		kpathCnt[u.x]++;
		if (kpathCnt[u.x] == K && u.x == ed)
		{
			printf("%lld\n", distFromSt[u.x][u.t]);
			return;
		}
		for (int i = 0; i < g[u.x].size(); i++)
		{
			long long av = (u.d / g[u.x][i].c + (u.d % g[u.x][i].c != 0)), w;
			int to = g[u.x][i].to;
			w = g[u.x][i].w;
			av = av * g[u.x][i].c;
			for (; av - u.d <= T; av += g[u.x][i].c)
			{
				pQ.push(Info(to, (av + w) % cycle, av + w));
			}
		}
	}
	printf("-1\n");
}

int main()
{
	int N, M, K, T, U, V, C, W, t = 0;
	while (scanf("%d%d%d%d", &N, &M, &K, &T) == 4 && N)
	{
		for (int i = 0; i < N; i++)
		{
			g[i].clear();
			invg[i].clear();
		}
		for (int i = 0; i < M; i++)
		{
			scanf("%d%d%d%d", &U, &V, &C, &W);
			g[U].push_back(Edge(V, C, W));
			invg[V].push_back(Edge(U, C, W));
		}
		printf("Case %d: ", ++t);
		kthSSSP(0, N - 1, K + 1, N, T);
	}
	return 0;
}
