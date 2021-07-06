#include <bits/stdc++.h>

using namespace std;

const int maxrounds = 300, maxlabels = 10000;
const int maxenv = 2 * maxrounds, maxn = 2 * maxenv;

int labels[maxn], idx[maxlabels], n; // for country labels
int rounds, coins[maxenv][2], chosen[maxenv], last[2 * maxn], visited[2 * maxn];

// graph
vector<int> edges[maxn];

// get the other endpoint of an edge e
int endpoint(int e, int a)
{
	return coins[e][0] + coins[e][1] - a;
}

// is edge e (in envelop e / 2) currently chosen?
bool is_chosen(int e)
{
	return chosen[e / 2] == (e & 1);
}

int depth[maxn], prev_[maxn];

// DFS from vertex (country) v
void dfs(int v, int d = 0, int p = -1)
{
	depth[v] = d;
	prev_[v] = p;
	for (int i = 0; i < edges[v].size(); ++i)
	{
		int e = edges[v][i], w = endpoint(e, v);
		if (is_chosen(e) && depth[w] < 0)
		{
			dfs(w, d + 1, e);
		}
	}
}

int parent(int a)
{
	return prev_[a] >= 0 ? endpoint(prev_[a], a) : -1;
}

bool find_cycle(int e, vector<int> &cycle)
{
	int a = coins[e][0], b = coins[e][1];
	fill(&depth[0], &depth[n], -1);
	dfs(a);
	if (depth[b] < 0)
	{
		return false;
	}
	while (b != a)
	{
		cycle.push_back(prev_[b]);
		b = parent(b);
	}
	return true;
}

bool process_envelop(int i)
{
	chosen[i] = -1;
	deque<int> q;
	for (int j = 0; j < 2; ++j)
	{
		visited[2 * i + j] = i;
		q.push_back(2 * i + j);
	}
	// BFS to find an augmenting path
	while (!q.empty())
	{
		int add = q.front();
		q.pop_front(); // edge to add
		vector<int> cycle;
		// if the edge does not create a cycle
		if (!find_cycle(add, cycle))
		{
			// trace the path back to one of the two edges in this round
			while (add / 2 != i)
			{
				chosen[add / 2] ^= 1;
				add = last[add];
			}
			chosen[i] = add & 1;
			return true;
		}
		else
		{
			// try to remove one edge and add its companion
			for (int k = 0; k < cycle.size(); ++k)
			{
				int remove = cycle[k],
						add_next = remove ^ 1;
				if (visited[add_next] != i)
				{
					visited[add_next] = i;
					last[add_next] = add;
					q.push_back(add_next);
				}
			}
		}
	}
	return false;
}

int main()
{
	while (scanf("%i", &rounds) == 1 && rounds > 0)
	{
		int ret = 0;
		n = 0; // #country
		for (int r = 0; r < rounds; ++r)
		{
			for (int i = 0; i < 2; ++i)
			{
				for (int j = 0; j < 2; ++j)
				{
					int a;
					scanf("%i", &a);
					// add new country if needed
					if (idx[a] >= 0 && idx[a] < n && labels[idx[a]] == a)
						;
					else
					{
						edges[n].clear();
						visited[n] = visited[n + 1] = -1;
						labels[idx[a] = n++] = a;
					}
					coins[2 * r + i][j] = idx[a];
					edges[coins[2 * r + i][j]].push_back(2 * r + i);
				}
			}
			// ret < n - 1 cond not needed
			if (ret < n - 1 && process_envelop(r))
			{
				++ret;
			}
		}
		printf("%i\n", 2 * ret);
	}
	return 0;
}
