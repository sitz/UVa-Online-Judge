#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100;
const int MAX_V = 2 * MAX_N + 2;

int bs[MAX_N + 2], ss[MAX_N];
int B, S, D;

typedef int flow_t;
const flow_t INF = 1 << 20;
const flow_t EPS = 0;

struct edge
{
	int to, rev;
	flow_t cap;
};
vector<edge> graph[MAX_V];

int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, flow_t cap)
{
	graph[from].push_back((edge){
			to, (int)graph[to].size(), cap});
	graph[to].push_back((edge){
			from, (int)graph[from].size() - 1, 0});
}

void bfs(int source)
{
	memset(level, -1, sizeof(level));
	queue<int> que;
	level[source] = 0;
	que.push(source);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (int i = 0; i < (int)graph[v].size(); i++)
		{
			edge &e = graph[v][i];
			if (e.cap > 0 && level[e.to] < 0)
			{
				level[e.to] = level[v] + 1;
				que.push(e.to);
			}
		}
	}
}

flow_t dfs(int v, int sink, flow_t f)
{
	if (v == sink)
	{
		return f;
	}
	for (int &i = iter[v]; i < (int)graph[v].size(); i++)
	{
		edge &e = graph[v][i];
		if (e.cap > EPS && level[v] < level[e.to])
		{
			int d = dfs(e.to, sink, min(f, e.cap));
			if (d > EPS)
			{
				e.cap -= d;
				graph[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}

flow_t max_flow(int source, int sink)
{
	flow_t flow = 0;
	for (;;)
	{
		bfs(source);
		if (level[sink] < 0)
		{
			break;
		}
		memset(iter, 0, sizeof(iter));
		flow_t f;
		while ((f = dfs(source, sink, INF)) > 0)
		{
			flow += f;
		}
	}
	return flow;
}

void init()
{
	B = S = 0;
	int N;
	scanf("%d%d ", &N, &D);
	for (int i = 0; i < N; i++)
	{
		char c;
		int d;
		scanf("%c-%d ", &c, &d);
		if (c == 'B')
		{
			bs[B++] = d;
		}
		else
		{
			ss[S++] = d;
		}
	}
	bs[B++] = 0;
	bs[B++] = D;
}

bool check(int x)
{
	for (int i = 0; i < MAX_V; i++)
	{
		graph[i].clear();
	}
	const int source = B + 2 * S - 2, sink = source + 1;
	for (int i = 0; i < S; i++)
	{
		add_edge(i, i + S, 1);
		add_edge(i + S, i, 1);
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = i + 1; j < S; j++)
			if (abs(ss[i] - ss[j]) <= x)
			{
				add_edge(i + S, j, INF);
				add_edge(j + S, i, INF);
			}
	}
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < B; j++)
			if (abs(ss[i] - bs[j]) <= x)
			{
				add_edge(i + S, j + 2 * S, INF);
				add_edge(j + 2 * S, i, INF);
			}
	}
	for (int i = 0; i < B; i++)
	{
		for (int j = i + 1; j < B; j++)
			if (abs(bs[i] - bs[j]) <= x)
			{
				add_edge(i + 2 * S, j + 2 * S, INF);
				add_edge(j + 2 * S, i + 2 * S, INF);
			}
	}
	return max_flow(source, sink) >= 2;
}

int solve()
{
	int low = 0, high = D;
	while (high - low > 1)
	{
		int mid = (high + low) / 2;
		if (check(mid))
		{
			high = mid;
		}
		else
		{
			low = mid;
		}
	}
	return high;
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++)
	{
		init();
		printf("Case %d: %d\n", c, solve());
	}
	return 0;
}
