#include <bits/stdc++.h>

using namespace std;

// MinCostMaxFlow #StanfordUniversityNotebook
// @ https://web.stanford.edu/~liszt90/acm/notebook.html
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long L;
typedef vector<L> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const L INF = numeric_limits<L>::max() / 4;

struct MinCostMaxFlow
{
	int N;
	VVL cap, flow, cost;
	VI found;
	VL dist, pi, width;
	VPII dad;

	MinCostMaxFlow(int N) : N(N), cap(N, VL(N)), flow(N, VL(N)), cost(N, VL(N)),
													found(N), dist(N), pi(N), width(N), dad(N) {}

	void AddEdge(int from, int to, L cap, L cost)
	{
		this->cap[from][to] = cap;
		this->cost[from][to] = cost;
	}

	void Relax(int s, int k, L cap, L cost, int dir)
	{
		L val = dist[s] + pi[s] - pi[k] + cost;
		if (cap && val < dist[k])
		{
			dist[k] = val;
			dad[k] = make_pair(s, dir);
			width[k] = min(cap, width[s]);
		}
	}

	L Dijkstra(int s, int t)
	{
		fill(found.begin(), found.end(), false);
		fill(dist.begin(), dist.end(), INF);
		fill(width.begin(), width.end(), 0);
		dist[s] = 0;
		width[s] = INF;

		while (s != -1)
		{
			int best = -1;
			found[s] = true;
			for (int k = 0; k < N; k++)
			{
				if (found[k])
					continue;
				Relax(s, k, cap[s][k] - flow[s][k], cost[s][k], 1);
				Relax(s, k, flow[k][s], -cost[k][s], -1);
				if (best == -1 || dist[k] < dist[best])
					best = k;
			}
			s = best;
		}

		for (int k = 0; k < N; k++)
			pi[k] = min(pi[k] + dist[k], INF);
		return width[t];
	}

	pair<L, L> GetMaxFlow(int s, int t)
	{
		L totflow = 0, totcost = 0;
		while (L amt = Dijkstra(s, t))
		{
			totflow += amt;
			for (int x = t; x != s; x = dad[x].first)
			{
				if (dad[x].second == 1)
				{
					flow[dad[x].first][x] += amt;
					totcost += amt * cost[dad[x].first][x];
				}
				else
				{
					flow[x][dad[x].first] -= amt;
					totcost -= amt * cost[x][dad[x].first];
				}
			}
		}
		return make_pair(totflow, totcost);
	}
};

int main()
{
	int T = 0;
	cin >> T;

	// This problem can be interpreted as a minimum weight bipartite matching.
	// We can reduce the minimum weight bipartite matching problem to the
	// min cost flow problem by adding a source node 's' and a sink node 't'
	// such that 's' has an edge with capacity 1 and cost 0 to each chef, and
	// each facility has an edge to 't' with capacity 1 and cost 0.
	// Besides the edges between chefs and facilities must have capacity 1 and
	// the cost is specified by the problem statement.
	// https://en.wikipedia.org/wiki/Minimum-cost_flow_problem
	// https://en.wikipedia.org/wiki/File:Minimum_weight_bipartite_matching.pdf
	while (T--)
	{
		// Chefs, facilities and edges
		int C = 0, F = 0, E = 0;
		cin >> C >> F >> E;

		// The total number of nodes are the number of chefs and facilities
		// plus two more: the source s and the sink t
		MinCostMaxFlow mcmf(C + F + 2);

		// Identifiers go from 0 to C-1 for chefs,
		// and from C to C+F-1 for facilities
		for (int i = 0; i < E; ++i)
		{
			int ci, fi, ei;
			cin >> ci >> fi >> ei;

			int fip = fi + C;

			mcmf.AddEdge(ci, fip, 1, ei);
		}

		// Identifiers for s (source) and t (sink)
		int s = C + F;
		int t = s + 1;

		// Add edges from sink to chefs
		for (int i = 0; i < C; ++i)
		{
			mcmf.AddEdge(s, i, 1, 0);
		}

		// Add edges from facilities to sink
		for (int i = 0; i < F; ++i)
		{
			mcmf.AddEdge(i + C, t, 1, 0);
		}

		cout << mcmf.GetMaxFlow(s, t).second << endl;

		if (T >= 1)
		{
			cout << endl;
		}
	}

	return 0;
}
