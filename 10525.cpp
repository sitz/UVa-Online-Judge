#include <bits/stdc++.h>

using namespace std;

struct edge
{
	int u_;// src vertex
	int v_;// dst vertex
	int t_;// time
	int l_;// len

	edge() : u_(-1), v_(-1), t_(-1), l_(-1) {}
	edge(int u, int v, int t, int l) : u_(u), v_(v), t_(t), l_(l) {}
};

pair<int, int> bellman_ford(int n, int s, int t, const vector<edge> &edges)
{
	vector<pair<int, int> > dists(n, make_pair(numeric_limits<int>::max(), numeric_limits<int>::max()));
	dists[s].first = dists[s].second = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (size_t j = 0, je = edges.size(); j < je; j++)
		{
			const edge &e = edges[j];
			long long lt = static_cast<long long>(dists[e.u_].first),
								ll = static_cast<long long>(dists[e.u_].second);
			if (lt + e.t_ < dists[e.v_].first ||
					lt + e.t_ == dists[e.v_].first && ll + e.l_ < dists[e.v_].second)
			{
				dists[e.v_] = make_pair(dists[e.u_].first + e.t_, dists[e.u_].second + e.l_);
			}
		}
	}
	return dists[t];
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		vector<edge> edges(m * 2);
		for (int i = 0; i < m; i++)
		{
			int a, b, c, d;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			a--;
			b--;
			edges[i * 2].u_ = edges[i * 2 + 1].v_ = a;
			edges[i * 2].v_ = edges[i * 2 + 1].u_ = b;
			edges[i * 2].t_ = edges[i * 2 + 1].t_ = c;
			edges[i * 2].l_ = edges[i * 2 + 1].l_ = d;
		}
		int q;
		scanf("%d", &q);
		while (q--)
		{
			int s, t;
			scanf("%d%d", &s, &t);
			pair<int, int> d = bellman_ford(n, s - 1, t - 1, edges);
			if (d.first != numeric_limits<int>::max())
			{
				printf("Distance and time to reach destination is %d & %d.\n", d.second, d.first);
			}
			else
			{
				printf("No Path.\n");
			}
		}
		if (T)
		{
			printf("\n");
		}
	}
	return 0;
}
