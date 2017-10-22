#include <bits/stdc++.h>

using namespace std;

#define MAXN 100
#define MAXV 300

int flow[MAXV + 1][MAXV + 1], prev_[MAXV + 1], queue_[MAXV + 1], delta[MAXV + 1], s, t, maxflow;
set<int> S;
map<int, int> M1, M2;
pair<int, int> p[MAXN + 1];
vector<vector<pair<int, int>>> adj;
vector<pair<int, int>> sorted, ans;

bool dijkstra()
{
	int j, u, v, c, head, tail;
	memset(prev_, 0, sizeof(prev_));
	prev_[s] = s + 1;
	delta[s] = 1000000000;
	head = tail = 0;
	queue_[tail++] = s;
	while (head < tail)
	{
		u = queue_[head++];
		for (j = 0; j < adj[u].size(); j++)
		{
			v = adj[u][j].first;
			c = adj[u][j].second;
			if (prev_[v] == 0)
			{
				if (c - flow[u][v] != 0)
				{
					delta[v] = min(delta[u], c - flow[u][v]);
					prev_[v] = u + 1;
					queue_[tail++] = v;
				}
				else if (flow[v][u] != 0)
				{
					delta[v] = min(delta[u], flow[v][u]);
					prev_[v] = -u - 1;
					queue_[tail++] = v;
				}
			}
		}
	}
	if (prev_[t] != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void max_flow()
{
	int j;
	maxflow = 0;
	while (dijkstra() == true)
	{
		j = t;
		while (j != s)
		{
			//printf("%d %d\n", j, prev_[j]);
			if (prev_[j] > 0)
			{
				flow[prev_[j] - 1][j] = flow[prev_[j] - 1][j] + delta[t];
				j = prev_[j] - 1;
			}
			else
			{
				flow[j][-prev_[j] - 1] = flow[j][-prev_[j] - 1] - delta[t];
				j = -prev_[j] - 1;
			}
		}
		maxflow = maxflow + delta[t];
	}
}

int main()
{
	int v[MAXN + 1], len[MAXV + 1];
	int i, j, k, m, n, r, sum, start, end, differ;
	r = 0;
	while ((scanf("%d", &n) != EOF) && (n != 0))
	{
		memset(flow, 0, sizeof(flow));
		S.clear();
		M1.clear();
		M2.clear();
		scanf("%d", &m);
		sum = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%d %d %d", &v[i], &p[i].first, &p[i].second);
			sum = sum + v[i];
			S.insert(p[i].first);
			S.insert(p[i].second);
		}
		k = -1;
		for (set<int>::iterator it = S.begin(); it != S.end(); it++)
		{
			k++;
			M1[k] = *it;
			M2[*it] = k;
		}
		s = k + n;
		t = s + 1;
		adj.clear();
		adj.resize(t + 1);
		for (i = 0; i < n; i++)
		{
			for (j = M2[p[i].first]; j < M2[p[i].second]; j++)
			{
				adj[i].push_back(make_pair(n + j, M1[j + 1] - M1[j]));
				adj[n + j].push_back(make_pair(i, 0));
			}
			adj[s].push_back(make_pair(i, v[i]));
			adj[i].push_back(make_pair(s, 0));
		}
		for (j = 0; j < k; j++)
		{
			adj[n + j].push_back(make_pair(t, (M1[j + 1] - M1[j]) * m));
			adj[t].push_back(make_pair(n + j, 0));
		}
		max_flow();
		printf("Case %d: ", ++r);
		if (sum == maxflow)
		{
			printf("Yes\n");
			for (j = 0; j < k; j++)
			{
				len[j] = M1[j];
			}
			for (i = 0; i < n; i++)
			{
				sorted.clear();
				ans.clear();
				for (j = 0; j < k; j++)
				{
					if (flow[i][n + j] != 0)
					{
						start = len[j];
						end = start + flow[i][n + j];
						differ = M1[j + 1] - M1[j];
						len[j] = end;
						if (end <= M1[j + 1])
						{
							sorted.push_back(make_pair(start, end));
						}
						else
						{
							sorted.push_back(make_pair(start, M1[j + 1]));
							sorted.push_back(make_pair(M1[j], end - differ));
							len[j] = len[j] - differ;
						}
						if (len[j] == M1[j + 1])
						{
							len[j] = M1[j];
						}
					}
				}
				sort(sorted.begin(), sorted.end());
				for (j = 0; j < sorted.size(); j++)
				{
					if ((ans.size() != 0) && (ans.back().second == sorted[j].first))
					{
						ans.back().second = sorted[j].second;
					}
					else
					{
						ans.push_back(sorted[j]);
					}
				}
				printf("%d", ans.size());
				for (j = 0; j < ans.size(); j++)
				{
					printf(" (%d,%d)", ans[j].first, ans[j].second);
				}
				printf("\n");
			}
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
