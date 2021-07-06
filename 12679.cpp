#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

const int INF = 1000000000;

struct MaxFlow
{
	int N;
	VVI cap, flow;
	VI dad, Q;

	MaxFlow(int N) : N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N) {}

	void AddEdge(int from, int to, int cap)
	{
		this->cap[from][to] += cap;
	}

	void SetEdge(int from, int to, int cap)
	{
		this->cap[from][to] = cap;
	}

	int BlockingFlow(int s, int t)
	{
		fill(dad.begin(), dad.end(), -1);
		dad[s] = -2;

		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail)
		{
			int x = Q[head++];
			for (int i = 0; i < N; i++)
			{
				if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0)
				{
					dad[i] = x;
					Q[tail++] = i;
				}
			}
		}

		if (dad[t] == -1)
			return 0;

		int totflow = 0;
		for (int i = 0; i < N; i++)
		{
			if (dad[i] == -1)
				continue;
			int amt = cap[i][t] - flow[i][t];
			for (int j = i; amt && j != s; j = dad[j])
				amt = min(amt, cap[dad[j]][j] - flow[dad[j]][j]);
			if (amt == 0)
				continue;
			flow[i][t] += amt;
			flow[t][i] -= amt;
			for (int j = i; j != s; j = dad[j])
			{
				flow[dad[j]][j] += amt;
				flow[j][dad[j]] -= amt;
			}
			totflow += amt;
		}

		return totflow;
	}

	int GetMaxFlow(int source, int sink)
	{
		fill(Q.begin(), Q.end(), 0);

		for (int i = 0; i < N; ++i)
		{
			fill(flow[i].begin(), flow[i].end(), 0);
		}

		int totflow = 0;
		while (int flow = BlockingFlow(source, sink))
			totflow += flow;
		return totflow;
	}
};

struct Course
{
	// init, end, classes required
	int a, b, s;
};

Course courses[101];
int clean[101][101];

int main()
{
	int tests = 0;
	cin >> tests;

	for (int t = 1; t <= tests; ++t)
	{
		int n, m;
		cin >> n >> m;

		int totalClasses = 0;

		for (int i = 0; i < n; ++i)
		{
			int s = 0;
			cin >> courses[i].a >> courses[i].b >> s;
			courses[i].s = s / m + (s % m != 0);
			totalClasses += courses[i].s;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> clean[i][j];
			}
		}

		MaxFlow maxFlow(2 * n + 4);

		//source to classes
		int sourceId = 2 * n;
		int sinkId = 2 * n + 1;
		int subSourceId = 2 * n + 2;
		int subSinkId = 2 * n + 3;

		for (int i = 0; i < n; ++i)
		{
			maxFlow.AddEdge(sourceId, i, courses[i].s);
			maxFlow.AddEdge(i + n, sinkId, courses[i].s);
			maxFlow.AddEdge(i, subSourceId, INF);
			maxFlow.AddEdge(subSinkId, i + n, INF);
		}

		for (int i = 0; i < n - 1; ++i)
		{
			const Course &c1 = courses[i];

			for (int j = i + 1; j < n; ++j)
			{
				const Course &c2 = courses[j];

				if (c1.b + clean[i][j] < c2.a)
				{
					maxFlow.AddEdge(i, j + n, INF);
				}

				if (c2.b + clean[j][i] < c1.a)
				{
					maxFlow.AddEdge(j, i + n, INF);
				}
			}
		}

		int low = 0;
		int high = totalClasses;
		int ans = -1;

		while (low <= high)
		{
			int mid = (low + high) / 2;

			maxFlow.SetEdge(subSourceId, subSinkId, mid);
			int totFlow = maxFlow.GetMaxFlow(sourceId, sinkId);

			if (totFlow == totalClasses)
			{
				ans = mid;
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		cout << "Case " << t << ": " << ans << endl;
	}

	return 0;
}
