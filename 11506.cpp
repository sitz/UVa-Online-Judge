#include <bits/stdc++.h>

using namespace std;

#define D(x) cout << #x " is " << x << endl

const int MAXN = 2 * 55;

int cap[MAXN + 1][MAXN + 1], flow[MAXN + 1][MAXN + 1], prev_[MAXN + 1];

// cap[i][j] = edge (i, j) capacity
// flow[i][j] = curr flow i->j
// prev_[i] = predecessor of node i on augmenting path
int ford_fulkerson(int n, int s, int t)
{
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		fill(flow[i], flow[i] + n, 0);
	}
	while (1)
	{
		fill(prev_, prev_ + n, -1);
		queue<int> q;
		q.push(s);
		while (q.size() && prev_[t] == -1)
		{
			int u = q.front();
			q.pop();
			for (int v = 0; v < n; ++v)
			{
				if (v != s && prev_[v] == -1 && cap[u][v] - flow[u][v] > 0)
				{
					prev_[v] = u, q.push(v);
				}
			}
		}
		if (prev_[t] == -1)
		{
			break;
		}
		int bottleneck = INT_MAX;
		for (int v = t, u = prev_[v]; u != -1; v = u, u = prev_[v])
		{
			bottleneck = min(bottleneck, cap[u][v] - flow[u][v]);
		}
		for (int v = t, u = prev_[v]; u != -1; v = u, u = prev_[v])
		{
			flow[u][v] += bottleneck;
			flow[v][u] = -flow[u][v];
		}
		ans += bottleneck;
	}
	return ans;
}

inline int in(int i)
{
	return 2 * i;
}
inline int out(int i)
{
	return 2 * i + 1;
}

int main()
{
	int n, e;
	while (cin >> n >> e && (n + e))
	{
		memset(cap, 0, sizeof cap);
		// 2 machines that cannot be destroyed
		cap[in(0)][out(0)] = cap[in(n - 1)][out(n - 1)] = INT_MAX;
		// cost of machine destruction
		for (int k = 2, i, w; k < n; ++k)
		{
			cin >> i >> w;
			--i;
			cap[in(i)][out(i)] = w;
		}
		// cost of cable destruction
		for (int k = 0, i, j, w; k < e; ++k)
		{
			cin >> i >> j >> w;
			--i, --j;
			cap[out(i)][in(j)] = cap[out(j)][in(i)] = w;
		}
		int ans = ford_fulkerson(2 * n, in(0), out(n - 1));
		cout << ans << endl;
	}
	return 0;
}
