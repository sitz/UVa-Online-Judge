#include <bits/stdc++.h>

using namespace std;

// o(n^4) soln using max-flow with 'smart' updates
// after the initial max-flow computation, it determines which edges can be removed at no cost. this
// is accomplished by updating the max-flow network to that of a slightly modified graph, with the
// guarantee that the new flow can be at most 1 unit larger than the prev_ious one, so each such step
// only needs o(e) = o(n^2) time
// since this is repeated o(n^2) times, the total running time is o(n^4)

const int maxn = 192;

int cap[maxn][maxn], deg[maxn], edge[maxn][maxn], queue_[maxn], prev_[maxn];

// leaves residual capacities in cap[] and returs the max flow value
int maxflow(int n, int src, int sink)
{
	int flow = 0, i, v, w;
	for (;;)
	{
		// find shortest augmenting path with BFS
		fill(&prev_[0], &prev_[n], -1);
		int startq = 0, endq = 0;
		prev_[queue_[endq++] = src] = -2;
		while (startq != endq && prev_[sink] < 0)
			for (v = queue_[startq++], i = deg[v] - 1; i >= 0; --i)
				if (prev_[w = edge[v][i]] < 0 && cap[v][w] > 0)
				{
					prev_[queue_[endq++] = w] = v;
				}
		if (prev_[sink] == -1)
		{
			break;
		}
		// for each reachable vertex adjacent to the sink, find the path from the source,
		// remove these edges, and repeat while possible
		for (i = 0; i < n; i++)
			if (cap[i][sink] && prev_[i] != -1)
			{
				int minc = cap[i][sink];
				for (v = i; v != src; v = prev_[v])
				{
					minc = min(minc, cap[prev_[v]][v]);
				}
				if (!minc)
				{
					continue;
				}
				cap[i][sink] -= minc;
				cap[sink][i] += minc;
				for (v = i; v != src; v = prev_[v])
				{
					cap[prev_[v]][v] -= minc;
					cap[v][prev_[v]] += minc;
				}
				flow += minc;
			}
	}
	return flow;
}

// add an edge between 'a' and 'b' with capacity 'c'
void add(int a, int b, int c)
{
	edge[a][deg[a]++] = b;
	edge[b][deg[b]++] = a;
	cap[a][b] = c;
	cap[b][a] = 0;
}

int main()
{
	int ly, lx;
	bool first = true;
	while (scanf("%i%i", &ly, &lx), ly)
	{
		vector<int> sumx(lx), sumy(ly);
		for (int i = 0; i < ly; ++i)
		{
			scanf("%i", &sumy[i]);
		}
		for (int j = 0; j < lx; ++j)
		{
			scanf("%i", &sumx[j]);
		}
		if (!first)
		{
			puts("");
		}
		else
		{
			first = false;
		}
		int n = ly + lx + 2, src = n - 1, sink = n - 2,
			total = accumulate(sumx.begin(), sumx.end(), 0);
		fill(&deg[0], &deg[n], 0);
		for (int i = 0; i < n; ++i)
		{
			cap[i][sink] = 0;
		}
		for (int y = 0; y < ly; ++y)
		{
			add(src, y, sumy[y]);
		}
		for (int x = 0; x < lx; ++x)
		{
			add(ly + x, sink, sumx[x]);
		}
		for (int i = 0; i < ly * lx; ++i)
		{
			add(i / lx, ly + (i % lx), 1);
		}
		if (accumulate(sumy.begin(), sumy.end(), 0) != total || maxflow(n, src, sink) != total)
		{
			printf("Impossible\n");
		}
		else
			for (int i = 0; i < ly * lx; ++i)
			{
				int y = i / lx, x = i % lx;
				bool canbezero = (cap[y][ly + x] != 0);
				if (!canbezero)
				{
					// try not using this edge
					++cap[src][y];
					++cap[ly + x][sink];
					cap[y][ly + x] = cap[ly + x][y] = 0;
					if (maxflow(n, src, sink) > 0)
					{
						canbezero = true;
					}
					else
					{
						--cap[src][y];
						--cap[ly + x][sink];
					}
				}
				cap[y][ly + x] = cap[ly + x][y] = 0;
				if (canbezero)
				{
					putchar('N');
				}
				else
				{
					--total;
					putchar('Y');
				}
				if (i % lx == lx - 1)
				{
					printf("\n");
				}
			}
	}
	return 0;
}
